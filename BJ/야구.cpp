#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;

int n; //이닝 수
int ening[50][9]; //이닝수, 선수 번호
bool chk[9]; //선수 체크
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

		int ta = ening[ening_num][per[idx]]; // 타자가 친 볼

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
		q_end_idx++; //타자 들어가 큐의 마지막 인덱스 값 늘림

		//그 전의 타자들에 내가 친 타수만큼 더함
		for (int i = q_start_idx; i < q_end_idx; i++) {
			whole_ening[i] += ta;
			if (whole_ening[i] > 3) { //타자 빠짐
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

	for (int i = 1; i < 9; i++) {//타자번호
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
	//ening[i][0] 은 4번 타자로 설정!
	dfs(0);

	cout << score << endl;

	return 0;

}