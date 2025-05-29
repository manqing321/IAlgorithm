#include <iostream>
#include <vector>
using std::cout;
using std::vector;

class Solution {
public:
    int countGoodStrings(int low, int high, int zero, int one) {
        auto limit = 1000000000 + 7;
        auto vec = vector<int>(high + 1, 0);
        for (size_t i = 0; i < vec.size(); i++)
        {
            if (i == zero) {
                vec[i] += 1;
            }
            if (i == one) {
                vec[i] += 1;
            }
            if (i > zero && vec[i - zero]) {
                vec[i] += vec[i - zero];
            }
            if (i > one && vec[i - one]){
                vec[i] += vec[i - one];
            }
            if (vec[i] >= limit) {
                vec[i] %= limit;
            }
        }
        for (size_t i = 0; i < vec.size(); i++) {
            cout << vec[i] << ", ";
        }
        cout << "\n";        
        int ans = 0;
        for (int i = low; i <= high; i++) {
            ans += vec[i];
            if (ans >= limit) {
                ans %= limit;
            }
        }
        return ans;
    }
};

void test01() {
    int low = 3;
    int high = 3;
    int zero = 1;
    int one = 1;
    int except = 8;
    int actual = Solution().countGoodStrings(low, high, zero, one);
    cout << __func__ << " expect: " << except << ", actual: " << actual << "\n";
}

void test02() {
    int low = 2;
    int high = 3;
    int zero = 1;
    int one = 2;
    int except = 5;
    int actual = Solution().countGoodStrings(low, high, zero, one);
    cout << __func__ << " expect: " << except << ", actual: " << actual << "\n";
}

int main() {
    test01();
    test02();
}