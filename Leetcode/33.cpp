// 搜索旋转排序数组
// 局部有序可以使用二分查找
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        // 先解决两个比较容易的情况
        int n = nums.size();
        if(n == 0) return -1;
        if(n == 1) {
            if(nums[0] == target) return 0;
            else return -1;
        }
        // 下面开始利用二分的方式解决问题，借鉴必然是有一边是有序的
        int l = 0, r = n - 1;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(nums[mid] == target) return mid;
            // 第一个判断有序的序列是不是在这一边
            if(nums[l] <= nums[mid]) {
                if(target >= nums[l] && target <= nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if(target >= nums[mid] && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main() {
    vector<int> test;
    test.push_back(4);
    test.push_back(5);
    test.push_back(6);
    test.push_back(0);
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    Solution S;
    int res = S.search(test, 4);
    cout << res << endl;
    return 0;
}