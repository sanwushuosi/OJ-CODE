#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector< vector<int> > graph;
vector<bool> visited;
vector<int> connect_nodes;

void dfs(int x){
    connect_nodes.push_back(x);
    visited[x] = true;
    for (int i = 0; i < graph[x].size(); i++){
        if (!visited[graph[x][i]]) dfs(graph[x][i]);
    }
}

bool judge(int x){
    //cout<<"x = "<<x<<endl;
    connect_nodes.clear();
    dfs(x);
    //for (int i = 0; i < connect_nodes.size(); i ++) cout<<connect_nodes[i]<<" ";
    //cout<<endl;
    int node_num = connect_nodes.size();
    int edge_num = 0;
    for (int i = 0; i < node_num; i ++){
        edge_num += graph[connect_nodes[i]].size();
    }
    edge_num /= 2;
    if (edge_num == (node_num * (node_num - 1) / 2)) return true;
    return false;
}

int main(){
    int n, m;
    while (cin>>n>>m){
        graph.resize(n);
        graph.clear();
        for (int i = 0; i < m; i ++){
            int a,b;
            cin>>a>>b;
            graph[a - 1].push_back(b - 1);
            graph[b - 1].push_back(a - 1);
        }
        for (int i = 0; i < n; i ++){
            //cout<<i<<" : ";
            //for (int j = 0; j < graph[i].size(); j++) cout<<graph[i][j]<<",";
            //cout<<endl;
        }
        visited.resize(n);
        for (int i = 0; i < n; i ++) visited[i] = false;
        bool good_net = true;
        for (int i = 0; i < n && good_net; i ++){
            if (!visited[i]){
                if (!judge(i)) good_net = false;
            }
        }
        if (good_net) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
