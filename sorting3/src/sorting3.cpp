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
using namespace std;
#define pb push_back
#define ii pair<ll, ll>
#define vi vector<ll>
#define vii vector<ii>
#define vs vector<string>
#define ll long long

bool sorted(vi nums) {
	vi test; test.insert(test.end(),nums.begin(),nums.end());
	sort(nums.begin(),nums.end());
	if (test == nums) return true;
	return false;
}


int solve(vi nums, int moves) {
	if (sorted(nums)) {
		return moves;
	} else {
		int ans = 1000000;
		moves++;
		for (int i = 0; i < (int)nums.size(); i++) {
			for (int j = i + 1; j < (int)nums.size(); j++) {
				vi temp; temp.insert(temp.end(),nums.begin(),nums.end());
				temp[i] = nums[j]; temp[j] = nums[i];
				ans = min(ans,solve(nums,moves));
			}
		}
		return ans;
	}
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("sort3.in");
	fout.open("sort3.out");
	int a;
	cin>>a;
	vi nums(a);
	for (int i = 0; i < a; i++) {
		cin >> nums[i];
	}
	cout << solve(nums,0) << endl;
	fin.close();
	fout.close();
}
