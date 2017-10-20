#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    ll a, b, f, k;
    cin >> a >> b >> f >> k;
    vector<ll> sz;
    sz.push_back(0);
    for (int i = 1; i <= k; i++){
        if (i%2==1) sz.push_back((i-1)*a+f);
        else sz.push_back(i*a-f);
    }
    sz.push_back(k*a);
    ll p = 0;
    ll t = 0;
    ll l = sz.size();
    //for (int i = 0; i < l; i ++) cout << sz[i] << " ";cout << endl;
    for (int i = 0; i < l; i++){
        ll next_p = p + b;
        if (next_p >= sz[l - 1]) break;
        if (next_p < sz[i + 1]){
            cout << "-1" << endl;
            return 0;
        }
        int j = i + 1;
        while (j + 1 < l){
            if (sz[j + 1] <= next_p) j++;
            else break;
        }
        if (j == l - 1) break;
        t++;
        //cout << "p = " << next_p << ", next_p = " << sz[j] << endl;
        p = sz[j];
    }
    cout << t << endl;
    return 0;
}
