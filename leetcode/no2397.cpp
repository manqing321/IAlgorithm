#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
class Solution {
public:
    size_t res;
    void dfs(const vector<vector<int>>& matrix, vector<size_t>& selected, size_t idx, size_t remainder_cnt) {
        if (idx == matrix[0].size()){
            size_t t = count_if(matrix.begin(), matrix.end(), 
            [&](const vector<int>& vec){
                for (size_t i = 0; i < vec.size(); i++)
                {
                    if (vec[i] && find(selected.begin(), selected.end(), i) == selected.end()){
                        return false;
                    }
                }
                return true;
            });
            res = max(res, t);
            return;
        }
        // not take this
        dfs(matrix, selected, idx + 1, remainder_cnt);

        // take this
        if (remainder_cnt)
        {
            selected.push_back(idx);
            dfs(matrix, selected, idx + 1, remainder_cnt - 1);
            selected.pop_back();
        }
    }
    int maximumRows(vector<vector<int>>& matrix, int numSelect) {
        res = 0;
        auto selected = vector<size_t>();
        dfs(matrix, selected, 0, numSelect);
        return res;
    }
};

void test01(){
    auto matrix = vector<vector<int>>{{0,0,0},{1,0,1},{0,1,1},{0,0,1}};
    int num_select = 2;
    auto except = 3;
    auto actual = Solution().maximumRows(matrix, num_select);
    cout << __func__ << " expect: " << except << ", actual: " << actual << "\n";
}
void test02(){
    auto matrix = vector<vector<int>>{{1},{0}};
    int num_select = 1;
    auto except = 2;
    auto actual = Solution().maximumRows(matrix, num_select);
    cout << __func__ << " expect: " << except << ", actual: " << actual << "\n";
}
int main(){
    test01();
    test02();
}