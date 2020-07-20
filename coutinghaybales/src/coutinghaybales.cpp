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

int main() {
	int haybalesCount, queryCount;
	vector<int> haybales;
	cin>>haybalesCount>>queryCount;
	for(int i=0; i<haybalesCount; i++){
		int place;
		cin>>place;
		haybales.push_back(place);
	}
	sort(haybales.begin(), haybales.end());
	for(int j=0; j<queryCount; j++){
		int beginning, end;
		cin>>beginning>>end;
		int count=0;
		for(vector<int>::iterator itr=haybales.begin(); itr!=haybales.end(); itr++){
			if(*itr>end){
				break;
			}
			if(*itr>=beginning && *itr<=end){
				count++;
			}
		}
		cout<<count<<endl;
	}
}
