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

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("mroute.in");
	fout.open("mroute.out");
	int junctionPoints, pipeCount, milkCount;
	fin >> junctionPoints >> pipeCount >> milkCount;
	vector< pair<int,vi> > pipes;
	for (int i = 0; i < pipeCount; i++) {
		int pipeStart, pipeEnd, pipeLatency, pipeCapacity;
		fin >> pipeStart >> pipeEnd >> pipeLatency >> pipeCapacity;
		pipes.pb(pair<int,vi>(min(pipeStart,pipeEnd),{max(pipeStart,pipeEnd),pipeLatency,pipeCapacity}));
	}
	sort(pipes.begin(),pipes.end());
	vector< vi > AdjList;
	for (int i = 0; i < pipeCount; i++) {
		vi adjTo;
		for (int j = 0; j < pipeCount; j++) {
			if (pipes[j].first == pipes[i].second[0]) {
				adjTo.pb(j);
			}
		}
		AdjList.pb(adjTo);
	}
	int ans = 1000001;
	for (int i = 0; i < pipeCount; i++) {
		if (pipes[i].first != 1) {
			continue;
		}
		vi dist(junctionPoints, 1000001);
		dist[0] = 0;
		priority_queue< int, vi, greater<int> > pq;
		pq.push(0);
		int totalLatency = pipes[i].second[1];
		int minCapacity = pipes[i].second[2];
		while (!pq.empty()) {
			int front = pq.top();
			pq.pop();
			if (front > dist[front]) {
				continue;
			}
			for (int j = 0; j < (int)AdjList[front].size(); j++) {
				int v = AdjList[front][j];
				if (totalLatency + pipes[v].second[1] + milkCount/min(minCapacity,pipes[v].second[2]) < dist[v]) {
					totalLatency += pipes[v].second[1];
					minCapacity = min(minCapacity,pipes[v].second[2]);
					dist[v] = totalLatency + milkCount/minCapacity;
					pq.push(dist[v]);
				}
			}
		}
		ans = min(ans,dist[junctionPoints - 1]);
	}
	fout << ans << endl;
	fin.close();
	fout.close();
}
