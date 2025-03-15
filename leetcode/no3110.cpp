#include <iostream>
#include <string>
using namespace std;
class Solution {
public:
    int scoreOfString(string s) 
    {
        int ans = 0, pre = 0, num = 0, diff = 0;
        for(auto beg = s.begin(); beg != s.end(); beg++)
        {
            num = *beg;
            if(beg != s.begin())
            {
                diff = num - pre;
                if(diff > 0)
                {
                    ans += diff;
                }
                else
                {
                    ans -= diff;
                }
            }
            pre = num;
        }
        return ans;
    }
};

int main()
{
    auto sol = Solution();
    string s = "hello";
    auto ans = sol.scoreOfString(s);
    cout << ans << endl;
}