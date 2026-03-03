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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> storeIndex ;
        int index = 2 ;
        ListNode* prev = head ;
        ListNode* curr = head -> next ;
        while(curr -> next != nullptr){
            if(curr -> val < prev -> val && curr -> val < curr -> next -> val){
                storeIndex.push_back(index);
            }
            else if(curr -> val > prev -> val && curr -> val > curr -> next -> val){
                storeIndex.push_back(index);
            }
            curr = curr -> next ;
            prev = prev -> next ;
            index++;
        }

        if(storeIndex.size() < 2) return {-1 , -1} ;
        int minIndex = INT_MAX  ;
        for(int i = 1 ; i < storeIndex.size() ; i++){
            int mini = storeIndex[i] - storeIndex[i-1];
            minIndex = min(mini , minIndex);
        }

        return {minIndex , storeIndex[storeIndex.size() - 1] - storeIndex[0]};
    }
};