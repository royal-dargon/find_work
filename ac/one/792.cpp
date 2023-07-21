// 高精度减法
#include <iostream>
#include <vector>

using namespace std;

// 判断 A >= B
bool cmp(vector<int> &A, vector<int> &B) {
    if(A.size() != B.size()) return A.size() > B.size();
    for(int i = A.size() - 1;i >= 0;i --){
        if(A[i] != B[i]) return A[i] > B[i];
    }
    return true;
}

vector<int> solve_sub(vector<int> &A, vector<int> &B) {
    vector<int> C;
    int t = 0;
    for(int i = 0;i < A.size() || i < B.size();i ++){
        if(i < A.size()) t += A[i];
        if(i < B.size()) t -= B[i];
        // 这里可以进行优化
        if(t < 0){
            C.push_back(t + 10);
            t = -1;
        } else {
            C.push_back(t);
            t = 0;
        }
    }
    for(int i = C.size() - 1;i >= 0;i --) {
        if(C[i] != 0) break;
        else C.erase(C.begin() + i);
    }
    // cout << C.size() << endl;
    if(C.size() == 0) C.push_back(0);
    return C;
}

int main() {
    string a, b;
    vector<int> A, B;
    cin >> a >> b;
    for(int i = a.size() - 1;i >= 0;i --) A.push_back(a[i] - '0');
    for(int i = b.size() - 1;i >= 0;i --) B.push_back(b[i] - '0');

    if(cmp(A, B)) {
        vector<int> C = solve_sub(A, B);
        for(int i = C.size() - 1;i >= 0;i --) cout << C[i];
    } else {
        vector<int> C = solve_sub(B, A);
        cout << "-";
        for(int i = C.size() - 1;i >= 0;i --) cout << C[i];
    }
    cout << endl;
    return 0;
}