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
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
}

const int N = 5005;
int n, dp[N][N];
string s;

int solve(int i = 0, int j = n - 1){
  	if(i > j)
      return 1;

    if(i == j)
        return dp[i][j] = 1;

    int &ret = dp[i][j];
    if(~ret)	return ret;

  	ret = 0;

	solve(i + 1, j);
	solve(i, j - 1);

  	return ret |= s[i] == s[j] && solve(i + 1, j - 1);
}

int valK[N];
int memo[N][N];
int calcK(int i, int j){
    if(i > j)
        return 0;

    int &ret = memo[i][j];
    if(~ret)    return ret;

    calcK(i + 1, j);
    calcK(i, j - 1);

    int k = 0;
    ret = 0;
    if(dp[i][j] == 1){
        ret = k = 1 + calcK(i, i + (j - i + 1) / 2 - 1);
        valK[1]++;
        valK[k+1]--;
    }
    return ret;
}

int main(){
  init();

  cin >> s;
  n = s.size();

  memset(dp, -1, sizeof dp);
  solve(0, n - 1);

  memset(memo, -1, sizeof memo);
  calcK(0, n - 1);
  partial_sum(valK, valK + N, valK);

  for(int i = 1;i <= n;i++)
    cout << valK[i] << " ";
}