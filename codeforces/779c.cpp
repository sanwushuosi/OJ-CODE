#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct triple{
    int x1;
    int x2;
    int diff;
};

bool my_cmp(triple x, triple y){
    return (x.diff < y.diff);
}

int main(){
    int n, k;
    cin>>n>>k;
    vector<triple> prices(n);
    for (int i = 0; i < n; i ++) cin>>prices[i].x1;
    for (int i = 0; i < n; i ++) cin>>prices[i].x2;
    for (int i = 0; i < n; i ++) prices[i].diff = prices[i].x1 - prices[i].x2;
    sort(prices.begin(), prices.end(), my_cmp);
    //for (int i = 0; i < n; i ++) cout<<prices[i].x1<<","<<prices[i].x2<<","<<prices[i].diff<<endl;
    int ret = 0;
    for (int i = 0; i < k; i ++) ret += prices[i].x1;
    while (k < n && prices[k].diff < 0){
        ret += prices[k].x1;
        k++;
    }
    for (int i = k; i < n; i ++) ret += prices[i].x2;
    cout<<ret<<endl;
    return 0;
}
    
