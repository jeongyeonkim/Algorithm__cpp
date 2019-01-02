import java.util.Scanner;

public class Baekjoon_1546 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int[] score = new int[n];
		int max =0;
		double sum=0;
	
		for(int i=0; i<n; i++) {
			score[i] = sc.nextInt();
			sum += score[i];
			if(score[i]>max)
				max = score[i];
		}
		double avg = (sum/max*100)/n;
		System.out.printf("%.2f", avg);
	
	}

}
