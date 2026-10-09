#include <bits/stdc++.h>
using namespace std;

int cal(int n){
    if (n == 1) return 1;
    if (n % 2 == 0) return cal(n / 2) + 1;
    else return cal(3 * n + 1) + 1;
}

int biggest(vector<int> &res, int a, int b){
    int max = 0;
    for (int i = a; i <= b; i++){
        if (res[i] > max) max = res[i];
    }
    return max;
}

int main(){
    vector<int> res(10000);
    for (int i = 1; i < 10000; i++){
        res[i] = cal(i);
    }
    int a, b;
    while (cin >> a >> b){
        cout << a << " " << b << " " << biggest(res, a, b) << endl;
    }
    return 0;
}