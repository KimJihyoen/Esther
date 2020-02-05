package com.ssafy.permutation;

public class Permutation_For {

	public static void main(String[] args) {
		System.out.println("===========중복순열============");
		//n개중에 n개 뽑기
		int n=3;
		int cnt =0;
		for(int i=1;i<=n;i++) { //첫번째 원소 뽑기
			for(int j=1;j<=n;j++) { //두번째 원소 뽑기
				for(int k=1;k<=n;k++) { //세번째 원소 뽑기
					cnt++;
					System.out.printf("%d %d %d\n",i,j,k);
				}
			}
		}
		System.out.printf("%dㅠ%d의 개수 : %d\n",n,n,cnt);
		
		System.out.println("===========순열============");
		

		cnt =0;
		for(int i=1;i<=n;i++) { //첫번째 원소 뽑기
			for(int j=1;j<=n;j++) { //두번째 원소 뽑기
				if(i==j) continue;
				for(int k=1;k<=n;k++) {
					if(k==i||j==k) continue;//세번째 원소 뽑기
					cnt++;
					System.out.printf("%d %d %d\n",i,j,k);
				}
			}
		}
		System.out.printf("%dP%d의 개수 : %d\n",n,n,cnt);
	}

}
