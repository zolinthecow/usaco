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
		for(vector<wormhole>::iterator itr=wormholepos.begin();
			itr!=wormholepos.end(); itr+=2){
			vector< vector<wpair> > alltemp;
			wpair thing;
			thing.a=*itr;
			thing.b=*(itr+1);
			vector<wormhole> wormholeposcopy;
			for(vector<wormhole>::iterator it=wormholepos.begin();
				it!=wormholepos.end(); it++){
				if((*it).x != thing.a.x && (*it).y != thing.a.y && (*it).x != thing.b.x && (*it).y != thing.b.y){
					wormholeposcopy.push_back(*it);
				}
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
int main() {
	int a;
	cin>>a;
	vector<wormhole> wormholepos;
	for(int i=0; i<a; i++){
		wormhole temp;
		cin>>temp.x>>temp.y;
		wormholepos.push_back(temp);
	}
	vector< vector<wpair> > allpairs;
	allpairs=findPairs(wormholepos);
	for(vector< vector<wpair> >::iterator itr=allpairs.begin(); itr!=allpairs.end(); itr++){
		for(vector<wpair>::iterator it=(*itr).begin(); it!=(*itr).end(); it++){
			cout<<(*it).a.x<<" "<<(*it).a.y<<endl<<(*it).b.x<<" "<<(*it).b.y<<endl;
		}
		cout<<endl;
	}
}
