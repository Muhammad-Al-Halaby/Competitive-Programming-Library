#include "bits/stdc++.h"

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define EPS 1e-9

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e6 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


void go(int tc = 0){

    int n, m;   cin >> n >> m;

    int ans = 0;
    for(int i = 0;i < n;i++){
        for(int j = 0;j < m;j++){
            char c; cin >> c;
            if(i == n - 1)  ans += (c == 'D');
            if(j == m - 1)  ans += (c == 'R');
        }
    }

    cout << ans << '\n';
}


int main(){
    init();

//    freopen("in.in", "r", stdin);
//    freopen("out.out", "w", stdout);

   int t = 1, tc = 1;
   cin >> t;
    while(t--)
        go(tc++);
}