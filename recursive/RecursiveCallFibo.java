package com.ssafy.recursive;

public class RecursiveCallFibo {
	/**
	 * 피보나치 수열을 출력하고 수열의 합을 리턴하는 기능
	 * @param n n번째 수열
	 * @return n번째 수열까지의 합
	 */
	static int N = 7;
	
	public static int recursivefibo(int n,int old,int cur,int sum) {

		if( n==0) {
			System.out.print(old+" ");
			return sum;
		}
		System.out.print(old+" ");
				
		return recursivefibo(n-1,cur,old+cur,sum+cur);
		
	}
	
	/*
	 * if(n==1){
	 * 	
	 */
	public static int fibo1(int n) {
		int sum =0;
		int old =0;  //n-2
		int su =1; //n-1
		int newsu =0; // n
		for(int i=1;i<=n;i++) {
			System.out.print(su+" ");
			sum+=su;
			newsu = old+su;
			old = su;
			su=newsu;
		}
		return sum;
	}
	public static int fibo2(int n) {
		if(n==1) return 1;
		else if(n==0) return 0;
		
		return fibo1(n-1)+fibo1(n-2);
	}
	
	public static int fibo3(int n,int cur, int su) {
		if(n==1) {
			System.out.print(cur+" ");
			return su;
		}
		System.out.print(cur+" ");
		return fibo3(--n,su,cur+su);
	}
	public static void main(String[] args) {
		System.out.println(fibo1(7));
		System.out.println(recursivefibo(7,0,1,0));
		System.out.println(fibo3(7,0,1));
	}

}
