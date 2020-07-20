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
#define INF 1000000000
#define MOD 1000000007

ll **dp;

ll N, M;

struct node{
	ll to, cost, flow;
};

vector< vector<node> > AdjList;


ll minCost(ll on, ll flow, ll cost, vector<bool> visited) {
	ll ans = INF;
	if (dp[on][flow] != -1) return dp[on][flow];
	visited[on] = true;
	if (on == N - 1) {
		ans = cost;
	} else {
		for (ll j = 0; j < (ll)AdjList[on].size(); j++) {
			ll v = AdjList[on][j].to;
			if (visited[v]) continue;
			ll t = minCost(v, min(flow, AdjList[on][j].flow), cost + AdjList[on][j].cost, visited);
			ans = min(ans, t);
		}
	}
	dp[on][flow] = ans;
	return ans;
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("pump.in");
	fout.open("pump.out");
	fin >> N >> M;
	AdjList.resize(N);
	for (ll i = 0; i < M; i++) {
		ll a, b, c, f;
		fin >> a >> b >> c >> f;
		a -= 1; b -= 1;
		node toB; toB.to = b; toB.cost = c; toB.flow = f;
		node toA; toA.to = a; toA.cost = c; toA.flow = f;
		AdjList[a].pb(toB);
		AdjList[b].pb(toA);
	}
	dp = new ll*[N];
	for (ll i = 0; i < N; i++) {
		dp[i] = new ll[1001];
		for (ll j = 0; j < 1001; j++) {
			dp[i][j] = -1;
		}
	}
	vector<bool> visited(N, false);
	ll ans = minCost(0, 1000, 0, visited);
	ll realAns = -1;
	for (ll i = 1000; i >= 0; i--) {
		realAns = max(realAns, (i * 1000000) / dp[N][i]);
	}
	fout << realAns << endl;
	fin.close();
	fout.close();
}
