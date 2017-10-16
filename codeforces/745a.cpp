#include <cstdio>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int main(){
    string s;
    map<string,int> string_map;
    cin>>s;
    int l = s.length();
    //cout<<l<<endl;

    string_map[s] = 1;
    int ret = 1;
    string new_s = s;
    //cout<<new_s<<endl;
    for (int i = 0;i < l - 1;i++){
        new_s = new_s.substr(l-1, 1) + new_s.substr(0, l-1);
        //cout<<new_s<<endl;
        if (string_map.find(new_s) == string_map.end()){
            ret ++;
            string_map[new_s] = 1;
        }
    }
    cout<<ret<<endl;
    return 0;
}

