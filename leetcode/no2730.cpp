#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
    public:
        int longestSemiRepetitiveSubstring(string s) {
            int res = 0;
            int cnt = 0;
            for (int left = 0, right = 0; right < s.size(); right += 1)
            {
                if (right && s[right - 1] == s[right]) {
                    cnt += 1;
                }
                while (cnt > 1) {
                    if (s[left] == s[left + 1]) {
                        cnt -= 1;
                    }
                    left += 1;
                }
                res = max(res, right - left + 1);
            }
            return res;
        }
    };