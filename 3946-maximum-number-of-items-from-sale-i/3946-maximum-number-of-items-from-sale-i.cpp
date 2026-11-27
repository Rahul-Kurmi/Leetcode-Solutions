//Approach-1 (Recursion Memo)
//T.C : O(n^2 + n*budget)
//S.C : O(n + n*budget)
class Solution {
public:
    int t[1001][1501];

    int solve(int i, int budget, int minPrice, vector<vector<int>>& items, vector<int>& copies) {
        if(i == 0) {
            return budget/minPrice;
        }

        if(t[i][budget] != -1)
            return t[i][budget];

        int take = 0;
        int price = items[i-1][1];

        if(price <= budget) {
            take = 1 + copies[i-1] + solve(i-1, budget-price, minPrice, items, copies);
        }

        int skip = solve(i-1, budget, minPrice, items, copies);

        return t[i][budget] = max(take, skip);
    }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();

        vector<int> copies(n, 0); //copies[i] = count of copies if I buy ith item
        int minPrice = INT_MAX;

        for(int i = 0; i < n; i++) {
            minPrice = min(minPrice, items[i][1]);

            int copy = 0;
            for(int j = 0; j < n; j++) {
                if(i == j) continue;

                if(items[j][0] % items[i][0] == 0)
                    copy++;
            }

            copies[i] = copy;
        }

        memset(t, -1, sizeof(t));
        return solve(n, budget, minPrice, items, copies);
    }
};