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
#include <unordered_set>
#include <functional>
using namespace std;
#define ll long long
#define pb push_back
#define ii pair<ll, ll>
#define vi vector<ll>
#define vii vector<ii>
#define vs vector<string>

bool storeSort(ii a, ii b) {
	return a.second > b.second;
}
bool farmSort(ll a, ll b) {
	return a > b;
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("rental.in");
	fout.open("rental.out");
	ll cowAmount, storeAmount, farmAmount;
	fin >> cowAmount >> storeAmount >> farmAmount;
	vi cows(cowAmount); vii stores; vi farms(farmAmount);
	for (ll i = 0; i < cowAmount; i++) {
		fin >> cows[i];
	}
	for (ll i = 0; i < storeAmount; i++) {
		ii store;
		fin >> store.first >> store.second;
		stores.pb(store);
	}
	for (ll i = 0; i < farmAmount; i++) {
		fin >> farms[i];
	}
	sort(stores.begin(),stores.end(),storeSort);
	sort(farms.begin(),farms.end(),farmSort);
	sort(cows.begin(),cows.end(),farmSort);
	vi maxFarm(cowAmount,0);
	ll farmOn = 0;
	for (ll i = 0; i < cowAmount; i++) {
		if (farmOn < farmAmount) {
			maxFarm[i] += farms[farmOn];
			farmOn++;
		}
		if (i < cowAmount - 1) {
			maxFarm[i + 1] = maxFarm[i];
		}
	}
	ii storeOn(0,stores[0].first);
	vi maxStore(cowAmount,0);
	for (ll i = 0; i < cowAmount; i++) {
		if (storeOn.first < storeAmount) {
			ll milkAmount = cows[i];
			while(storeOn.first < storeAmount && milkAmount > 0) {
				if (milkAmount > storeOn.second) {
					maxStore[i] += storeOn.second * stores[storeOn.first].second;
					milkAmount -= storeOn.second;
					storeOn.first += 1, storeOn.second = stores[storeOn.first].first;
				} else {
					maxStore[i] += milkAmount * stores[storeOn.first].second;
					storeOn.second -= milkAmount;
					milkAmount = 0;
				}
			}
		}
		if (i < cowAmount - 1) {
			maxStore[i + 1] = maxStore[i];
		}
	}
	ll ans = 0;
	maxFarm.insert(maxFarm.begin(),0); maxStore.insert(maxStore.begin(),0);
	for (ll i = 0; i <= cowAmount; i++) {
		ans = max(ans,maxStore[i] + maxFarm[cowAmount - i]);
	}
	fout << ans << endl;
	fin.close();
	fout.close();
}
