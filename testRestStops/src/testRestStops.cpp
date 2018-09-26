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

int length, restStopsAmount, fjSpeed, bessieSpeed;

struct restStop{
	int place, tastiness;
};

bool sortRestStops(restStop a, restStop b){
	return a.tastiness>b.tastiness;
}

int main() {
	cin>>length>>restStopsAmount>>fjSpeed>>bessieSpeed;
	vector<restStop> restStops;
	for(int i=0; i<restStopsAmount; i++){
		restStop temp;
		cin>>temp.place>>temp.tastiness;
		restStops.push_back(temp);
	}
	sort(restStops.begin(), restStops.end(), sortRestStops);
	ll bessiePlace=0, fjPlace=0, answer=0, previousPlace=0;
	for(vector<restStop>::iterator itr=restStops.begin(); itr!=restStops.end(); itr++){
		if((*itr).place>previousPlace){
			ll timeSpent=((*itr).place-fjPlace)*fjSpeed-((*itr).place-bessiePlace)*bessieSpeed;
			answer+=timeSpent*(*itr).tastiness;
			bessiePlace=(*itr).place, fjPlace=(*itr).place;
			previousPlace=(*itr).place;
		}
	}
	cout<<answer<<endl;
}
