#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

int main(){
    int n;
    string ss;
    cin >> n;
    cin >> ss;
    int l = ss.length();
    if (ss[0] == 'S' && ss[l - 1] == 'F') cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
