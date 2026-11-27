//Approach-2 (Bottom Up)
//T.C : O(n^2 + n*budget)
//S.C : O(n + n*budget)
class Solution {
public:
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

        vector<vector<int>> t(n + 1, vector<int>(budget + 1, 0));

        // Base case: no item types left, spend leftover on the cheapest item
        // n = 0
        for (int b = 0; b <= budget; b++)
            t[0][b] = b / minPrice;

        for (int i = 1; i <= n; i++) {
            for (int b = 0; b <= budget; b++) {
                int price = items[i - 1][1];
                int take = 0;

                if (price <= b)
                    take = 1 + copies[i - 1] + t[i - 1][b - price];

                int skip = t[i - 1][b];

                t[i][b] = max(take, skip);
            }
        }

        return t[n][budget];
    }
};
