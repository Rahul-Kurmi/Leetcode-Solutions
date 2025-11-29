class Solution {
public:
    int findPeakElement(vector<int>& arr) {
        int start = 0;
        int end = arr.size() - 1;

        while (start < end) {
            int mid = start + (end - start) / 2;

            // Handle boundaries safely
            int left  = (mid == 0) ? INT_MIN : arr[mid - 1];
            int right = (mid == arr.size() - 1) ? INT_MIN : arr[mid + 1];

            // Peak condition
            if (arr[mid] > left && arr[mid] > right) {
                return mid;
            }
            // Move right
            else if (arr[mid] < right) {
                start = mid + 1;
            }
            else {
                end = mid - 1;
            }
        }

        return start; // start == end → peak
    }
};
