#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define vi vector<int>
#define ii pair<int, int>
#define vii vector<ii>
#define pb push_back
#define INF 2000000000
#define line pair<int, bool>

void setIO(string s) {
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen((s + ".in").c_str(), "r", stdin);
	freopen((s + ".out").c_str(), "w", stdout);
}

const int mxN = 1e5 + 5;

int N;
ii start, barn;

map<int, vi> sameX;
map<int, vi> sameY;

vector<vi> adjList;

int main() {
	setIO("lasers");
	cin >> N;
	cin >> start.first >> start.second;
	cin >> barn.first >> barn.second;
	int x, y;
	for (int i = 0; i < N; i++) {
		cin >> x >> y;
		sameX[x].pb(y);
		sameY[y].pb(x);
	}
	line startX(start.first, false);
	line startY(start.second, true);
	map<line, int> dist;
	dist[startX] = 0;
	dist[startY] = 0;
	queue<line> q;
	q.push(startX);
	q.push(startY);
	int ans = -1;
	while (!q.empty()) {
		line u = q.front(); q.pop();
		if (u.second && u.first == barn.second) {
			ans = dist[u];
			break;
		}
		if (!u.second && u.first == barn.first) {
			ans = dist[u];
			break;
		}
		map<int, vi> source = u.second ? sameY : sameX;
		if (source.find(u.first) != source.end()) {
			for (auto next : source[u.first]) {
				line nextLine(next, !u.second);
				if (dist.find(nextLine) == dist.end()) {
					dist[nextLine] = dist[u] + 1;
					q.push(nextLine);
				}
			}
		}
	}
	cout << ans << endl;
}
