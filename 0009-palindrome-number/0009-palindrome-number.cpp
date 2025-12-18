class Solution {
public:
    bool isPalindrome(int x) {
        // Negative numbers are not palindromes
        if (x < 0) return false;

        int original = x;
        long revNo = 0;  // Use long to handle potential overflow temporarily

        while (x > 0) {
            int rem = x % 10;
            revNo = revNo * 10 + rem;
            x = x / 10;
        }

        // Cast back to int for comparison
        return original == revNo;
    }
};