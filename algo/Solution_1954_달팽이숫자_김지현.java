import java.util.Scanner;

public class Solution_1954_달팽이숫자_김지현 {

	public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		int T;
		T=sc.nextInt();
		int[] dx = {0,1,0,-1};
		int[] dy = {1,0,-1,0};
		

		for(int test_case = 1; test_case <= T; test_case++)
		{
			int n = sc.nextInt();
			int arr[][]= new int[n][n];
			boolean chk[][]=new boolean[n][n];
					
			System.out.println("#"+test_case);
			
			int val = 2;
			arr[0][0]=1;
			chk[0][0]=true;
			int tr=0,tc=0;
			int d_idx =0;
			do{
				
				tr+=dx[d_idx];
				tc+=dy[d_idx];
				
				
				if(tr < 0||tr > n-1||tc < 0||tc > n-1||chk[tr][tc]) {
					tr-=dx[d_idx];
					tc-=dy[d_idx];
					
					d_idx++;
					if(d_idx > 3) d_idx=0; 
					continue;
					
				}
				
				arr[tr][tc]=val;
				chk[tr][tc]=true;
				val++;
			}while(val<=n*n);
			
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					System.out.print(arr[i][j]+" ");
				}
				System.out.println();
			}
			
		}
	}

}
