#include <cstdio>
#include <iostream>

using namespace std;

int main(){
    int a;
    cin >> a;
    if (a == 1){
        cout << "1 1" << endl;
        cout << "1" << endl;
        return 0;
    }
    int n = (a - 1) * 2;
    cout << n << " " << "2" << endl;
    cout << "1 2" << endl;
    return 0;
}
