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

int main () {
	int N;
	cin >> N;
	vi heights(N);
	for (int i = 0; i < N; i++) cin >> heights[i];
	int ans = 0, minHeight;
	for (int i = 0; i < N; i++) {
		minHeight = INF;
		for (int j = i; j < N; j++) {
			minHeight = min(minHeight, heights[j]);
			ans = max(ans, minHeight * (j - i + 1));
			//cout << minHeight * (i - j + 1) << endl;
		}
	}
	cout << ans << endl;
}
