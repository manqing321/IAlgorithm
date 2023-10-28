#include <iostream>
#include <vector>
#include <set>
#include <assert.h>
#include <math.h>
using namespace std;
long long pick_gifts(vector<int> &gifts, int k)
{
    multiset<int> st;
    for (auto beg = gifts.begin(); beg != gifts.end(); beg++)
    {
        st.insert(*beg);
    }
    while (k > 0)
    {
        auto last = st.rbegin();
        int sq = sqrt(*last);
        // cout << "pick (" << *last << "), insert (" << sq << ")" << endl;
        last++;
        st.erase(last.base());
        st.insert(sq);
        k--;
    }
    long long res = 0;
    for (auto beg = st.begin(); beg != st.end(); beg++)
    {
        // cout << *beg << ",";
        res += *beg;
    }
    // cout << endl;
    return res;
}

int main()
{
    vector<int> v1{25, 64, 9, 4, 100};
    assert(pick_gifts(v1, 4) == 29);
    vector<int> v2{1, 1, 1, 1};
    assert(pick_gifts(v2, 4) == 4);
    vector<int> v3{54, 6, 34, 66, 63, 52, 39, 62, 46, 75, 28, 65, 18, 37, 18, 13, 33, 69, 19, 40, 13, 10, 43, 61, 72};
    assert(pick_gifts(v3, 7) == 618);
    cout << "finish" << endl;
}
