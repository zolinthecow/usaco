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
#define ii pair<ll, ll>
#define vi vector<ll>
#define vii vector<ii>
#define vs vector<string>
#define ll long long

bool leftEdgeSort(ii a, ii b) {
	ll leftEdgeA = a.first - a.second;
	ll leftEdgeB = b.first - b.second;
	return leftEdgeA < leftEdgeB;
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("mountains.in");
	fout.open("mountains.out");
	ll mountainsAmount;
	cin >> mountainsAmount;
	vii mountainPeaks;
	for (ll i = 0; i < mountainsAmount; i++) {
		ii t;
		cin >> t.first >> t.second;
		mountainPeaks.pb(t);
	}
	sort(mountainPeaks.begin(),mountainPeaks.end(),leftEdgeSort);
	ii currentChecker(-1,-1);
	ll ans = mountainsAmount;
	for (ll i = 0; i < mountainsAmount; i++) {
		ii on = mountainPeaks[i];
		ll rightEdge = currentChecker.first + currentChecker.second;
		ll onRightEdge = on.first + on.second;
		ll leftEdge = currentChecker.first - currentChecker.second;
		ll onLeftEdge = on.first - on.second;
		if ((rightEdge >= onRightEdge && leftEdge <= onLeftEdge) || (onRightEdge >= rightEdge && onLeftEdge <= leftEdge)) ans--;
	}
	cout << ans << endl;
	fin.close();
	fout.close();
}
