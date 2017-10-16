#include <cstdio>
#include <queue>
#include <unordered_map>
#include <iostream>
#include <vector>

using namespace std;

bool judge(string s){
    if (s.find("VK") == string::npos) return true;
    return false;
}

int main(){
    int n;
    while (cin>>n){
        string input_s;
        cin>>input_s;
        queue<string> q;
        unordered_map<string, int> hash;
        bool found = false;
        q.push(input_s);
        hash[input_s] = 0;
        while (!found){
            string now_s = q.front();
            if (judge(now_s)) found = true;
            else{
                for (int i = 1; i < n; i++){
                    if (now_s[i] == 'K'){
                        if (now_s[i - 1] == 'V'){
                            string new_s = now_s;
                            new_s[i - 1] = 'K';new_s[i] = 'V';
                            if (hash.find(new_s) == hash.end()){
                                q.push(new_s);
                                hash[new_s] = hash[now_s] + 1;
                            }
                            if (i != n - 1){
                                new_s[i - 1] = 'V';new_s[i] = new_s[i + 1];new_s[i + 1] = 'K';
                                if (hash.find(new_s) == hash.end()){
                                    q.push(new_s);
                                    hash[new_s] = hash[now_s] + 1;
                                }
                            }
                        }
                    }
                }
            }
            if (!found) q.pop();
        }
        cout<<hash[q.front()]<<endl;
    }
    return 0;
}


