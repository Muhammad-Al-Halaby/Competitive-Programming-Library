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

const int N = 109, M = 2e3 + 9, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;


int main(){
    init();

    int n, x = 0;  cin >> n;
    string s;   cin >> s;
    int ans = 0;
    for(int i = 0;i < n;i++){
        if(s[i] == 'I') x++;
        else x--;

        ans = max(ans, x);
    }

    cout << ans;

}