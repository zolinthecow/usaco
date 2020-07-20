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

int fieldAmount;
vector< vi > AdjList;
vector< vi > nearlyAdjacent;
vi colors;

/*int solve() {
	int answer = 0;
	for (int i = 0; i < fieldAmount; i++) {
		int colorToUse = 1;
		int greatestColor = 0;
		for (int j = 0; j < (int)nearlyAdjacent[i].size(); j++) {
			if (colors[nearlyAdjacent[i][j]] == colorToUse) {
				colorToUse++;
			}
			greatestColor = max(greatestColor,colors[nearlyAdjacent[i][j]]);
		}
		if (colorToUse > greatestColor) {
			answer++;
		}
		colors[i] = colorToUse;
	}
	return answer;
}*/

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("planting.in");
	fout.open("planting.out");
	fin >> fieldAmount;
	AdjList.resize(fieldAmount);
	colors.resize(fieldAmount,0);
	nearlyAdjacent.resize(fieldAmount);
	for (int i = 0; i < fieldAmount - 1; i++) {
		int a, b;
		fin >> a >> b;
		a -= 1, b -= 1;
		AdjList[a].pb(b);
		AdjList[b].pb(a);
	}
	int ans = 0;
	/*for (int i = 0; i < fieldAmount; i++) {
		nearlyAdjacent[i].insert(end(nearlyAdjacent[i]),begin(AdjList[i]),end(AdjList[i]));
		for (int j = 0; j < (int)AdjList.size(); j++) {
			nearlyAdjacent[i].insert(end(nearlyAdjacent[i]),begin(AdjList[AdjList[i][j]]),end(AdjList[AdjList[i][j]]));
		}
		sort(nearlyAdjacent[i].begin(), nearlyAdjacent[i].end());
		nearlyAdjacent[i].erase(unique(nearlyAdjacent[i].begin(),nearlyAdjacent[i].end()),nearlyAdjacent[i].end());
		ans = max(ans,(int)nearlyAdjacent[i].size() - 1);
	}*/
	for (int i = 0; i < fieldAmount; i++) {
		ans = max(ans,(int)AdjList[i].size() + 1);
	}
	fout << ans << endl;
	fin.close();
	fout.close();
}
