package com.ssafy.permutation;

import java.util.Arrays;
import java.util.Scanner;

public class Permutation_nPn2 {
	static int N;
	static int[] Numbers;
	static int testcase;
	static boolean chk[];
	public static void main(String[] args) {
		
		Scanner s= new Scanner(System.in);
		
		N = s.nextInt();
		Numbers = new int[N];
		chk=new boolean[N];
		permutation(0);
		System.out.printf("순열 %dㅠ%d의 개수 : %d",N,N,testcase);
	}
	/**
	 * 순열을 만들 함수
	 * @param i
	 * @return
	 */
	private static void permutation(int cnt) {
		
		if(cnt == N) {
			testcase++;
			System.out.println(Arrays.toString(Numbers));
			return;
		}
		for(int i=0;i<N;i++) {
			if(chk[i]) continue;
			Numbers[cnt]=i;
			chk[i]=true;
			permutation(cnt+1);
			chk[i]=false;
		}
	}
}


/*
 * 저렇게 boolean배열 말고 
 * for문 돌려서 지금 인덱스 이전에 배열을 뒤져서 나온것이 잇으면  continue할 수 있는데
 * 그러면 시간이 엄청 많이 걸림
 */
