/*
ID: colinzh3
PROG: castle
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

bool sortAscending(pair<int, int> a, pair<int, int> b){
	return a.first<b.first;
}
bool waytosort(int a, int b){
	return a>b;
}

int fireOne(vector< pair<int, int> >allLifeguards){
	/*vector<int> actualShifts;
	unsigned int counta=1;
	for(vector<pair<int, int> >::iterator itr=allLifeguards.begin(); itr!=allLifeguards.end(); itr++){
		if(counta==allLifeguards.size()){
			actualShifts.push_back(itr->second - itr->first);
			break;
		}
		int shiftOverlap=itr->second - (itr+1)->first;
		if(shiftOverlap<0){
			actualShifts.push_back(itr->second - itr->first);
			break;
		}
		actualShifts.push_back((itr->second-shiftOverlap) - itr->first);
		counta++;
	}
	sort(actualShifts.begin(), actualShifts.end(), waytosort);
	int total=0;
	for(vector< pair<int, int> >::iterator it=allLifeguards.begin(); it!=allLifeguards.end(); it++){
		total+=it->second
	}
	return total;*/
	int count=0;
	vector<int> removedOne;
	for(vector< pair<int, int> >::iterator itr=allLifeguards.begin(); itr!=allLifeguards.end(); itr++){
		pair<int, int> temp;
		temp.first=itr->first;
		temp.second=itr->second;
		allLifeguards.erase(allLifeguards.begin()+count);
		unsigned int counta=1;
		int total=0;
		for(vector<pair<int, int> >::iterator it=allLifeguards.begin(); it!=allLifeguards.end(); it++){
			if(counta==allLifeguards.size()){
				total+=it->second - it->first;
				break;
			}
			int shiftOverlap=it->second - (it+1)->first;
			if(shiftOverlap<0){
				total+=it->second - it->first;
				counta++;
				continue;
			}
			total+=(it->second-shiftOverlap) - it->first;
			counta++;
		}
		removedOne.push_back(total);
		count++;
		allLifeguards.push_back(temp);
		sort(allLifeguards.begin(), allLifeguards.end(), sortAscending);
	}
	sort(removedOne.begin(), removedOne.end(), waytosort);
	return removedOne.front();
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("lifeguards.in");
	fout.open("lifeguards.out");
	int amount;
	vector< pair<int, int> >allLifeguards;
	fin>>amount;
	for(int i=0; i<amount; i++){
		pair<int, int> lifeguard;
		fin>>lifeguard.first>>lifeguard.second;
		allLifeguards.push_back(lifeguard);
	}
	sort(allLifeguards.begin(), allLifeguards.end(), sortAscending);
	fout<<fireOne(allLifeguards)<<endl;
	fin.close();
	fout.close();
}
