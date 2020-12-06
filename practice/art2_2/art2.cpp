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

int N;
int paint[mxN];

int times[mxN];

bool seen[mxN], popped[mxN];
vi s;

int main () {
	setIO("art2");
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> paint[i];
		times[paint[i]]++;
	}
	int next, pop;
	int ans = 0;
	for (int i = 0; i < N; i++) {
		pop = -1;
		next = paint[i];
		if (next == 0) {
			while (s.size()) {
				popped[s.back()] = true;
				s.pop_back();
			}
			continue;
		}
		if (!seen[next]) {
			s.pb(next);
			seen[next] = true;
		}
		if (seen[next] || times[next] == 1) {
			ans = max(ans, sz(s));
			if (popped[next]) {
				cout << -1 << endl;
				return 0;
			}
			while (s.size() && pop != next) {
				pop = s.back();
				popped[pop] = true;
				s.pop_back();
			}
		}
		cout << endl;
	}
	cout << ans << endl;
}
