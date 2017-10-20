#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> sz;
    unordered_map<int, int> cnt;
    for (int i = 0; i < n; i ++){
        int a;
        cin >> a;
        sz.push_back(a);
        cnt[a] ++;
    }
    queue<int> mis;
    for (int i = 1; i <= n; i ++){
        if (cnt.find(i) == cnt.end()) mis.push(i);
    }
    int ret = 0;
    unordered_set<int> skip;
    for (int i = 0; i < n; i ++){
        if (cnt[sz[i]] > 1){
            if (sz[i] < mis.front()){
                if (skip.find(sz[i]) == skip.end()){
                    skip.insert(sz[i]);
                    continue;
                }
            }
            cnt[sz[i]] --;
            sz[i] = mis.front();
            mis.pop();
            ret ++;
        }
    }
    cout << ret << endl;
    for (int i = 0; i < n; i ++){
        cout << sz[i] << " ";
    }
    cout << endl;
    return 0;
}



