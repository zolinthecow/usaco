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
	//freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 1e2 + 5;
const int mxK = 7 + 5;

int N, K;
int cows[mxN];

vector<vi> perms;

int main() {
	//setIO("cbarn2");
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> cows[i];
	}
	vi empty;
	queue<vi> q;
	q.push(empty);
	while(q.size()) {
		vi u = q.front(); q.pop();
		for (int i = 0; i < N; i++) {
			if (find(u.begin(), u.end(), i) != u.end() ||
				(u.size() && i < u[u.size() - 1])) continue;
			u.pb(i);
			if ((int) u.size() == K) {
				u.pb(u[0] + N);
				perms.pb(u);
				u.pop_back();
				u.pop_back();
				continue;
			}
			q.push(u);
			u.pop_back();
		}
	}
	int ans = INF;
	for (auto perm : perms) {
		int res = 0;
		for (int i = 0; i < K; i++) {
			int on = perm[i];
			for (int j = 0; j < perm[i + 1] - perm[i]; j++) {
				res += j * cows[on];
				on++;
				if (on == N) on = 0;
			}
		}
		ans = min(ans, res);
	}
	cout << ans << endl;
}
