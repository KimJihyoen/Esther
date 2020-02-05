package jongol;

import java.util.Scanner;

public class Main_1810_백설공주_김지현 {

	static int nan[] = new int[9];
	static int cnan[];
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		cnan = new int[7];
		for(int i=0;i<9;i++) {
			nan[i]=sc.nextInt();
		}
		
		choosenan(0,0,0);
	}
	private static void choosenan(int d, int r,int sum) {
		if(d==7) {
			if(sum==100) {
				for(int n:cnan) {
					System.out.println(n);
				}
			}
			return;
		}
		for(int i=r;i<9;i++) {
			if(sum+nan[i]>100) continue;
			cnan[d]=nan[i];
			choosenan(d+1,i+1,sum+nan[i]);
			
		}
	}

}
