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

int dr[] = {1,0,-1,0};
int dc[] = {0,1,0,-1};

char grid[1000][1000];
int visited[1000][1000];

int size;

ii floodfill(int r, int c) {
	if (r < 0 || r >= size || c < 0 || c >= size) return ii(0,0);
	if (visited[r][c] == 1 || grid[r][c] == '.') return ii(0,0);
	ii ans = ii(1,0);
	visited[r][c] = 1;
	for (int i = 0; i < 4; i++) {
		int nR = r + dr[i], nC = c + dc[i];
		if (nR < 0 || nR >= size || nC < 0 || nC >= size) {
			ans.second++;
			continue;
		}
		if (grid[nR][nC] == '.') ans.second++;
	}
	for (int i = 0; i < 4; i++) {
		ii newAns = floodfill(r + dr[i], c + dc[i]);
		ans.first += newAns.first, ans.second += newAns.second;
	}
	return ans;
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("perimeter.in");
	fout.open("perimeter.out");
	fin >> size;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			fin >> grid[i][j];
		}
	}
	ii ans = ii(0,0);
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++) {
			ii nAns = floodfill(i,j);
			if (nAns.first > ans.first) ans = nAns;
			if (nAns.first == ans.first) {
				if (nAns.second < ans.second) ans = nAns;
			}
		}
	}
	fout << ans.first << " " << ans.second << endl;
	fin.close();
	fout.close();
}
