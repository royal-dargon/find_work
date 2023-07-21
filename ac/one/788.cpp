// 逆序对的数量 
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 100010;
int q[N];
int tmp[N];

LL merge_sort(int q[], int l, int r){
    if(l >= r) return 0;
    int mid = (l + r) >> 1;
    LL res = merge_sort(q, l, mid) + merge_sort(q, mid + 1, r);
    int i = l, j = mid + 1, k = 0;
    while(i <= mid && j <= r){
        if(q[i] <= q[j]) tmp[k ++] = q[i ++];
        else{
            tmp[k ++] = q[j ++];
            // 这里很关键，分类讨论
            res += (mid - i + 1);
        }
    }
    while(i <= mid){
        tmp[k ++] = q[i ++];
    }
    while(j <= r){
        tmp[k ++] = q[j ++];
    }
    for(i = l, j = 0;i <= r;i ++, j ++){
        q[i] = tmp[j];
    }
    return res;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i ++) scanf("%d", &q[i]);
    LL res = merge_sort(q, 0, n-1);
    cout << res << endl;
    return 0;
}