#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

/* 1. ��ȣ �߰��ϰ� �߰����� ���� ��� ���������� ���
	�����ȣ ���� �Է¹ް� ��� ȣ���� ���� ������ �����ȣ�� �������� ��´�
	N/2�� �� ���� �����ȣ�� ���� -> �������
	���̰� N/2�� �Ѵ´ٸ� ��� �����ȣ�� ���� ����� ������ ��� ���� ���ϰ�*/

int n; //������ ����
int answer;
int num[11];
int oper[10];
int oper_num; //�������� ����
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
	freopen("��ȣ.txt", "r", stdin);
	
	cin >> n;

	string s;
	cin >> s;

	answer = -2100000000;
	int n_idx = 0;
	int op_idx = 0;
	for (int i = 0; i < s.size(); i++) {
		if (i % 2 == 0) {
			num[n_idx] = s[i] - '0';//���ڸ�����
			n_idx++;
		}
		else {
			oper[op_idx] = s[i]; //������ ����
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