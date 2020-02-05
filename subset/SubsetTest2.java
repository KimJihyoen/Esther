package com.ssafy.subset;

public class SubsetTest2 {

	public static void main(String[] args) {
		
		int[] arr = {3,6,7,1,5};
		int n = arr.length;  //5
		
		/*
		 * subset의 개수는 2의 n승개 
		 * size : 1 << n
		 * 0	: 원소 하나도 선택안한 서브셋
		 * 1	:맨 끝의 원소 하나를 선택한 서브셋
		 * 2	:맨 끝에서 두번째 원소 하나를 선택한 서브셋
		 * 3	:맨 끝에서 두개의 원소를 선택한 서브셋
		 * ...
		 * size - 1 1111 : 모든 원소를 선택한 서브셋 
		 * 
		 * O(1<<n) : n이 20개까지는 1초안에 구할 수 있다.
		 */
		
		for(int i=0,size = 1<<n;i<size;i++) { //나올 수 있는 부분집합 개수만큼
			for(int j = 0;j<n;j++) { //n번째가 들어있는지 확인
				if((i & 1<<j)!=0) {
					//System.out.print(j+" ");
					System.out.print(arr[j]+" ");

				}
			}
			System.out.println();
		}
	}

}
