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

bool waytosort(pair<int, int> a, pair<int, int> b){
	return a.first<b.first;
}

int findTime(vector< pair<int, int> >allcows){
	int time=0;
	for(vector< pair<int, int> >::iterator itr=allcows.begin(); itr!=allcows.end(); itr++){
		int arriveTime=itr->first, processTime=itr->second;
		if(arriveTime>time){
			time=arriveTime+processTime;
		}else{
			time+=processTime;
		}
	}
	return time;
}
int main() {
	int amount;
	vector< pair<int, int> >allcows;
	cin>>amount;
	for(int i=0; i<amount; i++){
		pair<int, int> cow;
		cin>>cow.first>>cow.second;
		allcows.push_back(cow);
	}
	sort(allcows.begin(), allcows.end(), waytosort);
	cout<<findTime(allcows)<<endl;
}
