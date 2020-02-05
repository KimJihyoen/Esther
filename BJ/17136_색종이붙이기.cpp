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

	// �ش� ���� �� Ȯ�� �ؼ� ���� �� Ȯ��
	if (c == 10) {
		dfs(r + 1, 0);
		return;
	}
	// �� ������ �ٱ��� �� Ȯ�������Ƿ� ���� ������ ���� Ȯ��
	if (r == 10) {
		result = min(result, paper_cnt);
		return;
	}

	// ���� �ʿ� �����Ƿ� ����ĭ
	if (map[r][c] == 0) {
		dfs(r, c + 1);
		return;
	}

	for (int k = 5; k > 0; k--) { //������ 5�� ũ�����

		//���� k ũ���� �����̰� ���ų� ������ �� ������ ����� continue
		if (paper[k] == 0 || r + k > 10 || c + k > 10) continue;

		// k ���̸��� ���簢���� �����ϴ��� Ȯ��
		if (!iscovered(r, c, k)) continue;

		//�����ٰ� ġ��
		covervalue(r, c, k, 0);

		paper[k]--;
		paper_cnt++;

		dfs(r, c + 1);

		// ������ ������ ġ���
		covervalue(r, c, k, 1);

		paper[k]++;
		paper_cnt--; //���� ������ �� ����
	}
}

int main()
{
	int test_case;
	int T=8;

	freopen("������.txt", "r", stdin);

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
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}
