class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> maxHeap;
        if(a > 0) maxHeap.push({a ,'a'});
        if(b > 0) maxHeap.push({b ,'b'});
        if(c > 0) maxHeap.push({c, 'c'});

        string ans = "";
        while(maxHeap.size() > 1){
            auto firstData = maxHeap.top();
            maxHeap.pop();
            auto secondData = maxHeap.top();
            maxHeap.pop();

            if(firstData.first >= 2){
                ans += firstData.second;
                ans += firstData.second;
                firstData.first -= 2; 
            }
            else{
                ans += firstData.second;
                firstData.first -= 1; 
            }

            if(secondData.first >= 2 && secondData.first > firstData.first){
                ans += secondData.second;
                ans += secondData.second;
                secondData.first -= 2;
            }
            else{
                ans += secondData.second;
                secondData.first -= 1;
            }

            if(firstData.first > 0) maxHeap.push(firstData);
            if(secondData.first > 0) maxHeap.push(secondData);
        }

        if(maxHeap.size() == 1){
            auto lastTop = maxHeap.top();
            if(lastTop.first >= 2){
                ans += lastTop.second;
                ans += lastTop.second;
            }
            else{
                ans += lastTop.second;
            }
        }

        return ans;
    }
};