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
    TreeNode* SortedLL_Into_BST(ListNode*& head, int n) {
        if(n <= 0 || !head ) return nullptr ;

        TreeNode* leftSubTree = SortedLL_Into_BST(head , n - n/2 - 1);

        TreeNode* root = new TreeNode(head -> val) ;

        root -> left = leftSubTree ;
        head = head -> next ;

        root -> right = SortedLL_Into_BST(head , n/2);
        return root ; 
    }

    int sizeOfLL(ListNode* head) {
        ListNode* temp = head;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = sizeOfLL(head);
        return SortedLL_Into_BST(head, n);
    }
};