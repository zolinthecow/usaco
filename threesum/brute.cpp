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

const ll mxN = 5e3;

ll N, Q;
ll A[mxN + 1];

int main() {
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) cin >> A[i];
	int a, b, ans;
	while (Q--) {
		ans = 0;
		cin >> a >> b;
		for (int i = a; i <= b; i++) {
			for (int j = i + 1; j <= b; j++) {
				for (int k = j + 1; k <= b; k++) {
					if (A[i] + A[j] + A[k] == 0) ans++;
				}
			}
		}
		cout << ans << endl;
	}
}
