#include<iostream>
#include<algorithm>
#define MAX 2100000000
using namespace std;

int map[10][10];
int paper[6] = { 0,5,5,5,5,5 };
int paper_cnt=0;
int result;

bool iscovered(int r,int c, int size) {
	for (int i = r; i < r + size; i++) {
		for (int j = c; j < c + size; j++) {
			if (map[i][j] == 0) return false;
		}
	}
	return true;
}

void covervalue(int r, int c, int k, int val) {
	for (int i = r; i < r + k; i++) {
		for (int j = c; j < c + k; j++) {
			map[i][j] = val;
		}
	}
}
void dfs(int r, int c) {

	// 해당 줄을 다 확인 해서 다음 줄 확인
	if (c == 10) {
		dfs(r + 1, 0);
		return;
	}
	// 맨 마지막 줄까지 다 확인했으므로 현재 색종이 갯수 확인
	if (r == 10) {
		result = min(result, paper_cnt);
		return;
	}

	// 덮을 필요 없으므로 다음칸
	if (map[r][c] == 0) {
		dfs(r, c + 1);
		return;
	}

	for (int k = 5; k > 0; k--) { //색종이 5의 크기부터

		//현재 k 크기의 색종이가 없거나 덮었을 때 범위를 벗어나면 continue
		if (paper[k] == 0 || r + k > 10 || c + k > 10) continue;

		// k 길이만한 정사각형이 존재하는지 확인
		if (!iscovered(r, c, k)) continue;

		//덮었다고 치고
		covervalue(r, c, k, 0);

		paper[k]--;
		paper_cnt++;

		dfs(r, c + 1);

		// 덮었던 색종이 치운다
		covervalue(r, c, k, 1);

		paper[k]++;
		paper_cnt--; //덮은 색종이 수 감소
	}
}

int main()
{
	int test_case;
	int T=8;

	freopen("색종이.txt", "r", stdin);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		result = MAX;
		paper_cnt = 0;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 10; j++) {
				cin >> map[i][j];
			}
		}

		
		dfs(0,0);

		if (result == MAX) {
			cout << -1 << endl;
		}
		else {
			cout << result << endl;
		}
	
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
