import java.util.Scanner;

public class Baekjoon_1924 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int month = sc.nextInt();
		int day = sc.nextInt();
		String output="";
		
		int sum[] = new int[13];
		sum[1]=sum[3]=sum[5]=sum[7]=sum[8]=sum[10]=sum[12]=31;
		sum[4]=sum[6]=sum[9]=sum[11]=30;
		sum[2]=28;
		
		int a=0;
		
		for (int i=0; i<month; i++) {
			a += sum[i];
		}
		
		a += day;
		
		switch(a%7) {
		case 1 : 
			output = "MON";
			break;
		case 2 : 
			output = "TUE";
			break;
		case 3 : 
			output = "WED";
			break;
		case 4 : 
			output = "THU";
			break;
		case 5 : 
			output = "FRI";
			break;
		case 6 : 
			output = "SAT";
			break;
		case 0 : 
			output = "SUN";
			break;
		
		}
		System.out.println(output);
		}

}
