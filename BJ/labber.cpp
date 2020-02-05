#include<iostream>

using namespace std;

int map[100][100];

int main() {
	

	int test_case;
	
	freopen("input.txt", "r", stdin);
	
	
	for (int test_case = 0; test_case < 10; ++test_case)
	{
		int T;
		cin >> T;
		for (int i = 0; i < 100; i++) {
			for (int j = 0; j < 100; j++) {
				cin >> map[i][j];
			}
		}
		int result = -1;
		for (int i = 0; i < 100; i++) {
			if (map[0][i] == 0) continue; //�������� 0�̸� skip

			int c = i;
			for (int r = 1; r < 100; r++) {
				if (c > 0 && map[r][c - 1]) {//left
					while (map[r][c]) {
						c--;
						if (c == -1) break;
					}
					c++;
					//TODO if(c < 0) c>0 �����̶� map[r][c]���� ���� ó���ϱ�
				}
				else if (c < 99 && map[r][c + 1]) {//right
					while (map[r][c]) {
						c++;
						if (c == 100) break;
					}
					c--;
				}
				
			}

			if (map[99][c] == 2) result = i;
		}


		cout << "#" << T << " " << result << endl;
	}
	return 0;//��������� �ݵ�� 0�� �����ؾ��մϴ�.

}