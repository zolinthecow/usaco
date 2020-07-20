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

vector<vii> AdjList;

vi taken;
priority_queue<ii> pq;

void process(ll vtx) {
	taken[vtx] = 1;
	for (ll j = 0; j < (ll)AdjList[vtx].size(); j++) {
		ii v = AdjList[vtx][j];
		if (!taken[v.first]) pq.push(ii(-v.second, -v.first));
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream fin;
	ofstream fout;
	fin.open("fencedin.in");
	fout.open("fencedin.out");
	ll A, B, N, M;
	fin >> A >> B >> N >> M;
	vi vert(N + 2), hor(M + 2);
	vert[0] = 0, vert[N + 1] = A;
	hor[0] = 0, hor[M + 1] = B;
	for (ll i = 1; i <= N; i++) {
		fin >> vert[i];
	}
	for (ll i = 1; i <= M; i++) {
		fin >> hor[i];
	}
	sort(vert.begin(), vert.end());
	sort (hor.begin(), hor.end());
	AdjList.resize((N + 1) * (M + 1));
	for (ll i = 1; i < N + 2; i++) {
		ll width = vert[i] - vert[i - 1];
		for (ll j = 1; j < M + 2; j++) {
			ll height = hor[j] - hor[j - 1];
			ll on = (M + 1) * (i - 1) + j - 1;
			ll right = on + M + 1, up = on + 1;
			if (i != N + 1) {
				AdjList[on].pb(ii(right, height));
				AdjList[right].pb(ii(on, height));
			}
			if (j != M + 1) {
				AdjList[on].pb(ii(up, width));
				AdjList[up].pb(ii(on, width));
			}
		}
	}
	taken.assign((N + 1) * (M + 1), 0);
	process(0);
	ll mst_cost = 0;
	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		ll u = -front.second, w = -front.first;
		if (!taken[u]) {
			mst_cost += w, process(u);
		}
	}
	fout << mst_cost << endl;
	fin.close();
	fout.close();
}
