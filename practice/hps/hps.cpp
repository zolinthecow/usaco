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

const int mxN = 1e5 + 5;
const int mxK = 2e1 + 5;

int N, K;
int gest[mxN];

//H0 P1 S2
int dp[mxN][mxK][3];

inline int win(int b, int f) {
    return (int) ((b == 0 && f == 2) || (b == 1 && f == 0) || (b == 2 && f == 1));
}

int calc() {
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= K; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][j][k] = dp[i - 1][j][k] + win(k, gest[i]);
                if (j > 0) {
                    for (int l = 0; l < 3; l++) {
                        if (l == k) continue;
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - 1][l] + win(k, gest[i]));
                    }
                }
            }
        }
    }
    return max(dp[N][K][0], max(dp[N][K][1], dp[N][K][2]));
}

int main () {
    setIO("hps");	
    cin >> N >> K;
    char g;
    for (int i = 1; i <= N; i++) {
        cin >> g;
        if (g == 'H') gest[i] = 0;
        else if (g == 'P') gest[i] = 1;
        else gest[i] = 2;
    }
    cout << calc() << "\n";
}
