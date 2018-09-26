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

struct walls{
	bool n, s, e, w;
};

walls **blueprint;
vector<int> *castle;
int *components;
int x, y;

walls getWalls(int z){
	walls result;
	result.n=0, result.s=0, result.e=0, result.w=0;
	if(z%2!=0){
		result.w=1;
	}
	z/=2;
	if(z%2!=0){
		result.n=1;
	}
	z/=2;
	if(z%2!=0){
		result.e=1;
	}
	z/=2;
	if(z%2!=0){
		result.s=1;
	}
	return result;
}

void buildGraph(){
	int count=0;
	for(int i=0; i<y; i++){
		for(int j=0; j<x; j++){
			if(blueprint[i][j].n==0){
				castle[count].push_back(count-(7*i));
			}
			if(blueprint[i][j].s==0){
				castle[count].push_back(count+(7*(i+1)));
			}
			if(blueprint[i][j].e==0){
				castle[count].push_back(count+1);
			}
			if(blueprint[i][j].w==0){
				castle[count].push_back(count-1);
			}
			count++;
		}
	}
}

bool noChildren(int a){
	int xside=0, yside=0, acopy=a;
	while(acopy>6){
		acopy-=7;
		xside++;
	}
	yside=acopy;
	if(blueprint[xside][yside].n==0){
		if(components[a-7]==0){
			return false;
		}
	}
	if(blueprint[xside][yside].s==0){
		if(components[a+7]==0){
			return false;
		}
	}
	if(blueprint[xside][yside].e==0){
		if(components[a+1]==0){
			return false;
		}
	}
	if(blueprint[xside][yside].w==0){
		if(components[a-1]==0){
			return false;
		}
	}
	return true;
}
void fillComponents(int num, int mark){
	if(components[num]==0){
		components[num]=mark;
	}else{
		return;
	}
	if(noChildren(num)){
		return;
	}else{
		int xside=0, yside=0, tempnum=num;
		while(tempnum>6){
			tempnum-=7;
			xside++;
		}
		yside=tempnum;
		if(blueprint[xside][yside].n==0){
			fillComponents(num-7, mark);
		}
		if(blueprint[xside][yside].s==0){
			fillComponents(num+7, mark);
		}
		if(blueprint[xside][yside].e==0){
			fillComponents(num+1, mark);
		}
		if(blueprint[xside][yside].w==0){
			fillComponents(num-1, mark);
		}
	}
}
int main() {
	cin>>x>>y;
	blueprint=new walls*[x];
	castle=new vector<int>[x*y];
	components=new int[x*y];
	for(int i=0; i<y; i++){
		blueprint[i]=new walls[x];
	}
	int count=0;
	for(int j=0; j<y; j++){
		for(int k=0; k<x; k++){
			int temp;
			cin>>temp;
			blueprint[j][k]=getWalls(temp);
			components[count]=0;
			count++;
		}
	}
	buildGraph();
	int mark=1;
	for(int l=0; l<x*y; l++){
		if(components[l]==0){
			fillComponents(l, mark);
			mark++;
		}
	}
	int *roomsizes;
	roomsizes=new int[mark-1];
	for(int n=0; n<mark; n++){
		roomsizes[n]=0;
	}
	cout<<mark-1<<endl;
	for(int m=0; m<x*y; m++){
		roomsizes[ components[m] ]++;
	}
	int max=0;
	for(int o=0; o<mark; o++){
		if(roomsizes[o]>max){
			max=roomsizes[o];
		}
	}
	cout<<max<<endl;
}
