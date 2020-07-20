/*
ID: colinzh3
PROG: wormhole
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

struct wormhole{
	int x;
	int y;
};
struct wpair{
	wormhole a;
	wormhole b;
};

vector< vector<wpair> > findPairs(vector<wormhole> wormholepos){
	vector< vector<wpair> > wormholepermutes;
	if(wormholepos.size()==2){
		vector<wpair> temp;
		wpair temp1;
		temp1.a=wormholepos.front();
		temp1.b=wormholepos.back();
		temp.push_back(temp1);
		wormholepermutes.push_back(temp);
		return wormholepermutes;
	}else{
		vector< vector<wpair> > allwpairs;
		wormhole first=wormholepos.front();
		for(vector<wormhole>::iterator itr=wormholepos.begin()+1;
			itr!=wormholepos.end(); itr++){
			vector< vector<wpair> > alltemp;
			wpair thing;
			thing.a=first;
			thing.b=*itr;
			vector<wormhole> wormholeposcopy;
			for(vector<wormhole>::iterator it=wormholepos.begin();
				it!=wormholepos.end(); it++){
				if(((*it).x == thing.a.x && (*it).y == thing.a.y) || ((*it).x == thing.b.x && (*it).y == thing.b.y)){
					continue;
				}
				wormholeposcopy.push_back(*it);
			}
			alltemp=findPairs(wormholeposcopy);
			for(vector< vector<wpair> >::iterator its=alltemp.begin();
					its!=alltemp.end(); its++){

				(*its).push_back(thing);

			}
			for(vector< vector<wpair> >::iterator itbob=alltemp.begin();
					itbob!=alltemp.end(); itbob++){
				allwpairs.push_back(*itbob);
			}
		}
		return allwpairs;
	}
}
wormhole nextWormhole(vector<wpair> solutions, int x, int y){
	for(vector<wpair>::iterator itr=solutions.begin(); itr!=solutions.end(); itr++){
		if((*itr).a.x==x&&(*itr).a.y==y){
			return (*itr).b;
		}else if(((*itr).b.x==x&&(*itr).b.y==y)){
			return (*itr).a;
		}
	}
	wormhole temp;
	temp.x=x;
	temp.y=y;
	return temp;
}
/*bool noWormhole(vector<wormhole> wormholepos, int x){
	for(vector<wormhole>::iterator itr=wormholepos.begin(); itr!=wormholepos.end(); itr++){
		if((*itr).x>=x){
			return false;
		}
	}
	return true;
}*/
wormhole nextRightWormhole(vector<wormhole> wormholepos, int x, int y){
	wormhole next;
	int mindistance=0;
	for(vector<wormhole>::iterator itr=wormholepos.begin(); itr!=wormholepos.end(); itr++){
		if((*itr).x==x&&(*itr).y==y){
			next.x = (*itr).x;
			next.y = (*itr).y;
			return next;
		}
		if ((*itr).y ==y && (*itr).x > x) {
			if(mindistance==0){
				mindistance=(*itr).x-x;
				next.x=(*itr).x;
				next.y=(*itr).y;
			} else{
				int temp=(*itr).x-x;
				if(temp<mindistance){
					mindistance=temp;
					next.x=(*itr).x;
					next.y=(*itr).y;
				}
			}
		}
	}
	if(mindistance ==0){
		next.x=-1;
		next.y=-1;
	}
	return next;
}
bool hasLoop(vector<wormhole> wormholepos, vector<wpair> solutions, int a){
	for(vector<wormhole>::iterator itr=wormholepos.begin(); itr!=wormholepos.end(); itr++){
		int foutnt=0;
		int x=(*itr).x;
		int y=(*itr).y;
		bool nomorewormhole=false;
		do{
			wormhole temp=nextWormhole(solutions, x, y);
			if(temp.x==x&&temp.y==y){
				//x++;
			}else{
				x=temp.x+1;
				y=temp.y;
				foutnt++;
			}
			wormhole right=nextRightWormhole(wormholepos, x, y);
			if(right.x==-1){
				nomorewormhole=true;
				break;
			}else{
				x=right.x;
				y=right.y;
			}
			/*if(noWormhole(wormholepos, x)){
				nomorewormhole=true;
				break;
			}
			*/
		}while(foutnt<a);
		if(foutnt==a){
			return true;
		}
	}
	return false;
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("wormhole.in");
	fout.open("wormhole.out");
	int a, totalcount=0;
	fin>>a;
	vector<wormhole> wormholepos;
	for(int i=0; i<a; i++){
		wormhole temp;
		fin>>temp.x>>temp.y;
		wormholepos.push_back(temp);
	}
	vector< vector<wpair> > allpairs;
	allpairs=findPairs(wormholepos);
	/*for(vector< vector<wpair> >::iterator itr=allpairs.begin(); itr!=allpairs.end(); itr++){
		for(vector<wpair>::iterator it=(*itr).begin(); it!=(*itr).end(); it++){
			foutt<<(*it).a.x<<" "<<(*it).a.y<<"=>"<<(*it).b.x<<" "<<(*it).b.y<<endl;
		}
	}*/
	for(vector< vector<wpair> >::iterator itr=allpairs.begin(); itr!=allpairs.end(); itr++){
		if(hasLoop(wormholepos, *itr, a)){
			totalcount++;
		}
	}
	fout<<totalcount<<endl;
	fin.close();
	fout.close();
}
