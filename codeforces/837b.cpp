#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

bool check_ver(vector<string> flag){
    int n = flag.size();
    int m = flag[0].length();
    if (m % 3 != 0) return false;
    int width = m / 3;
    //check same
    char now_ch;
    now_ch = flag[0][0];
    for (int i = 0; i < n; i ++){
        for (int j = 0; j < width; j ++){
            if (flag[i][j] != now_ch) return false;
        }
    }
    now_ch = flag[0][width];
    for (int i = 0; i < n; i ++){
        for (int j =  width; j < width * 2; j ++){
            if (flag[i][j] != now_ch) return false;
        }
    }
    now_ch = flag[0][width*2];
    for (int i = 0; i < n; i ++){
        for (int j = width*2; j < width*3; j ++){
            if (flag[i][j] != now_ch) return false;
        }
    }
    if (flag[0][0] != flag[0][width]
        && flag[0][width] != flag[0][width*2]
        && flag[0][0] != flag[0][width*2]) return true;
    return false;
}
    
bool check_hoz(vector<string> flag){
    int n = flag.size();
    int m = flag[0].length();
    if (n % 3 != 0) return false;
    int width = n / 3;
    //check same
    char now_ch;
    now_ch = flag[0][0];
    for (int i = 0; i < width; i ++){
        for (int j = 0; j < m; j ++){
            if (flag[i][j] != now_ch) return false;
        }
    }
    now_ch = flag[width][0];
    for (int i = width; i < width*2; i ++){
        for (int j =  0; j < m; j ++){
            if (flag[i][j] != now_ch) return false;
        }
    }
    now_ch = flag[width*2][0];
    for (int i = width*2; i < n; i ++){
        for (int j = 0; j < m; j ++){
            if (flag[i][j] != now_ch) return false;
        }
    }
    if (flag[0][0] != flag[width][0]
        && flag[width][0] != flag[width*2][0]
        && flag[0][0] != flag[width*2][0]) return true;
    return false;
}

int main(){
    int n,m;
    cin >> n >> m;
    vector<string> flag(n);
    for (int i = 0; i < n; i ++) cin >> flag[i];
    int ret = false;
    if (check_ver(flag)) ret = true;
    else if (check_hoz(flag)) ret = true;
    if (ret) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}
