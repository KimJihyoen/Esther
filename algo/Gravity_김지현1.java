import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class Gravity_김지현1 {
	
//	public void build_data(int[] data) {
//				
//		for(int i=0;i<100;i++) {
//			data[i] = (int)(Math.random() *100);
//		}
//	}

	public static void main(String[] args) throws FileNotFoundException {
		int data[] = new int[100];

		System.setIn(new FileInputStream("res/swea/d3/gravity.txt"));
		Scanner s = new Scanner(System.in);
		
		int n = s.nextInt();
		int max =0;
		int maxidx =0;

		
		for(int i=0;i<n;i++) {
			data[i]=s.nextInt();
			if(max < data[i]) {
				max=data[i];
				maxidx = i;
			}

		}
		int sidx =0;
		for(int i=0;i<n;i++) {
			if(data[i]!=0) {
				sidx =i;
				break;
			}
		}
		int maxcnt =0;
		for(int i=sidx;i<=maxidx;i++) {
			int cnt =0;
			for(int j=i+1;j<n;j++) {
				if(data[i]>data[j]) cnt++;
			}
			
			if(cnt > maxcnt) maxcnt =cnt;
		}
		
		
		System.out.println(maxcnt);

		
	}

}
