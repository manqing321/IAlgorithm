#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    int longestCycle(vector<int>& edges) {
        auto used = set<int>();
        auto cicle_lst = vector<set<int>>();
        for (int i = 0; i < edges.size(); i++) {
            // if the idx was used, skip it
            if (used.find(i) != used.end()) {
                continue;
            }
            // i as start, look forward a circle
            auto beg = i;
            auto next = edges[i];
            auto mp = map<int, int>{ make_pair(i, 0) };
            auto lst = vector<int>{ beg };
            cout <<"beg: " << beg <<endl;
            while(next != -1) {
                auto iter = mp.find(next);
                // find circle
                if(iter != mp.end()) {
                    // find start idx
                    auto start_idx = iter -> second;
                    used.insert(beg);
                    lst.push_back(beg);
                    // remove lst pre part, build a st insert into circle lst
                    cout <<"find circle:";
                    for_each(lst.begin() + start_idx, lst.end(), [&](const int& num){ cout << num << "->" << edges[num] <<" ";});
                    auto st = set<int>(lst.begin() + start_idx, lst.end());
                    cout << endl;
                    cicle_lst.push_back(st);
                    break;
                }
                if(used.find(beg) != used.end()) {
                    break;
                }
                mp.insert(make_pair(beg, lst.size()));
                used.insert(beg);
                lst.push_back(beg);
                beg = next;
                next = edges[beg];
                cout <<"next: " << beg <<endl;                
            }
        }
        int ans = -1;
        for (auto st : cicle_lst)
        {
            ans = max((int)st.size(), ans);
        }
        return ans;
    }
};

int main() {
    // auto args = vector<int>{3, 3, 4, 2, 3};
    auto args = vector<int>{2, -1, 3, 1};
    //
    auto sol = Solution();
    auto ans = sol.longestCycle(args);
    cout << ans << endl;
}