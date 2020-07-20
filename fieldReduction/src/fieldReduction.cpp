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
using namespace std;
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vs vector<string>
#define ll long long
#define pb push_back

vi dfs_num;
const int VISITED = 1, UNVISITED = -1;

vector< pair<int,vi>  > AdjList;

vector<vi> sections;

bool waytosort(ii a, ii b) {
	return a.first < b.first;
}

void dfs(int u, int on) {
	dfs_num[u] = VISITED;
	if (AdjList[u].first == -1) {
		return;
	}
	sections[on].pb(u);
	for (int j = 0; j < (int)AdjList[u].second.size(); j++) {
		int v = AdjList[u].second[j];
		if (AdjList[v].first == -1) {
			continue;
		}
		if (dfs_num[v] == UNVISITED) {
			dfs(v,on);
		}
	}
}

void AdjListRemove(int remove) {
	AdjList[remove].second.clear();
	AdjList[remove].first = -1;
	for (int i = 0; i < (int)AdjList.size(); i++) {
		for (vi::iterator it = AdjList[i].second.begin(); it!= AdjList[i].second.end(); it++) {
			if (*it == remove) {
				AdjList[i].second.erase(it);
				break;
			}
		}
	}
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("closing.in");
	fout.open("closing.out");
	int barnsAmount, pathsAmount;
	fin >> barnsAmount >> pathsAmount;
	vii paths(pathsAmount);
	for (int i = 0; i < pathsAmount; i++) {
		fin >> paths[i].first >> paths[i].second;
		paths[i].first -= 1, paths[i].second -= 1;
	}
	sort(paths.begin(),paths.end(),waytosort);
	for (int i = 0; i < barnsAmount; i++) {
		vi temp;
		AdjList.pb(pair<int,vi>(i,temp));
	}
	for (int k = 0; k< pathsAmount; k++) {
		AdjList[paths[k].first].second.pb(paths[k].second);
		AdjList[paths[k].second].second.pb(paths[k].first);
	}
	for (int k = 0; k < barnsAmount; k++) {
		sections.clear();
		int remove;
		dfs_num.assign(AdjList.size(), UNVISITED);
		int on = 0;
		for (int i = 0; i < barnsAmount; i++) {
			if (dfs_num[i] == UNVISITED) {
				vi temp;
				sections.pb(temp);
				dfs(i,on);
				if (sections[on].size() == 0) {
					sections.erase(sections.begin() + on);
					on--;
				}
				on++;
			}
		}
		if ((int)sections.size() == 1) {
			fout << "YES" << endl;
		} else {
			fout << "NO" << endl;
		}
		fin >> remove;
		AdjListRemove(remove - 1);
	}
	fin.close();
	fout.close();
}
