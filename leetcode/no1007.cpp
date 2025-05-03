#include <vector>
#include <iostream>
#include <algorithm>
using std::vector;
using std::cout;
using std::min;

class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // boundary contidion
        // 2 <= tops.length <= 2 * 104
        // bottoms.length == tops.length
        // 1 <= tops[i], bottoms[i] <= 6

        // step 1: try to switch to top and bottom
        int top = tops[0];
        int bottom = bottoms[0];

        bool is_top_break = false;
        bool is_bottom_break = false;

        int top2top_steps = 0;
        int bottom2top_steps = 0;

        int top2bottom_steps = 0;
        int bottom2bottom_steps = 0;

        for (size_t i = 0; i < tops.size(); i++)
        {
            if (tops[i] != top && bottoms[i] != top) {
                is_top_break = true;
            } else if (!is_top_break && tops[i] != top) {
                top2top_steps += 1;
            } else if (!is_top_break && bottoms[i] != top) {
                bottom2top_steps += 1;
            }
            if (tops[i] != bottom && bottoms[i] != bottom) {
                is_bottom_break = true;
            } else if (!is_bottom_break && tops[i] != bottom) {
                top2bottom_steps += 1;
            } else if (!is_bottom_break && bottoms[i] != bottom) {
                bottom2bottom_steps += 1;
            }
            if (is_top_break && is_bottom_break) {
                break;
            }
        }
        
        // step 2: compare top_steps and bottom_steps, select the minmun one
        if (!is_top_break && !is_bottom_break) {
            cout << top2top_steps <<", " << bottom2top_steps <<", " << top2bottom_steps << ", " << bottom2bottom_steps << "\n";
            return min(min(top2top_steps, bottom2top_steps), min(bottom2top_steps, bottom2bottom_steps));
        }
        if (!is_top_break) {
            return min(top2top_steps, bottom2top_steps);
        }
        if (!is_bottom_break) {
            return min(top2bottom_steps, bottom2bottom_steps);
        }
        return -1;
    }
};

void test01() {
    auto tops = vector<int>{2,1,2,4,2,2};
    auto bottoms = vector<int>{5,2,6,2,3,2};
    auto expect = 2;
    auto actual = Solution().minDominoRotations(tops, bottoms);
    cout << __func__ <<" expect: " << expect <<", actual: " << actual << "\n";
}
void test02() {
    auto tops = vector<int>{3,5,1,2,3};
    auto bottoms = vector<int>{3,6,3,3,4};
    auto expect = -1;
    auto actual = Solution().minDominoRotations(tops, bottoms);
    cout << __func__ <<" expect: " << expect <<", actual: " << actual << "\n";
}

void test03(){
    auto tops = vector<int>{2,1,1,1,2,2,2,1,1,2};
    auto bottoms = vector<int>{1,1,2,1,1,1,1,2,1,1};
    auto expect = 2;
    auto actual = Solution().minDominoRotations(tops, bottoms);
    cout << __func__ <<" expect: " << expect <<", actual: " << actual << "\n";
}

int main() {
    test01();
    test02();
    test03();
}