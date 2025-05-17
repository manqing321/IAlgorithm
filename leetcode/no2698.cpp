#include <vector>
#include <string>
#include <iostream>
using namespace std;

class Solution {
public:
    bool dfs(const string& s, vector<int>& selected, int idx, int target) {
        if (idx == s.size() - 1) {
            selected.push_back(idx);
            int start = 0;
            int sum = 0;
            for (int stop : selected)
            {
                auto inner_str = s.substr(start, stop + 1 - start);
                start = stop + 1;
                sum += stoi(inner_str);
            }
            selected.pop_back();
            if (sum == target){
                return true;
            }
            return false;
        }

        // not take
        bool not_take = dfs(s, selected, idx + 1, target);
        if (not_take) {
            return true;
        }
        // take it
        selected.push_back(idx);
        bool take = dfs(s, selected, idx + 1, target);
        selected.pop_back();
        return take;

    }
    bool verify(const string& s, int num) {
        auto selected = vector<int>();
        return dfs(s, selected, 0, num);
    }
    int punishmentNumber(int n) {
        int ans = 0;
        int squr = 0;
        int idx = 0;
        while (idx < n) {
            squr = squr + (idx << 1) + 1;
            idx += 1;
            string st = to_string(squr);
            
            if (verify(st, idx)) {
                // cout << idx << ", " << squr << "\n";
                ans += squr;
            }
        }
        return ans;
    }
};

void test01() {
    int n = 10;
    int expect = 182;
    int actual = Solution().punishmentNumber(n);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << "\n";
}
void test02() {
    int n = 37;
    int expect = 1478;
    int actual = Solution().punishmentNumber(n);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << "\n";
}

int main() {
    test02();
}