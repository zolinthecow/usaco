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

int **memo;

vi tiles;
vii boots;

int calculate(int tileOn, int bootOn)
{
	int result = boots.size();
	if (memo[tileOn][bootOn] != -1) {
		return memo[tileOn][bootOn];
	}
	if (tileOn == (int)tiles.size()-1) {
		memo[tileOn][bootOn] = bootOn;
		result = bootOn;
	} else {
		for (int i = bootOn; i < (int)boots.size(); i++) {
			for (int k = 1; k <= boots[i].second; k++) {
				if (k + tileOn < (int)tiles.size()) {
					if (boots[i].first >= tiles[tileOn + k]) {
						memo[tileOn + k][i] = calculate(tileOn + k,i);
						result = min(result,memo[tileOn + k][i]);
					}
				}
			}
		}
	}
	return result;
}
int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("snowboots.in");
	fout.open("snowboots.out");
	int tileCount, bootCount;
	fin>>tileCount>>bootCount;
	memo = new int *[tileCount];
	for (int i = 0; i < tileCount; i++) {
		int temp;
		fin >> temp;
		tiles.pb(temp);
		memo[i] = new int [bootCount];
	}
	for (int i = 0; i < bootCount; i++) {
		ii temp;
		fin >> temp.first >> temp.second;
		boots.pb(temp);
	}
	for (int i = 0; i < tileCount; i++) {
		for (int j = 0; j < bootCount; j++) {
			memo[i][j] = -1;
		}
	}
	fout << calculate(0,0) << endl;
	fin.close();
	fout.close();
}
