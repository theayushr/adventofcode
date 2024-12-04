/* ॐ */
//https://adventofcode.com/2024/day/4#part1
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;

const string XMAS = "XMAS";

void adventofcode();
int32_t main() {
	#ifndef ONLINE_JUDGE
	freopen("./input.txt","r",stdin);
	freopen("./output.txt","w",stdout);
	#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	adventofcode();
	return 0;
}

void adventofcode() {
	vector<vector<char>> rect;
	string line;
	while (getline(cin,line)) {
		vector<char> v;
		for(char c : line) v.push_back(c);
		rect.push_back(v);
	}

	int result = 0;
	const int nrow = rect.size();
	const int ncol = rect[0].size();

	int rows = rect.size();
	while (rows--) {
		int row = nrow-rows-1;
		for (int i=0; i<ncol; i++) {
			//checking in all the 8 directions if it makes XMAS

			//east
			if (i+4 <= ncol) {
				string test;
				test += rect[row][i+0];
				test += rect[row][i+1];
				test += rect[row][i+2];
				test += rect[row][i+3];
				result += test == XMAS;
			}

			//south
			if (row+4 <= nrow) {
				string test;
				test += rect[row+0][i];
				test += rect[row+1][i];
				test += rect[row+2][i];
				test += rect[row+3][i];
				result += test == XMAS;
			}

			//west
			if (i-3 >=0) {
				string test;
				test += rect[row][i-0];
				test += rect[row][i-1];
				test += rect[row][i-2];
				test += rect[row][i-3];
				result += test == XMAS;
			}

			//north
			if (row-3 >=0) {
				string test;
				test += rect[row-0][i];
				test += rect[row-1][i];
				test += rect[row-2][i];
				test += rect[row-3][i];
				result += test == XMAS;
			}

			//north-east
			if (i+4 <= ncol && row-3 >=0) {
				string test;
				test += rect[row-0][i+0];
				test += rect[row-1][i+1];
				test += rect[row-2][i+2];
				test += rect[row-3][i+3];
				result += test == XMAS;
			}

			//south-east
			if (i+4 <= ncol && row+4 <= nrow) {
				string test;
				test += rect[row+0][i+0];
				test += rect[row+1][i+1];
				test += rect[row+2][i+2];
				test += rect[row+3][i+3];
				result += test == XMAS;
			}

			//south-west
			if (i-3 >= 0 && row+4 <= nrow) {
				string test;
				test += rect[row+0][i-0];
				test += rect[row+1][i-1];
				test += rect[row+2][i-2];
				test += rect[row+3][i-3];
				result += test == XMAS;
			}

			//north-west
			if (i-3 >=0 && row-3 >=0) {
				string test;
				test += rect[row-0][i-0];
				test += rect[row-1][i-1];
				test += rect[row-2][i-2];
				test += rect[row-3][i-3];
				result += test == XMAS;
			}
		}
	}
	cout<<result;
}