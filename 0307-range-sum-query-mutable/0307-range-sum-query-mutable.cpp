class NumArray {
public:
    vector<int> segTree;
    int n ;

    void createSegmentTree(vector<int>& nums, int i , int l, int r){
        if(l == r){
            segTree[i] = nums[l];
            return ;
        }

        int mid = l + (r  -l) / 2 ;
        createSegmentTree(nums, 2*i+1 , l , mid);
        createSegmentTree(nums, 2*i+2, mid+1 , r);

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4*n);
        createSegmentTree(nums, 0 , 0, n-1); // nums, i --> of segTree, l, r of nums
    }
    
    void updateSegTreeQuery(int index , int val , int i , int l , int r){
        if(l == r){ // Base Case reached at index value of nums
            segTree[i] = val ;
            return ;
        }

        int mid = l + (r - l) / 2 ;
        if(index <= mid){ // index is left side of tree
            updateSegTreeQuery(index, val, 2*i+1, l , mid);
        }
        else{ // index is right side of tree
            updateSegTreeQuery(index, val, 2*i+2, mid+1, r);
        }

        segTree[i] = segTree[2*i+1] + segTree[2*i+2];
    }

    void update(int index, int val) {
        updateSegTreeQuery(index,  val , 0 , 0 , n-1);
    }
    

    int sumRangeQuery(int &start , int &end , int i , int l , int r){
        // [l, r] --> our segTree range
        // [start , end] --> find range sum 
        // we try to find [l , r] in  [start , end]

        // CASE 1 : [l,r] out of bound in [start, end]
        if(r < start ||  l > end){ // our [l,r] not in [start, end]
            return 0 ;
        }

        // CASE 2 : Intirely inside ir [l,r] is in [start, end]
        else if(l >= start && r <= end){
            return segTree[i];
        }

        // CASE 3 : overlapping or [start , end] inside [l , r]
        else{
            int mid = l + (r - l) / 2 ;
            return sumRangeQuery(start , end , 2*i+1 , l , mid) + 
                   sumRangeQuery(start , end , 2*i+2 , mid+1, r);
        }

    }

    int sumRange(int start, int end) {
        return sumRangeQuery(start , end , 0 , 0 , n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */