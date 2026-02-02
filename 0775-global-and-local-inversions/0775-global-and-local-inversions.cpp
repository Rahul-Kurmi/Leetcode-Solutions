class Solution {
    void merge(vector<int>& arr, vector<int>& temp, int start, int mid, int end, long& globalInversions) {
        int i = start, j = mid + 1, k = start;

        // Merging the two halves and counting global inversions
        while (i <= mid && j <= end) {
            if (arr[i] <= arr[j]) {
                temp[k++] = arr[i++];
            } else {
                temp[k++] = arr[j++];
                globalInversions += (mid - i + 1); // Count the inversions
            }
        }

        // Copy remaining elements of left half, if any
        while (i <= mid) {
            temp[k++] = arr[i++];
        }

        // Copy remaining elements of right half, if any
        while (j <= end) {
            temp[k++] = arr[j++];
        }

        // Copy sorted elements back to original array
        for (int i = start; i <= end; i++) {
            arr[i] = temp[i];
        }
    }

    void mergeSort(vector<int>& arr, vector<int>& temp, int start, int end, long& globalInversions) {
        if (start < end) {
            int mid = start + (end - start) / 2;

            // Count inversions in left half
            mergeSort(arr, temp, start, mid, globalInversions);

            // Count inversions in right half
            mergeSort(arr, temp, mid + 1, end, globalInversions);

            // Count split inversions
            merge(arr, temp, start, mid, end, globalInversions);
        }
    }

public:
    bool isIdealPermutation(vector<int>& arr) {
        long globalInversions = 0;
        long localInversions = 0;

        // Count local inversions FIRST (before modifying nums)
        for (int i = 0; i < arr.size() - 1; ++i) {
            if (arr[i] > arr[i + 1]) {
                localInversions++;
            }
        }

        // Now count global inversions (this will modify nums)
        // Count global inversions using merge sort
        vector<int> temp(arr.size(), 0);
        mergeSort(arr, temp, 0, arr.size() - 1, globalInversions);

        return globalInversions == localInversions;
    }
};