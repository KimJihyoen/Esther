#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
 // 위치,방향,값

string result = "YES";
char map[20][20];
bool chk[20][20][4][16];
int sr = 0, sc = 0;
int dx[4] = { 1,-1,0,0 }; //남북서동
int dy[4] = { 0,0,-1,1 };
int r, c;
int d;
bool isend = false;
int mem = 0;

void changedir() {
	int memcp;
	int tr;
	int tc;
	bool chkcpy[20][20][4][16];
	while (1) {
		char a = map[sr][sc];


		int ctoi = a - '0';
		if (ctoi >= 0 && ctoi < 10) {
			mem = int(a - '0');
		}
		else {
			switch (a) {
			case '>':
				d = 3;
				break;
			case '<':
				d = 2;
				break;
			case '^':
				d = 1;
				break;
			case 'v':
				d = 0;
				break;
			case '_':
				if (mem == 0) {
					d = 3;
				}
				else {
					d = 2;
				}
				break;
			case '|':
				if (mem == 0) {
					d = 0;
				}
				else {
					d = 1;
				}
				break;
			case '?':
				memcp = mem;
				tr = sr;
				tc = sc;
				for (int i = 0; i < 4; i++) {
					//?는 이미 한번씩 다가보는 거니까 다시 false 해줄 필요 없다.
					chk[sr][sc][i][mem] = true;
				}
				
				for (int i = 0; i < 4; i++) {
					
					mem = memcp;
					sr = tr;
					sc = tc;
					d = i;
					
					sr = ((sr + dx[d] + r) % r);
					sc = ((sc + dy[d] + c) % c);
					if (chk[sr][sc][d][mem]) {
						
						continue;
					}
					changedir();
					if (result == "YES") return;
	
				}
				
				return;
				break;
			case '.':
				break;
			case '@':
				isend = true;
				break;
			case '+':
				mem = (mem + 1) % 16;
				break;
			case '-':
				mem = (mem + 15) % 16;
				break;

			}
		}

		if (chk[sr][sc][d][mem]) {
			result = "N0";
			return;
		}
		else if (isend) {
			result = "YES";
			return;
		}
		chk[sr][sc][d][mem] = true;

		sr = ((sr + dx[d]  + r ) % r);
		sc = ((sc + dy[d] + c) % c);

	}
}
int main()
{
	int test_case;
	int T;

	freopen("input2.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{

		result = "NO";
		mem = 0;
		d = 3;//left
		memset(chk, false, sizeof(chk));
		sr = 0, sc = 0;
		isend = false;
		cin >> r >> c;
		bool hasend = false;
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> map[i][j];
				if (map[i][j] == '@') {
					hasend = true;
				}
			}
		}

		if (hasend) {
			changedir();
		}

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

