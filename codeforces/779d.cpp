#include <cstdio>
#include <string>
#include <iostream>
#include <vector>

using namespace std;
string s1,s2;
int l1,l2;
vector<int> permu;

bool check(int x){
    string temp_s1 = s1;
    for (int i = 0; i < x; i ++) temp_s1[permu[i] - 1] = '-';
    string new_s1;
    for (int i = 0; i < l1; i ++){
        if (temp_s1[i] != '-') new_s1 += temp_s1[i];
    }
    int new_l = new_s1.length();
    int k = 0;
    for (int i = 0; i < new_l; i ++){
        if (new_s1[i] == s2[k]){
            k++;
            if (k >= l2) return true;
        }
    }
    return false;
}

int binary_search(int x, int y){
    if (y - x <= 1){
        if (check(y)) return y;
        else if (check(x)) return x;
        else return 0;
    }else{
        int mid = (x + y) / 2;
        if (check(mid)) return binary_search(mid, y);
        else return binary_search(x, mid - 1);
    }
    return 0;
}

int main(){
    //binary search result
    cin>>s1>>s2;
    l1 = s1.length();
    permu.resize(l1);
    for (int i = 0; i < l1; i ++) cin>>permu[i];
    l2 = s2.length();
    int ret = binary_search(0, l1 - l2);
    cout<<ret<<endl;
    return 0;
}
