package com.ssafy.permutation;

import java.util.Arrays;
import java.util.Scanner;

public class Permutation_nPIn {
	static int N;
	static int[] Numbers;
	static int testcase;
	public static void main(String[] args) {
		
		Scanner s= new Scanner(System.in);
		
		N = s.nextInt();
		Numbers = new int[N];
		permutation(0);
		System.out.printf("중복순열 %dㅠ%d의 개수 : %d",N,N,testcase);
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
		for(int i=1;i<=N;i++) {
			Numbers[cnt]=i;
			permutation(cnt+1);
		}
	}
}
