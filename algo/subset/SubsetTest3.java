package com.ssafy.subset;

import java.util.Arrays;

public class SubsetTest3 {

	public static void main(String[] args) {
		long start = System.currentTimeMillis();
		int[] arr = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
		
		int n = arr.length;  //5
		int size = 1<<n; //부분 집합 개수
		int[] select = new int[n];//선택 된거
		int[][] subset = new int[size][n];
		
	
		for(int i=0 ;i<size;i++) { //나올 수 있는 부분집합 개수만큼
			//int[] select = new int[n];
			for(int j = 0;j<n;j++) { //n번째가 들어있는지 확인
				if((i & 1<<j)!=0) {
					select[j]=1;
				}
			}
			subset[i]=Arrays.copyOf(select,n);
			Arrays.fill(select, 0);
			//select 생성을 포문 안에 하는 것보다 빠름, 객체 생성하는게 더 오래걸림
		}
		long end = System.currentTimeMillis();		
		System.out.println(end-start);
		
		for(int[] s: subset) {
			System.out.println(Arrays.toString(s));
		}
		
		//Integer.toBinaryString(i);
	}

}
//밀리세컨드 
//n이 10000개면  n이 16승=65536 2의14승 16384