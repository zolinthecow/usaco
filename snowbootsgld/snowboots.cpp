#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define LSOne(S) (S & (-S))

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 1e5 + 5, mxB = 1e5 + 5;

int N, B;
int tiles[mxN];
ii boots[mxB];

int nxt[mxN];
int prv[mxN];

int tilesOrd[mxN];
int bootsOrd[mxB];

bool tileSort(int a, int b) { return tiles[a] > tiles[b]; }

bool bootSort(int a, int b) { return boots[a].first > boots[b].first; }

int ans[mxN];

int main() {
	setIO("snowboots");
	cin >> N >> B;
	for (int i = 0; i < N; i++) {
		cin >> tiles[i];
		tilesOrd[i] = i;
		if (i > 0) prv[i] = i - 1;
		if (i < N - 1) nxt[i] = i + 1;
	}
	for (int i = 0; i < B; i++) {
		cin >> boots[i].first >> boots[i].second;
		bootsOrd[i] = i;
	}
	sort(tilesOrd, tilesOrd + N, tileSort);
	sort(bootsOrd, bootsOrd + B, bootSort);
	int maxDist = 0, j = 0;
	for (int i = 0; i < B; i++) {
		while (j < N && boots[bootsOrd[i]].first < tiles[tilesOrd[j]]) {
			prv[nxt[tilesOrd[j]]] = prv[tilesOrd[j]];
			nxt[prv[tilesOrd[j]]] = nxt[tilesOrd[j]];
			maxDist = max(maxDist, nxt[tilesOrd[j]] - prv[tilesOrd[j]]);
			j++;
		}
		if (maxDist <= boots[bootsOrd[i]].second) ans[bootsOrd[i]] = 1;
	}
	for (int i = 0; i < B; i++) cout << ans[i] << endl;
}
