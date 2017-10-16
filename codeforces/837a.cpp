#include <cstdio>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;
    string ss;
    int ret = 0;
    while (cin >> ss){
        int word_v = 0;
        for (int i = 0; i < ss.length(); i ++){
            if (ss[i] >= 'A' && ss[i] <= 'Z') word_v++;
        }
        if (word_v > ret) ret = word_v;
    }
    cout << ret << endl;
    return 0;
}
