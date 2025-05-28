#include <vector>
#include <algorithm>
#include <numeric>
#include <initializer_list>
#include <iostream>
using std::vector;
using std::max;
using std::initializer_list;
using std::cout;

class Solution {
public:
    int bfs(int idx, int pre, const vector<vector<int>>& links, int k) {
        if (k == 0) {
            return 1;
        }
        int cnt = 1;
        for (int next : links[idx]) {
            if (next != pre) {
                cnt += bfs(next, idx, links, k - 1);
            }
        }
        return cnt;
    }
    vector<int> get_dps(const vector<vector<int>>& edges, int k){
        // step 1: build link array
        auto links = vector<vector<int>>(edges.size() + 1, vector<int>());
        for (const vector<int>& vec : edges) {
            links[vec[0]].push_back(vec[1]);
            links[vec[1]].push_back(vec[0]);
        }
        // step 2: count every node's link, deepth is k
        auto cnts = vector<int>(edges.size() + 1, 0);
        for (size_t i = 0; i < cnts.size(); i++) {
            cnts[i] = bfs(i, -1, links, k);
        }
        return cnts;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // boundary condition
        auto ans = vector<int>(edges1.size() + 1, 1);
        if (k == 0) {
            return ans;
        }
        auto cnts1 = get_dps(edges1, k);
        auto cnts2 = get_dps(edges2, k - 1);
        auto max_cnt_2 = cnts2[0];
        for (auto iter = cnts2.begin(); iter != cnts2.end(); iter++) {
            max_cnt_2 = max(max_cnt_2, *iter);
        }        
        for (auto iter = cnts1.begin(); iter != cnts1.end(); iter++) {
            *iter += max_cnt_2;
        }
        return cnts1;
    }
};

int main() {
    // auto edges1 = vector<vector<int>>{{0,1},{0,2},{2,3},{2,4}};
    // auto edges2 = vector<vector<int>>{{0,1},{0,2},{0,3},{2,7},{1,4},{4,5},{4,6}};

    auto edges1 = vector<vector<int>>{{0,1},{0,2},{0,3},{0,4}};
    auto edges2 = vector<vector<int>>{{0,1},{1,2},{2,3}};

    auto k = 1;
    auto actual = Solution().maxTargetNodes(edges1, edges2, k);
    for_each(actual.begin(), actual.end(), [](int num){ cout << num <<", "; });
    cout << "\n";
}