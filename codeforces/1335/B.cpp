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

const int N = 50, M = 500, OO = 0x3f3f3f3f;
const ll llOO = 0x3f3f3f3f3f3f3f3f;



int main(){
    init();

    int t;  cin >> t;
    while(t--){
        int n, a, b;    cin >> n >> a >> b;
        for(int i = 0;i < n;i++)
            cout << char('a' + (i % b));
            cout << '\n';
    }
}