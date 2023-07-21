// 前缀和
#include <iostream>

using namespace std;

const int N = 100010;
int a[N], S[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0;i < n;i ++) scanf("%d", &a[i+1]);
    S[0] = 0;
    for(int i = 1;i <= n;i ++) S[i] = S[i-1] + a[i];

    while(m --) {
        int l, r;
        scanf("%d %d", &l, &r);
        printf("%d\n", S[r] - S[l-1]);
    }
    return 0;
}