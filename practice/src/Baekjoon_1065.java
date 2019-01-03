import java.util.Scanner;

public class Baekjoon_1065 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int count = 0;
	
		if (N<100) {
			count = N;
		}
		else {
			Baekjoon_1065 hansu = new Baekjoon_1065();
			count = hansu.Hansu(N);
		}
		
		
		System.out.println(count);
	}
	
	public int Hansu(int hansu) {
		int[] han = new int[3];
		int count=99;
		
		for(int i=111; i<=hansu; i++) {
			han[0] = i/100;
			han[1] = (i%100)/10;
			han[2] = (i%100)%10;
			if((han[0]-han[1]) == (han[1]-han[2])) {
				count++;
			}
		}
		return count;
	}
}
