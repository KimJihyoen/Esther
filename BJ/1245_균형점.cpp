#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;
int n;
int xidx[10];
int m[10];

/*F = G*m1*m2/(d*d), G는 양의 상수 값*/
int main()
{
	int test_case;
	int T;

	freopen("균형점.txt", "r", stdin);
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{


		cin >> n;

		for (int i = 0; i < n; i++) {
			cin >> xidx[i];
		}

		for (int i = 0; i < n; i++) {
			cin >> m[i];
		}

		cout << "#" << test_case << " ";
		cout << fixed;
		cout.precision(10);
		for (int i = 1; i < n; i++) {
			int d1 = xidx[i - 1];
			int d2 = xidx[i];

			int m1 = m[i - 1];
			int m2 = m[i];

			double a = m1 - m2;
			double x;
			
			double b = 2 * (m2 * d1- m1*d2);
			double c = (m1 * d2*d2)- (m2 * d1*d1);
			
			if (a == 0) {
				x = -c / b;
				
				cout << x ;
			}
			else {
				float x1 = (-b + sqrt((b*b) - 4 * a*c))/ (2.0 * a);
				float x2 = (-b - sqrt(b*b - 4 * a*c)) / (2.0 * a);
				if (x1 >= d1 && x1 <= d2) {
					cout << x1<<" ";
				}
				else {
					cout << x2<<" ";
				}
				
			}

			
		}
		//

		cout << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

/*#1 1.5000000000
#2 1.0306534300
#3 462.5504629633
#4 1.4060952085 2.5939047915
#5 2.5328594461 3.7271944335 6.0999536409
#6 6.3428568767 11.5477377494 15.9641592998 24.9267991615
#7 57.8805685415 81.8651598883 91.0573691382 105.0835650491 133.2934094881
#8 74.2211477711 190.6837563313 305.8269181686 348.3304429927 470.2694219293 555.4943093854
#9 21.5171374463 47.9890597763 68.6536668433 82.9131954023 95.0052272762 99.1999097770 116.4978330953
#10 11.5573600056 24.0238341337 38.4847676134 44.6137453708 64.7500445424 126.9908128982 184.3221650927 197.9760596291 266.0574653677*/