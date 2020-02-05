package jongol;

import java.util.Scanner;

public class Main_1175_주사위던지기2_김지현 {

	static int N;
	static int M;
	static int[] dices;
	public static void main(String[] args) {
		
		Scanner s= new Scanner(System.in);
		
		N = s.nextInt();
		M = s.nextInt();
		
		dices=new int[N];
		
		getsum(0,0);
	}
	public static void getsum(int d,int sum) {
		if(d==N) {
			if(sum==M) {
			 for(int i=0;i<N;i++) {
				 System.out.print(dices[i]+" ");
			 }
			 System.out.println();
			}
			return;
		}
		
		for(int i=1;i<=6;i++) {
			dices[d]=i;
			getsum(d+1,sum+i);
			
		}
		
		
	}

}
