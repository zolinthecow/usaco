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

const int mxN = 2e2 + 5;

int N, M;
int grid[mxN][mxN];

bool possible[mxN][mxN][mxN];

int edge[mxN][mxN];

int main () {
    setIO("fortmoo");	
    cin >> N >> M;
    char on;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> on;
            if (on == '.') grid[i][j] = 1;
        }
    }
    for (int k = 0; k < M; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (i == j) {
                    possible[k][i][j] = (bool) grid[i][k];
                    continue;
                }
                possible[k][i][j] = possible[k][i][j - 1] && grid[j][k];
            }
        }
    }
    int ans = 0;
    for (int k = 0; k < M; k++) {
        for (int i = 0; i < N; i++) {
            for (int j = i; j < N; j++) {
                if (grid[i][k] && grid[j][k]) {
                    if (edge[i][j] == 0) {
                        if (!possible[k][i][j]) {
                            continue;
                        }
                    }
                    edge[i][j] += j - i + 1;
                    if (possible[k][i][j]) {
                        ans = max(ans, edge[i][j]);
                    } 
                } else {
                    edge[i][j] = 0;
                }
            }
        }
    }
    cout << ans << endl;
}
