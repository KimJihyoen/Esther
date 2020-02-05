#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n; //�̴� ��
int ening[50][9]; //�̴׼�, ���� ��ȣ
bool chk[9]; //���� üũ
int per[9];
int score;
int calc() {
	int idx = 0;
	int q_start_idx = 0;
	int q_end_idx = 0;
	int whole_ening[27];
	int out_num = 0;
	int ening_num = 0;
	int result = 0;

	memset(whole_ening, 0, sizeof(whole_ening));
	while (ening_num < n) {

		int ta = ening[ening_num][per[idx]]; // Ÿ�ڰ� ģ ��

		if (ta == 0) {
			out_num++;

			if (out_num == 3) {
				ening_num++;
				out_num = 0;
				memset(whole_ening, 0, sizeof(whole_ening));
				q_start_idx = 0;
				q_end_idx = 0;
			}
			idx = (idx + 1) % 9;
			continue;
		}
		q_end_idx++; //Ÿ�� �� ť�� ������ �ε��� �� �ø�

		//�� ���� Ÿ�ڵ鿡 ���� ģ Ÿ����ŭ ����
		for (int i = q_start_idx; i < q_end_idx; i++) {
			whole_ening[i] += ta;
			if (whole_ening[i] > 3) { //Ÿ�� ����
				result++;
				q_start_idx++;
			}
		}



		idx = (idx + 1) % 9;
	}

	return result;
}

void dfs(int depth) {
	if (depth == 9) {
		score = max(score, calc());
		return;
	}
	else if (depth == 3) {
		dfs(4);
		return;
	}

	for (int i = 1; i < 9; i++) {//Ÿ�ڹ�ȣ
		if (chk[i]) continue;

		chk[i] = true;
		per[depth] = i;
		dfs(depth + 1);
		chk[i] = false;
	}
}
int main() {


	cin >> n;
	score = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> ening[i][j];
			chk[j] = false;
		}

	}
	chk[0] = true;
	per[3] = 0;
	//ening[i][0] �� 4�� Ÿ�ڷ� ����!
	dfs(0);

	cout << score << endl;

	return 0;

}