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
    //freopen((name+".out").c_str(), "w", stdout);
}

const int mxN = 1e4 + 5, mxK = 1e3 + 5;

int N, K;
int cows[mxN];

int mxFrom[mxN][mxN];

int dp[mxN][mxK];
int mxDp[mxN];

int main () {
    setIO("teamwork");	
    cin >> N >> K;
    for (int i = 1; i <= N; i++) cin >> cows[i];
    for (int i = 0; i <= N; i++) {
        for (int j = max(i, 1); j <= N; j++) {
            mxFrom[i][j] = max(mxFrom[i][j - 1], cows[j]);
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K && j <= i; j++) {
            dp[i][j] = mxDp[i - j] + (i - j + 1) * mxFrom[i - j][i];
            mxDp[i] = max(mxDp[i], dp[i][j]);
        }
    }
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= K; j++) {
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << mxDp[N] << "\n";
}
