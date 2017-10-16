#include <iostream>

using namespace std;

const int maxn=100000;
int n,k;
int a[maxn+5],b[maxn+5];

int judge(const int x){
  int last = k;
  for (int i=0;i<n;i++){
    long long need = (long long)a[i] * (long long)x - b[i];
    if (need <=0) continue;
    if (need <= last) last = last - need;
    else return 0;
  }
  return 1;
}

int b_search(int x,int y){
  //cout<<"debug1 : x = "<<x<<", y = "<<y<<endl;
  if (x>y) return 0;
  if (y-x<2){
    if (judge(y)) return y;
    else if (judge(x)) return x;
    else return 0;
  }
  int m=int(x/2.0+y/2.0);
  //cout<<"debug3 : m = "<<m<<", judge(m) = "<<judge(m)<<endl;
  if (judge(m)) return b_search(m,y);
  else return b_search(x,m-1);
}

int main(){
  cin>>n>>k;
  for (int i=0;i<n;i++) cin>>a[i];
  for (int i=0;i<n;i++) cin>>b[i];
  int ret = b_search(0,2000000000);
  cout<<ret<<endl;
  return 0;
}

