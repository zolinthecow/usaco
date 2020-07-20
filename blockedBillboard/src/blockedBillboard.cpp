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

int board[2000][2000];

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("billboard.in");
	fout.open("billboard.out");
	int b1lx,b1ly,b1rx,b1ry;
	fin >> b1lx >> b1ly >> b1rx >> b1ry;
	int b2lx,b2ly,b2rx,b2ry;
	fin >> b2lx >> b2ly >> b2rx >> b2ry;
	int tlx,tly,trx,ttry;
	fin >> tlx >> tly >> trx >> ttry;
	b1lx += 1000, b1ly += 1000, b1rx += 1000, b1ry += 1000;
	b2lx += 1000, b2ly += 1000, b2rx += 1000, b2ry += 1000;
	tlx += 1000, tly += 1000, trx += 1000, ttry += 1000;
	for (int i = b1lx; i < b1rx; i++) {
		for (int j = b1ly; j < b1ry; j++) {
			board[i][j] = 1;
		}
	}
	for (int i = b2lx; i < b2rx; i++) {
		for (int j = b2ly; j < b2ry; j++) {
			board[i][j] = 1;
		}
	}
	for (int i = tlx; i < trx; i++) {
		for (int j = tly; j < ttry; j++) {
			board[i][j] = 2;
		}
	}
	int answer = 0;
	for (int i = 0; i < 2000; i++) {
		for (int j = 0; j < 2000; j++) {
			if (board[i][j] == 1) {
				answer++;
			}
		}
	}
	fout << answer << endl;
	fin.close();
	fout.close();
}
