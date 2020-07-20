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

int length, boots, tiles[250], stepSize[250], stepDepth[250], smallest=250;
bool beenthere[250][250];
void search(int tile, int boot){
	if(beenthere[tile][boot]){
		return;
	}
	beenthere[tile][boot]=true;
	if(tile==length-1){
		smallest=min(smallest, boot);
	}else{
		for(int i=tile+1; i<tile+1+stepSize[boot]; i++){
			if(i>=length){
				continue;
			}
			if(tiles[i]<=stepDepth[boot]){
				search(i, boot);
			}
		}
		for(int j=boot+1; j<boots; j++){
			search(tile, j);
		}
	}
}
int main() {
	cin>>length>>boots;
	for(int i=0; i<length; i++){
		cin>>tiles[i];
	}
	for(int i=0; i<boots; i++){
		cin>>stepDepth[i]>>stepSize[i];
	}
	search(0, 0);
	cout<<smallest;
}
