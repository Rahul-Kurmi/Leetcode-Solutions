//Approach-1 (Simple Maths)
//T.C : O(log(n))
//S.C : O(1)
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        // Sum of first n odd numbers  = n * n
        // Sum of first n even numbers = n * (n + 1)
        return __gcd(n * n, n * (n + 1)); 
    }
};