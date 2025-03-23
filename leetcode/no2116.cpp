#include <iostream>
#include <string>
#include <map>
#include <deque>
#include <queue>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int diff = 0;
        auto que = queue<int>();
        for (size_t i = 0; i < s.length(); i++)
        {
            char ch = s[i];
            if(ch == ')'){
                if(locked[i] == '0'){
                    que.push(i);
                }
                if(diff == 0){
                    if(que.size() == 0){
                        return false;
                    }else{
                        auto idx = que.front();
                        que.pop();
                        s[idx] = '(';
                        diff += 1;
                    }
                }else{
                    diff -= 1;
                }
            }else{
                diff += 1;
            }
        } 

        diff = 0;
        que = queue<int>();
        for (int i = s.length() - 1; i >= 0; i--)
        {
            char ch = s[i];
            if(ch == '('){
                if(locked[i] == '0'){
                    que.push(i);
                }
                if(diff == 0){
                    if(que.size() == 0){
                        return false;
                    }else{
                        auto idx = que.front();
                        que.pop();
                        s[idx] = ')';
                        diff += 1;
                    }
                }else{
                    diff -= 1;
                }
            }else{
                diff += 1;
            }
        }
        
        return !diff;
    }
};

int main()
{
    string s = "))()))";
    string locked = "010100";
    auto sol = Solution();
    auto ans = sol.canBeValid(s, locked);
    cout << ans << endl;
}