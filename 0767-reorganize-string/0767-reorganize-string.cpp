
class node {
    public :
        char data ;
        int count ;

        node(char d , int c){
            data = d ;
            count = c ;
        }
};

class compare{
    public :
    bool operator () (node *a , node *b){
        return a->count < b-> count ;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        // Create Mapping 
        int freq[26] = {0} ;
        // 1 --> a , 2 --> b ans so on 

        // Count frequencies of each character
        for (char ch : s) {
            freq[ch - 'a']++;
        }

        // Create max heap using priority_queue with pointers
        priority_queue<node*, vector<node*>, compare> maxHeap;

        // Push characters with their frequencies into maxHeap
        for (int i = 0; i < 26; i++) {
            if (freq[i] != 0) {
                node *temp = new node(i + 'a', freq[i]);
                maxHeap.push(temp);
            }
        }

        string ans = "";


        // greter than 1 becuse hum 2 value nikal rahe hai max heap se 
        while(maxHeap.size() > 1) {
            node * first = maxHeap.top();
            maxHeap.pop() ;
            node * second = maxHeap.top();
            maxHeap.pop();

            ans = ans + first -> data ;
            ans = ans + second -> data ;

            first -> count-- ;
            second -> count--;

            if(first -> count != 0 ){
                maxHeap.push(first) ;
            }

            if(second -> count != 0 ){
                maxHeap.push(second) ;
            }
        }

        if(maxHeap.size() == 1){
            node * temp = maxHeap.top();
            maxHeap.pop() ;
            if(temp->count == 1){
                ans = ans + temp -> data ;
            }
            else{
                return "";
            }
        }

        return ans ;
    }
};