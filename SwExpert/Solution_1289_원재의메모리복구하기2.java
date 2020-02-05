package swea.d3;

import java.io.FileInputStream;
import java.util.Scanner;

public class Solution_1289_원재의메모리복구하기2 {
	static int cnt =0;
	public static void main(String[] args) throws Exception{
		
		System.setIn(new FileInputStream("res/swea/d3/1289_�����Ǹ޸𸮺����ϱ�.txt"));
		Scanner s = new Scanner(System.in);
		//Scanner scan = new Scanner(new FileInputStream(""));
		
		int T = s.nextInt();
		for(int test_case = 1; test_case<=T; test_case++) {
			cnt = 1;
			
			String data = s.next();
			int size = data.length();
			
			StringBuilder nData = new StringBuilder(data); //��Ʈ�� �����ؼ� ������ ������ ���� ���
			//ù 1�� ��ġ�� ã��
			
			int idx = data.indexOf('1'); //1�� �����ϴ� ��ġ �ε���
			
			for(int i=idx;i<size;) {
				
				change(nData,i,size,""+(cnt%2));//nData�� i���� cnt%2������ �� �ٲ��ش�.
				
				if(data.equals(nData.toString())) break; //������ break
				
				for(int j=i+1;j<size;j++) {
					// �� ���ڿ��� �� charAt(index) : ���ڿ��� �ε��� ��ġ�� �ش��ϴ� ���� �ϳ��� ����
					if(data.charAt(j) != nData.charAt(j)) {
						//j�ε������� ���� ���ڿ� �ٸ��ٸ� i�� �ٸ� �ε��� ������ �ٲٰ� break ����
						// �ٽ� i���� change�����Ѵ�.
						i=j;
						break;
					}
				} 
				cnt++;
			}
			
			System.out.println("#"+test_case+" "+cnt);
		}
	}
	private static void change(StringBuilder nData, int start, int end, String fill) {
		for(int i=start;i<end;i++) {
			nData.replace(i, i+1, fill);
		}
		
	}
}
