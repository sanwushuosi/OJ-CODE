#include <cstdio>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> compare(string s, string t, int x){
    vector<int> ret(0);
    int n = s.length();
    int m = t.length();
    for (int i = 0; i < n; i ++){
        if (s[i] != t[x + i]) ret.push_back(i);
    }
    return ret;
}

int main(){
    int n, m;
    cin >> n >> m;
    string s, t;
    cin >> s >> t;
    vector<int> ret(0);
    for (int i = 0; i < n; i ++) ret.push_back(i);
    for (int i = 0; i < m - n + 1; i ++){
        vector<int> diff = compare(s, t, i);
        if (diff.size() < ret.size()) ret = diff;
    }
    cout << ret.size() << endl;
    if (ret.size() > 0){
        for (int i = 0; i < ret.size() - 1; i ++) cout << ret[i] + 1 << " ";
        cout << ret[ret.size() - 1] + 1 << endl;
    }
    return 0;
}


