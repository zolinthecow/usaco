#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000
#define LSOne(S) (S & (-S))

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 5e2 + 5, mxM = 5e2 + 5;

int N, M;
string spotty[mxN];
string normal[mxN];

unsigned ll h1[mxN], h2[mxN], r[mxM];

int main() {
	setIO("cownomics");
	cin >> N >> M;
	for (int i = 0; i < N; i++) cin >> spotty[i];
	for (int i = 0; i < N; i++) cin >> normal[i];
	for (int i = 0; i < M; i++) r[i] = rand() % INF;
	int i = 0, j = 0;
	int best = M, dups = N;
	while (j < M) {
		if (dups == 0) best = min(best, j - i);
		if (dups > 0) {
			set<int> h;
			dups = 0;
			for (int k = 0; k < N; k++) h.insert(h1[k] += r[j] * spotty[k][j]);
			for (int k = 0; k < N; k++) if (h.count(h2[k] += r[j] * normal[k][j]) > 0) dups++;
			j++;
		} else {
			set<int> h;
			dups = 0;
			for (int k = 0; k < N; k++) h.insert(h1[k] -= r[i] * spotty[k][i]);
			for (int k = 0; k < N; k++) if (h.count(h2[k] -= r[i] * normal[k][i]) > 0) dups++;
			i++;
		}
	}
	cout << best << endl;
}
