#include <iostream>
#include <vector>
using std::cout;
using std::vector;

class Solution {
public:
    int numTilings(int n) {
        if (n == 1) {
            return 1;
        }
        auto vec = vector<long long>(n + 1, 0);
        vec[0] = 1;
        vec[1] = 1;
        vec[2] = 2;
        long long ans = 0;
        long long pre_sum = vec[0];
        long long limit = 1000000007;
        for (size_t i = 3; i <= n; i++)
        {
            vec[i] = vec[i - 1] + vec[i - 2] + 2 * pre_sum;
            pre_sum += vec[i - 2];
            while (pre_sum > limit) {
                pre_sum %= limit;
            }
            while (vec[i] > limit) {
                vec[i] %= limit;
            }
        }
        return vec[n];
    }
};

void test01() {
    int n = 3;
    int expect = 5;
    int actual = Solution().numTilings(n);
    cout << __func__ <<" expect: " << expect << ", actual: " << actual << "\n";
}
void test02() {
    int n = 1;
    int expect = 1;
    int actual = Solution().numTilings(n);
    cout << __func__ <<" expect: " << expect << ", actual: " << actual << "\n";
}
void test03() {
    int n = 6;
    int expect = 53;
    int actual = Solution().numTilings(n);
    cout << __func__ <<" expect: " << expect << ", actual: " << actual << "\n";
}
void test04() {
    int n = 4;
    int expect = 11;
    int actual = Solution().numTilings(n);
    cout << __func__ <<" expect: " << expect << ", actual: " << actual << "\n";
}
int main() {
    test01();
    test02();
    test03();
    test04();
}