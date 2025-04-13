#include <iostream>
#include <set>
using namespace std;

class Solution {
public:
    long long fast_power(long long base, long long n, long long power_cnt, long long limit){
        long long ans = 1;        
        while (power_cnt)
        {
            if (power_cnt & 1) {
                power_cnt--;
                ans *= n;
            }
            if (power_cnt) {
                n *= n;
                n %= limit;
                ans %= limit;
                power_cnt >>= 1;
            }
        }
        ans *= base;
        ans %= limit;
        return ans;
    }
    int countGoodNumbers(long long n) {
        auto odd_cnt = n >> 1;
        long long res = 1;
        long long limit = 1000000007;
        res = fast_power(res, 20, odd_cnt, limit);
        if(n & 1) {
            res *= 5;
            while(res > limit) {
                res -= limit;
            }
        }
        return res;
    }
};
void test01() {
    long long n = 1;
    auto expect = 5;
    auto actual = Solution().countGoodNumbers(n);
    cout << __func__ << ": "<< (actual == expect) << endl;
}
void test02() {
    long long n = 4;
    auto expect = 400;
    auto actual = Solution().countGoodNumbers(n);
    cout << __func__ << ": "<< (actual == expect) << endl;
}
void test03() {
    long long n = 50;
    auto expect = 564908303;
    auto actual = Solution().countGoodNumbers(n);
    cout << __func__ << ": "<< (actual == expect) << endl;
}
void test04() {
    long long n = 806166225460393;
    auto expect = 643535977;
    auto actual = Solution().countGoodNumbers(n);
    cout << __func__ << ": "<< (actual == expect) << endl;
}
int main() {
    test01();
    test02();
    test03();
    test04();
}