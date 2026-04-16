class Solution {
public:
    string reorganizeString(string s) {
        int freq[26] = {0};

        for(int i = 0 ; i < s.size() ; i++){
            freq[s[i] - 'a']++;
        }

        priority_queue<pair<int , char>> maxHeap ;

        for(int i = 0 ; i < 26 ; i++){
            if(freq[i] > 0){
                maxHeap.push({freq[i] , i + 'a'});
            }
        }

        string ans = "";
        while(maxHeap.size() > 1){
            pair<int , char> firstData = maxHeap.top();
            maxHeap.pop();
            pair<int , char> secondData = maxHeap.top();
            maxHeap.pop();
            
            ans += firstData.second;
            ans += secondData.second;
            firstData.first--;
            secondData.first--;

            if(firstData.first > 0) maxHeap.push(firstData);
            if(secondData.first > 0) maxHeap.push(secondData);
        }

        if(maxHeap.size() == 1){
            auto lastTop = maxHeap.top();
            if(lastTop.first == 1){
                ans+= lastTop.second;
            }
            else{
                return "";
            }
        }
        return ans;
    }
};