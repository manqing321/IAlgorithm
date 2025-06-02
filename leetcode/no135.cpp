#include <vector>
#include <iostream>
#include <algorithm>
#include <numeric>
using std::vector;
using std::cout;
using std::accumulate;

class Solution {
public:
    int candy(vector<int>& ratings) {
        auto candies = vector<int>(ratings.size(), 1);
        for (int i = 0; i < ratings.size() - 1; i++) {
            if (ratings[i + 1] > ratings[i]) {
                candies[i + 1] = candies[i] + 1;
            }
        }
        for (int i = ratings.size() - 1; i > 0; i--) {
            if (ratings[i - 1] > ratings[i] && candies[i - 1] <= candies[i]) {
                candies[i - 1] = candies[i] + 1;
            }
        }
        for (size_t i = 0; i < candies.size(); i++)
        {
            cout << candies[i] << ", ";
        }
        cout << "\n";
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

void test01() {
    auto rating = vector<int>{1, 0, 2};
    auto expect = 5;
    auto actual = Solution().candy(rating);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << "\n";
}
void test02() {
    auto rating = vector<int>{1, 2, 2};
    auto expect = 4;
    auto actual = Solution().candy(rating);
    cout << __func__ << " expect: " << expect << ", actual: " << actual << "\n";
}
int main() {
    test01();
    test02();
}