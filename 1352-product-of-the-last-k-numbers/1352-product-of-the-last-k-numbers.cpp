
class ProductOfNumbers {
public:
    vector<int> prefixProduct;
    vector<int> zeroIdx;

    ProductOfNumbers() {
        
    }
    
    void add(int num) { // O(1)
        if(num == 0) {
            zeroIdx.push_back(prefixProduct.size());
            prefixProduct.push_back(0);
        }
        else {
            if(prefixProduct.empty()) {
                prefixProduct.push_back(num);
            }
            else {
                int lastProduct = prefixProduct.back();

                if(lastProduct == 0) {
                    prefixProduct.push_back(num);
                }
                else {
                    prefixProduct.push_back(num * lastProduct);
                }
            }
        }
    }
    
    int getProduct(int k) { // O(log n)
        int end = prefixProduct.size() - 1;
        int start = end - k;

        // Check if zero exists in the last k elements
        auto lb = lower_bound(zeroIdx.begin(), zeroIdx.end(), start + 1);

        if(lb != zeroIdx.end()) return 0;

        if(start < 0 || prefixProduct[start] == 0) {
            return prefixProduct[end];
        }

        return prefixProduct[end] / prefixProduct[start];
    }
};