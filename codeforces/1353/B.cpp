#include <bits/stdc++.h>

using namespace std;

#define F first
#define S second
#define modulo ll (1e9 + 7)
#define neig(a, u, e, v) for(int v, e = (a).head[u] ; ~e and (v = (a).to[e], 1) ; e = (a).nxt[e])

typedef long long ll;
typedef pair<int,int> pii;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
}

const int N = 1e5 + 9, M = 4e5 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        int n, k;   cin >> n >> k;

        int a[n], b[n];
        for(int i = 0;i < n;i++)    cin >> a[i];
        for(int i = 0;i < n;i++)    cin >> b[i];

        sort(a, a + n);
        sort(b, b + n);

        ll sum = accumulate(a, a + n, 0ll);

        int l = 0, r = n - 1;
        while(k && l < n && r >= 0 && a[l] < b[r]){
            sum -= a[l++];
            sum += b[r--];
            k--;
        }

        cout << sum << '\n';
    }

}
