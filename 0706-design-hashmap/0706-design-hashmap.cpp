class Node{
    public : 
        int key ;
        int value ;
        Node* next ;
        Node(int k , int v){
            this -> key = k;
            this -> value = v;
            this -> next = nullptr;
        }
};

class MyHashMap {
public:
    static int m ; // static int defined at end of MyHashMap class
    vector<Node*> arr;

    static int hash(int key) {
        return key % m;
    }

    MyHashMap() {
        m = 15000;
        arr.resize(m , nullptr);
    }
    
    void put(int key, int value) {
        int index = hash(key);
        Node* newNode = new Node(key , value);
        if(arr[index] == nullptr){
            arr[index] = newNode;
        }
        else{
            Node* temp = arr[index];
            while(temp != nullptr){
                if(temp -> key == key){
                    temp -> value = value ;
                    return ;
                }
                if(temp -> next == nullptr) break ;
                temp = temp -> next ;
            }
            temp -> next = newNode ;
        }
    }
    
    int get(int key) {
        int index = hash(key);
        Node* temp = arr[index];
        while(temp != nullptr){
            if(temp -> key == key){
                return temp -> value ;
            }
            temp = temp -> next ;
        }
        return -1 ;
    }
    
    void remove(int key) {
        int index = hash(key);
        
        Node* temp = arr[index];
        Node* prev = nullptr;

        while(temp != nullptr){
            if(temp -> key == key){
                if(prev == nullptr){
                    arr[index] = temp -> next ;
                }
                else{
                    prev -> next = temp -> next ;
                }
                delete temp ;
                return ;
            }
            prev = temp ;
            temp = temp -> next ;
        }
    }
};

int MyHashMap::m = 0 ;

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */