#include <bits/stdc++.h>
using namespace std;

int main(){
    int a[3], b[3], c[3];
    //000 = BGC
    while (cin >> a[0] >> a[1] >> a[2] >> b[0] >> b[1] >> b[2] >> c[0] >> c[1] >> c[2]){
        vector<int> cost(6);
        cost[0] = b[0] + c[0] + a[2] + c[2] + a[1] + b[1]; // B->0, C->1, G->2
        cost[1] = b[0] + c[0] + a[2] + b[2] + a[1] + c[1]; // B->0, C->2, G->1
        cost[2] = a[0] + c[0] + b[2] + c[2] + a[1] + b[1]; // B->1, C->0, G->2
        cost[3] = a[0] + b[0] + b[2] + c[2] + a[1] + c[1]; // B->2, C->0, G->1
        cost[4] = a[0] + c[0] + a[2] + b[2] + b[1] + c[1]; // B->1, C->2, G->0
        cost[5] = a[0] + b[0] + a[2] + c[2] + b[1] + c[1]; // B->2, C->1, G->0
        int min_cost = INT_MAX;
        int min_index = -1;
        for (int i = 0; i < 6; i++){
            if (cost[i] < min_cost){
                min_cost = cost[i];
                min_index = i;
            }
        }
        switch (min_index){
            case 0:
                cout << "BCG ";
                break;
            case 1:
                cout << "BGC ";
                break;
            case 2:
                cout << "CBG ";
                break;
            case 3:
                cout << "CGB ";
                break;
            case 4:
                cout << "GBC ";
                break;
            case 5:
                cout << "GCB ";
                break;
            }
        cout << min_cost << endl;
    }
    return 0;
}