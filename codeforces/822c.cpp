#include <cstdio>
#include <vector>
#include <unordered_map>
#include <iostream>
#include <algorithm>

using namespace std;

struct data{
    int l,r,c;
    int min_c;
};

unordered_map<int, vector<data>> bucket;
int n, x;

bool my_cmp(data x, data y){
    if (x.r <= y.r) return true;
    return false;
}

int find_min(vector<data> vec, data d){
    int l = vec.size();
    if (d.l <= vec[l - 1].r) return -1;
    else{
        data temp_d = d;
        temp_d.l = d.r;temp_d.r = d.l;
        int index = upper_bound(vec.begin(), vec.end(), temp_d, my_cmp);
        if (vec[index].r == d.l) index++;
        return vec[index].min_c;
    }
}

int traverse_vector(vector<data> vec){
    int ret = -1;
    int l = vec.size();
    for (int i = 0; i < l; i ++){
        data d = vec[i];
        int v1 = d.r - d.l + 1;
        int cost1 = d.c;
        int v2 = x - v1;
        if (bucket.find(v2) != bucket.end()){
            int temp = find_min(bucket[v2], d);
            if (temp != -1){
                if (ret == -1 || temp + cost1 < ret) ret = temp + cost1;
            }
        }
    }
    return ret;
}

int main(){
    bucket.clear();
    cin >> n >> x;
    for (int i = 0; i < n; i ++){
        data d;
        cin >> d.l >> d.r >> d.c;
        d.min_c = d.c;
        bucket[d.r - d.l + 1].push_back(d);
    }
    unordered_map<int, vector<data>>::iterator *it;
    for (it = bucket.begin(); it != bucket.end(); it++){
        sort_vector(*it);
        minimize_vector(*it);
    }
    int ret = -1;
    for (it = bucket.begin(); it != bucket.end(); it++){
        int temp = traverse_vector(*it);
        if (temp != -1){
            if (ret == -1 || temp < ret) ret = temp;
        }
    }
    cout << ret << endl;
    return 0;
}
