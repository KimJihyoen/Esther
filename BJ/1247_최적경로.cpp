#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
int n;
int cr, cc, hr, hc; //ȸ�� ��ǥ, ����ǥ
bool chk[10];
vector <pair<int, int>> v;
int dis;
void dfs(int d,int ds,int r, int c) {
	if (d == n) {
		int dist = (abs(r - hr) + abs(c - hc)) + ds; // ������ �Ÿ�
		if (dis > dist) {
			dis = dist;
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (chk[i]) continue;
		
		int caldis = (abs(r - v[i].first) + abs(c - v[i].second)) + ds;
		if (caldis > dis) continue;
		
		chk[i] = true;		
		dfs(d + 1,caldis,v[i].first,v[i].second);
		chk[i] = false;
	}
}
int main()
{
	int test_case;
	int T;

	freopen("�������.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{

		
		cin >> n;
		dis = 100 * 2 * n;
		
		cin >> cr >> cc >> hr >> hc;

		for (int i = 0; i <n;i++){
			int r, c;
			cin >> r >> c;
			v.push_back({ r,c });
		}

		dfs(0,0,cr,cc);

		cout << "#" << test_case << " " << dis << endl;

		v.clear();
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.
}

