import java.util.Scanner;

public class Baekjoon_1152 {
	public static void main (String[] args){
		Scanner sc = new Scanner(System.in);
		
		String msg = sc.nextLine();
		String [] a = msg.split(" ");
		
		int count = 0;
		for(int i = 0 ; i < a.length; i++)
		{
			if (!a[i].equals("")){
			count++;	
			}
		}
		System.out.println(count);
		
	}
}