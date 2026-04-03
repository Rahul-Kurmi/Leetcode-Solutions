class Solution {
public:
    ListNode* midAndPrev(ListNode* head){
        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = nullptr;

        while(fast && fast->next){
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // break left half
        if(prev) prev->next = nullptr;

        return slow; // mid
    }

    TreeNode* solve(ListNode* head){
        if(!head) return nullptr;

        // ✅ handle single node early
        if(head->next == nullptr){
            return new TreeNode(head->val);
        }

        ListNode* mid = midAndPrev(head);

        TreeNode* root = new TreeNode(mid->val);

        root->left = solve(head);
        root->right = solve(mid->next);

        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        return solve(head);
    }
};