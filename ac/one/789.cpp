// 二分查找解决问题
#include <iostream>

using namespace std;

const int N = 100010;
int q[N];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0;i < n;i ++) scanf("%d", &q[i]);
    while(k --){
        int target;
        scanf("%d", &target);
        int l = 0, r = n - 1, mid;
        while(l < r){
            mid = (l + r) >> 1;
            if(q[mid] < target) l = mid + 1;
            else r = mid;
        }
        if(q[l] != target){
            cout << "-1 -1" << endl;
            continue;
        }
        cout << l << " ";
        l = 0, r = n - 1;
        while(l < r){
            mid = (l + r + 1) >> 1;
            if(q[mid] > target) r = mid - 1;
            else l = mid;
        }
        cout << l << endl;
    }
    return 0;
}

 