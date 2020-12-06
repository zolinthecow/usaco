#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;

#define pb push_back
#define rsz resize
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()

#define mp make_pair

#define LSOne(S) (S & (-S))

const int INF = 1061109567;

void setIO(string name) {
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen((name+".in").c_str(), "r", stdin); 
    freopen((name+".out").c_str(), "w", stdout);
}

const int mxN = 1e3 + 5;

int N, M, C;
int moonies[mxN];
vi adjList[mxN];

int dp[mxN][mxN];

int calc() {
    for (int i = 2; i <= N; i++) {
        dp[0][i] = -INF;
    }
    for (int i = 1; i <= 1000; i++) {
        for (int j = 1; j <= N; j++) {
            for (auto v : adjList[j]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][v] + moonies[j]);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= 1000; i++) {
        ans = max(ans, (int) (dp[i][1] - C * pow(i, 2)));
    }
    return ans;
}

int main () {
    setIO("time");	
    cin >> N >> M >> C;
    for (int i = 1; i <= N; i++) cin >> moonies[i];
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        adjList[b].pb(a);
    }
    cout << calc() << "\n";
}
