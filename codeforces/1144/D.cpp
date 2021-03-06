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
//#define modulo ll (1e9 + 7)
#define modulo ll (1e6 + 3)
const long double PI = 3.141592653589793238L;


typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<int,ll> pill;

#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)

#define time__(d) \
    for ( \
        auto blockTime = make_pair(chrono::high_resolution_clock::now(), true); \
        blockTime.second; \
        debug("%s: %lld ms\n", d, chrono::duration_cast<chrono::milliseconds>(chrono::high_resolution_clock::now() - blockTime.first).count()), blockTime.second = false \
    )

void init(){
    cin.tie(0);
    cin.sync_with_stdio(0);
#ifdef OnlineJudge
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
#endif
}

int fr[(int) 2e5 + 10];

int main(){
    init();
    int n, mxfreq = 0, idx;
    cin >> n;
    int arr[n],b[n];
    for(int i = 0;i < n;i++){
        cin >> arr[i];
        fr[arr[i]]++;
        if(fr[arr[i]] > mxfreq){
            mxfreq = fr[arr[i]];
            idx = i;
        }
    }

    vector<tuple<int,int,int>> v;
    for(int i = idx + 1;i < n;i++){
        if(arr[i] != arr[i - 1]){
            int op = (arr[i - 1] > arr[i])?1:2;
            v.push_back(make_tuple(op,i + 1, i));
            arr[i] = arr[idx];
        }
    }

    for(int i = idx - 1;i >= 0;i--){
        if(arr[i] != arr[i + 1]){
            int op = (arr[i + 1] > arr[i])?1:2;
            v.push_back(make_tuple(op,i + 1, i + 2));
            arr[i] = arr[idx];
        }
    }

    cout << v.size() << '\n';
    for(auto t : v){
        cout << get<0>(t) << " " << get<1>(t) << " " << get<2>(t) << '\n';
    }
}