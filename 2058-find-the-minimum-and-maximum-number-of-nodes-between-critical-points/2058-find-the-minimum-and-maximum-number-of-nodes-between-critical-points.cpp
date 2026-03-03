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
        vector<int> ans = {-1 , -1};

        ListNode* prev = head ;
        if(!prev) return ans ;

        ListNode* curr = head -> next ;
        if(!head) return ans ;

        ListNode* nxt  = head -> next -> next ;
        if(!nxt) return ans ;

        int firstCP = -1 ;
        int lastCP = -1 ;
        int minDist = INT_MAX ;
        int i = 1 ;
        while(nxt){
            bool isCriticalPoint = ((curr -> val < prev -> val && curr -> val < nxt -> val) || 
                                    (curr -> val > prev -> val && curr -> val > nxt -> val)) 
                                        ? true : false ;
            
            // Found first Critical Point
            if(isCriticalPoint && firstCP == -1){
                firstCP = i  ;
                lastCP = i ;
            }
            else if(isCriticalPoint){
                minDist = min(minDist , i - lastCP);
                lastCP = i ;
            }
            ++i;
            prev = prev -> next ;
            curr = curr -> next ;
            nxt = nxt -> next ;
        }

        if(lastCP == firstCP){
            // Only one CP was found
            return ans;
        }else{
            ans[0] = minDist ;
            ans[1] = lastCP - firstCP ;
        }

        return ans;
    }
};