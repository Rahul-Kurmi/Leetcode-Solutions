class Solution {
public:
    int kthGrammar(int n, int k) {
        // Base case: Row 1 always has "0"
        if(n == 1 && k == 1){
            return 0;
        }
        
        // Calculate total length of current row (n)
        // Row n has 2^(n-1) elements
        int length = pow(2, n-1);
        
        // Find the middle point of current row
        int mid = length / 2;
        
        // If k is in the first half
        // First half is same as previous row
        if(k <= mid){
            return kthGrammar(n-1, k);
        }
        // If k is in the second half
        // Second half is complement (flip) of previous row
        else{
            // Map k to its corresponding position in previous row
            // and flip the result (0→1, 1→0)
            return !kthGrammar(n-1, k - mid);
        }
    }
};