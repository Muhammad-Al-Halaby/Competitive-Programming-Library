#include <bits/stdc++.h>
using namespace std;

#define OnlineJudge1

#define loop(a,n) for(int i = a;i<n;i++)
#define NumofDigits(n) ((int)log10(n)+1)
#define CountofNumber(array,n,x)  (upper_bound(array, array+n, x)-lower_bound(array, array+n, x))
#define readline(s) getline(cin,s)
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define EPS 1e-7
#define modulo ll (1e9 + 7)


typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

int main(){
    init();

    int n, k;
    cin >> n >> k;

    int a[n], b[n];
    for(int i = 0;i < n;i++)
        cin >> a[i];
    for(int i = 0;i < n;i++)
        cin >> b[i];


    auto check = [&](ll cookies){
        ll total = k;
        for(int i = 0;i < n;i++){
            ll need = (ll)a[i] * cookies - b[i];
            if(need >= 0)
                total -= abs(need);
            if(total < 0)
                return false;
        }
        return (total >= 0);
    };
    ll l = 0, r = 3e9;
    while(l <= r){
        ll mid = (l + r) >> 1;
        if(check(mid))l = mid + 1;
        else r = mid - 1;
    }
    cout << l - 1;
}