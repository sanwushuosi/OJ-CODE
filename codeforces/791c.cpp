#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

vector<string> init(int n){
    vector<string> ret;
    for (int i = 0; i < n; i ++){
        char ch1;
        if (i < 26) ch1 = 'A';
        else ch1 = 'B';
        char ch2 = 'a' + (i % 26);
        string ss;
        ss += ch1;
        ss += ch2;
        ret.push_back(ss);
    }
    return ret;
}

int main(){
    int n,k;
    while (cin>>n>>k){
        vector<string> result = init(n);
        for (int i = k - 1; i < n; i ++){
            string judge;
            cin>>judge;
            if (judge.compare("NO") == 0){
                result[i] = result[i + 1 - k];
            }
        }
        cout<<result[0];
        for (int i = 1; i < n; i ++) cout<<" "<<result[i];
        cout<<endl;
    }
    return 0;
}
