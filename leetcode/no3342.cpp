#include <vector>
#include <iostream>
#include <queue>
#include <map>
#include <tuple>
#include <algorithm>
using std::vector;
using std::cout;
using std::queue;
using std::pair;
using std::tuple;
using std::get;
using std::max;
using std::for_each;
using std::multimap;
using std::make_pair;
class Solution {
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        auto matrix = vector<vector<int>>(moveTime.size(), vector<int>(moveTime[0].size(), INT32_MAX));
        matrix[0][0] = 0;
        auto mmp = multimap<int, pair<int, int>>();
        mmp.insert(make_pair(0, make_pair(0, 0)));
        auto methods = vector<pair<int, int>>{ { -1, 0 }, { 1, 0 }, { 0, -1 },  { 0, 1 } };
        while (mmp.size()) {
            auto beg = mmp.begin();
            int t = beg->first, r = beg->second.first, c = beg->second.second;
            if (r == moveTime.size() && c == moveTime[0].size()) {
                break;
            }
            mmp.erase(beg);
            int cost = 1 + ((r + c) & 1);
            for(const pair<int, int>& p : methods){
                int next_r = r + p.first;
                int next_c = c + p.second;
                if ( next_r >= 0 && next_r < moveTime.size()
                        && next_c >= 0 && next_c < moveTime[0].size()) { 
                    int next_time = max(t, moveTime[next_r][next_c]) + cost;
                    if (next_time < matrix[next_r][next_c]) {
                        matrix[next_r][next_c] = next_time;
                        mmp.insert(make_pair(next_time, make_pair(next_r, next_c)));
                    }
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
    auto expect = 7;
    auto actual = Solution().minTimeToReach(moveTime);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << "\n";
}
void test02() {
    auto moveTime = vector<vector<int>>{ 
        vector<int>{0, 0, 0, 0},
        vector<int>{0, 0, 0, 0}
    };
    auto expect = 6;
    auto actual = Solution().minTimeToReach(moveTime);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << "\n";
}
int main() {
    test01();
    test02();
}