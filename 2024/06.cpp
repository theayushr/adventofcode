/* ॐ */
//https://adventofcode.com/2024/day/3#part2
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>
#include <utility>
using namespace std;

const string regex = "mul(000,000)";
const unordered_map<char, int> ascii {
	{'0',48},
	{'1',49},
	{'2',50},
	{'3',51},
	{'4',52},
	{'5',53},
	{'6',54},
	{'7',55},
	{'8',56},
	{'9',57},
};
const int comma = 44; //ascii for ','
const string DO = "do()";
const string DONT = "don't()";

void adventofcode();
pair<int,int> isValid(string braces);

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
	string input;
	long long result = 0;
	bool isDo = true;
	while(std::getline(cin, input)) {
		for (int i =0; i<input.size(); i++) {
			long long currMul = 1;
			if (input.substr(i, DO.size()) == DO) {
				isDo = true;
			}
			if (input.substr(i, DONT.size()) == DONT) {
				isDo = false;
			}
			pair<int,int> nums = isValid(input.substr(i, regex.size()));
			currMul *= nums.first;
			currMul *= nums.second;
			if (isDo) result += currMul;
		}
	}
	cout<<result;
}

pair<int,int> isValid(string input) {
	if (input.substr(0, 4) == regex.substr(0,4)) {
		string nums = input.substr(4, regex.size()-4);
		string first = "";
		string second = "";
		bool isComma = false;
		bool isEndsWell = false;
		for(char ele : nums) {
			if (!isComma && (int)ele == comma) {
				isComma = true;
				continue;
			}
			if (!isComma && ascii.find(ele) != ascii.end()) {
				first += ele;
				continue;
			}
			if (isComma && ascii.find(ele) != ascii.end()) {
				second += ele;
				continue;
			}
			if (isComma && ascii.find(ele) == ascii.end() && ele ==')') {
				isEndsWell = true;
				continue;
			}
			break;
		}
		if (isEndsWell && first.size() != 0 and second.size() != 0){
 			return {stoi(first), stoi(second)};
		}
	}
	return {0,0};
}