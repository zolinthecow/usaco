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
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("convention.in");
	fout.open("convention.out");
	int cowAmount, busAmount, busCapacity;
	fin >> cowAmount >> busAmount >> busCapacity;
	vi arrivalTimes(cowAmount);
	for (int i = 0; i < cowAmount; i++) {
		fin >> arrivalTimes[i];
	}
	sort(arrivalTimes.begin(),arrivalTimes.end());
	int min = 0, max = arrivalTimes.back();
	while (min != max) {
		int mid = (min + max) / 2;
		bool cowLeft = false;
		int busOn = 0;
		int cowsUsed = 0;
		int firstCow = arrivalTimes[0];
		for (int i = 0; i < cowAmount; i++) {
			if (cowsUsed == busCapacity) {
				busOn++;
				cowsUsed = 0;
				firstCow = arrivalTimes[i];
			}
			if (arrivalTimes[i] > firstCow + mid) {
				busOn++;
				cowsUsed = 0;
				firstCow = arrivalTimes[i];
			}
			cowsUsed++;
			if (busOn == busAmount) {
				cowLeft = true;
				break;
			}
		}
		if (cowLeft) {
			min = mid + 1;
		} else {
			max = mid;
		}
	}
	fout << max << endl;
	fin.close();
	fout.close();
}
