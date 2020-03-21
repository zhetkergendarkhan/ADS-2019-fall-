#include <iostream>
using namespace std;

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

int f(int n){
    if(n < 2) return n;
    return f(n-1)+f(n-2);
}
int lcm (int a, int b) {
    return a / gcd (a, b) * b;
}

int main() 
{
    int x, y;
    cin >> x >> y;
    cout << lcm(f(x),f(y));
}