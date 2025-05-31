#include <vector>
#include <iostream>
#include <queue>
#include <set>
using std::vector;
using std::cout;
using std::queue;
using std::set;

class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int rows = board.size(), cols = board[0].size();
        auto roads = vector<int>(rows * cols + 1, -1);
        auto visiteds = vector<bool>(roads.size(), false);
        auto idx = 0, total = rows * cols;
        for (size_t r = 0; r < rows; r++) {
            for (size_t c = 0; c < cols; c++) {
                if ((rows - r) & 1) {
                    idx = (r + 1) * cols - c;
                } else {
                    idx = r * cols + c + 1;
                }
                idx = total - idx + 1;
                cout << idx  << ",("<< board[r][c] << ") ";
                roads[idx] = board[r][c];
            }
            cout << "\n";
        }
        auto step = 1;
        auto que = queue<int>();
        que.push(1);
        while(que.size()) {
            auto len = que.size();
            while (len > 0) {
                len -= 1;
                auto node = que.front();
                que.pop();
                for (size_t i = 1; i <= 6; i++) {
                    if (node + i > total) {
                        break;
                    }
                    auto next = node + i;
                    if (roads[next] > 0){
                        next = roads[next];
                    }
                    if (visiteds[next]) {
                        continue;
                    }
                    if (next == total) {
                        return step;
                    }
                    que.push(next);
                    visiteds[next] = true;
                }
            }
            step += 1;
        }
        return -1;
    }
};

void test01() {
    auto board = vector<vector<int>>{{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1,-1},{-1,35,-1,-1,13,-1},{-1,-1,-1,-1,-1,-1},{-1,15,-1,-1,-1,-1}};
    auto expect = 4;
    auto actual = Solution().snakesAndLadders(board);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << "\n";
}
void test02() {
    auto board = vector<vector<int>>{{-1,7,-1},{-1,6,9},{-1,-1,2}};
    auto expect = 1;
    auto actual = Solution().snakesAndLadders(board);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << "\n";
}

void test03() {
    auto board = vector<vector<int>> {{1,1,-1},{1,1,1},{-1,1,1}};
    auto expect = -1;
    auto actual = Solution().snakesAndLadders(board);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << "\n";
}

void test04() {
    auto board = vector<vector<int>> {{-1,1,2,-1},{2,13,15,-1},{-1,10,-1,-1},{-1,6,2,8}};
    auto expect = 2;
    auto actual = Solution().snakesAndLadders(board);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << "\n";
}

void test05() {
    auto board = vector<vector<int>> {{-1,-1,-1,46,47,-1,-1,-1},{51,-1,-1,63,-1,31,21,-1},{-1,-1,26,-1,-1,38,-1,-1},{-1,-1,11,-1,14,23,56,57},{11,-1,-1,-1,49,36,-1,48},{-1,-1,-1,33,56,-1,57,21},{-1,-1,-1,-1,-1,-1,2,-1},{-1,-1,-1,8,3,-1,6,56}};
    auto expect = 4;
    auto actual = Solution().snakesAndLadders(board);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << "\n";
}
int main() {
    test01();
    test02();
    test03();
    test04();
    test05();
}