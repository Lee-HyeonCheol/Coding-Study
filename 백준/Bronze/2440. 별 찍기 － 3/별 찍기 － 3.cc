#include <bits/stdc++.h>
using namespace std;

int main(void) {
	int N; cin >> N;
	for (int i = N; i > 0; i--) {
		for (int j = 0; j < i; j++)
			putchar('*');
		putchar('\n');
	}
}