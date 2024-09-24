#include <bits/stdc++.h>
using namespace std;

struct point {
	int y, x, cnt, d;
};

int N, M, K;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };
char board[1001][1001];
bool visited[1001][1001][11];

bool is_in_range(int y, int x) {
	return y >= 0 && y < N && x >= 0 && x < M;
}

int bfs(int y, int x) {
	queue<point> q;
	q.push({ y, x, 0, 1 });
	for (int c = 0; c < 11; c++)
		visited[y][x][c] = true;

	while (!q.empty()) {
		point cur = q.front();
		q.pop();

		if (cur.y == N - 1 && cur.x == M - 1)
			return cur.d;

		for (int i = 0; i < 4; i++) {
			int cy = cur.y + dy[i];
			int cx = cur.x + dx[i];

			if (!is_in_range(cy, cx))
				continue;
			if (board[cy][cx] == '1' && cur.cnt < K && !visited[cy][cx][cur.cnt + 1]) {
				q.push({ cy, cx, cur.cnt + 1, cur.d + 1 });
				for (int c = cur.cnt + 1; c < 11; c++)
					visited[cy][cx][c] = true;
			}
			else if (board[cy][cx] == '0' && !visited[cy][cx][cur.cnt]) {
				q.push({ cy, cx, cur.cnt, cur.d + 1 });
				for (int c = cur.cnt; c < 11; c++)
					visited[cy][cx][c] = true;
			}
		}
	}
	return -1;
}

int main(void) {
	cin.tie(NULL);
	ios_base::sync_with_stdio(false);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> board[i][j];

	cout << bfs(0, 0);
}