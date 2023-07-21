// 高精度系列问题之加法，先解决存储问题再解决模拟运算问题
#include <iostream>
#include <vector>

using namespace std;


vector<int> solve_add(vector<int> &a, vector<int> &b) {
    vector<int> c;
    int t = 0;      // 进位标志
    for(int i = 0;i < a.size() || i < b.size();i ++) {
        if(i < a.size()) t += a[i];
        if(i < b.size()) t += b[i];
        c.push_back(t % 10);
        t = t / 10;
    }

    if(t) c.push_back(1);
    return c;
}

int main(){
    string a, b;
    vector<int> A, B;

    cin >> a >> b;
    for(int i = a.size() - 1;i >= 0;i --) A.push_back(a[i] - '0');
    for(int i = b.size() - 1;i >= 0;i --) B.push_back(b[i] - '0');
    vector<int> C = solve_add(A, B);
    for(int i = C.size() - 1;i >= 0;i --) printf("%d", C[i]);
    cout << endl;
    return 0;
}