package com.ssafy.subset;

public class bitMaskTest {

	public static void main(String[] args) {

		for(int i=0;i<5;i++) {
			printBit(i);
		}

	}

	private static void printBit(int i) {
		
		for(int j=7;j>=0;j--) { // bit 수 8개
			System.out.printf("%d", (i & (1<<j))==0?0:1);
		}
		System.out.println();
	}

}
