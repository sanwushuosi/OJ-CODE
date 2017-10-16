#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main(){
    int a,b;
    while (cin>>a>>b){
        int ret = 0;
        while (a <= b){
            ret ++;
            a *= 3;
            b *= 2;
        }
        cout<<ret<<endl;
    }
    return 0;
}

