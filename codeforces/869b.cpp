#include <cstdio>
#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    ll a,b;
    cin >> a >> b;
    if (b - a >= 10) cout << "0" << endl;
    else if (a == b) cout << "1" << endl;
    else{
        ll result = 1;
        for (ll i = a + 1; i <= b; i ++){
            result = (result * (i % 10)) % 10;
        }
        cout << result << endl;
    }
    return 0;
}
