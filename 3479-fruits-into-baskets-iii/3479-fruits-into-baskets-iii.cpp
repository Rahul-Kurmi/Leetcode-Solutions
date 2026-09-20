class Solution {
public:
    void buildSegmentTree(int idx , int l , int r , vector<int>& segTree, vector<int>& baskets){
        if(l == r){
            segTree[idx] = baskets[l];
            return ;
        }

        int mid = l + (r - l) / 2 ;
        buildSegmentTree(2*idx+1, l , mid , segTree, baskets);
        buildSegmentTree(2*idx+2, mid+1, r, segTree, baskets);

        segTree[idx] = max(segTree[2*idx+1] , segTree[2*idx+2]);
    }

    bool querySegmentTree(int idx, int l , int r, vector<int>& segTree, int fruitSize){
        // No basket in this range can hold the fruit
        if(segTree[idx] < fruitSize){
            return false;
        }

        // We found a basket
        if(l == r){
            segTree[idx] = -1;
            return true;
        }

        int mid = l + (r - l) / 2;

        // Try left side first
        bool leftQuery = querySegmentTree(
            2*idx+1, l, mid, segTree, fruitSize
        );

        if(leftQuery){
            // Update current node after using basket
            segTree[idx] = max(segTree[2*idx+1], segTree[2*idx+2]);
            return true;
        }

        // Try right side
        bool rightQuery = querySegmentTree(2*idx+2, mid+1, r, segTree, fruitSize);

        // Update current node after using basket
        segTree[idx] = max(segTree[2*idx+1], segTree[2*idx+2]);

        return rightQuery;
        
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = baskets.size();
        vector<int> segTree(4*n, 0);

        buildSegmentTree(0, 0 , n-1, segTree, baskets);

        int count = 0 ;
        for(int i = 0 ; i < fruits.size(); i++){
            bool canGetLeftBasket = querySegmentTree(0, 0, n-1, segTree, fruits[i]);

            if(!canGetLeftBasket) count++; 
        }

        return count ;
    }
};