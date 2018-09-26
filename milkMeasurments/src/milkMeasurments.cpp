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

bool waytosort1(ii a, ii b){
	return a.first<b.first;
}

int main()
{
	ifstream fin;
	ofstream fout;
	fin.open("measurement.in");
	fout.open("measurement.out");
	int cowCount, initialGallons;
	fin >> cowCount >> initialGallons;
	vi cowsProduction(1000001, initialGallons);
	map<int, pair<int, string> > productionChanges;
	for (int i = 0; i < cowCount; i++) {
		int day;
		fin >> day;
		pair<int, string> cowChange;
		fin >> cowChange.first >> cowChange.second;
		cowChange.first -= 1;
		productionChanges.insert( pair<int, pair<int, string> > (day, cowChange) );
	}
	vi oldMax( initialGallons, 1000001 );
	int answer=0;
	for(map<int, pair<int, string> >::iterator it = productionChanges.begin(); it != productionChanges.end(); it++) {
		bool found = false;
		ii previousMax = oldMax.back();
		if( it->second.second.at(0) == '+' ) {
			cowsProduction[ it->second.first ] += stoi( it->second.second.substr(1, 1) );
			if( itr != oldMax.end() ) {
				itr->first += stoi( it->second.second.substr(1, 1) );
				found = true;
			}
		}else{
			auto itr = find( oldMax.begin(), oldMax.end(), ii( cowsProduction[ it->second.first ], it->second.first ) );
			cowsProduction[ it->second.first ] -= stoi( it->second.second.substr(1, 1) );
			if( itr != oldMax.end() ) {
				itr->first += stoi( it->second.second.substr(1, 1) );
				found = true;
			}
		}
		if( !found ) {
			oldMax.pb( ii( cowsProduction[ it->second.first ], it->second.first) );
		}
		sort( oldMax.begin(), oldMax.end(), waytosort1);
		/*if( cowsProduction[ it->second.first ] >= oldMax.back().first && oldMax.back().second != it->second.first) {
			answer++;
		}*/
		if( oldMax.back() != previousMax ) {
			answer++;
		}
	}
	fout<<answer<<endl;
	fin.close();
	fout.close();

}
