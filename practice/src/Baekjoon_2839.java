import java.util.Scanner;

public class Baekjoon_2839 {
	
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int five = 0;
		int three = 0;
		
		Scanner sc = new Scanner(System.in);
		int input = sc.nextInt();
		sc.close();
		
		if(!(3 <= input)&&(input <= 5000)) {
		      System.exit(0);
		    }
		
		while(input >=0){
			if (input%5 ==0) {
				five = input/5;
				break;
			}
			else {
				input -= 3;
				three++;
			}
			five = input/5;
			if (input ==1 ||input ==2) {
				System.out.println("-1");
				return;
			}
		}
		System.out.println(five+three);
	
	}
}



