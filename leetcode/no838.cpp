#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using std::string;
using std::vector;
using std::cout;
using std::for_each;
class Solution {
public:
    string pushDominoes(string dominoes) {
        // Boundary condition
        // n == dominoes.length
        // 1 <= n <= 10^5
        // dominoes[i] 为 'L'、'R' 或 '.'

        // step 1: get pre R cnt vector and rear L cnt vector
        auto pre_r_cnt_vec = vector<int>(dominoes.size(), INT32_MAX);
        auto rear_l_cnt_vec = vector<int>(dominoes.size(), INT32_MAX);
        int pre_r_cnt = 0;
        int rear_l_cnt = 0;
        for (size_t i = 0; i < dominoes.size(); i++)
        {
            char c = dominoes[i];
            if (c == 'R') {
                pre_r_cnt = 1;
                continue;
            }
            if (c == 'L') {
                pre_r_cnt = 0;
                continue;
            }
            if (pre_r_cnt) {
                pre_r_cnt_vec[i] = pre_r_cnt;
                pre_r_cnt += 1;
            }
        }
        for(int i = dominoes.size() - 1; i >= 0; i--){
            char c = dominoes[i];
            if (c == 'R') {
                rear_l_cnt = 0;
                continue;
            }
            if (c == 'L') {
                rear_l_cnt = 1;
                continue;
            }
            if (rear_l_cnt) {
                rear_l_cnt_vec[i] = rear_l_cnt;
                rear_l_cnt += 1;
            }
        } 

        // step 2: caculate every point by compare left R cnt and right L cnt
        for (size_t i = 0; i < dominoes.size(); i++)
        {
            if (dominoes[i] == '.') {
                // cout << i << " ";
                if(pre_r_cnt_vec[i] == rear_l_cnt_vec[i]){
                    continue;
                }else if (pre_r_cnt_vec[i] > rear_l_cnt_vec[i]) {
                    dominoes[i] = 'L';
                } else {
                    dominoes[i] = 'R';
                }
            }
        }
        // T(n) = O(n), S(n) = O(n)
        return dominoes;
    }
};

void test01() {
    auto dominoes = "RR.L";
    auto expect = "RR.L";
    auto actual = Solution().pushDominoes(dominoes);
    cout << __func__ << " ecxpect: " << expect <<", actual: " << actual << "\n";
}
void test02() {
    auto dominoes = ".L.R...LR..L..";
    auto expect = "LL.RR.LLRRLL..";
    auto actual = Solution().pushDominoes(dominoes);
    cout << __func__ << " ecxpect: " << expect <<", actual: " << actual << "\n";
}
int main() {
    test01();
    test02();
}