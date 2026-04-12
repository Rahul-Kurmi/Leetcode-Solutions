/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

class compare{
    public:
    bool operator()(ListNode* a , ListNode* b){
        return a -> val > b -> val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode* , vector<ListNode*> , compare> minHeap ;

        int totalLists = lists.size();

        for(int i = 0 ; i < totalLists ; i++){
            if(lists[i] != nullptr){
                minHeap.push(lists[i]);
            }
        }

        ListNode* head = nullptr ;
        ListNode* tail = nullptr ;
        while(!minHeap.empty()){
            ListNode* temp = minHeap.top();
            minHeap.pop();

            if(head == nullptr){
                head = temp ;
                tail = temp ;
                if(temp -> next){
                    minHeap.push(temp -> next);
                }
            }
            else{
                tail -> next =  temp ;
                tail = temp ;
                if(temp -> next){
                    minHeap.push(temp -> next);
                }
            }
        }
        return head ;
    }
};