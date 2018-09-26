/*
ID: colinzh3
PROG: wormhole
LANG: C++
 */
#include <stdlib.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <map>
#include <fstream>
#include <string>
#include <fstream>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <math.h>
using namespace std;
struct node{
	int x;
	int y;
};
struct pairs{
	node a;
	node b;
};
struct vectorpairscompare{
	bool operator()(vector<pairs> a, vector<pairs> b){
		if(a.size()>b.size()){
			return true;
		}else if(a.size()<b.size()){
			return false;
		}else{
			if(a.front().a.x>b.front().a.x){
				return true;
			}else{
				return false;
			}
		}
	}
};
vector<vector<pairs> > getCombinations(node wormholes[], int size){
	if(size==2){
		vector<pairs> allpairs;
		vector<vector<pairs> > allcombos;
		for(int i=0; i<size; i+=2){
			pairs apair;
			apair.a=wormholes[i];
			apair.b=wormholes[i+1];
			allpairs.push_back(apair);
		}
		allcombos.push_back(allpairs);
		return allcombos;
	}else{
		vector<vector<pairs> > allcombos;
		vector<vector<pairs> >combos;
		node *temp=new node [size-2];
		node firstnode=wormholes[0];
		for(int i=1; i<size; i++){
			node secondnode=wormholes[i];
			pairs apair;
			apair.a=firstnode;
			apair.b=secondnode;
			int k=1;
			int bob=0;
			while(k<size){
				if(k!=i){
					temp[bob]=wormholes[k];
					bob++;
				}
				k++;
			}
			combos=getCombinations(temp, size-2);
			for(vector<vector<pairs> >::iterator itr=combos.begin(); itr!=combos.end(); itr++){
				vector<pairs> allPairs;
				vector<vector<pairs> >::iterator bobby=allcombos.begin();
				allPairs.assign((*itr).begin(), (*itr).end());
				allPairs.push_back(apair);
				allcombos.insert(bobby, allPairs);
			}
		}
		return allcombos;
	}
}
int main() {
	int a;
	cin>>a;
	node *wormholes=new node[a];
	for(int i=0; i<a; i++){
		node apair;
		cin>>apair.x>>apair.y;
		wormholes[i]=apair;
	}
	vector<vector<pairs> > wormholecombos=getCombinations(wormholes, a);
	for(vector<vector<pairs> >::iterator itr=wormholecombos.begin(); itr!=wormholecombos.end(); itr++){
		vector<pairs> temp=*itr;
		cout<<"combination:";
		for(vector<pairs>::iterator it=temp.begin(); it!=temp.end(); it++){
			cout<<"pair:("<<(*it).a.x<<","<<(*it).a.y<<")-("<<(*it).b.x<<" "<<(*it).b.y<<"), ";
		}
		cout<<endl;
	}
}
