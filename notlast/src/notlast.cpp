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

bool waytosort(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second;
}

int main() {
	int amount, min, secondmin=-1;
	map<string, int> tempcows;
	vector<pair<string, int> > cows;
	cin >> amount;
	for (int i = 0; i < amount; i++) {
		string cow;
		int milk;
		cin >> cow >> milk;
		tempcows[cow] += milk;
	}
	for (map<string, int>::iterator itr = tempcows.begin();
			itr != tempcows.end(); itr++) {
		pair<string, int> temp;
		temp.first = itr->first, temp.second = itr->second;
		cows.push_back(temp);
	}
	if(cows.size()==1){
		cout<<cows.front().first<<endl;
		return 0;
	}
	sort(cows.begin(), cows.end(), waytosort);
	if (tempcows.find("Bessie") == tempcows.end()
			&& tempcows.find("Elsie") == tempcows.end()
			&& tempcows.find("Daisy") == tempcows.end()
			&& tempcows.find("Gertie") == tempcows.end()
			&& tempcows.find("Annabelle") == tempcows.end()
			&& tempcows.find("Maggie") == tempcows.end()
			&& tempcows.find("Henrietta") == tempcows.end()) {
		min = 0;
	} else {
		min = cows.front().second;
	}
	int count=0;
	string cowon="";
	for(vector< pair<string, int> >::iterator it=cows.begin(); it!=cows.end(); it++){
		count++;
		if(it->second>min && secondmin==-1){
			secondmin=it->second;
			cowon=it->first;
			break;
		}
	}
	if(cowon==""){
		cout<<"Tie"<<endl;
		return 0;
	}
	for(vector< pair<string, int> >::iterator its=cows.begin()+count; its!=cows.end(); its++){
		if(its->second==secondmin){
			cout<<"Tie"<<endl;
			return 0;
		}
	}
	cout<<cowon<<endl;
}
