class Solution {
public:
    int digitSum(int n) {
        return
            (n / 10000) +           // ten-thousands digit
            (n % 10000 / 1000) +    // thousands digit
            (n % 1000 / 100) +      // hundreds digit
            (n % 100 / 10) +        // tens digit
            (n % 10);               // units digit
    }

    int minElement(vector<int>& nums) {
        int result = 37; //Note that 1 <= nums[i] <= 10^4 and biggest sum can be obtained by 9999 (whose digit sum = 36)

        for(int num : nums) {
            int s = digitSum(num); //O(1)

            result = min(result, s);
        }

        return result;
    }
};

/* 

int digitSum(int n) {

    // Example: n = 5678

    return
        (n / 10000) +           
        // 5678 / 10000 = 0
        // Extracts ten-thousands digit

        (n % 10000 / 1000) +    
        // 5678 % 10000 = 5678
        // 5678 / 1000 = 5
        // Extracts thousands digit

        (n % 1000 / 100) +      
        // 5678 % 1000 = 678
        // 678 / 100 = 6
        // Extracts hundreds digit

        (n % 100 / 10) +        
        // 5678 % 100 = 78
        // 78 / 10 = 7
        // Extracts tens digit

        (n % 10);               
        // 5678 % 10 = 8
        // Extracts units digit
}

*/