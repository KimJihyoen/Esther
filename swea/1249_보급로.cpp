#include<iostream>
#include<queue>
#include<string>
#include<cstring>
#define INT_MAX 2147483647
using namespace std;
int map[100][100];
int chk[100][100];
struct road {
	int r, c, d;
};

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int dx[4] = { 0,0,1,-1 };
	int dy[4] = { 1,-1,0,0 };
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int result = 0;
		int n;
		memset(chk, -1, sizeof(chk));
		queue <road> q;
		cin >> n;
		string s;
		for (int i = 0; i < n; i++) {
			cin >> s;

			for (int j = 0; j < n; j++) {
				map[i][j] = int(s[j] - '0');
			}
		}
		q.push({ 0,0,0 });

		int mini = INT_MAX;
		int r, c, depth;
		while (!q.empty()) {
			int sz = q.size();

			for (int i = 0; i < sz; i++) {
				r = q.front().r;
				c = q.front().c;
				depth = q.front().d;
				q.pop();

				for (int d = 0; d < 4; d++) {
					int tr = r + dx[d];
					int tc = c + dy[d];
					int newdp = depth + map[tr][tc];


					if (tr<0 || tr>n - 1 || tc<0 || tc>n - 1 || (chk[tr][tc] != -1 && chk[tr][tc] <= newdp) || newdp >= mini) continue;

					if (tr == n - 1 && tc == n - 1) {
						if (mini > depth) {
							mini = depth;
						}
						break;
					}

					q.push({ tr,tc,newdp });
					chk[tr][tc] = newdp;
				}

			}
		}


		cout << "#" << test_case << " " << mini << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}