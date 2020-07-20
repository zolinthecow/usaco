#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<ll>
#define ii pair<ll, ll>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 1e3 + 5;

int N;
ii coords[mxN];

vector< vii > adjList;

inline int sqDist(ii a, ii b) {
	return pow(a.first - b.first, 2) + pow(a.second - b.second, 2);
}

int calculate(int on, int maxDist, int visited, int p) {
	if (visited == N - 1) {
		return maxDist;
	} else {
		for (auto it : adjList[i]) {
			
		}
	}
}

int main() {
	//setIO("moocast");
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> coords[i].first >> coords[i].second;
	}
	adjList.resize(N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == j) continue;
			adjList[i].pb(ii(j, sqDist(coords[i], coords[j])));
		}
	}
	
}
