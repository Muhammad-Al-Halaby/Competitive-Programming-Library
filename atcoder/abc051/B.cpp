#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 2e5 + 9, M = 1e6, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;



ll power(ll b, ll p){
    if(p == 0)return 1;
    ll res = power(b,p/2);
    res *= res;
    res %= modulo;
    if(p & 1)res *= b;
    return res % modulo;
}


int main(){
    init();

    int k, s;    cin >> k >> s;

    int ans = 0;
    for(int i = 0;i <= k;i++){
        for(int j = 0;j <= k;j++){
            int u = s - i - j;
            if(u >= 0 && u <= k)    ans++;
        }
    }
    cout << ans;
}