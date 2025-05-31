#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using std::cout;
using std::string;
using std::vector;
using std::for_each;

class Solution {
public:
    int countTexts(string pressedKeys) {
        auto limit = 1000000000 + 7;
        auto vecs = vector<int>(pressedKeys.size(), 0);
        auto four_chars = vector<char>{'7', '9'};
        for (size_t i = 0; i < pressedKeys.size(); i++) {
            if (i == 0) {
                vecs[i] = 1;
                continue;
            }
            // not union
            int pre_idx = i - 1;
            vecs[i] = vecs[pre_idx];
            // union chars
            int max_unions = 2;
            if (pressedKeys[i] == '7' || pressedKeys[i] == '9') {
                max_unions += 1;
            }
            while (max_unions-- && pressedKeys[pre_idx] == pressedKeys[i]) {
                if (pre_idx == 0) {
                    vecs[i] += 1;
                    break;
                } else {
                    vecs[i] += vecs[--pre_idx];
                    vecs[i] %= limit;
                }
            }
        }
        for_each(vecs.begin(), vecs.end(), [](int num){ cout << num << ", "; });
        cout << '\n';
        return vecs.back() % limit;
    }
};

void test01() {
    string pressedKeys = "22233";
    int expect = 8;
    int actual = Solution().countTexts(pressedKeys);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << "\n";
}

int main() {
    test01();
}