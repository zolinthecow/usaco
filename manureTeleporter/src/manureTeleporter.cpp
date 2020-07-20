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

int calculateYPosition(int pileAmount, vii piles){

}
int main() {
	int pileAmount;
	cin>>pileAmount;
	vii piles;
	for(int i=0; i<pileAmount; i++){
		int firstpile, secondpile;
		cin>>firstpile>>secondpile;
		ii temp;
		temp.first=firstpile, temp.second=secondpile;
		piles.push_back(temp);
	}
}
