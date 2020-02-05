#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;

int n;
int answer;
char map[20];
bool bracket[20];
int oper_num;
int operate(int n1,int n2, char op) {
	switch (op) {
	case '+':
		return n1 + n2;
	case '-':
		return n1 - n2;
	case '*':
		return n1 * n2;
	}
}
int cal() {
	vector <string> v;
	for (int i = 0; i < n; ) {
		if (bracket[i]) {//괄호있으면
			string s = "";
			s += map[i];
			int temp1 = stoi(s);

			s = ""; s += map[i + 2];
			int temp2 = stoi(s);

			int result = operate(temp1, temp2, map[i + 1]);
			
			v.push_back(to_string(result));
			i += 3;
		}
		else { //괄호 없으면
			string s = "";
			s += map[i];
			v.push_back(s);
			i++;
		}
	}

	int rs =stoi(v[0]);
	for (int i = 1; i < v.size()-1; i+=2) {
		rs = operate(rs, stoi(v[i + 1]), v[i][0]);
	}
	return rs;
}
void dfs(int d) {
	if (d >= n) {
		answer = max(answer, cal());
		return;
	}

	for (int i = d; i < n; i = i + 2) {
		if (i + 2 < n) {
			//두 숫자에 괄호하나라도 있으면
			if (bracket[i] || bracket[i + 2]) continue;
			
			//괄호 하나 만들고 재귀
			bracket[i] = true;
			bracket[i + 2] = true;
			dfs(d + 2);
			bracket[i] = false;
			bracket[i + 2] = false;

		}
		else {
			//i+2가 n을 넘는다. ???
			dfs(i + 1);
		}
	}
}
 void main() {
	freopen("괄호.txt", "r", stdin);

	cin >> n;
	answer = -2100000000;
	
	for (int i = 0; i < n; i++) {
		cin >> map[i];
		bracket[i] = false;
	}
	oper_num = n / 2;
	dfs(0);

	cout << answer << endl;
}