#include <iostream>
using namespace std;

double power(double x, int n) {
    if (n == 0) return 1;
    
    if (n < 0) {
        return 1 / power(x, -n);
    }
    
    return x * power(x, n - 1);
}
double fastPower(double x, int n) {
    if (n == 0) return 1;
    
    if (n < 0) {
        return 1 / fastPower(x, -n);
    }
    
    double half = fastPower(x, n / 2);
    
    if (n % 2 == 0) {
        return half * half;
    } 
    else {
        return x * half * half;
    }
}
int main(){
    int val;
    int n;
    cout << "Enter val and n:";
    cin >> val >> n;
    cout << "Power:"<< power(val,n)<< endl;
    cout << "fast power:" << fastPower(val,n) << endl;
}