#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(vector <int> a, vector <int> b) {
    if(a[0] != b[0]) return a[0] < b[0];
	if(a[1] != b[1]) return a[1] < b[1];
    return false;
}

class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        vector <vector<int> > top_down;
        for(int i=0; i<nums.size(); i++) {
            vector <int> temp;
            temp.push_back(nums[i] - k);
            temp.push_back(nums[i] + k);
            top_down.push_back(temp);
        }
        int res = 0;
        sort(top_down.begin(), top_down.end(), cmp);
        vector<int> dp(nums.size(), 1);
        for(int i=1; i<nums.size(); i++) {
            for(int j=0; j<i; j++) {
                if(top_down[i][0] < top_down[j][1]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        return res;
    }
};

int main() {
    vector<int> test;
    test.push_back(4);
    test.push_back(6);
    test.push_back(1);
    test.push_back(2);
    Solution S;
    int res = S.maximumBeauty(test, 2);
    cout << res << endl; 
    return 0;
}