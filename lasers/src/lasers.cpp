#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define ii pair<int, int>
#define dd pair<double, double>
#define vi vector<ll>
#define vd vector<double>
#define vii vector<ii>
#define vdd vector<dd>
#define vs vector<string>
#define ll long long
#define INF 1000000000
#define MOD 1000000007

struct point{
	int x, y, direc, dist;
};

bool pointComp(point a, point b) {
	return a.dist > b.dist;
}

inline bool impossible(point a, ii b) {
	if (a.direc == 0 && a.y > b.second) return true;
	if (a.direc == 1 && a.x > b.first) return true;
	if (a.direc == 2 && a.y < b.second) return true;
	if (a.direc == 3 && a.x < b.first) return true;
	return false;
}

int changeDirec(point a, ii b) {
	if (a.x == b.first) {
		if (a.y < b.second) return 0;
		if (a.y > b.second) return 2;
	} else {
		if (a.x < b.first) return 1;
		if (a.x > b.first) return 3;
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ifstream fin;
	ofstream fout;
	fin.open("lasers.in");
	fout.open("lasers.out");
	int N, lx, ly, bx, by;
	fin >> N >> lx >> ly >> bx >> by;
	ii laser = ii(lx, ly);
	ii barn = ii(bx, by);
	vii mirrors(N);
	map<int, vii> t1;
	vii t2;
	map<int, map<int, vii> > AdjListHor;
	map<int, map<int, vii>> AdjListVer;
	for (int i = 0; i < N; i++) {
		fin >> mirrors[i].first >> mirrors[i].second;
		if (AdjListVer.find(mirrors[i].first) == AdjListVer.end()) AdjListVer[mirrors[i].first] = t1;
		AdjListVer[mirrors[i].first][mirrors[i].second] = t2;
		if (AdjListHor.find(mirrors[i].second) == AdjListHor.end()) AdjListHor[mirrors[i].second] = t1;
		AdjListHor[mirrors[i].second][mirrors[i].first] = t2;
	}
	mirrors.pb(ii(lx, ly));
	if (AdjListVer.find(lx) == AdjListVer.end()) AdjListVer[lx] = t1;
	AdjListVer[lx][ly] = t2;
	if (AdjListHor.find(ly) == AdjListHor.end()) AdjListHor[ly] = t1;
	AdjListHor[ly][lx] = t2;
	mirrors.pb(ii(bx, by));
	if (AdjListVer.find(bx) == AdjListVer.end()) AdjListVer[bx] = t1;
	AdjListVer[bx][by] = t2;
	if (AdjListHor.find(by) == AdjListHor.end()) AdjListHor[by] = t1;
	AdjListHor[by][bx] = t2;
	for (int i = 0; i < N + 2; i++) {
		for (auto it : AdjListHor[mirrors[i].second]) {
			if (it.first == mirrors[i].first) continue;
			AdjListHor[mirrors[i].second][it.first].pb(mirrors[i]);
		}
		for (auto it : AdjListVer[mirrors[i].first]) {
			if (it.first == mirrors[i].second) continue;
			AdjListVer[mirrors[i].first][it.first].pb(mirrors[i]);
		}
	}
	map<ii, int> distUp;
	for (auto it : mirrors) {
		distUp[it] = INF;
	}
	distUp[laser] = 0;
	priority_queue< point, vector<point>, function<bool(point, point)> > pq(pointComp);
	point firstVer; firstVer.x = lx, firstVer.y = ly, firstVer.dist = 0, firstVer.direc = 0;
	pq.push(firstVer);
	firstVer.direc = 1;
	pq.push(firstVer);
	while (!pq.empty()) {
		point front = pq.top(); pq.pop();
		int d = front.dist;
		ii u = ii(front.x, front.y);
		if (d > distUp[u]) continue;
		for (auto it : AdjListVer[u.first][u.second]) {
			ii v = it;
			if (impossible(front, v)) continue;
			if (distUp[u] + (changeDirec(front, v) == front.direc ? 0 : 1) < distUp[v]) {
				distUp[v] = distUp[u] + (changeDirec(front, v) == front.direc ? 0 : 1);
				point temp; temp.x = v.first, temp.y = v.second, temp.direc = changeDirec(front, v), temp.dist = distUp[v];
				pq.push(temp);
			}
		}
		for (auto it : AdjListHor[u.second][u.first]) {
			ii v = it;
			if (impossible(front, v)) continue;
			if (distUp[u] + (changeDirec(front, v) == front.direc ? 0 : 1) < distUp[v]) {
				distUp[v] = distUp[u] + (changeDirec(front, v) == front.direc ? 0 : 1);
				point temp; temp.x = v.first, temp.y = v.second, temp.direc = changeDirec(front, v), temp.dist = distUp[v];
				pq.push(temp);
			}
		}
	}
	int ans = (distUp[barn] == INF) ? -1 : distUp[barn];
	fout << ans << endl;
	fin.close();
	fout.close();
}
