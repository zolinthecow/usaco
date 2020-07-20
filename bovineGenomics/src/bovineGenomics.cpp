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

int spotty[500][50];
int plain[500][50];
bool position[64];
int cowCount, geneCount;

bool check(int pos1, int pos2, int pos3) {
	bool yes = true;
	for (int i = 0; i < cowCount; i++) {
		int temp1 = spotty[i][pos1] * 16;
		int temp2 = spotty[i][pos2] * 4;
		int temp3 = spotty[i][pos3];
		position[temp1 + temp2 + temp3] = true;
	}
	for (int i = 0; i < cowCount; i++) {
		int temp1 = plain[i][pos1] * 16;
		int temp2 = plain[i][pos2] * 4;
		int temp3 = plain[i][pos3];
		if (position[temp1 + temp2 + temp3]) {
			yes = false;
		}
	}
	for (int i = 0; i < 64; i++) {
		position[i] = false;
	}
	return yes;
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("cownomics.in");
	fout.open("cownomics.out");
	fin >> cowCount >> geneCount;
	for (int i = 0; i < cowCount; i++) {
		for (int j = 0; j < geneCount; j++) {
			char a;
			fin >> a;
			if (a == 'A') {
				spotty[i][j] = 0;
			} else if (a == 'C') {
				spotty[i][j] = 1;
			} else if (a == 'G') {
				spotty[i][j] = 2;
			} else if (a == 'T') {
				spotty[i][j] = 3;
			}
		}
	}
	for (int i = 0; i < cowCount; i++) {
		for (int j = 0; j < geneCount; j++) {
			char a;
			fin >> a;
			if (a == 'A') {
				plain[i][j] = 0;
			} else if (a == 'C') {
				plain[i][j] = 1;
			} else if (a == 'G') {
				plain[i][j] = 2;
			} else if (a == 'T') {
				plain[i][j] = 3;
			}
		}
	}
	int answer = 0;
	for (int i = 0; i < geneCount; i++) {
		for (int j = 0; j < geneCount && j != i; j++) {
			for (int k = 0; k < geneCount&& k != j; k++) {
				if (check(i,j,k)) {
					answer++;
				}
			}
		}
	}
	fout << answer << endl;
	fin.close();
	fout.close();
}
