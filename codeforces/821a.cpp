#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

class Solution{
    public:
    bool check_all(vector< vector<int> > arr){
        int l = arr.size();
        if (l <= 0) return true;
        if (l != arr[0].size()) return false;
        for (int i = 0; i < l; i ++){
            for (int j = 0; j < l; j ++){
                if (arr[i][j] != 1){
                    if (!check_one(arr, i, j)) return false;
                }
            }
        }
        return true;
    }
    private:
    bool check_one(vector< vector<int> > arr, int x, int y){
        int l = arr.size();
        for (int i = 0; i < l; i ++){
            for (int j = 0; j < l; j ++){
                if (arr[x][i] + arr[j][y] == arr[x][y]) return true;
            }
        }
        return false;
    }
};

int main(){
    int n;
    cin >> n;
    vector< vector<int> > sz(n, vector<int>(n));
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < n; j ++){
            cin >> sz[i][j];
        }
    }
    Solution sol;
    if (sol.check_all(sz)) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
