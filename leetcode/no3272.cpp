#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
using namespace std;
class Solution {
public:
    map<int, long long> fact_mp;
    long long factorial(int n) { 
        int ans = 1;
        if (fact_mp.find(n) == fact_mp.end()) {
            if(n == 1) {
                ans = 1;
            }    
            else {
                ans = factorial(n - 1) * n;
            }
            fact_mp[n] = ans;
        }else{
            ans = fact_mp[n];
        }
        return ans;
    }
    long long countGoodIntegers(int n, int k) {
        // step 1: find all palindrome number
        long long ans = 0;
        int bit_set = n;
        int half_bit_set = (bit_set + 1) >> 1;
        auto bit_vec = vector<int>(half_bit_set, 0);
        bit_vec[0] = 1;
        auto vec = vector<int>(n, 0);
        auto mp = map<int, int>();
        auto st = set<string>();
        auto char_vec = vector<char>();
        // build palindrome number
        auto beg = 1;
        auto beg_bit = 1;
        while(beg_bit != half_bit_set){
            beg_bit += 1;
            beg *= 10;
        }
        auto end = beg * 10;
        for (int i = beg; i < end; i++)
        {
            if(i != beg) {
                // increment
                auto increment = true;
                auto iter = bit_vec.rbegin();
                while(increment && iter != bit_vec.rend()) {
                    *iter += 1;
                    if(*iter == 10){
                        *iter = 0;
                    }else{
                        increment = false;
                    }
                    iter++;
                }
            }
            char_vec.clear();
            int idx = 0;
            while(idx < bit_vec.size())
            {
                vec[idx] = bit_vec[idx];
                vec[n - 1 - idx] = bit_vec[idx];
                char ch = '0';
                ch += vec[idx];
                char_vec.push_back(ch);
                if(idx != n - 1- idx) {
                    char_vec.push_back(ch);
                }
                idx += 1;
            }
            long long num = 0;
            for (auto iter = vec.begin(); iter != vec.end(); iter++)
            {
                num = num * 10 + *iter;
            }
            string sb;
            sort(char_vec.begin(), char_vec.end());
            for (char c : char_vec)
            {
                sb.push_back(c);
            }
            if ((num % k) == 0 && st.find(sb) == st.end()) {
                st.insert(sb);
                // cout << num   << "|" << sb << ":";
                // step 2: 重排计数
                int size = n;
                int zero_cnt = 0;
                mp.clear();
                for (auto iter = vec.begin(); iter != vec.end(); iter++)
                {
                    if (mp.find(*iter) == mp.end()) {
                        mp.insert(make_pair(*iter, 0));
                    }
                    mp[*iter] += 1;
                    if(*iter == 0){
                        zero_cnt += 1;
                    }
                }
                long long cnt = factorial(size);
                for (auto iter = mp.begin(); iter != mp.end(); iter++)
                {
                    cnt /= factorial(iter->second);
                }
                if(zero_cnt > 0) {
                    long long zero_first_cnt = zero_cnt * factorial(size - 1);
                    for (auto iter = mp.begin(); iter != mp.end(); iter++)
                    {
                        if(iter->second) {
                            zero_first_cnt /= factorial(iter->second);
                        }
                    }
                    cnt -= zero_first_cnt;
                }
                ans += cnt;
                // cout << cnt <<", ";
            }
        }
        return ans;
    }
};

void test01(){
    int n = 3, k = 5;
    auto res = Solution().countGoodIntegers(n, k);
    cout << res << endl;
}
void test02(){
    int n = 5, k = 6;
    auto res = Solution().countGoodIntegers(n, k);
    cout << res << endl;
}
void test03(){
    int n = 1, k = 4;
    auto res = Solution().countGoodIntegers(n, k);
    cout << res << endl;
}
void test04(){
    int n = 4, k = 5;
    auto res = Solution().countGoodIntegers(n, k);
    cout << res << endl;
}
void test05(){
    int n = 3, k = 5;
    auto res = Solution().countGoodIntegers(n, k);
    cout << res << endl;
}
void test06(){
    int n = 4, k = 9;
    auto res = Solution().countGoodIntegers(n, k);
    cout << res << endl;
}
int main(){
    // test01();
    test02();
    // test03();
    // test04();
    // test05();
    // test06();
    

     
}