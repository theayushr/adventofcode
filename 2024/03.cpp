/* ॐ */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <sstream>

using namespace std;

const int N = 1000;

void adventofcode();
bool isSafe(vector<int> nums);

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

std::vector<std::string> split_string(const std::string &str, char delim = ' ') {
    std::vector<std::string> tokens;
    std::stringstream ss(str);
    std::string token;
    while (getline(ss, token, delim)) {
        if (!token.empty())
            tokens.push_back(token);
    }
    return tokens;
}

void adventofcode() {
	int ans = 0;
	for(int i=0; i<N; i++) {
		string line;
		std::getline(std::cin, line);
		vector<string> numsStr = split_string(line, ' ');
		vector<int> nums;
		for(string ele : numsStr) nums.push_back(stoi(ele));
		ans += isSafe(nums);
	}
	cout<<ans;
}

bool isSafe(vector<int> nums) {
	if(nums.size() == 1) return true;
	bool incr = (nums[1] - nums[0]) > 0;
	for(int i=1; i<nums.size(); i++) {
		int diff = nums[i] - nums[i-1];
		if (incr && diff >= 1 && diff <= 3) continue;
		if (!incr && diff <= -1 && diff >= -3 ) continue;
		return false;
	}
	return true;
}