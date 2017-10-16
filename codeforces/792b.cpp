#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

int next(vector<bool> &a, int pos){
    int ret = pos + 1;
    if (ret >= a.size()) ret = 0;
    while (!a[ret]){
        ret++;
        if (ret >= a.size()) ret = 0;
    }
    return ret;
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<bool> a(n, true);
    vector<int> b(k);
    for (int i = 0; i < k; i ++) cin>>b[i];
    //simulate
    int leader = 0;
    int people_remain = n;
    for (int i = 0; i < k; i ++){
        //cout<<"now leader = " << leader << ", next b[i] = " << b[i] << endl;
        int now_a = b[i] % people_remain;
        int now_eliminate = leader;
        while (now_a --){
            //clockwise counting
            now_eliminate = next(a, now_eliminate);
        }
        a[now_eliminate] = false;
        cout << now_eliminate + 1;
        if (i < k - 1) cout<<" ";
        else cout<<endl;
        leader = next(a, now_eliminate);
        people_remain --;
    }
    return 0;
}
