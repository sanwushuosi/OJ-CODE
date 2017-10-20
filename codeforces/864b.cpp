#include <cstdio>
#include <string>
#include <iostream>
#include <unordered_set>

using namespace std;

bool upcase(char ch){
    if (ch >= 'A' && ch <= 'Z') return true;
    return false;
}

int main(){
    int n;
    string s;
    cin >> n >> s;
    int result = 0;
    unordered_set<char> hash;
    int temp_result = 0;
    for (int i = 0; i < n; i ++){
        if (upcase(s[i])){
            if (temp_result > result) result = temp_result;
            temp_result = 0;
            hash.clear();
        }else{
            if (hash.find(s[i]) == hash.end()){
                hash.insert(s[i]);
                temp_result ++;
            }
        }
    }
    if (temp_result > result) result = temp_result;
    cout << result << endl;
    return 0;
}

