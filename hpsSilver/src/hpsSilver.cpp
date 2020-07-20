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

struct moveType {
	int h, p, s;
};
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("hps.in");
	fout.open("hps.out");
	int moveCount;
	fin >> moveCount;
	vs moves(moveCount);
	for (int i = 0; i < moveCount; i++) {
		fin >> moves[i];
	}
	vector<moveType> stepMoves;
	for (int i = 0; i < moveCount; i++) {
		moveType temp;
		if (i == 0) {
			temp.h = 0, temp.p = 0, temp.s = 0;
		} else {
			temp = stepMoves[i - 1];
		}
		if (moves[i] == "H") {
			temp.h += 1;
		} else if (moves[i] == "P") {
			temp.p += 1;
		} else {
			temp.s += 1;
		}
		stepMoves.pb(temp);
	}
	int answer = 0;
	for (int i = 1; i <= moveCount; i++) {
		int won = max(stepMoves[i - 1].h,stepMoves[i - 1].p);
		won = max(won, stepMoves[i - 1].s);
		int used;
		if (won == stepMoves[i - 1].h) {
			used = 1;
		} else if (won == stepMoves[i - 1].p) {
			used = 2;
		} else {
			used = 3;
		}
		moveType rest;
		rest.h = stepMoves.back().h - stepMoves[i - 1].h;
		rest.p = stepMoves.back().p - stepMoves[i - 1].p;
		rest.s = stepMoves.back().s - stepMoves[i - 1].s;
		if (used == 1) {
			won += max(rest.p,rest.s);
		} else if (used == 2) {
			won += max(rest.h,rest.s);
		} else {
			won += max(rest.h, rest.p);
		}
		answer = max(answer, won);
	}
	fout << answer << endl;
	fin.close();
	fout.close();
}
