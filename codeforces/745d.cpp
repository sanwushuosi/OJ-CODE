#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int maxn=1005;
const int max_ret=1000000005;
int output[maxn];
int output_l;
int n;
int sz[maxn];
int result[maxn];

int main(){
    memset(sz,0,sizeof(sz));
    for (int i=0;i<maxn;i++) result[i]=max_ret;
    cin>>n;
    int mod_num=2;
    for (int rnd=0;rnd<20;){
        memset(output,0,sizeof(output));
        output_l=0;
        for (int i=0;i<n;i++){
            if (i%mod_num<(mod_num/2)) {output[i]=1;output_l++;}
        }
        if (output_l>0){
            cout<<output_l<<endl;
            int new_out=1;
            for (int i=0;i<n;i++) if (output[i]==1) {if (!new_out) cout<<" ";cout<<i+1;new_out=0;}
            cout<<endl;
            cout << flush;
            for (int i=0;i<n;i++) cin>>sz[i];
            for (int i=0;i<n;i++){
                if (output[i]!=1){
                    result[i] = min(result[i],sz[i]);
                }
            }
        }
        rnd++;

        memset(output,0,sizeof(output));
        output_l=0;
        for (int i=0;i<n;i++){
            if (i%mod_num>=(mod_num/2)) {output[i]=1;output_l++;}
        }
        if (output_l>0){
            cout<<output_l<<endl;
            int new_out=1;
            for (int i=0;i<n;i++) if (output[i]==1) {if (!new_out) cout<<" ";cout<<i+1;new_out=0;}
            cout<<endl;
            cout << flush;
            for (int i=0;i<n;i++) cin>>sz[i];
            for (int i=0;i<n;i++){
                if (output[i]!=1){
                    result[i] = min(result[i],sz[i]);
                }
            }
        }
        rnd++;
        mod_num*=2;
    }
    cout<<"-1"<<endl;
    cout<<result[0];
    for (int i=1;i<n;i++) cout<<" "<<result[i];
    cout<<endl;
    cout << flush;
    return 0;
}
