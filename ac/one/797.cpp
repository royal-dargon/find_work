// 797差分
#include <iostream>

using namespace std;

const int N = 100010;
int S[N], a[N];

int main() {
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0;i < n;i ++) scanf("%d", &S[i+1]);
    S[0] = 0;
    a[0] = 0;
    for(int i = 0;i < n;i ++) a[i+1] = S[i+1] - S[i];
    while(m --) {
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c);
        a[l] += c;
        if(r < n) a[r+1] -= c;
    }
    for(int i = 0;i < n;i ++) S[i+1] = S[i] + a[i+1];
    for(int i = 1;i <= n;i ++) printf("%d ", S[i]);
    return 0;
}

// 另一个题解
int n, m;
int a[N], b[N];

void insert(int l, int r, int c) {
    b[l] += c;
    b[r + 1] -= c;
}

int main() {
    scanf("%d %d", &n, &m);
    for(int i = 1;i <= n;i ++) scanf("%d", &a[i]);
    for(int i = 1;i <= n;i ++) insert(i, i, a[i]);
    while(m --) {
        int l, r, c;
        scanf("%d %d %d", &l, &r, &c);
        insert(l, r, c);
    }
    for(int i = 1;i <= n;i ++) b[i] += b[i - 1];
    for(int i = 1;i <= n;i ++) printf("%d ", b[i]);
}