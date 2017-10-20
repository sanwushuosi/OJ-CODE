#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
typedef long long ll;

int main(){
    ll n, s;
    cin >> n >> s;
    vector< pair<ll, ll> > data;
    ll result = 0;
    ll tots = 0;
    for (int i = 0; i < n; i ++){
        ll si, ai, bi;
        cin >> si >> ai >> bi;
        data.push_back(make_pair(ai - bi, si));
        result += bi * si;
        tots += si;
    }
    if (tots % s != 0){
        data.push_back(make_pair(0, s - tots % s));
    }
    sort(data.begin(), data.end());
    ll now_s = 0;
    ll temp_sum = 0;
    for (int i = 0; i < data.size(); i ++){
        ll di = data[i].first;
        ll si = data[i].second;
        //cout << "di = " << di << ", si = " << si <<
        //    ",now_s = " << now_s << ", temp_sum = " << temp_sum <<
        //    ", result = " << result << endl;
        if (now_s + si >= s){
            temp_sum += (s - now_s) * di;
            result = max(result, result + temp_sum);
            temp_sum = 0;
            si -= s - now_s;

            ll t = (ll)(si / s);
            result = max(result, result + t * s * di);
            now_s = si - s * t;
            temp_sum = now_s * di;
        }else{
            temp_sum += si * di;
            now_s += si;
        }
    }
    if (temp_sum > 0){
        result = max(result, result + temp_sum);
    }
    cout << result << endl;
    return 0;
}
