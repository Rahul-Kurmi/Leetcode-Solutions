class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();

        // take 2 boolean array pf size -> n+1
        vector<bool> isPresentInA(n+1 , false);
        vector<bool> isPresentInB(n+1 , false);
        // these will mark for each element is present till ith iteration
        // size -> n+1 because element 1 -> n in arr
        // thus bool index 0 -> n to mark every elements 

        vector<int> ans(n);

        // SC : O(n) --> 2 , 2 extra boolen array 
        // TC : O(n^2)

        for(int i = 0 ; i < n ; i++){
            isPresentInA[A[i]] = true ;
            isPresentInB[B[i]] = true ;

            int matched = 0 ;
            for(int check = 1 ; check <= n ; check++){
                if(isPresentInA[check] && isPresentInB[check]){
                    matched++;
                }
            }

            ans[i] = matched ;
        }
        return ans ;
    }
};