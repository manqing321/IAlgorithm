#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<int>> findMatrix(vector<int>& nums) {
            auto ans = vector<vector<int>>();
            auto mp = map<int, int>();
            for (int num : nums)
            {
                if (mp.count(num))
                {
                    mp[num] += 1;
                }
                else
                {
                    mp.insert(make_pair(num, 1));
                }
            }
             
            while (mp.size())
            { 
                auto vec = vector<int>();
                auto beg = mp.begin();
                while (beg != mp.end())
                {
                    vec.push_back(beg->first);
                    beg->second -= 1;
                    if (beg->second > 0)
                    {
                        beg++;
                    }
                    else
                    {
                        beg = mp.erase(beg);
                    }
                }
                ans.push_back(vec);
            }
            return ans;
        }
    };

    int main()
    {
        vector<int> nums = {1,3,4,1,2,3,1}; 
        auto sol = Solution();
        auto ans = sol.findMatrix(nums);
        for_each(ans.begin(), ans.end(), [](vector<int>& vec) {
            for_each(vec.begin(), vec.end(), [](int num){cout << num <<" "; });
            cout << endl;
        });
    }