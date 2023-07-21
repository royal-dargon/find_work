class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int res = 0;
        for(int i = 1; i <= nums.size(); i ++) {
            if(nums.size() % i == 0) {
                res = res + nums[i-1] * nums[i-1];
            }
        }
        return res;
    }
};

int main() {

    return 0;
}