#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main(){
    int n;
    cin >> n;
    unordered_map<int, int> hash;
    for (int i = 0; i < n; i ++){
        int a;
        cin >> a;
        hash[a] = hash[a] + 1;
    }
    unordered_map<int, vector<int> > total;
    for (unordered_map<int, int>::iterator it = hash.begin(); it != hash.end(); it++){
        total[it->second].push_back(it->first);
    }
//    for (unordered_map<int, vector<int> >::iterator it = total.begin(); it != total.end(); it++){
//        if (it->second.size() > 1){
//            cout << it->first << " :";
//            for (int i = 0; i < it->second.size(); i++) cout << " " << it->second[i];
//            cout << endl;
//        }
//    }
    if (total.size() == 1 && total.begin()->second.size() == 2){
        cout << "YES" << endl;
        cout << total.begin()->second[0] << " " << total.begin()->second[1] << endl;
    }
    else cout << "NO" << endl;
    return 0;
}



