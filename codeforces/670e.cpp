#include <cstdio>
#include <iostream>
#include <stack>
using namespace std;

const int maxn=5e+5;

stack<int> s;
char sz[maxn];
int n_next[maxn];
int pre[maxn];
int p_pair[maxn];

int n,m,pos;

void output_result(void){
  int output=0;
  while(output<n){
    cout<<sz[output];
    output=n_next[output];
  }
  cout<<endl;
}

int main(){
  cin>>n>>m>>pos;
  pos--;

  string sss;
  cin>>sss;
  for (int i=0;i<n;i++){
    if (sss[i]=='('){
      s.push(i);
    }else{
      p_pair[i]=s.top();
      p_pair[s.top()]=i;
      s.pop();
    }
    sz[i]=sss[i];
    pre[i]=i-1;
    n_next[i]=i+1;
  }
  cout<<endl<<"debug1 : string = ";
  output_result();

  cin>>sss;
  for (int i=0;i<m;i++){
    if (sss[i]=='R') pos=n_next[pos];
    else if (sss[i]=='L') pos=pre[pos];
    else{
      int left=min(pos,p_pair[pos]);
      int right=max(pos,p_pair[pos]);
      pos=n_next[right];
      n_next[pre[left]]=n_next[right];
      pre[n_next[right]]=pre[left];
      cout<<"debug2 : string now = ";output_result();
    }
  }
  output_result();
  return 0;
}



