#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while(t--){
        int n, m;
        cin >> n >> m;
        string s;
        cin >> s;
        vector<int> sum(n + 1, 0), lmin(n + 1, 0), lmax(n + 1, 0), rmin(n + 1, 0), rmax(n + 1, 0);
        for (int i = 0; i < n; i ++){
            if (s[i] == '+'){
                sum[i + 1] = sum[i] + 1;
            }
            else{
                sum[i + 1] = sum[i] - 1;
            }
            lmin[i + 1] = min(lmin[i], sum[i + 1]);
            lmax[i + 1] = max(lmax[i], sum[i + 1]);
        }
        rmin[n] = sum[n];
        rmax[n] = sum[n];
        for (int i = n - 1; i >= 0; i --){
            rmin[i] = min(rmin[i + 1], sum[i]);
            rmax[i] = max(rmax[i + 1], sum[i]);
        }
        // for (int i = 1; i <= n; i ++) cout << sum[i] << " "; cout << endl;
        // for (int i = 1; i <= n; i ++) cout << lmin[i] << " "; cout << endl;
        // for (int i = 1; i <= n; i ++) cout << lmax[i] << " "; cout << endl;
        // for (int i = 1; i <= n; i ++) cout << rmin[i] << " "; cout << endl;
        // for (int i = 1; i <= n; i ++) cout << rmax[i] << " "; cout << endl;
        while (m --){
            int l, r;
            cin >> l >> r;
            if (l == 1 && r == n) cout << 1 << endl;
            else if (r == n) cout << lmax[l - 1] - lmin[l - 1] + 1 << endl;
            else if (l == 1) cout << max(rmax[r + 1] - sum[r], 0) - min(rmin[r + 1] - sum[r], 0) + 1 << endl;
            else {
                int diff = sum[l - 1] - sum[r];
                if (lmax[l - 1] < rmin[r + 1] + diff || rmax[r + 1] + diff < lmin[l - 1]) cout << lmax[l - 1] - lmin[l - 1] + 1 + rmax[r + 1] - rmin[r + 1] + 1 << endl;
                else cout << max(lmax[l - 1], rmax[r + 1] + diff) - min(lmin[l - 1], rmin[r + 1] + diff) + 1 << endl;
            }
        }
    }
    return 0;
}