package com.ssafy.recursive;

public class RecursiveCallFactorial {
	static int N=7;
	public static int fac1(int n) {
		if(n==1) return 1;
		return n*fac1(n-1);
		
		
	}
	
	public static int fac2(int n) {
		if(n==N) return N;
		return n*fac2(n+1);
	}

	public static void main(String[] args) {
		
		
		int fac =1;
		for(int i=2;i<=N;i++) {
			fac*=i;
			System.out.printf("%d: %d\n",i,fac);
		}
		
		System.out.println(fac1(N));
		System.out.println(fac2(1));
	}
	
}
