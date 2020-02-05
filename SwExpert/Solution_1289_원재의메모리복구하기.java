package swea.d3;

import java.io.FileInputStream;
import java.util.Scanner;

public class Solution_1289_원재의메모리복구하기 {

	public static void main(String[] args) throws Exception{
		
		System.setIn(new FileInputStream("res/swea/d3/1289_�����Ǹ޸𸮺����ϱ�.txt"));
		Scanner s = new Scanner(System.in);
		//Scanner scan = new Scanner(new FileInputStream(""));
		
		int T = s.nextInt();
		for(int test_case = 1; test_case<=T; test_case++) {
			int cnt = 0;
			
			String data = s.next();
			int size = data.length();
			
			//startsWith(str) : ���ڿ��� ������ ���ڿ��� �����ϸ� true, �ƴϸ� false
			if(data.startsWith("1")) {
				cnt++;
			}
			
			for(int i=0;i < size-1;i++) {
				if(data.charAt(i) != data.charAt(i+1)) {
					cnt++;
				}
			}
			
			System.out.println("#"+test_case+" "+cnt);
		}
	}
	
}
