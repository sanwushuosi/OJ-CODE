#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;


int cal(int x, int y, vector< vector<int> > &sz){
    if (sz[x][y] != 0) return sz[x][y];
    else if (x > y) return cal(y, x, sz);
    else{
        ll a = cal(x - 1, y, sz);
        ll b = cal(x - 1, y - 1, sz);
        ll result = (a + y * b) % 998244353;
        sz[x][y] = result;
    }
    return sz[x][y];
}

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    int maxn = max(a, max(b, c));
    vector< vector<int> > sz(maxn + 1, vector<int>(maxn + 1));
    for (int i = 1; i <= maxn; i ++){
        sz[i][1] = i + 1;
        sz[1][i] = i + 1;
    }
    for (int i = 2; i <= maxn; i ++){
        for (int j = i; j <= maxn; j ++){
            sz[i][j] = cal(i, j, sz);
        }
    }
    ll ab = cal(a, b, sz);
    ll bc = cal(b, c, sz);
    ll ac = cal(a, c, sz);
    ll result = ((ab * bc) % 998244353) * ac % 998244353;
    cout << result << endl;
    return 0;
}
