//T.C : O(1) for both methods
//S.C : O(n) for the stream
class ProductOfNumbers {
public:
    vector<int> nums; //cumulative prod store karenge
    int n;

    ProductOfNumbers() {
        nums.clear();
        n = 0;
    }
    
    void add(int num) {
        if(num == 0) {
            nums = {}; // make it empty 
            n = 0;
        } else {
            if(nums.empty()) {
                nums.push_back(num);
            } else {
                nums.push_back(nums[n-1] * num);
            }
            n++; //increasing size by 1
        }
    }
    
    int getProduct(int k) {
        if(k > n) {
            return 0;
        } else if(k == n) {
            return nums[n-1];
        }

        return nums[n-1] / nums[n-k-1];
    }
};
