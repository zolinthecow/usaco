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

char **grid;
int **regions;
map<int, char> regionColors;

void floodFill(int a){
	int processed=0;
	int on=1;
	int row=0, column=0;
	while(processed!=a*a){
		queue<ii> region;
		for(int i=0; i<a; i++){
			for(int j=0; j<a; j++){
				if(regions[i][j]==-2){
					row=i, column=j;
					i=a-1, j=a-1;
					processed++;
				}
			}
		}
		regionColors.insert(pair<int, char>(on, grid[row][column]));
		regions[row][column]=on;
		ii place;
		place.first=row, place.second=column;
		region.push(place);
		while(region.size()>0){
			if(region.front().first>0){
				if(grid[region.front().first][region.front().second]==grid[region.front().first-1][region.front().second]){
					if(regions[region.front().first-1][region.front().second]==-2){
						processed++;
						regions[region.front().first-1][region.front().second]=on;
						ii temp;
						temp.first=region.front().first-1, temp.second=region.front().second;
						region.push(temp);
					}
				}
			}
			if(region.front().second>0){
				if(grid[region.front().first][region.front().second]==grid[region.front().first][region.front().second-1]){
					if(regions[region.front().first][region.front().second-1]==-2){
						processed++;
						regions[region.front().first][region.front().second-1]=on;
						ii temp;
						temp.first=region.front().first, temp.second=region.front().second-1;
						region.push(temp);
					}
				}
			}
			if(region.front().first<a-1){
				if(grid[region.front().first][region.front().second]==grid[region.front().first+1][region.front().second]){
					if(regions[region.front().first+1][region.front().second]==-2){
						processed++;
						regions[region.front().first+1][region.front().second]=on;
						ii temp;
						temp.first=region.front().first+1, temp.second=region.front().second;
						region.push(temp);
					}
				}
			}
			if(region.front().second<a-1){
				if(grid[region.front().first][region.front().second]==grid[region.front().first][region.front().second+1]){
					if(regions[region.front().first][region.front().second+1]==-2){
						processed++;
						regions[region.front().first][region.front().second+1]=on;
						ii temp;
						temp.first=region.front().first, temp.second=region.front().second+1;
						region.push(temp);
					}
				}
			}
			region.pop();
		}
		on++;
	}
}

bool isPCL(ii topLeft, ii bottomRight){
	vi regionsUsed;
	vector<char> colorsUsed;
	for(int i=topLeft.first; i<bottomRight.first; i++){
		for(int j=topLeft.second; j<bottomRight.second; j++){
			if(find(regionsUsed.begin(), regionsUsed.end(), regions[i][j])==regionsUsed.end()){
				regionsUsed.push_back(regions[i][j]);
			}
			if(find(colorsUsed.begin(), colorsUsed.end(), grid[i][j])==colorsUsed.end()){
				colorsUsed.push_back(grid[i][j]);
			}
		}
	}
	if(regionsUsed.size()>=3){
		if(colorsUsed.size()==2){
			map<char, int> test;
			for(vi::iterator itr=regionsUsed.begin(); itr!=regionsUsed.end(); itr++){
				test[ regionColors[*itr] ]++;
			}
			int oneCount=0;
			for(map<char, int>::iterator itr=test.begin(); itr!=test.end(); itr++){
				if((*itr).second==1){
					oneCount++;
				}
			}
			if(oneCount==1){
				return true;
			}
		}
	}
	return false;
}
int calculatePCL(int a){
	int answer=0;
	for(int i=0; i<a; i++){
		for(int j=0; j<a; j++){
			for(int k=0; k<a; k++){
				for(int l=0; l<a; l++){
					ii topLeft;
					topLeft.first=i, topLeft.second=j;
					ii bottomRight;
					bottomRight.first=k, bottomRight.second=l;
					if(isPCL(topLeft, bottomRight)){
						answer++;
					}
				}
			}
		}
	}
	return answer;
}
int main() {
	int a;
	cin>>a;
	grid=new char*[a];
	regions=new int*[a];
	for(int i=0; i<a; i++){
		grid[i]=new char[a];
		regions[i]=new int[a];
	}
	for(int i=0; i<a; i++){
		for(int j=0; j<a; j++){
			regions[i][j]=-2;
		}
	}
	for(int i=0; i<a; i++){
		string colors;
		cin>>colors;
		for(unsigned int j=0; j<colors.length(); j++){
			grid[i][j]=colors.at(j);
		}
	}
	floodFill(a);
	/*for(int i=0; i<a; i++){
		for(int j=0; j<a; j++){
			cout<<regions[i][j]<<" ";
		}
		cout<<endl;
	}*/
	cout<<calculatePCL(a);
}
