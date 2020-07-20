#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ii pair<ll, ll>
#define dd pair<double, double>
#define vi vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vdd vector<dd>
#define vs vector<string>
#define ll long long
#define INF 10000000
#define MOD 10000000
#define LSOne(S) (S & (-S))

const int mxN = 100;

int grid[mxN][mxN];

vi rows[mxN];
vi cols[mxN];

int T, N;

int k, r, c;

set<int> seen;

int main() {
	cin >> T;
	for (int x = 1; x <= T; x++) {
		k = 0, r = 0, c = 0;
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> grid[i][j];
			}
		}
		for (int i = 0; i < N; i++) {
			rows[i].clear();
			cols[i].clear();
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				rows[i].pb(grid[i][j]);
				cols[j].pb(grid[i][j]);
			}
		}
		for (int i = 0; i < N; i++) {
			k += grid[i][i];
			seen.clear();
			for (auto it : rows[i]) seen.insert(it);
			if ((int) seen.size() != N) r++;
			seen.clear();
			for (auto it : cols[i]) seen.insert(it);
			if ((int) seen.size() != N) c++;
		}
		cout << "Case #" << x << ": " << k << " " << r << " " << c << "\n";
	}
}
