#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int s,v1,v2,t1,t2;
    cin >> s >> v1 >> v2 >> t1 >> t2;
    int ret1, ret2;
    ret1 = t1 * 2 + v1 * s;
    ret2 = t2 * 2 + v2 * s;
    if (ret1 < ret2) cout << "First" << endl;
    else if (ret1 > ret2) cout << "Second" << endl;
    else cout << "Friendship" << endl;
    return 0;
}
