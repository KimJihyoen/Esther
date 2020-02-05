import java.util.Scanner;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.LinkedList;
import java.util.Queue;
/*
 * �ִ� ��θ� ã�� ���� �ƴ� �ܼ��� ���������� ���� ã�ư��� ���̶�
 * �ٸ� �ڵ�� ���� DFS�� Ǯ� �ѱ�� ������ ã�� ���Բ���
 * BFS���� DFS�� Ǯ�� �ֵ���
 */
class Pair{
	int r,c;
	
	Pair(int r,int c){
		this.r=r;
		this.c=c;
	}
}
public class Solution_1226_�̷�1 {

	
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new FileInputStream("�̷�1.txt"));
		Scanner sc = new Scanner(System.in);
		
		
		int map[][]=new int[16][16];
		
		int[] dx= {0,0,1,-1};
		int[] dy= {1,-1,0,0};

		for(int test_case = 1; test_case <= 10; test_case++)
		{	
			sc.nextInt();
			sc.nextLine();
			boolean chk[][] = new boolean[16][16];
			for(int i=0;i<16;i++) {
				String s = sc.nextLine();
				for(int j=0;j<16;j++) {
					map[i][j]=Integer.parseInt(s.substring(j, j+1));
				}
			}
			
			int result = 0;
			Queue<Pair> q = new LinkedList<Pair>();
			
			q.offer(new Pair(1,1));
			chk[1][1]=true;
			int str;
			int stc;
			
			top:
			while(!q.isEmpty()) {
				int size = q.size();
				
				for(int i=0;i<size;i++) {
					str = q.peek().r;
					stc = q.poll().c;
					
					int tr;
					int tc;
					for(int d=0;d<4;d++) {
						tr = str;
						tc = stc;
						
						tr+=dx[d];
						tc+=dy[d];
						
						if(tr<0||tr>15||tc<0||tc>15||map[tr][tc]==1||chk[tr][tc]) continue;
						
						if(map[tr][tc]==3) {
							result=1;
							break top;
						}
						q.offer(new Pair(tr,tc));
						chk[tr][tc]=true;
					}
				}
			}
			
			
			System.out.println("#"+test_case+" "+result);
		}

	}

}
