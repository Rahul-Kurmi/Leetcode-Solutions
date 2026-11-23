
class ProductOfNumbers {
public:
    vector<long long> prefixProduct;

    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0) {
            prefixProduct.clear();
        }
        else {
            if(prefixProduct.empty()) {
                prefixProduct.push_back(num);
            }
            else {
                long long last = prefixProduct.back();
                prefixProduct.push_back(last * num);
            }
        }
    }
    
    int getProduct(int k) {
        if(k > prefixProduct.size()) return 0;

        int n = prefixProduct.size();

        if(k == n) return prefixProduct[n-1];

        return prefixProduct[n-1] / prefixProduct[n-k-1];
    }
};