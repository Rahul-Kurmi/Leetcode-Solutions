class Node {
public:
    int data;
    Node* next;

    Node(int _d) {
        data = _d;
        next = nullptr;
    }
};

class MyHashSet {
public:
    vector<Node*> arr;
    static int m;

    static int hash(int key) {
        return key % m;
    }

    MyHashSet() {
        m = 10007;
        arr.resize(m, nullptr);
    }

    void add(int key) {
        int index = hash(key);

        Node* temp = arr[index];

        // check duplicates
        while (temp != nullptr) {
            if (temp->data == key) return;
            if (temp->next == nullptr) break;
            temp = temp->next;
        }

        Node* newNode = new Node(key);

        if (arr[index] == nullptr) {
            arr[index] = newNode;
        } else {
            temp->next = newNode;
        }
    }

    void remove(int key) {
        int index = hash(key);

        Node* temp = arr[index];
        Node* prev = nullptr;

        while (temp != nullptr) {
            if (temp->data == key) {
                if (prev == nullptr) {
                    arr[index] = temp->next;
                } else {
                    prev->next = temp->next;
                }
                delete temp;
                return; // important
            }
            prev = temp;
            temp = temp->next;
        }
    }

    bool contains(int key) {
        int index = hash(key);

        Node* temp = arr[index];

        while (temp != nullptr) {
            if (temp->data == key) return true;
            temp = temp->next;
        }

        return false;
    }
};

int MyHashSet::m = 0;