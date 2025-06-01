#include <vector>
#include <iostream>
using std::vector;
using std::cout;

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        size_t r = 0, c = 0;
        for (; r < grid.size(); r++) {
            for (c = 0; c < grid[0].size(); c++) {
                if (r == 0 && c == 0) {
                    continue;
                } else if (r == 0) {
                    grid[r][c] += grid[r][c - 1];
                } else if (c == 0) {
                    grid[r][c] += grid[r - 1][c];
                } else {
                    grid[r][c] += grid[r][c - 1] < grid[r - 1][c] ? grid[r][c - 1] : grid[r - 1][c];
                }
            }
        }
        return grid[r - 1][c - 1];
    }
};

void test01() {
    auto grid = vector<vector<int>>{{1,3,1},{1,5,1},{4,2,1}};
    auto expect = 7;
    auto actual = Solution().minPathSum(grid);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << "\n";
}

int main() {
    test01();
}