#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

const int maxn = 1005;
int n,m,k;
int node[maxn][maxn];
int gov[maxn];
int gov_nodes[maxn];
int visited[maxn];

int dfs(int x){
    int ret=1;
    for (int i=0;i<n;i++){
        if (!visited[i] && node[x][i]){
            visited[i]=1;
            ret += dfs(i);
        }
    }
    return ret;
}

int c(int x){
    return x*(x-1)/2;
}

int main(){
    bool DEBUG=false;
    memset(node,0,sizeof(node));
    memset(gov,0,sizeof(gov));
    cin>>n>>m>>k;
    for (int i=0;i<k;i++){
        cin>>gov[i];
        gov[i]--;
    }
    for (int i=0;i<m;i++){
        int node_a, node_b;
        cin>>node_a>>node_b;
        node_a--;
        node_b--;
        node[node_a][node_b]=1;
        node[node_b][node_a]=1;
    }
    memset(gov_nodes,0,sizeof(gov_nodes));
    memset(visited,0,sizeof(visited));
    for (int i=0;i<k;i++){
        visited[gov[i]]=1;
        gov_nodes[i]=dfs(gov[i]);
        if (DEBUG) cout<<"gov["<<i<<"] nodes = "<<gov_nodes[i]<<endl;
    }
    int no_gov = 0;
    for (int i=0;i<n;i++){
        if (!visited[i]) no_gov++;
    }
    if (DEBUG) cout<<"no_gov = "<<no_gov<<endl;
    int max_nodes_gov = 0;
    for (int i=1;i<k;i++){
        if (gov_nodes[i]>gov_nodes[max_nodes_gov]) max_nodes_gov=i;
    }
    gov_nodes[max_nodes_gov]+=no_gov;
    if (DEBUG) cout<<"max nodes gov nodes = " << gov_nodes[max_nodes_gov]<<endl;
    int tot_max_edge = 0;
    for (int i=0;i<k;i++){
        tot_max_edge += c(gov_nodes[i]);
        if (DEBUG) cout<<"tot_max_edge round["<<i<<"] = "<<tot_max_edge<<endl;
    }
    tot_max_edge -= m;
    cout<<tot_max_edge<<endl;
    return 0;
}



