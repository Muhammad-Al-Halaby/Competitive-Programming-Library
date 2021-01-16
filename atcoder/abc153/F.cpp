#include <bits/stdc++.h>

using namespace std;

#define OnlineJudge1

#define loop(x,a,n) for(int x = a;x < n;x++)
#define NumofDigits(n) ((int)log10(n)+1)
#define CountofNumber(array,n,x)  (upper_bound(array, array+n, x)-lower_bound(array, array+n, x))
#define readline(s) getline(cin,s)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)
const long double PI = 3.141592653589793238L;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;
typedef pair<ll,ll> pll;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )

void init(){
    cin.tie(0);
    ios::sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

const int N = 2e5 + 9, M = 1e4 + 9, OO = 0x3f3f3f3f;
const ll llOO = 1e18;


ll cumu[N];

int main(){
    init();

    ll n, d, a; cin >> n >> d >> a;
    pll m[n];
    for(int i = 0;i < n;i++)    cin >> m[i].F >> m[i].S;

    sort(m, m + n);

    ll ans = 0;
    for(int i = 0;i < n;i++){
        if(i)   cumu[i] += cumu[i - 1];

        ll x = m[i].F + 2 * d;

        int l = i, r = n - 1;
        while(l <= r){
            int mid = (l + r) >> 1;
            if(m[mid].F <= x)   l = mid + 1;
            else r = mid - 1;
        }

        ll moves = max(0.0, ceil(1.0 * (m[i].S) / a) - cumu[i]);
        cumu[i] += moves;
        if(r + 1 < n)   cumu[r + 1] -= moves;

        ans += moves;

    }

    cout << ans;
}