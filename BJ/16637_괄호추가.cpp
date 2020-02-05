#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/* 1. 괄호 추가하고 추가하지 않은 경우 순차적으로 계산
	연산기호 따로 입력받고 재귀 호출할 때의 기준은 연산기호를 기준으로 잡는다
	N/2를 한 값이 연산기호의 갯수 -> 재귀조건
	깊이가 N/2를 넘는다면 모든 연산기호에 대한 계산을 끝내서 재귀 진행 안하게*/

int n; //수식의 길이
int answer;
int num[11];
int oper[10];
int oper_num; //연산자의 갯수
int cal(int n1, int n2, char oper) {
	switch (oper) {
	case '+':
		return n1 + n2;
	case '-':
		return n1 - n2;
	case '*':
		return n1 * n2;
	}
}
void dfs(int idx, int result) {
	if (idx >= oper_num) {
		answer = max(answer, result);
		return;
	}

	int cur_result = cal(result, num[idx + 1], oper[idx]);
	dfs(idx + 1, cur_result);

	if (idx + 1 < oper_num) {
		int after_result = cal(num[idx + 1], num[idx + 2], oper[idx + 1]);
		int cur_result = cal(result, after_result, oper[idx]);
		dfs(idx + 2, cur_result);
	}
}
int main() {
	freopen("괄호.txt", "r", stdin);
	
	cin >> n;

	string s;
	cin >> s;

	answer = -2100000000;
	int n_idx = 0;
	int op_idx = 0;
	for (int i = 0; i < s.size(); i++) {
		if (i % 2 == 0) {
			num[n_idx] = s[i] - '0';//숫자만저장
			n_idx++;
		}
		else {
			oper[op_idx] = s[i]; //연산자 저장
			op_idx++;
		}
	}
	oper_num = n / 2;


	if (n == 1) {
		cout << num[0] << endl;
		return;
	}
	else if (n == 3) {
		cout << cal(num[0], num[1], oper[0]) << endl;
		return;
	}

	dfs(0, num[0]);

	cout << answer << endl;
	
}