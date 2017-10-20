#include <cstdio>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;
typedef long long ll;

int main(){
    int n;
    cin >> n;
    ll result = 0;
    priority_queue<ll> q;
    for (int i = 0; i < n; i ++){
        ll pi;
        cin >> pi;
        q.push(-pi);
        q.push(-pi);
        result += pi + q.top();
        q.pop();
    }
    cout << result << endl;
    return 0;
}


