// 按照分割符拆分字符串
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> splitWordsBySeparator(vector<string>& words, char separator) {
        vector<string> res;
        int lenth = words.size();
        for(int i = 0;i < lenth;i ++) {
            string word = words[i];
            int k = 0;
            int j = 0;
            for(j = 0;k < word.size();j ++) {
                // cout << k << " " << j << endl;
                if(word[k] == separator) {
                    k ++;
                    // j ++;
                    continue;
                }
                while(word[j] != separator && j < word.size()) {
                    j ++;
                }
                string tmp = word.substr(k, j-k);
                res.push_back(tmp);
                k = j + 1;
                
            }
        }
        return res;
    }
};


int main() {
    vector<string> test;
    Solution S;
    test.push_back("###x#i@f");
    // test.push_back("four");
    // test.push_back("six");
    char separator = '#';
    vector<string> r = S.splitWordsBySeparator(test, separator);
    for(int i = 0;i < r.size();i ++) cout << r[i] << " ";
    cout << endl;
    return 0;
}