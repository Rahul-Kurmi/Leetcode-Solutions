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
    string longestDiverseString(int a, int b, int c) {
        // Create max heap using priority_queue with pointers
        priority_queue<node*, vector<node*>, compare> maxHeap;

        if(a > 0){
            node * temp = new node ('a' , a);
            maxHeap.push(temp) ;
        }

        if(b > 0){
            node * temp = new node ('b' , b);
            maxHeap.push(temp) ;
        }

        if(c > 0){
            node * temp = new node ('c' , c);
            maxHeap.push(temp) ;
        }

        string ans = "";

        while(maxHeap.size() > 1){
            node * first = maxHeap.top();
            maxHeap.pop() ;
            node * second = maxHeap.top();
            maxHeap.pop();

            if(first->count >= 2){
                ans += first->data ;
                ans += first->data ;

                first->count -= 2 ;
            }
            else{ // count 1 hai 
                ans += first->data ;
                first->count -= 1 ;
            }
            
            if(second->count >= 2 && second->count >= first->count){
                ans += second->data ;
                ans += second->data ;

                second->count -= 2 ;
            }
            else{ // count 1 hai 
                ans += second->data ;
                second->count -= 1 ;
            }

            // push back in heap
            if(first->count > 0 ){
                maxHeap.push(first) ;
            }
            if(second->count > 0 ){
                maxHeap.push(second) ;
            }
        }

        if(maxHeap.size() == 1){
            node * temp = maxHeap.top();
            maxHeap.pop() ;
            if(temp->count >= 2){
                ans += temp->data ;
                ans += temp->data ;

                temp->count -= 2 ;
            }
            else{ // count 1 hai 
                ans += temp->data ;
                temp->count -= 1 ;
            }
        }
        

        return ans ;
    }
};