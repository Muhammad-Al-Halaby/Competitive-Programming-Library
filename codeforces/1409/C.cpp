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

const int N = 3e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


void go(int tc = 0){
    int n, x, y;    cin >> n >> x >> y;

    int mx = llOO, st, step;
    for(int s = 1;s <= min(x, y);s++){
        for(int d = 1;d <= abs(x - y);d++){
            int a = (x - s) / d, b = (y - s) / d;
            if((x - s) % d == 0 && (y - s) % d == 0 && a < n && b < n){
                if(s + (n - 1) * d < mx){
                    mx = s + (n - 1) * d;
                    st = s;
                    step = d;
                }
            }
        }
    }

    for(int i = 0;i < n;i++)
        cout << st + i * step << " ";
    cout << '\n';
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