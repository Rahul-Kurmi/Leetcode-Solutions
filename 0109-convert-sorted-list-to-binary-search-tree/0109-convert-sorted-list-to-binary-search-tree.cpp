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
    pair<ListNode* , ListNode*> midAndPrev(ListNode* head){
        ListNode* slow = head ;
        ListNode* fast = head ;
        ListNode* prev = nullptr ;
        while(fast && fast -> next){
            prev = slow ;
            slow = slow -> next ;
            fast = fast -> next -> next ;
        }
        return {slow , prev} ;
    }

    TreeNode* solve(ListNode* head){
        if(!head) return nullptr ;

        auto temp = midAndPrev(head);
        ListNode* mid = temp.first ;
        ListNode* prev = temp.second ;

        TreeNode* root = new TreeNode(mid -> val) ;

        // means only one element
        if(!prev) return root ;

        prev -> next = nullptr ;

        root -> left =  solve(head) ;
        root -> right = solve(mid -> next);

        return root ;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head);
    }
};