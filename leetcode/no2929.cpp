#include <iostream>
using std::cout;
using std::endl;

class Solution {
public:
    long long distributeCandies(int n, int limit) {
        long long ans = 0;
        for (size_t i = 0; i <= limit && i <= n; i++)
        {
            long long left = n - i;
            if (left == 0 || left == 2 * limit) {
                ans += 1;
            } else if (left < 2 * limit) {
                if (left > limit) {
                    ans += 2 * limit - left + 1;
                } else {
                    ans += left + 1;
                }
            }
        }
        return ans;
    }
};

void test01() {
    int n = 5;
    int limit = 2;
    int expect = 3;
    int actual = Solution().distributeCandies(n, limit);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << endl;
}

void test02() {
    int n = 3;
    int limit = 3;
    int expect = 10;
    int actual = Solution().distributeCandies(n, limit);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << endl;
}

int main() {
    test01();
    test02();
}
