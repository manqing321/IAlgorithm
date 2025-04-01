#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        auto vec = vector<long long>(questions.size() + 1, 0);
        for (int i = questions.size() - 1; i >= 0; i--) {
            long long unselect = vec[i + 1];
            long long select = questions[i][0];
            auto cost = questions[i][1];
            if (i + cost + 1 < vec.size()) {
                select += vec[i + cost + 1];
            }
            vec[i] = max(unselect, select);
        }
        return vec[0];
    }
};
int main() {
    auto questions = vector<vector<int>>{{1, 1}, {2, 2}, {3, 3}, {4, 4}, {5, 5}};
    auto ans = Solution().mostPoints(questions);
    cout << ans << endl;

}