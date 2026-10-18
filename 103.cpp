#include <bits/stdc++.h>
using namespace std;

struct Box{
    vector<int> di;
    int id;
};

bool exact_cover(Box a, Box b){
    for (int i = 0; i < a.di.size(); i++){
        if (a.di[i] >= b.di[i]){
            return false;
        }
    }
    return true;
}

int main(){
    int n, d;
    while (cin >> n >> d){
        vector<Box> a(n);
        for (int i = 0; i < n; i++){
            a[i].id = i + 1;
            a[i].di.resize(d);
            for (int j = 0; j < d; j++){
                cin >> a[i].di[j];
            }
            sort(a[i].di.begin(), a[i].di.end());
        }
        sort(a.begin(), a.end(), [](Box a, Box b){
            return a.di < b.di;
        });
        // for (int i = 0; i < n; i++){
        //     cout << a[i].id << " ";
        //     for (int j = 0; j < d; j++){
        //         cout << a[i].di[j] << " ";
        //     }
        //     cout << endl;
        // }
        vector<int> dp(n, 1);
        vector<int> pre(n, -1);
        for (int i = 0; i < n; i++){
            for (int j = 0; j < i; j++){
                if (exact_cover(a[j], a[i])){
                    if (dp[j] + 1 > dp[i]){
                        dp[i] = dp[j] + 1;
                        pre[i] = j;
                    }
                }
            }
        }
        int ans = *max_element(dp.begin(), dp.end());
        cout << ans << endl;
        for (int i = 0; i < n; i++){
            if (dp[i] == ans){
                vector<int> path;
                int j = i;
                while (j != -1){
                    path.push_back(a[j].id);
                    j = pre[j];
                }
                reverse(path.begin(), path.end());
                for (int j = 0; j < path.size(); j++){
                    cout << path[j] << " ";
                }
                cout << endl;
                break;
            }
        }
    }
    return 0;
}