// 差分矩阵
#include <iostream>

using namespace std;

const int N = 1010;
int a[N][N], b[N][N];

void insert(int x_1, int y_1, int x_2, int y_2, int c) {
    b[x_1][y_1] += c;
    b[x_2 + 1][y_1] -= c;
    b[x_1][y_2 + 1] -= c;
    b[x_2 + 1][y_2 + 1] += c;
}

int main() {
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            scanf("%d", &a[i][j]);
        }
    }
    // 构造
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            insert(i, j, i, j, a[i][j]);
        }
    }
    while(q --) {
        int x_1, y_1, x_2, y_2, c;
        scanf("%d %d %d %d %d", &x_1, &y_1, &x_2, &y_2, &c);
        insert(x_1, y_1, x_2, y_2, c);
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            b[i][j] += b[i-1][j] + b[i][j-1] - b[i-1][j-1];
        }
    }
    for(int i = 1;i <= n;i ++) {
        for(int j = 1;j <= m;j ++) {
            printf("%d ", b[i][j]);
        }
        cout <<endl;
    }
    return 0;
}