#include <bits/stdc++.h>
using namespace std;

int cal(long long n, vector<int> &res){
    if (n < 1000000 && res[n] != 0) return res[n];
    if (n == 1) return 1;
    else if (n % 2 == 0) return cal(n / 2, res) + 1;
    else return cal(3 * n + 1, res) + 1;
}

int biggest(vector<int> &res, int a, int b){
    if (a > b) swap(a, b);
    int max = 0;
    for (int i = a; i <= b; i++){
        if (res[i] > max) max = res[i];
    }
    return max;
}

int main(){
    vector<int> res(1000000, 0);
    for (int i = 1; i < 1000000; i++){
        res[i] = cal(i, res);
    }
    int a, b;
    while (cin >> a >> b){
        cout << a << " " << b << " " << biggest(res, a, b) << endl;
    }
    return 0;
}