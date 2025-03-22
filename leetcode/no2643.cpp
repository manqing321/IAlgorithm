#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
    public:
        vector<int> rowAndMaximumOnes(vector<vector<int>>& mat) {
            auto ans = vector<int>(2, 0);
            for (size_t row = 0; row < mat.size(); row++)
            {
                int sum = accumulate(mat[row].begin(), mat[row].end(), 0, [](int sed, int num){ return sed + num; });
                if(sum > ans[1])
                {
                    ans[0] = row;
                    ans[1] = sum;
                }
            }
            return ans;
        }
    };
int main()
{
    vector<vector<int>> mat = {{0,0,0},{0,1,1}};
    auto sol = Solution();
    auto ans = sol.rowAndMaximumOnes(mat);
    for_each(ans.begin(), ans.end(), [](int x){cout << x << " ";});
    cout << endl;
}