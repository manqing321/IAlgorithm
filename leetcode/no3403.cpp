#include <string>
#include <iostream>
using std::cout;
using std::string;

class Solution {
public:
    int max_dict(const string& word, int idx1, int idx2, int max_len) {
        for (size_t i = 0; i < max_len; i++) {
            if(idx1 + i >= word.size()) {
                return idx2;
            } else if (idx2 + i >= word.size()) {
                return idx1;
            }
            cout << word[idx1 + 1] << ": " << word[idx2 + i] << "\n";
            if (word[idx1 + i] > word[idx2 + i]) {
                return idx1;
            } else if (word[idx2 + i] > word[idx1 + i]) {
                return idx2;
            }
        }
        return idx1;
    }
    string answerString(string word, int numFriends) {
        if (numFriends == 1) {
            return word;
        }
        auto max_len = word.size() - numFriends + 1;
        auto max = 0;
        for (size_t i = 1; i < word.size(); i++) {
            max = max_dict(word, max, i, max_len);
            cout << i << ", " << max << "\n";
        }
        if (max + max_len > word.size()){
            return word.substr(max, word.size() - max);
        }
        return word.substr(max, max_len);
    }
};

int main(){
    auto word = "aann";
    auto numFriends = 2;
    auto actual = Solution().answerString(word, numFriends);
    cout << actual << "\n";
}