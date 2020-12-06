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

void clear(deque<int>* q) {
    while ((int) q -> size()) q -> pop_front();
}

const int mxN = 1.5e3 + 5;

int M, N, K;
int grid[mxN][mxN];

int pref[mxN];

int ans = 0;

void calcPref(int m, int n) {
    int row, sum;
    deque<int> q;
    for (int i = 0; i <= m - K; i++) {
        clear(&(q));
        sum = 0;
        for (int j = 0; j < K; j++) {
            row = 0;
            for (int l = 0; l < K; l++) {
                row += grid[i + l][j];
            }
            q.pb(row);
            sum += row;
        }
        pref[i] = sum;
        for (int j = K; j < n; j++) {
            row = 0;
            sum -= q.front();
            q.pop_front();
            for (int l = 0; l < K; l++) {
                row += grid[i + l][j];
            }
            q.pb(row);
            sum += row;
            pref[i] = max(pref[i], sum);
        }
        cout << endl;
    }
}

void calcAns(int m, int n) {
    int f, s, t;
    for (int i = K * 2; i < m; i++) {
        f = pref[i];
        t = 0;
        for (int j = K; j < i - K; j++) {
            s = pref[j];
            t = max(t, pref[j - K]);
            ans = max(ans, f + s + t);
        }
    }
}

int main () {
    setIO("diggingForOil");	
    cin >> M >> N >> K;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            cin >> grid[i][j];
        }
    }    
    calcPref(M, N);

}
