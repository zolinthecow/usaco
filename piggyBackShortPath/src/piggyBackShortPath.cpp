#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;
#define INF 1000000000

vector<ll> shortestPath(ll st, vector<vector<ll> > E) {
	vector<ll> D(E.size(), INF);
	priority_queue<ll, vector<ll>, greater<ll> > Q;
	D[st] = 0;
	Q.push(st);
	while (!Q.empty()) {
		ll x = Q.top();
		Q.pop();
		for (ll y : E[x]) {
			if (D[y] > D[x] + 1) {
				D[y] = D[x] + 1;
				Q.push(y);
			}
		}
	}
	return D;
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("piggyback.in");
	fout.open("piggyback.out");
	ll bessieSpeed, elsieSpeed, piggySpeed, fieldCount, connectionsCount;
	fin >> bessieSpeed >> elsieSpeed >> piggySpeed >> fieldCount
			>> connectionsCount;
	vector<vector<ll> > fields(fieldCount, vector<ll>());
	for (ll i = 0; i < connectionsCount; i++) {
		ll x, y;
		fin >> x >> y;
		x--;
		y--;
		fields[x].push_back(y);
		fields[y].push_back(x);
	}
	vector<ll> bessie = shortestPath(0, fields);
	vector<ll> elsie = shortestPath(1, fields);
	vector<ll> last = shortestPath(fieldCount - 1, fields);
	ll answer = ll(1000) * 1000 * 1000 * 1000;
	for (ll meet = 0; meet < fieldCount; meet++) {
		answer = min(answer,
				bessie[meet] * bessieSpeed + elsie[meet] * elsieSpeed
						+ last[meet] * piggySpeed);
	}
	fout << answer << endl;
	fin.close();
	fout.close();
}
