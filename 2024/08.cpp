/* ॐ */
//https://adventofcode.com/2024/day/4#part2
#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>
using namespace std;

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

	long long result = 0;
	const int nrow = rect.size();
	const int ncol = rect[0].size();

	int rows = rect.size();
	while (rows--) {
		int row = nrow-rows-1;
		for (int i=0; i<ncol; i++) {
			if (row-1 >= 0 && row <= nrow-2 && i-1 >= 0 && i <= ncol-2 && rect[row][i] == 'A') {

				string onehalf;
				onehalf += rect[row-1][i-1];
				onehalf += rect[row+0][i+0];
				onehalf += rect[row+1][i+1];

				string secondhalf;
				secondhalf += rect[row-1][i+1];
				secondhalf += rect[row+0][i+0];
				secondhalf += rect[row+1][i-1];

				if ((onehalf == "MAS" || onehalf == "SAM") && (secondhalf == "MAS" || secondhalf =="SAM")) {
					result++;
				}
			}
		}
	}
	cout<<result;
}