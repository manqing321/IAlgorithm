#include <iostream>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int minimizedStringLength(string s) {
        return set<char>(s.begin(), s.end()).size();
    }
};

int main() {
    cout << Solution().minimizedStringLength("dddaaa");
}