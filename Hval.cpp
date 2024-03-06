#include<algorithm>
#include<map>
#include<stack>
#include<string>
#include<vector>
#include<iostream>
#include<stdlib.h>
#include<math.h>
#include<set>
#include<queue>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
const int N = 100001;
int num[N];
int n, l, pos, j, tmp;
bool check(int pos) {
	if (pos - num[pos] > 1) {
		return false;
	}
	tmp = 0;
	for (int i = pos; i >= 1; --i) {
		if (num[i] >= pos) {
			tmp = i;
			break;
		}
	}
	if (l >= pos - tmp)	return true;
	return false;
}
int main() {
	cin >> n >> l;
	for (int i = 1; i <= n; ++i) {
		cin >> num[i];
	}
	sort(num + 1, num + n + 1, greater<int>());
	for (int i = 1; i <= n; ++i) {
		if (num[i] < i) {
			pos = i;
			break;
		}
	}
	while (pos <= n) {
		if (check(pos)) {
			if (pos == n) break;
			pos++;
		}
		else {
			pos--;
			break;
		}
	}
	cout << pos;
	return 0;
}
