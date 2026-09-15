class Solution {
public:
    void buildSegmentTree(int idx, int l, int r, int* segmentTree,  vector<int>& heights){
        if(l == r){
            segmentTree[idx] = l;
            return;
        }

        int mid = l + (r - l)/2 ;
        buildSegmentTree(2*idx + 1 , l , mid , segmentTree, heights);
        buildSegmentTree(2*idx + 2 , mid + 1, r, segmentTree, heights);

        segmentTree[idx] = (heights[segmentTree[2*idx+1]] > heights[segmentTree[2*idx + 2]]) ? 
                            segmentTree[2*idx + 1] : segmentTree[2*idx + 2];
    }

    int* constructSegTree(vector<int>& heights, int n){
        int * segmentTree = new int[4*n] ;
        buildSegmentTree(0 , 0 , n-1, segmentTree, heights);
        return segmentTree ;
    }


    int querySegmentTree(int start, int end, int idx, int l, int r, int* segmentTree, vector<int>& heights){
        // CASE 1 : out of range
        if(l > end || r < start ){
            return -1 ; 
        }
        // CASE 2 : perfectly in range 
        else if(l >= start && r <= end) {
            return segmentTree[idx];
        }
        // CASE 3 : Partial overlap
        int mid = l + (r - l) / 2 ;
        int leftIndex = querySegmentTree(start, end, 2*idx+1 , l , mid, segmentTree, heights);
        int rightIndex = querySegmentTree(start, end, 2*idx+2, mid+1, r, segmentTree, heights);

        // check for invalid indexes
        if(leftIndex == -1) return rightIndex;
        if(rightIndex == -1) return leftIndex;

        return (heights[leftIndex] >= heights[rightIndex]) ? leftIndex : rightIndex ;
    }

    int RMIQ(int* segmentTree, vector<int>& heights, int n, int start, int end){
        return querySegmentTree(start, end , 0 , 0 , n-1 , segmentTree, heights);
    }


    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int* segmentTree = constructSegTree(heights, n);

        vector<int> result ;

        for(auto query : queries){
            int minIdx = min(query[0] , query[1]);
            int maxIdx = max(query[0] , query[1]);

            if(minIdx == maxIdx){
                result.push_back(minIdx);
            }
            else if(heights[maxIdx] > heights[minIdx]){
                result.push_back(maxIdx);
            }
            else{
                // get right range in which we will search for next leftmost higer building
                int l = maxIdx + 1 ;
                int r = n - 1;
                int result_idx = INT_MAX ;
                while(l <= r){
                    int mid = l + (r - l) / 2 ;

                    int idx = RMIQ(segmentTree, heights, n, l , mid);

                    // if idx uilding is higher than both the building 
                    if(heights[idx] > max(heights[maxIdx] , heights[minIdx])){
                        r = mid - 1 ;
                        result_idx = min(result_idx, idx);
                    }
                    else{
                        l = mid + 1 ;
                    }
                }

                result_idx == INT_MAX ? result.push_back(-1) : result.push_back(result_idx);
            }
        }

        return result ;
    }
};