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

//x * n + y
bool **adjCell;
ii *cowPos;
bool *isCow;
bool **cowUsed;
bool *visited;

int calculate(int gridSize, int cowCount, ii cow) {
	int reachable = 0;
	queue<ii> visit;
	visit.push(cow);
	while (!visit.empty()) {
		ii cellOn = visit.front();
		visit.pop();
		if (visited[cellOn.first * gridSize + cellOn.second]) {
			continue;
		}
		visited[cellOn.first * gridSize + cellOn.second] = true;
		if (isCow[cellOn.first * gridSize + cellOn.second] && !cowUsed[cow.first * gridSize + cow.second][cellOn.first * gridSize + cellOn.second] && !cowUsed[cellOn.first * gridSize + cellOn.second][cow.first * gridSize + cow.second]) {
			cowUsed[cow.first * gridSize + cow.second][cellOn.first * gridSize + cellOn.second] = true;
			cowUsed[cellOn.first * gridSize + cellOn.second][cow.first * gridSize + cow.second] = true;
			reachable++;
		}
		if (cellOn.first + 1 < gridSize && !adjCell[cellOn.first * gridSize + cellOn.second][(cellOn.first + 1) * gridSize + cellOn.second]) {
			visit.push(ii(cellOn.first + 1,cellOn.second));
		}
		if (cellOn.first  - 1 >= 0 && !adjCell[cellOn.first * gridSize + cellOn.second][(cellOn.first - 1) * gridSize + cellOn.second]) {
			visit.push(ii(cellOn.first - 1,cellOn.second));
		}
		if (cellOn.second + 1 < gridSize && !adjCell[cellOn.first * gridSize + cellOn.second][(cellOn.first) * gridSize + cellOn.second + 1]) {
			visit.push(ii(cellOn.first,cellOn.second + 1));
		}
		if (cellOn.second - 1 >= 0 && !adjCell[cellOn.first * gridSize + cellOn.second][(cellOn.first) * gridSize + cellOn.second - 1]) {
			visit.push(ii(cellOn.first,cellOn.second - 1));
		}
	}
	return cowCount - 1 - reachable;
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("countcross.in");
	fout.open("countcross.out");

	int gridSize, cowCount, roadCount;
	fin >> gridSize >> cowCount >> roadCount;

	adjCell = new bool*[gridSize * gridSize];
	isCow = new bool[gridSize * gridSize];
	cowUsed = new bool*[gridSize * gridSize];
	cowPos = new ii[cowCount];
	visited = new bool[gridSize * gridSize];

	for (int i = 0; i < gridSize * gridSize; i++) {
		adjCell[i] = new bool[gridSize * gridSize];
		isCow[i] = false;
		cowUsed[i] = new bool[gridSize * gridSize];
		visited[i] = false;
		for (int j = 0; j < gridSize * gridSize; j++) {
			cowUsed[i][j] = false;
			adjCell[i][j] = false;
		}
	}

	for (int i = 0; i < roadCount; i++) {
		int cellx, celly, adjx, adjy;
		fin >> cellx >> celly >> adjx >> adjy;
		cellx -= 1, celly -= 1, adjx -= 1, adjy -= 1;
		adjCell[cellx * gridSize + celly][adjx * gridSize + adjy] = true;
		adjCell[adjx * gridSize + adjy][cellx * gridSize + celly] = true;
	}

	for (int i = 0; i < cowCount; i++) {
		int cowx, cowy;
		fin >> cowx >> cowy;
		cowx -= 1, cowy -= 1;
		isCow[cowx * gridSize + cowy] = true;
		cowPos[i] = ii(cowx,cowy);
	}
	int ans = 0;
	for (int i = 0; i < cowCount; i++) {
		ans += calculate(gridSize,cowCount,cowPos[i]);
		for (int j = 0; j < gridSize * gridSize; j++) {
			visited[j] = false;
		}
	}
	fout << ans << endl;
	fin.close();
	fout.close();
}
