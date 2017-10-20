#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct node{
    int t,d,p,index;
};

struct res{
    int score;
    vector<int> path;
};

bool my_cmp(node x, node y){
    return (x.d < y.d);
}

int main(){
    int n;
    cin >> n;
    vector<node> item;
    int maxd = 0;
    for (int i = 0; i < n; i ++){
        node _node;
        cin >> _node.t >> _node.d >> _node.p;
        _node.index = i + 1;
        item.push_back(_node);
        maxd = max(maxd, _node.d);
    }
    sort(item.begin(), item.end(), my_cmp);
    //for (int i = 0; i < item.size(); i++) cout<<item[i].t<<" "<<item[i].d<<" "<<item[i].p<<endl;
    vector<res> result(maxd);
    for (int i = 0; i < maxd; i ++) result[i].score = 0;
    for (int i = 0; i < item.size(); i++){
        for (int j = item[i].d - 1; j >= item[i].t; j--){
            if (result[j].score < result[j - item[i].t].score + item[i].p){
                result[j].score = result[j - item[i].t].score + item[i].p;
                result[j].path = result[j - item[i].t].path;
                result[j].path.push_back(item[i].index);
            }
        }
        //for (int j = 0; j < maxd; j++) cout<<result[j].score<<" ";cout<<endl;
    }
    int output = maxd - 1;
    for (int i = 0; i < maxd - 1; i ++){
        if (result[i].score > result[output].score) output = i;
    }
    cout << result[output].score << endl;
    cout << result[output].path.size() << endl;
    if (result[output].path.size() > 0){
        for (int i = 0; i < result[output].path.size(); i++){
            cout << result[output].path[i] << " ";
        }
        cout << endl;
    }
    return 0;
}


