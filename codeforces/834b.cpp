#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_set>

using namespace std;

int main(){
    int n, k;
    cin >> n >> k;
    string ss;
    cin >> ss;
    vector<bool> mark_end(n, false);
    unordered_set<char> char_set;
    for (int i = n - 1; i >= 0; i --){
        if (char_set.find(ss[i]) == char_set.end()){
            mark_end[i] = true;
            char_set.insert(ss[i]);
        }
    }
    //for (int i = 0; i < n; i ++) if (mark_end[i]) cout << i << endl;
    int need_guard = 0;
    bool unguard = false;
    char_set.clear();
    for (int i = 0; i < n - 1; i ++){
        if (char_set.find(ss[i]) == char_set.end()){
            need_guard ++;
            if (need_guard > k) unguard = true;
            char_set.insert(ss[i]);
        }
        if (mark_end[i]){
            need_guard --;
        }
    }
    if (unguard) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
