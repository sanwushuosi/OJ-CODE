#include <bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while (t--){
        int n, k;
        cin >> n >> k;
        vector<long long> s(n + 5);
        vector<long long> a(n + 5);
        bool res = true;
        for (int i = 0; i < k; i++){
            cin >> s[i];
        }
        if (k == 1){
            cout << "Yes" << endl;
            continue;
        }
        for (int i = k - 1, j = n - 1; i >= 1; i--, j--){
            a[j] = s[i] - s[i - 1];
            if (j < n - 1 && a[j] > a[j + 1]) res = false;
        }
        if (k == n){
            a[0] = s[0];
            if (a[0] > a[1]) res = false;
        }
        if (res){
            long long need_a = n - k + 1;
            if (need_a > 1){
                if (a[need_a] * need_a < s[0]){
                    res = false;
                }
            }
        }
        if (res) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}