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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    ListNode* findMid(ListNode* start , ListNode* end){
        ListNode* slow = start ;
        ListNode* fast = start ;
        while(fast != end && fast -> next != end){
            slow = slow -> next ;
            fast = fast -> next -> next ;
        }
        return slow ;
    }

    TreeNode* createBST(ListNode* head , ListNode* tail){
        if(head == tail) return nullptr ;

        ListNode* mid = findMid(head , tail) ;

        TreeNode* root = new TreeNode(mid -> val);

        root -> left = createBST(head , mid) ; // here findMid chhecks fast != mid
        root -> right = createBST(mid -> next , tail) ; // same thing tail always nullptr

        return root ;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return createBST(head , nullptr);
    }
};