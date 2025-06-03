#include <vector>
#include <iostream>
#include <set>
using std::vector;
using std::cout;
using std::set;

class Solution {
public:
    void open_box(vector<int>& open_status, 
                vector<int>& box_visiable_status,
                vector<int>& keys_status,
                const vector<vector<int>>& keys,
                const vector<vector<int>>& contained_boxes, 
                int box_idx) {
        auto next_opens = vector<int>();
        // open box
        open_status[box_idx] = 1;
        for (int key : keys[box_idx]) {
            keys_status[key] = 1;
            if (box_visiable_status[key] && !open_status[key]){
                next_opens.push_back(key);
            }
        }
        for (int box : contained_boxes[box_idx]) {
            if (!box_visiable_status[box]) {
                box_visiable_status[box] = 1;
                if (keys_status[box] || open_status[box]) {
                    next_opens.push_back(box);
                }
            }
        }
        for (int next_box : next_opens) {
            open_box(open_status, box_visiable_status, keys_status, keys, contained_boxes, next_box);
        }
    }
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        // init keys vec
        auto box_visiable_status = vector<int>(candies.size(), 0);
        auto keys_status = vector<int>(candies.size(), 0);
        auto ans = 0;
        for (int i : initialBoxes) {
            box_visiable_status[i] = true;
        }
        for (int i : initialBoxes) {
            if (status[i]) {
                open_box(status, box_visiable_status, keys_status, keys, containedBoxes, i);
            }
        }
        for (size_t i = 0; i < candies.size(); i++) {
            if (status[i] && box_visiable_status[i]) {
                ans += candies[i];
            }
        }
        return ans;
    }
};

void test01() {
    auto status = vector<int>{1,0,1,0};
    auto candies = vector<int>{7,5,4,100};
    auto keys = vector<vector<int>>{{},{},{1},{}};
    auto contains = vector<vector<int>>{{1,2},{3},{},{}};
    auto boxes = vector<int>{0};
    auto expect = 16;
    auto actual = Solution().maxCandies(status, candies, keys, contains, boxes);
    cout << __func__ << " expect: " << expect << " actual: " << actual << "\n";
}

void test02() {
    auto status = vector<int>{1,1,1};
    auto candies = vector<int>{100,1,100};
    auto keys = vector<vector<int>>{{},{0, 2},{}};
    auto contains = vector<vector<int>>{{},{},{}};
    auto boxes = vector<int>{1};
    auto expect = 1;
    auto actual = Solution().maxCandies(status, candies, keys, contains, boxes);
    cout << __func__ << " expect: " << expect << " actual: " << actual << "\n";
}

void test03() {
    auto status = vector<int>{1,0,1,0};
    auto candies = vector<int>{7,5,4,100};
    auto keys = vector<vector<int>>{{},{},{},{}};
    auto contains = vector<vector<int>>{{1,2},{3},{},{}};
    auto boxes = vector<int>{1, 2};
    auto expect = 4;
    auto actual = Solution().maxCandies(status, candies, keys, contains, boxes);
    cout << __func__ << " expect: " << expect << " actual: " << actual << "\n";
}
int main() {
    test01();
    test02();
    test03();
}