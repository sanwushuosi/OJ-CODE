#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    unordered_set<int> hash;
    for (int i = 0; i < n; i ++){
        cin>>x[i];
        hash.insert(x[i]);
    }
    for (int i = 0; i < n; i ++){
        cin>>y[i];
        hash.insert(y[i]);
    }
    int total = 0;
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            //cout << x[i] << " " << y[j] << " " << int(x[i] ^ y[j]) << endl;
            if (hash.find(int(x[i] ^ y[j])) != hash.end()) total++;
        }
    }
    if (total % 2 == 0) cout << "Karen" << endl;
    else cout << "Koyomi" << endl;
    return 0;
}
