class Solution {
public:
    void updateSegmentTree(int idx, int l , int r, int updateIdx, vector<long long>& segmentTree){
        if(l == r){
            segmentTree[idx] = 1 ; // for one element count is 1
            return ;
        }

        int mid = l + (r - l) / 2 ;
        if(updateIdx <= mid){
            updateSegmentTree(2*idx + 1, l, mid, updateIdx, segmentTree);
        }
        else{
            updateSegmentTree(2*idx + 2, mid+1, r, updateIdx, segmentTree);
        }

        // update for current node
        segmentTree[idx] = segmentTree[2*idx + 1] + segmentTree[2*idx + 2]; 
    }

    long long querySegmentTree(int start , int end , int idx, int l , int r, vector<long long>& segmentTree){
        // CASE 1 : out of range
        if(l > end || r < start){
            return 0 ;
        }
        // CASE 2 : fully in range
        else if(l >= start && r <= end){
            return segmentTree[idx];
        }
        // CASE 3 : partial Overlap
        else{
            int mid = l + (r - l) / 2 ;
            long long leftPart = querySegmentTree(start , end, 2*idx + 1 , l , mid , segmentTree);
            long long rightPart = querySegmentTree(start, end, 2*idx + 2 , mid + 1 , r , segmentTree);

            return leftPart + rightPart ;
        }
    }

    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();

        unordered_map<int, int> mp ; // stores nums2 -> {element, index}
        for(int i = 0 ; i < n ; i++){
            mp[nums2[i]] = i ;
        }

        vector<long long> segmentTree(4*n) ; 
        long long result = 0 ;

        // Update with first element's mapped index from nums2
        updateSegmentTree(0, 0 , n-1, mp[nums1[0]], segmentTree);

        for(int i = 1 ; i < n ; i++){
            int idx = mp[nums1[i]]; // get index of nums2 for same element in nums1
            long long leftCommonCount = querySegmentTree(0, idx, 0, 0, n-1, segmentTree);
            long long leftUncommonCountNums1 = i -  leftCommonCount;
            long long elementsAfterIdxNums2 = n - idx - 1 ;
            long long rightCommonCount = elementsAfterIdxNums2 - leftUncommonCountNums1;

            result += leftCommonCount * rightCommonCount ;

            // update for current element ie. at idx in nums2 
            updateSegmentTree(0, 0, n - 1, idx, segmentTree);
        } 

        return result ;
    }
};