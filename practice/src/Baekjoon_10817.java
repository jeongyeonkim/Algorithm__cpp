import java.util.Scanner;

public class Baekjoon_10817 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		int max_2 = 0;
		
		if (a>=b) {
			if (a>=c) {
				if (b>=c)
					max_2 = b;
				else 
					max_2 = c;
			}else
			max_2 = a;
		}else {
		if (b>=c) {
			if (a>=c)
				max_2 = a;
			else 
				max_2 = c;
		}else
		max_2 = b;
		}
		
		System.out.println(max_2);
	}

}
