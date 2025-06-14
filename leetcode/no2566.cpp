#include <vector>
#include <iostream>
using std::vector;
using std::cout;
class Solution {
public:
    int minMaxDifference(int num) {
        auto vec = vector<int>();
        int temp = num;
        while (temp) {
            vec.push_back(temp % 10);
            temp /= 10;
        }
        // 最高位替换为 0
        auto min_replace_num = vec.back();
        // 最高位替换为 9 如果最高位是 9 那么往后找不是 9 的最高位
        auto max_replace_num = 9;
        for (int i = vec.size() - 1; i >= 0; i--) {
            if (vec[i] != 9) {
                max_replace_num = vec[i];
                break;
            }
        }
        auto min_num = 0;
        auto bit = 1;
        for (size_t i = 0; i < vec.size(); i++) {
            if (vec[i] != min_replace_num) {
                min_num += vec[i] * bit;
            }
            bit *= 10;
        }
        cout << "min_num: " <<  min_num << "\n";
        auto max_num = 0;
        if (max_replace_num == 9) {
            max_num = num;
        } else {
            bit = 1;
            for (size_t i = 0; i < vec.size(); i++) {
                if (vec[i] == max_replace_num) {
                    max_num += bit * 9;
                } else {
                    max_num += bit * vec[i];
                }
                bit *= 10;
            }            
        }
        cout << "max_num: " <<  max_num << "\n";
        return max_num - min_num;
    }
};