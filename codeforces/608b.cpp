#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

int main(){
  char str_a[200005],str_b[200005];
  int tot[2][200005];
  while(scanf("%s",str_a)!=EOF){
    scanf("%s",str_b);
    int la=strlen(str_a);
    int lb=strlen(str_b);
    memset(tot,0,sizeof(tot));
    for (int i=0;i<lb;i++){
      tot[str_b[i]-'0'][i+1]=tot[str_b[i]-'0'][i]+1;
      tot[1-(str_b[i]-'0')][i+1]=tot[1-(str_b[i]-'0')][i];
    }
    //for (int i=0;i<=lb;i++) printf("%d ",tot[0][i]);printf("\n");
    //for (int i=0;i<=lb;i++) printf("%d ",tot[1][i]);printf("\n");
    long long out=0;
    for (int i=0;i<la;i++){
      out+=tot[1-(str_a[i]-'0')][lb-la+1+i]-tot[1-(str_a[i]-'0')][i];
    }
    cout << out << endl;
  }
  return 0;
}

