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

int **grid;
int **check;
map< int, vi > regions;
map<int, vii> numRegions;

void floodFill(int a){
	int processed=0;
	int on=1;
	int row=0, column=0;
	while(processed!=a*a){
		queue<ii> region;
		for(int i=0; i<a; i++){
			for(int j=0; j<a; j++){
				if(check[i][j]==-2){
					row=i, column=j;
					i=a-1, j=a-1;
					processed++;
				}
			}
		}
		regions[on-1].push_back(grid[row][column]);
		ii thing;
		thing.first=row, thing.second=column;
		numRegions[grid[row][column] ].push_back(thing);
		check[row][column]=on;
		ii place;
		place.first=row, place.second=column;
		region.push(place);
		while(region.size()>0){
			if(region.front().first>0){
				if(grid[region.front().first][region.front().second]==grid[region.front().first-1][region.front().second]){
					if(check[region.front().first-1][region.front().second]==-2){
						processed++;
						check[region.front().first-1][region.front().second]=on;
						ii temp;
						temp.first=region.front().first-1, temp.second=region.front().second;
						region.push(temp);
						regions[on-1].push_back(grid[region.front().first-1][region.front().second]);
						numRegions[grid[region.front().first-1][region.front().second] ].push_back(temp);
					}
				}
			}
			if(region.front().second>0){
				if(grid[region.front().first][region.front().second]==grid[region.front().first][region.front().second-1]){
					if(check[region.front().first][region.front().second-1]==-2){
						processed++;
						check[region.front().first][region.front().second-1]=on;
						ii temp;
						temp.first=region.front().first, temp.second=region.front().second-1;
						region.push(temp);
						regions[on-1].push_back(grid[region.front().first][region.front().second-1]);
						numRegions[grid[region.front().first][region.front().second-1] ].push_back(temp);
					}
				}
			}
			if(region.front().first<a-1){
				if(grid[region.front().first][region.front().second]==grid[region.front().first+1][region.front().second]){
					if(check[region.front().first+1][region.front().second]==-2){
						processed++;
						check[region.front().first+1][region.front().second]=on;
						ii temp;
						temp.first=region.front().first+1, temp.second=region.front().second;
						region.push(temp);
						regions[on-1].push_back(grid[region.front().first+1][region.front().second]);
						numRegions[grid[region.front().first+1][region.front().second] ].push_back(temp);
					}
				}
			}
			if(region.front().second<a-1){
				if(grid[region.front().first][region.front().second]==grid[region.front().first][region.front().second+1]){
					if(check[region.front().first][region.front().second+1]==-2){
						processed++;
						check[region.front().first][region.front().second+1]=on;
						ii temp;
						temp.first=region.front().first, temp.second=region.front().second+1;
						region.push(temp);
						regions[on-1].push_back(grid[region.front().first][region.front().second+1]);
						numRegions[grid[region.front().first][region.front().second+1] ].push_back(temp);
					}
				}
			}
			region.pop();
		}
		on++;
	}
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("multimoo.in");
	fout.open("multimoo.out");
	int a;
	fin>>a;
	grid=new int*[a];
	check=new int*[a];
	map<int, int> checks;
	for(int i=0; i<a; i++){
		grid[i]=new int[a];
		check[i]=new int[a];
	}
	int counts=-1;
	for(int i=0; i<a; i++){
		for(int j=0; j<a; j++){
			fin>>grid[i][j];
			check[i][j]=-2;
			if(checks.find(grid[i][j])==checks.end()){
				counts++;
				checks[grid[i][j] ]=counts;
			}
			grid[i][j]=checks[grid[i][j] ];
		}
	}
	floodFill(a);
	int firstMax=0;
	for(map<int, vi>::iterator itr=regions.begin(); itr!=regions.end(); itr++){
		int size=(*itr).second.size();
		firstMax=max(firstMax, size);
	}
	int secondMax=0;
	for(map<int, vii>::iterator itr=numRegions.begin(); itr!=numRegions.end(); itr++){
		for(map<int, vii>::iterator it=numRegions.begin(); it!=itr; it++){
			if(itr==it){
				continue;
			}
			int count=0;
			for(vii::iterator its=(*itr).second.begin(); its!=(*itr).second.end(); its++){
				bool used=false;
				if((*its).first>0){
					if(grid[(*its).first-1][(*its).second]==(*itr).first || grid[(*its).first-1][(*its).second]==(*it).first){
						if(!used){
							count++;
							used=true;
						}
					}
				}
				if((*its).second>0){
					if(grid[(*its).first][(*its).second-1]==(*itr).first || grid[(*its).first][(*its).second-1]==(*it).first){
						if(!used){
							count++;
							used=true;
						}
					}
				}
				if((*its).first<a-1){
					if(grid[(*its).first+1][(*its).second]==(*itr).first || grid[(*its).first+1][(*its).second]==(*it).first){
						if(!used){
							count++;
							used=true;
						}
					}
				}
				if((*its).second<a-1){
					if(grid[(*its).first][(*its).second+1]==(*itr).first || grid[(*its).first][(*its).second+1]==(*it).first){
						if(!used){
							count++;
							used=true;
						}
					}
				}
			}
			for(vii::iterator its=(*it).second.begin(); its!=(*it).second.end(); its++){
				bool used=false;
				if((*its).first>0){
					if(grid[(*its).first-1][(*its).second]==(*itr).first || grid[(*its).first-1][(*its).second]==(*it).first){
						if(!used){
							count++;
							used=true;
						}
					}
				}
				if((*its).second>0){
					if(grid[(*its).first][(*its).second-1]==(*itr).first || grid[(*its).first][(*its).second-1]==(*it).first){
						if(!used){
							count++;
							used=true;
						}
					}
				}
				if((*its).first<a-1){
					if(grid[(*its).first+1][(*its).second]==(*itr).first || grid[(*its).first+1][(*its).second]==(*it).first){
						if(!used){
							count++;
							used=true;
						}
					}
				}
				if((*its).second<a-1){
					if(grid[(*its).first][(*its).second+1]==(*itr).first || grid[(*its).first][(*its).second+1]==(*it).first){
						if(!used){
							count++;
							used=true;
						}
					}
				}
			}
			secondMax=max(count, secondMax);
		}
	}
	fout<<firstMax<<endl<<secondMax<<endl;
	fin.close();
	fout.close();
}
