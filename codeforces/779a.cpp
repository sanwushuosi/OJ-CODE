#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

bool divide(vector<int> tot){
    for (int i = 1; i <= 5; i ++){
        if (tot[i] % 2 != 0) return false;
    }
    return true;
}

int main(){
    int n;
    cin>>n;
    int a[105];
    int b[105];
    for (int i = 0; i < n; i ++) cin>>a[i];
    for (int i = 0; i < n; i ++) cin>>b[i];
    vector<int> tot(10);
    for (int i = 0; i < n; i ++){
        tot[a[i]]++;
        tot[b[i]]++;
    }
    if (!divide(tot)){
        cout<<"-1"<<endl;
        return 0;
    }
    for (int i = 1; i <= 5; i ++) tot[i] /= 2;
    int ret = 0;
    for (int i = 0; i < n; i ++){
        if (tot[a[i]] > 0) tot[a[i]]--;
        else ret ++;
    }
    cout<<ret<<endl;
    return 0;
}
