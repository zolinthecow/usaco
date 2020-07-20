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
#define vii vector<ii>
#define vs vector<string>
#define ll long long

vi dfsVisited;
vector<vii> AdjList;
int ans;

void dfs(int u, int relevence, int k) {
	dfsVisited[u] = 1;
	for (int j = 0; j < (int)AdjList[u].size(); j++) {
		ii v = AdjList[u][j];
		int newRelevence = min(relevence,v.second);
		if (dfsVisited[v.first] == 0 && newRelevence >= k) {
			ans++;
			dfs(v.first,newRelevence,k);
		}
	}
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("mootube.in");
	fout.open("mootube.out");
	int videosAmount, questionsAmount;
	fin >> videosAmount >> questionsAmount;
	AdjList.resize(videosAmount);
	for (int i = 0; i < videosAmount - 1; i++) {
		int  p; ii qr;
		fin >> p >> qr.first >> qr.second;
		qr.first -= 1, qr.second -= 1; p -= 1;
		AdjList[p ].pb(qr);
		AdjList[qr.first].pb(ii(p,qr.second));
	}
	vii questions;
	for (int i = 0; i < questionsAmount; i++) {
		ii kv;
		fin >> kv.first >> kv.second;
		kv.first -= 1, kv.second -= 1;
		questions.pb(kv);
	}
	for (int i = 0; i < videosAmount; i++) {
		dfsVisited.pb(0);
	}
	for (int i = 0; i < questionsAmount; i++) {
		ans = 0;
		dfs(questions[i].second,1000000,questions[i].first);
		for (int j = 0; j < videosAmount; j++) {
			dfsVisited[j] = 0;
		}
		fout << ans << endl;
	}
	fin.close();
	fout.close();
}
