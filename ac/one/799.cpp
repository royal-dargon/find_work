// 最长连续不重复子序列
#include <iostream>

using namespace std;

const int N = 100010;
int q[N];
int s[N];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0;i < n;i ++) scanf("%d", &q[i]);
    
    int res = 0;
    int i, j;
    for(i = 0, j = 0;i < n;i ++) {
        s[q[i]] ++;
        while(s[q[i]] > 1) {
            s[q[j]] --;
            j ++;
        }
        res = max(res, i - j + 1);
    }
    cout << res;
    return 0;
}