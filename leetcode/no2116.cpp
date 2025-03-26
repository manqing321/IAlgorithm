#include <iostream>
#include <string>
#include <map>
#include <deque>
#include <queue>
using namespace std;
class Solution {
    private:
        int ssum(int first_elem, int last_elem, int cnt)
        {
            return (first_elem + last_elem) * cnt / 2;
        }
    public:
        int minimumSum(int n, int k) {            
            if (n <= k / 2){
                return ssum(1, n, n);
            }
            return ssum(1, k / 2, k / 2) + ssum(k, k - 1 + n - k / 2 , n - k / 2);
        }
    
    };

int main()
{
    int n = 4;
    int k = 5;
    auto sol = Solution();
    auto ans = sol.minimumSum(n, k);
    cout << ans << endl;
}