/* ॐ */
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

const int N = 1000;

void solve();

int32_t main() {
	#ifndef ONLINE_JUDGE
	freopen("./input.txt","r",stdin);
	freopen("./output.txt","w",stdout);
	#endif
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	solve();
	return 0;
}

void solve() {
	vector<int> a, b;
	for(int i=0; i<N; i++) {
		int num1, num2;
		cin >> num1 >> num2;
		a.push_back(num1);
		b.push_back(num2);
	}
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	long long sum = 0;
	for(int i = 0; i<N; i++) {
		sum += abs(a[i] - b[i]);
	}
	cout<<sum<<"\n";
}