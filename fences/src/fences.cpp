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
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;
#define INF 1000000000

bool horizontal(pair<ii, ii> a){
	if(a.first.first!=a.second.first && a.first.second==a.second.second){
		return true;
	}
	return false;
}
bool vertical(pair<ii, ii> a){
	if(a.first.first==a.second.first && a.first.second!=a.second.second){
		return true;
	}
	return false;
}

bool overlaps(pair<ii, ii> a, pair<ii, ii> b){
	if(horizontal(a) && vertical(b)){
		if(b.first.first<a.first.first && b.first.first<a.second.first){
			return true;
		}
	}else if(vertical(a) && horizontal(b)){
		if(a.first.first<b.first.first && a.first.first<b.second.first){
			return true;
		}
	}
	return  false;
}

int calculate(vii edgeMap){
	vector< pair<ii, ii> > lineMap;
	pair<ii, ii> segment(ii(-2, -2), ii(-2, -2));
	for(int i=1; i<(int)edgeMap.size(); i++){
		if(segment.first==ii(-2, -2) && segment.second==ii(-2, -2)){
			segment.first=edgeMap[i-1];
		}else{
			if(edgeMap[i].first!=segment.first.first || edgeMap[i].second!=segment.first.second){
				segment.second=edgeMap[i-1];
				lineMap.push_back(segment);
				segment.first=ii(-2, -2), segment.second=ii(-2, -2);
			}
		}
	}
	int count=0;
	for(auto it : lineMap){
		for(auto itr : lineMap){
			if(overlaps(it, itr)){
				count++;
			}
		}
	}
	return count;
}

int main() {
	int stepsCount;
	cin>>stepsCount;
	string steps;
	cin>>steps;
	vii edgeMap={ii(0, 0)};
	for(int i=1; i<=stepsCount; i++){
		if(steps[i-1]=='N'){
			edgeMap.push_back(ii(edgeMap[i-1].first+1, edgeMap[i-1].second));
		}else if(steps[i-1]=='S'){
			edgeMap.push_back(ii(edgeMap[i-1].first-1, edgeMap[i-1].second));
		}else if(steps[i-1]=='W'){
			edgeMap.push_back(ii(edgeMap[i-1].first, edgeMap[i-1].second-1));
		}else{
			edgeMap.push_back(ii(edgeMap[i-1].first, edgeMap[i-1].second+1));
		}
	}
	cout<<calculate(edgeMap)<<endl;
}
