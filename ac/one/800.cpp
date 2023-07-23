// 双指针问题，数组元素的目标和
#include <iostream>

using namespace std;

const int N = 1e5 + 10;
// typedef long long ll;
int A[N];
int B[N];

int main() {
    int n, m, x;
    scanf("%d %d %d", &n, &m, &x);
    for(int i = 0;i < n;i ++) scanf("%d", &A[i]);
    for(int i = 0;i < m;i ++) scanf("%d", &B[i]);
    int i = 0, j = 0;
    for(i = 0,j = m - 1;i < n;i ++) {
        while(j >= 0 && A[i] + B[j] > x) j --;
        if(A[i] + B[j] == x) cout << i << " " << j;
    }
    return 0;
}