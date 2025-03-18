#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
    public:
        bool is_prime(int num)
        {
            for(int i = 2; i * i <= num; i += 1)
            {
                if (num % i == 0)
                {
                    return false;
                }
            }
            return num > 1;
        }

        int diagonalPrime(vector<vector<int>>& nums) {
            int ans = 0;
            auto st = set<int>();
            for (int r = 0; r < nums.size(); r += 1)
            {
                int col1 = r;
                int col2 = nums[r].size() - 1 - r;
                int num1 = nums[r][col1];
                int num2 = nums[r][col2];
                st.insert(num1);
                st.insert(num2);
            }
            for (auto beg = st.begin(); beg != st.end(); beg++)
            {
                int num = *beg;
                if(num > ans && is_prime(num))
                {
                    ans = num;
                }
            }
            return ans;
        }
    };

    int main()
    {
        vector<vector<int>> vec = {{1,2,3},{5,6,7},{9,10,11}};
        auto sol = Solution();
        auto ans = sol.diagonalPrime(vec);
        cout << ans << endl;
    }