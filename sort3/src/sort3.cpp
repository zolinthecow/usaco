/*
ID: colinzh3
PROG: sort3
LANG: C++
 */
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

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("sort3.in");
	fout.open("sort3.out");
	vector<int> d;
	int n; fin >> n;
	for (int i = 0; i < n; ++i) {
		int num; fin >> num;
		d.push_back(num);
	}

	vector<int> sorted = d;
	sort(sorted.begin(), sorted.end());

	int times = 0;
	int index = 0;

	for (int i = 0; i < n; ++i) {
		if (sorted[i] != d[i]) {
			for (int j = i + 1; j < n; ++j) {
				if (d[j] == sorted[i] && sorted[j] == d[i]) {
					times++;
					swap(d[i], d[j]);
					break;
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		if (sorted[i] != d[i] && d[i] == 1) {
			times += 2;
		}
	}

	fout << times << endl;
	fin.close();
	fout.close();
}
