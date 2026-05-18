class Solution {
public:
    int minJumps(vector<int>& arr) {

        int n = arr.size();

        if(n == 1)
            return 0;

        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++) {
            mp[arr[i]].push_back(i);
        }

        vector<bool> visited(n, false);

        queue<int> q;

        q.push(0);
        visited[0] = true;

        int jumps = 0;

        while(!q.empty()) {

            int size = q.size();

            while(size--) {

                int front = q.front();
                q.pop();

                if(front == n - 1)
                    return jumps;

                // front + 1
                if(front + 1 < n &&
                   !visited[front + 1]) {

                    visited[front + 1] = true;
                    q.push(front + 1);
                }

                // front - 1
                if(front - 1 >= 0 &&
                   !visited[front - 1]) {

                    visited[front - 1] = true;
                    q.push(front - 1);
                }

                // same value jumps
                for(int idx : mp[arr[front]]) {

                    if(!visited[idx]) {

                        visited[idx] = true;
                        q.push(idx);
                    }
                }

                // optimization --> as we have visited every index of that elemnt this remove the entry from MAP --> else TLE as we'll be doing extra iteration 
                mp[arr[front]].clear();
            }

            jumps++;
        }

        return -1;
    }
};