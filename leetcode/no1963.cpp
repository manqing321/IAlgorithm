#include<string>
using namespace std;

class Solution
{
public:
    int minSwaps(string s)
    {
        int diff = 0;
        for (size_t i = 0; i < s.size(); i++)
        {
            if (s[i] == '[')
            {
                diff += 1;
            }
            else
            {
                if (diff > 0)
                {
                    diff -= 1;
                }
            }
        }
        return (diff + 1) / 2;
    }
};