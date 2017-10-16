#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int f(int x){
    int ret = 1;
    for (int i = 2; i <= x; i ++) ret *= i;
    return ret;
}

int main(){
    int a, b;
    cin >> a >> b;
    if (a <= b) cout << f(a) << endl;
    else cout << f(b) << endl;
    return 0;
}
