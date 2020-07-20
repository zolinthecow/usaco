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

vi calculateSmallCase (vi diamonds, int minimumSizeDifference) {
	vi diamondAmounts(diamonds.size());
	int j = 0;
	for (int i = 0; i < (int)diamonds.size(); i++) {
		while (j < (int)diamonds.size() && diamonds[i] - diamonds[j] > minimumSizeDifference) {
			j++;
		}
		diamondAmounts[i] = j;
	}
	return diamondAmounts;
}
vi calculateLargeCase (vi diamonds, int minimumSizeDifference) {
	vi diamondAmounts(diamonds.size());
	int j = diamonds.size() - 1;
	for (int i = (int)diamonds.size() - 1; i >= 0; i--) {
		while (j >= 0 && diamonds[j] - diamonds[i] > minimumSizeDifference) {
			j--;
		}
		diamondAmounts[i] = j;
	}
	return diamondAmounts;
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("diamond.in");
	fout.open("diamond.out");
	int diamondsAmount, minimumSizeDifference;
	fin >> diamondsAmount >> minimumSizeDifference;
	vi diamonds(diamondsAmount);
	for (int i = 0; i < diamondsAmount; i++) {
		fin >> diamonds[i];
	}
	sort(diamonds.begin(),diamonds.end());
	vi smallCase = calculateSmallCase(diamonds,minimumSizeDifference);
	vi smallSizes(smallCase.size());
	for (int i = 0; i < (int)smallSizes.size(); i++) {
		smallSizes[i] = i - smallCase[i] + 1;
		if (i > 0) {
			smallSizes[i] = max(smallSizes[i],smallSizes[i - 1]);
		}
	}
	vi largeCase = calculateLargeCase(diamonds,minimumSizeDifference);
	vi largeSizes(largeCase.size());
	for (int i = largeSizes.size() - 1; i >= 0; i--) {
		largeSizes[i] = largeCase[i] - i + 1;
		if (i < (int)largeSizes.size() - 1) {
			largeSizes[i] = max(largeSizes[i],largeSizes[i + 1]);
		}
	}
	int answer = 0;
	for (int i = 0; i < (int)largeSizes.size() - 1; i++) {
		answer = max(answer,smallSizes[i] + largeSizes[i + 1]);
	}
	fout << answer << endl;
	fin.close();
	fout.close();
}
