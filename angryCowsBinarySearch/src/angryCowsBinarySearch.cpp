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

int main() {
	int baleLocations, cowCount;
	cin >> baleLocations >> cowCount;
	vi bales(baleLocations);
	for (int i = 0; i < baleLocations; i++) {
		cin >> bales[i];
	}
	sort(bales.begin(),bales.end());
	int min = 0, max = 50000;
	while (min != max) {
		int mid = (min + max) / 2;
		int used = 0, last = 0;
		while (last < baleLocations) {
			int on = last + 1;
			while (bales[on] - bales[last] < mid * 2 && on < baleLocations) {
				on++;
			}
			used++;
			last = on;
		}
		if (used <= cowCount) {
			max = mid;
		} else {
			min = mid + 1;
		}
	}
	cout << min << endl;
}
