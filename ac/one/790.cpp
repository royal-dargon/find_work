#include <iostream>

using namespace std;

int main(){
    double n;
    cin >> n;
    double l = -10000, r = 10000;
    double mid;
    while((r - l) > 1e-8){
        mid = (l + r) / 2;
        if((mid * mid * mid) > n) r = mid;
        else l = mid;
    }
    printf("%.6f", mid);
    return 0;
}