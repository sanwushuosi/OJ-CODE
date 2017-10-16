#include <cstdio>
#include <iostream>

using namespace std;

int n,m;
char sz[505][505];

int judge(int l, int r, int up, int down){
    for (int i=up;i<=down;i++){
        for (int j=l;j<=r;j++){
            if (sz[i][j] != 'X') return 0;
        }
    }
    return 1;
}

int main(){
    cin>>n>>m;
    int l=-1;
    int r=-1;
    int up=-1;
    int down=-1;
    for (int i=0;i<n;i++){
        string temp_s;
        cin>>temp_s;
        for (int j=0;j<m;j++){
            sz[i][j]=temp_s[j];
            if (sz[i][j]=='X'){
                down=i;
                if (up == -1) up=i;
                if (l==-1 || j<l) l=j;
                if (r==-1 || j>r) r=j;
            }
        }
    }
    int ret = judge(l,r,up,down);
    if (ret) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}

