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

const int mxN = 1e5 + 5, mxD = 1e9 + 5;

int N, D;
int bessieTastiness[2 * mxN], elsieTastiness[2 * mxN];

queue<int> q;
int d[2 * mxN];

struct besComp {
	bool operator() (int a, int b) const {
		return elsieTastiness[a] < elsieTastiness[b];
	}
};

struct elsComp {
	bool operator() (int a, int b) const {
		return bessieTastiness[a] < bessieTastiness[b];
	}
};

multiset<int, besComp> bes;
multiset<int, elsComp> els;

multiset<int, besComp>::iterator itB;
multiset<int, elsComp>::iterator itE;

int main() {
	setIO("piepie");
	memset(d, -1, sizeof(d));
	cin >> N >> D;
	for (int i = 0; i < 2 * N; i++) {
		cin >> bessieTastiness[i] >> elsieTastiness[i];
		bessieTastiness[i] = -bessieTastiness[i];
		elsieTastiness[i] = -elsieTastiness[i];
	}
	for (int i = 0; i < N; i++) {
		if (elsieTastiness[i] == 0) {
			q.push(i);
			d[i] = 1;
		} else {
			bes.insert(i);
		}
		if (bessieTastiness[i + N] == 0) {
			q.push(i + N);
			d[i + N] = 1;
		} else {
			els.insert(i + N);
		}
	}
	
	while (!q.empty()) {
		int u = q.front(); q.pop();
		if (u < N) {
			while (true) {
				itE = els.lower_bound(u);
				if (itE == els.end() || bessieTastiness[*itE] > bessieTastiness[u] + D) break;
				d[*itE] = d[u] + 1;
				q.push(*itE);
				els.erase(itE);
			}
		} else {
			while (true) {
				itB = bes.lower_bound(u);
				if (itB == bes.end() || elsieTastiness[*itB] > elsieTastiness[u] + D) break;
				d[*itB] = d[u] + 1;
				q.push(*itB);
				bes.erase(itB);
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		cout << d[i] << endl;
	}
}
