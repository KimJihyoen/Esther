package com.ssafy.combination;

import java.util.Arrays;
import java.util.Scanner;

public class Combination2 {
	//subsetTest2
	static int[] arr = {3,6,7,1,5};
	static int r;
	static int[] combi;
	
	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		r=sc.nextInt();
		int n = arr.length;  //5
		combi=new int[n];
		
		int k;
		
		for(int i=0,size = 1<<n;i<size;i++) { //나올 수 있는 부분집합 개수만큼
			k=0;
			for(int j = 0;j<n;j++) { //j번째가 1인지 확인
				if((i & 1<<j)!=0) {
					combi[k++]=j;
				}
			}
			if(k==r) { 
				print();
			}
			
		}
	}

	private static void print() {
		for(int c : combi) {
			System.out.print(c+" ");
		}
		System.out.println();
	}

}
