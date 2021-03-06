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

const int N = 1e5 + 9, M = 1e6 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;

int main(){
    init();

    int t;  cin >> t;
    while(t--){
        int n;  cin >> n;

        int total = n, freq[n + 1] = {0}, ans = 0;
        for(int i = 0;i < n;i++){
            int x;  cin >> x;
            freq[x]++;
        }


        int rem = 0;
        for(int i = 1;i <= n;i++){
            int g = freq[i] / i;
            ans += g;

            rem += freq[i] % i;
            
                g = rem / i;
                ans += g;
                rem -= g * i;
            
        }

        cout << ans << '\n';
    }

}
