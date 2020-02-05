import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Gravity_김지현2 {

	public static void main(String[] args) throws FileNotFoundException {
		
		
		
		System.setIn(new FileInputStream("res/swea/d3/gravity.txt"));
		Scanner s = new Scanner(System.in);
		
		int n = s.nextInt();
		int data[][] = new int[n][n];
		int newdata[][] = new int[n][n];
		int max =0;
		
		for(int i=0;i<n;i++) {
			int h = s.nextInt();
			for(int j=n-1;j>(n-h-1);j--) {
				data[j][i]=1;
			}
		}
		
		for(int i=0;i<n;i++) {
			for(int j=n-1;j>-1;j--) {
				newdata[i][n-1-j]=data[j][i];
			}
		}
		
		int maxcnt =0;
		for(int i=0;i<n;i++) {
			int cnt =0;
			for(int j=n-1;j>-1;j--) {
				if(newdata[j][i]==0) cnt++;
				else {
					if(maxcnt < cnt) maxcnt = cnt;
				}
			}
			
			
		}
		
		System.out.println(maxcnt);
//		for(int i=0;i<n;i++) {
//			for(int j=0;j<n;j++) {
//				System.out.print(data[i][j]);
//			}
//			System.out.println();
//		}
//		
//
//		for(int i=0;i<n;i++) {
//			for(int j=0;j<n;j++) {
//				System.out.print(newdata[i][j]);
//			}
//			System.out.println();
//		}

	}

}
