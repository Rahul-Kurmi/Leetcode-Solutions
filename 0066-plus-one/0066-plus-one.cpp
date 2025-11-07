class Solution {
public:
    vector<int> plusOne(vector<int>& arr) {
        int j = arr.size() - 1;
        int carry = 1; // start with +1

        while (j >= 0) {
            int data = arr[j] + carry;
            arr[j] = data % 10;   // new digit after addition
            carry = data / 10;    // update carry
            j--;
        }

        if (carry > 0) {
            arr.insert(arr.begin(), carry);
        }

        return arr;
    }
};
