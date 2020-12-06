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

const int mxN = 1e5 + 5;

int N, M;
int flavor[mxN], spicy[mxN];

int main () {
    //setIO("hayfeast");	
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> flavor[i] >> spicy[i];
	int ans = INF;
	for (int i = 0; i < N; i++) {
		for (int j = i; j < N; j++) {
			int sum = 0, maxSpicy = 0;
			for (int k = i; k <= j; k++) {
				sum += flavor[k];
				maxSpicy = max(maxSpicy, spicy[k]);
			}
			if (sum >= M) ans = min(ans, maxSpicy);
		}
	}
	cout << ans << '\n';
}
