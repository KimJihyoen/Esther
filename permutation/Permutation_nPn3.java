package com.ssafy.permutation;

import java.util.Arrays;
import java.util.Scanner;

public class Permutation_nPn3 {
	static int N;
	static int[] Numbers;
	static int testcase;

	public static void main(String[] args) {
		
		Scanner s= new Scanner(System.in);
		
		N = s.nextInt();
		Numbers = new int[N];

		permutation(0,0);
		System.out.printf("순열 %dㅠ%d의 개수 : %d",N,N,testcase);
	}
	/**
	 * 순열을 만들 함수
	 * @param cnt 배열의 index
	 * @return flag 데이터의 중복 여부를 검사할 bit mask
	 */
	private static void permutation(int cnt,int flag) {
		
		if(cnt == N) {
			testcase++;
			System.out.println(Arrays.toString(Numbers));
			return;
		}
		for(int i=0;i<N;i++) {
			if((flag & 1<<i)==0) {
				Numbers[cnt]=i;
				permutation(cnt+1,flag|1<<i);
			}
		}
	}
}


/*
 * 저렇게 boolean배열 말고 
 * for문 돌려서 지금 인덱스 이전에 배열을 뒤져서 나온것이 잇으면  continue할 수 있는데
 * 그러면 시간이 엄청 많이 걸림
 */
