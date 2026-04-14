class Solution {
public:
    bool checkBound(vector<vector<int>>& grid , vector<pair<int, int>>& vertices){
        int m = grid.size();
        int n = grid[0].size();

        for(auto pts : vertices){
            if(pts.first < 0 || pts.first >= m || pts.second < 0 || pts.second >= n){
                return false ;
            }
        }
        return true ;
    }

    bool getAllVertices(vector<vector<int>>& grid , vector<pair<int, int>>& vertices, pair<int, int> center , int& delta){
        pair<int, int> A(center.first - delta , center.second);
        pair<int, int> B(center.first , center.second + delta);
        pair<int, int> C(center.first + delta , center.second);
        pair<int, int> D(center.first  , center.second - delta);

        vertices[0] = A ;
        vertices[1] = B ;
        vertices[2] = C ;
        vertices[3] = D ;
        // check if the vertices are in bound
        if(checkBound(grid , vertices)){
            return true ;
        }
        return false ;
    }

    void getAllSum(vector<vector<int>>& grid , int& cx , int& cy , priority_queue<int>& pq){
        pq.push(grid[cx][cy]);
        int delta = 1 ;
        vector<pair<int, int>> vertices(4);
        while(getAllVertices(grid , vertices , {cx, cy} , delta)){
            pair<int, int>& A = vertices[0];
            pair<int, int>& B = vertices[1];
            pair<int, int>& C = vertices[2];
            pair<int, int>& D = vertices[3];
            
            // get the vertices sum  
            int cSum = grid[A.first][A.second] + grid[B.first][B.second] + grid[C.first][C.second] + grid[D.first][D.second];


            // all cells between AB 
            for(int i = 1 ; i < B.first - A.first ; i++){
                cSum += grid[A.first+i][A.second+i];
            }
            
            // all cells between BC 
            for(int i = 1 ; i < C.first - B.first ; i++){
                cSum += grid[B.first+i][B.second-i];
            }
            
            // all cells between CD
            for(int i = 1 ; i < C.first - D.first ; i++){
                cSum += grid[C.first-i][C.second-i];
            }
            
            // all cells between DA
            for(int i = 1 ; i < D.first - A.first ; i++){
                cSum += grid[D.first-i][D.second+i];
            }

            pq.push(cSum); // push the rhombus sum in heap
            delta++;
        }
    }

    bool canPush(vector<int>& ans , int& top){
        for(auto val : ans){
            if(val == top) return false ;
        }
        return true ;
    }

    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> ans ;
        priority_queue<int> pq ;
        int m = grid.size();
        int n = grid[0].size();

        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                getAllSum(grid , i , j , pq);
            }
        }


        while(!pq.empty() && ans.size() < 3){
            int topValue = pq.top();
            pq.pop();
            if(canPush(ans , topValue)) ans.push_back(topValue);
        }
        return ans ;
    }
};