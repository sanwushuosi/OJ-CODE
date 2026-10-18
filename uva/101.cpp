#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> blocks;
vector<int> belong;

void init(int n){
    blocks.resize(n);
    belong.resize(n);
    for (int i = 0; i < n; i++){
        blocks[i].push_back(i);
        belong[i] = i;
    }
}

void clear_top(int x){
    int k = belong[x];
    for (int i = 0; i < blocks[k].size(); i++){
        if (blocks[k][i] == x){
            for (int j = blocks[k].size() - 1; j >= i + 1; j--){
                blocks[blocks[k][j]].push_back(blocks[k][j]);
                belong[blocks[k][j]] = blocks[k][j];
                blocks[k].pop_back();
            }
            return;
        }
    }
}

int main(){
    int n;
    cin >> n;
    init(n);
    string op;
    while (cin >> op) {
        if (op == "quit") break;
        int x, y;
        string op_type;
        cin >> x >> op_type >> y;
        if (belong[x] == belong[y]) continue;
        if (op == "move"){
            clear_top(x);
            if (op_type == "onto") clear_top(y);
            blocks[belong[x]].pop_back();
            blocks[belong[y]].push_back(x);
            belong[x] = belong[y];
        }else{
            //op == "pile"
            if (op_type == "onto") clear_top(y);
            int col = belong[x];
            for (int i = 0; i < blocks[col].size(); i++){
                if (blocks[col][i] == x){
                    for (int j = i; j < blocks[col].size(); j++){
                        blocks[belong[y]].push_back(blocks[col][j]);
                        belong[blocks[col][j]] = belong[y];
                    }
                    blocks[col].resize(i);
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++){
        cout << i << ":";
        for (int j = 0; j < blocks[i].size(); j++){
            cout << " " << blocks[i][j];
        }
        cout << endl;
    }
    return 0;
}