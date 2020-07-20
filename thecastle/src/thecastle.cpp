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
struct removed{
	int width, height, size;
	string position;
};

bool sortRemovedWalls(removed a, removed b){
	if(a.size>b.size){
		return true;
	}else if(a.size<b.size){
		return false;
	}else if(a.width<b.width){
		return true;
	}else if(a.width>b.width){
		return false;
	}else if(a.height>b.height){
		return true;
	}else if(a.height<b.height){
		return false;
	}else if(a.position=="N"){
		return true;
	}else{
		return false;
	}
}
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
bool noChildren(int a, int *components, walls **blueprint, int width, int height){
	int xside=a/width, yside=a%width;
	if(blueprint[xside][yside].n==0){
		if(components[a-width]==0){
			return false;
		}
	}
	if(blueprint[xside][yside].s==0){
		if(components[a+width]==0){
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
void fillComponents(int num, int mark, int *components, walls **blueprint, int width, int height){
	if(components[num]==0){
		components[num]=mark;
	}else{
		return;
	}
	if(noChildren(num, components, blueprint, width, height)){
		return;
	}else{
		int xside=num/width, yside=num%width;
		if(blueprint[xside][yside].n==0){
			fillComponents(num-width, mark, components, blueprint, width, height);
		}
		if(blueprint[xside][yside].s==0){
			fillComponents(num+width, mark, components, blueprint, width, height);
		}
		if(blueprint[xside][yside].e==0){
			fillComponents(num+1, mark, components, blueprint, width, height);
		}
		if(blueprint[xside][yside].w==0){
			fillComponents(num-1, mark, components, blueprint, width, height);
		}
	}
}
int findRooms(int *components, int height, int width, walls **blueprint){
	int mark=1;
	for(int i=0; i<height*width; i++){
		if(components[i]==0){
			fillComponents(i, mark, components, blueprint, width, height);
			mark++;
		}
	}
	return mark-1;
}
int findMax(int *components, int width, int height, int mark){
	int *roomsizes;
	roomsizes=new int[width*height];
	for(int k=0; k<width*height; k++){
		roomsizes[k]=0;
	}
	for(int i=0; i<width*height; i++){
		roomsizes[ components[i] ]++;
	}
	int max=0;
	for(int j=0; j<=mark; j++){
		if(roomsizes[j]>max){
			max=roomsizes[j];
		}
	}
	delete[] roomsizes;
	return max;
}
removed removeWall(walls **blueprint, int width, int height){
	vector<removed> allRemovedWalls;
	removed result;
	for(int i=0; i<height; i++){
		for(int j=0; j<width; j++){
			if(blueprint[i][j].n && i!=0){
				int *components;
				components=new int[width*height];
				for(int l=0; l<width*height; l++){
					components[l]=0;
				}
				removed thisWall;
				blueprint[i][j].n=0;
				blueprint[i-1][j].s=0;
				int newRooms=findRooms(components, height, width, blueprint);
				int newMax=findMax(components, width, height, newRooms);
				thisWall.height=i, thisWall.width=j, thisWall.size=newMax, thisWall.position="N";
				allRemovedWalls.push_back(thisWall);
				blueprint[i][j].n=1;
				blueprint[i-1][j].s=1;
				for(int k=0; k<width*height; k++){
					components[k]=0;
				}
				delete[] components;
			}
			if(blueprint[i][j].e && j!=width-1){
				int *components;
				components=new int[width*height];
				for(int l=0; l<width*height; l++){
					components[l]=0;
				}
				removed thisWall;
				blueprint[i][j].e=0;
				blueprint[i][j+1].w=0;
				int newRooms=findRooms(components, height, width, blueprint);
				int newMax=findMax(components, width, height, newRooms);
				thisWall.height=i, thisWall.width=j, thisWall.size=newMax, thisWall.position="E";
				allRemovedWalls.push_back(thisWall);
				blueprint[i][j].e=1;
				blueprint[i][j+1].w=1;
				for(int k=0; k<width*height; k++){
					components[k]=0;
				}
				delete[] components;
			}
		}
	}
	sort(allRemovedWalls.begin(), allRemovedWalls.end(), sortRemovedWalls);
	int firstHeight=allRemovedWalls.front().height, firstWidth=allRemovedWalls.front().width, firstSize=allRemovedWalls.front().size;
	string firstPosition=allRemovedWalls.front().position;
	result.size=firstSize, result.height=firstHeight, result.width=firstWidth, result.position=firstPosition;
	return result;
}
int main(){
	ifstream fin;
	ofstream fout;
	fin.open("castle.in");
	fout.open("castle.out");
	int width, height, *components;
	walls **blueprint;
	fin>>width>>height;
	blueprint=new walls*[height];
	components=new int[width*height];
	for(int i=0; i<height; i++){
		blueprint[i]=new walls[width];
	}
	for(int j=0; j<height; j++){
		for(int k=0; k<width; k++){
			int wall;
			fin>>wall;
			blueprint[j][k]=getWalls(wall);
		}
	}
	int roomCount=findRooms(components, height, width, blueprint);
	fout<<roomCount<<endl;
	int max=findMax(components, width, height, roomCount);
	fout<<max<<endl;
	removed largestRemoved=removeWall(blueprint, width, height);
	fout<<largestRemoved.size<<endl<<largestRemoved.height+1<<" "<<largestRemoved.width+1<<" "<<largestRemoved.position<<endl;
	fin.close();
	fout.close();
}
