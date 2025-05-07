#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using std::vector;
using std::cout;
using std::queue;
using std::max;
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        auto matrix = vector<vector<int>>(moveTime.size(), vector<int>(moveTime[0].size(), INT32_MAX));
        auto r_que = queue<int>();
        auto c_que = queue<int>();
        auto t_que = queue<int>();
        matrix[0][0] = 0;
        r_que.push(0);
        c_que.push(0);
        t_que.push(0);
        while(r_que.size()) {
            auto r = r_que.front();
            auto c = c_que.front();
            auto t = t_que.front();
            r_que.pop();
            c_que.pop();
            t_que.pop();

            // up
            if (r) {
                auto limit = moveTime[r - 1][c]; 
                auto t_up = max(limit + 1, t + 1);
                if (t_up < matrix[r - 1][c]) {
                    matrix[r - 1][c] = t_up;
                    r_que.push(r - 1);
                    c_que.push(c);
                    t_que.push(t_up);
                }
            }
            // down
            if (r < moveTime.size() - 1) {
                auto limit = moveTime[r + 1][c]; 
                auto t_down = max(limit + 1, t + 1);
                if (t_down < matrix[r + 1][c]) {
                    matrix[r + 1][c] = t_down;
                    r_que.push(r + 1);
                    c_que.push(c);
                    t_que.push(t_down);
                }
            }
            // left
            if (c) {
                auto limit = moveTime[r][c - 1]; 
                auto t_left = max(limit + 1, t + 1);
                if (t_left < matrix[r][c - 1]) {
                    matrix[r][c - 1] = t_left;
                    r_que.push(r);
                    c_que.push(c - 1);
                    t_que.push(t_left);
                }
            }
            // right
            if (c < moveTime[0].size() - 1) {
                auto limit = moveTime[r][c + 1]; 
                auto t_right = max(limit + 1, t + 1);
                if (t_right < matrix[r][c + 1]) {
                    matrix[r][c + 1] = t_right;
                    r_que.push(r);
                    c_que.push(c + 1);
                    t_que.push(t_right);
                }
            }
        }
        return matrix.back().back();
    }
};

void test01() {
    auto moveTime = vector<vector<int>>{ 
        vector<int>{0, 4},
        vector<int>{4, 4}
    };
    auto expect = 6;
    auto actual = Solution().minTimeToReach(moveTime);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << "\n";
}
void test02() {
    auto moveTime = vector<vector<int>>{ 
        vector<int>{0, 0, 0},
        vector<int>{0, 0, 0}
    };
    auto expect = 3;
    auto actual = Solution().minTimeToReach(moveTime);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << "\n";
}
void test03() {
    auto moveTime = vector<vector<int>>{ 
        vector<int>{0,1},
        vector<int>{1,2}
    };
    auto expect = 3;
    auto actual = Solution().minTimeToReach(moveTime);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << "\n";
}

int main() {
    test01();
    test02();
    test03();
}