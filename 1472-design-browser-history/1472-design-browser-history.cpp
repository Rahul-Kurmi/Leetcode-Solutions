class Node{
    public :
        string data = "";
        Node * next ;
        Node * prev ;
        Node(string data){
            this -> data = data ;
            next = nullptr ;
            prev = nullptr ;
        }
};

class BrowserHistory {
public:
    Node * home = nullptr ;
    Node * curr = nullptr ;
    BrowserHistory(string homepage) {
        home = new Node(homepage);
        curr = home ; 
    }
    
    void visit(string url) {
        Node * newPage = new Node(url);
        
        // Delete the forward history that is not used
        // Can do this also but better to delete
        // curr -> next = nullptr ;
        Node * temp = curr -> next ;
        while(temp){
            Node * nextNode  = temp -> next ;
            delete temp ;
            temp = nextNode ;
        }

        curr -> next = newPage ;
        newPage -> prev = curr ;
        curr = newPage ;
    }
    
    string back(int steps) {
        while(curr -> prev  != nullptr && steps--){
            curr = curr -> prev ;
        }
        return curr -> data;
    }
    
    string forward(int steps) {
        while(curr -> next != nullptr && steps--){
            curr = curr -> next ;
        }
        return curr -> data ;
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */