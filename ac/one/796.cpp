// 利用前缀和的思想求解子矩阵的和
#include <iostream>

using namespace std;

const int N = 1010;
int a[N][N], S[N][N];

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 0;i < n;i ++)
        for(int j = 0;j < m;j ++)
            scanf("%d", &a[i+1][j+1]);

    for(int i = 0;i < n;i ++)
        for(int j = 0;j < m;j ++)
            S[i+1][j+1] = a[i+1][j+1] + S[i][j+1] + S[i+1][j] - S[i][j];

    while(q --) {
        int x_1, y_1, x_2, y_2;
        scanf("%d %d %d %d", &x_1, &y_1, &x_2, &y_2);
        printf("%d\n", (S[x_2][y_2] - S[x_1 - 1][y_2] - S[x_2][y_1 - 1] + S[x_1 - 1][y_1 - 1]));
    }
    return 0;
}