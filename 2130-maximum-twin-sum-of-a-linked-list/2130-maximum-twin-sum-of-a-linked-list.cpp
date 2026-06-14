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
class Solution {
public:
    int totalNodes(ListNode* head){
        int count = 0 ;
        while(head != nullptr){
            count++;
            head = head -> next ;
        }
        return count ;
    }

    int pairSum(ListNode* head) {
        int size = totalNodes(head);
        unordered_map<int, int> mp ;
        int index = 1 ;
        int maxPairSum = 0 ;
        while(head != nullptr){
            if(mp.find(size - index + 1) != mp.end()){
                int sum = head -> val + mp[size - index + 1];
                maxPairSum = max(maxPairSum , sum);
            }
            else{
                mp[index] = head -> val;
            }
            index++;
            head = head -> next ;
        }
        return maxPairSum;
    }
};