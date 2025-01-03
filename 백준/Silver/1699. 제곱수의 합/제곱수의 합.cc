#include <bits/stdc++.h>
using namespace std;

int n;
int dp[100001];

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> n;
	for (int i = 1; i <= n; i++)
		dp[i] = i;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j * j <= i; j++)
			dp[i] = min(dp[i], dp[i - j * j] + 1);
	cout << dp[n];
}