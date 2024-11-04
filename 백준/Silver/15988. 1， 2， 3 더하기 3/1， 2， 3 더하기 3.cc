#include <bits/stdc++.h>
using namespace std;

long long dp[1000001];
int t, n;

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	dp[1] = 1; dp[2] = 2; dp[3] = 4;
	for (int i = 4; i <= 1000000; i++)
		dp[i] = (dp[i - 3] + dp[i - 2] + dp[i - 1]) % 1000000009;
	cin >> t;
	while (t--) {
		cin >> n;
		cout << dp[n] << '\n';
	}
}