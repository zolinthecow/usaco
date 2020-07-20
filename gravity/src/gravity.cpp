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
#define pb push_back
#define ii pair<int, int>
#define vi vector<int>
#define vii vector<ii>
#define vs vector<string>
#define ll long long
#define pb push_back

int **grid;
int ** dp;
bool ** visited;
int width, height;

bool validMove(int x, int y, string moveType, string gravity) {
	if (moveType == "g") {
		bool isBlock = false;
		if (gravity == "reg") {
			for (int i = y; i >= 0; i--) {
				if (grid[i][x] == 0) {
					isBlock = true;
					break;
				}
			}
		} else {
			for (int i = y; i < height; i++) {
				if (grid[i][x] == 0) {
					isBlock = true;
					break;
				}
			}
		}
		return isBlock;
	} else if (moveType == "l") {
		if (x - 1 >= 0) {
			if (grid[y][x  - 1] != 0) {
				if (gravity == "reg") {
					for (int i = y; i < height; i++) {
						if (grid[i][x - 1] == 0) {
							return true;
						}
					}
				} else {
					for (int i = y; i >= 0; i--) {
						if (grid[i][x - 1] == 0) {
							return true;
						}
					}
				}
			}
		}
		return false;
	} else {
		if (x + 1 < width) {
			if (grid[y][x + 1] != 0) {
				if (gravity == "reg") {
					for (int i = y; i < height; i++) {
						if (grid[i][x + 1] == 0) {
							return true;
						}
					}
				} else {
					for (int i = y; i >= 0; i--) {
						if (grid[i][x + 1] == 0) {
							return true;
						}
					}
				}
			}
		}
		return false;
	}
}

ii flipGravity(int x, int y, string gravity) {
	if (gravity == "reg") {
		for (int i = y; i >= 0; i--) {
			if (grid[i][x] == 0) {
				return(ii(x,i + 1));
			}
		}
	} else {
		for (int i = y; i < height; i++) {
			if (grid[i][x] == 0) {
				return(ii(x,i - 1));
			}
		}
	}
}

ii moveLeft(int x, int y, string gravity) {
	if (gravity == "reg") {
		for (int i = y; i < height; i++) {
			if (grid[i][x - 1] == 0) {
				return ii(x - 1, i - 1);
			}
		}
	} else {
		for (int i = y; i >= 0; i--) {
			if (grid[i][x - 1] == 0) {
				return ii(x - 1, i + 1);
			}
		}
	}
}

ii moveRight(int x, int y, string gravity) {
	if (gravity == "reg") {
		for (int i = y; i < height; i++) {
			if (grid[i][x + 1] == 0) {
				return ii(x + 1, i - 1);
			}
		}
	} else {
		for (int i = y; i >= 0; i--) {
			if (grid[i][x + 1] == 0) {
				return ii(x + 1, i + 1);
			}
		}
	}
}
int calculate(int switchCount, int x, int y, string gravity) {
	int result = 1000000;
	if (dp[y][x] != -1) {
		result = dp[y][x];
	} else if (visited[y][x] != false) {
		result = 1000000;
	} else if (grid[y][x] == 4) {
		result = switchCount;
	} else {
		visited[y][x] = true;
		int left = 1000000,right = 1000000,flip = 1000000;
		if (validMove(x,y,"l",gravity)) {
			ii movedLeft = moveLeft(x,y,gravity);
			left = calculate(switchCount,movedLeft.first, movedLeft.second, gravity);
		}
		if (validMove(x,y,"r",gravity)) {
			ii movedRight = moveRight(x,y,gravity);
			right = calculate(switchCount,movedRight.first, movedRight.second, gravity);
		}
		if (validMove(x,y,"g",gravity)) {
			ii flipped = flipGravity(x,y,gravity);
			string oppositeGravity;
			if (gravity == "reg") {
				oppositeGravity = "rev";
			} else {
				oppositeGravity = "reg";
			}
			flip = calculate(switchCount + 1, flipped.first, flipped.second, oppositeGravity);
		}
		result = min(left,right);
		result = min(result,flip);
		dp[y][x] = result;
	}
	return result;
}

int main() {
	ifstream fin;
	ofstream fout;
	fin.open("gravity.in");
	fout.open("gravity.out");

	fin >> width >> height;

	grid = new int *[height];
	dp = new int *[height];
	visited = new bool *[height];

	ii cPos, dPos;

	for (int i = 0; i < height; i++) {

		grid[i] = new int [width];
		dp[i] = new int [width];
		visited[i] = new bool [width];

		for (int j = 0; j < width; j++) {
			char cell;
			fin >> cell;
			if (cell == '#') {
				grid[i][j] = 0;
			} else if (cell == '.') {
				grid[i][j] = 1;
			} else if (cell == 'C') {
				grid[i][j] = 3;
				cPos.first = i;
				cPos.second = j;
			} else {
				grid[i][j] = 4;
				dPos.first = i;
				dPos.second = j;
			}
			dp[i][j] = -1;
			visited[i][j] = false;
		}
	}

	fout << calculate(0,cPos.second,cPos.first,"reg") << endl;
	fin.close();
	fout.close();

}
