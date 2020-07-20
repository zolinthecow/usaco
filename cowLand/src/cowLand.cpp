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
#include <map>
#include <functional>
using namespace std;
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<int>
#define vs vector<string>
#define ll long long

vector< pair<int,vi> > AdjList;

int traverse(int ans, int on, int end, vector<bool> visited) {
	if (on == end) {
		return ans;
	} else {
		for (int i = 0; i < (int)AdjList[on].second.size(); i++) {
			if (!visited[AdjList[on].second[i]]) {
				visited[AdjList[on].second[i]] = true;
				ans = ans xor AdjList[on].first;
				traverse(ans, AdjList[on].second[i], end, visited);
			}
		}
	}
}

int main() {
	int N, Q;
	cin >> N >> Q;
	for (int i = 0 ; i < N; i++) {
		int a; vi temp;
		cin >> a;
		AdjList.pb(pair<int,vi>(a,temp));
	}
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a -= 1, b -= 1;
		AdjList[a].second.pb(b);
	}
	for (int i = 0; i < Q; i++) {
		int test, v1, v2;
		cin >> test >> v1 >> v2;
		if (test == 1) {
			AdjList[v1 - 1].first = v2;
		} else {
			v1 -= 1, v2 -= 1;
			vector<bool> visited(N,false);
			cout << traverse(AdjList[v1].first, v1, v2, visited) << endl;
		}
	}
}
