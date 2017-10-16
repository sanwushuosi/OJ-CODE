#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    cin>>n;
    vector<int> sz(n);
    for (int i = 0; i < n; i ++) cin>>sz[i];
    sort(sz.begin(), sz.end());
    //find min
    int min_dis = (2e+9) + 1;
    for (int i = 1; i < n; i ++){
        if (sz[i] - sz[i - 1] < min_dis) min_dis = sz[i] - sz[i - 1];
    }
    //cal numbers
    int numbers = 0;
    for (int i = 1; i < n; i ++){
        if (sz[i] - sz[i - 1] == min_dis) numbers ++;
    }
    cout<<min_dis<<" "<<numbers<<endl;
    return 0;
}
