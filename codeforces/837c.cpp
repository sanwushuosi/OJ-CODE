#include <cstdio>
#include <vector>
#include <iostream>

using namespace std;

bool check_one(int a, int b, int x1, int y1, int x2, int y2){
    if (x1 > a || x2 > a || y1 > b || y2 > b) return false;
    if (x1 + x2 > a && y1 + y2 > b) return false;
    return true;
}

bool check(int a, int b, pair<int, int> s1, pair<int, int> s2){
    if (check_one(a, b, s1.first, s1.second, s2.first, s2.second)) return true;
    if (check_one(a, b, s1.first, s1.second, s2.second, s2.first)) return true;
    if (check_one(a, b, s1.second, s1.first, s2.first, s2.second)) return true;
    if (check_one(a, b, s1.second, s1.first, s2.second, s2.first)) return true;
    return false;
}

int main(){
    int n,a,b;
    cin >> n >> a >> b;
    vector< pair< int, int> > seals(n);
    for (int i = 0; i < n; i++){
        cin >> seals[i].first >> seals[i].second;
    }
    int ret = 0;
    for (int i = 0; i < n; i ++){
        for (int j = i + 1; j < n; j ++){
            if (check(a, b, seals[i], seals[j])){
                int area = seals[i].first * seals[i].second + seals[j].first * seals[j].second;
                if (area > ret) ret = area;
            }
        }
    }
    cout << ret << endl;
    return 0;
}
