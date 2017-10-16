#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

int lenth(int x){
    int ret = 1;
    while (x>9){
        x/=10;
        ret++;
    }
    return ret;
}

int main(){
    int n, k;
    cin>>n>>k;
    if (n == 0){
        cout<<0<<endl;
        return 0;
    }
    int markn = n;
    int ret = 0;
    while (n>9){
        int te = n % 10;
        if (te==0){
            k--;
            if (k == 0){
                cout<<ret<<endl;
                return 0;
            }
        }else{
            ret++;
        }
        n/=10;
    }
    cout<<lenth(markn) - 1<<endl;
    return 0;
}
