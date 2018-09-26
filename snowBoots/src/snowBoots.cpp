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

bool cannotStepFurther(int bootDepth, int stepLength, int tileOn, vi tiles){
	unsigned int temp=tileOn;
	if(temp==tiles.size()-1){
		return true;
	}
	for(int i=1; i<=stepLength; i++){
		if(tiles[tileOn+i]<=bootDepth){
			return false;
		}
	}
	return true;
}
int minimumDiscarded(int tiles, int boots, vii backpack, vi allTiles){
	int discarded=0, tileOn=0;
	for(unsigned int i=0; i<backpack.size(); i++){
		if(tileOn>=tiles-1){
			break;
		}
		while(!cannotStepFurther((backpack[i]).first, (backpack[i]).second, tileOn, allTiles)){
			int maximumToStep=0, tileToStepOn=0;
			for(int j=tileOn+1; j<tileOn+backpack[i].second+1; j++){
				unsigned int temp=j;
				if(temp>allTiles.size()-1){
					break;
				}
				if(allTiles[j]>=maximumToStep && allTiles[j]<=backpack[i].first){
					maximumToStep=allTiles[j];
					tileToStepOn=j;
				}
			}
			tileOn=tileToStepOn;
		}
		if(tileOn>=tiles-1){
			break;
		}
		discarded++;
	}
	return discarded;
}
int main() {
	ifstream fin;
	ofstream fout;
	fin.open("snowboots.in");
	fout.open("snowboots.out");
	int tile, boots;
	fin>>tile>>boots;
	vi tiles;
	for(int j=0; j<tile; j++){
		int thing;
		fin>>thing;
		tiles.push_back(thing);
	}
	vii backpack;
	for(int i=0; i<boots; i++){
		int bootDepth, stepLength;
		fin>>bootDepth>>stepLength;
		ii temp;
		temp.first=bootDepth, temp.second=stepLength;
		backpack.push_back(temp);
	}
	fout<<minimumDiscarded(tile, boots, backpack, tiles)<<endl;
	fin.close();
	fout.close();
}
