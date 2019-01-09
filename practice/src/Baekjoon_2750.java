import java.util.Scanner;

public class Baekjoon_2750 {
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		int num = sc.nextInt();
		int[] array = new int[num];
		int temp=0;
		//데이터 입
		for(int i=0; i<num; i++) {
			array[i] = sc.nextInt();
		}
		//버블 정렬 
		for(int i=0; i<num; i++) {
			for(int k=(num-1); k>i; k--) {
				if(array[k] < array[k-1]) {
					temp = array[k];
					array[k] = array[k-1];
					array[k-1] = temp;
				}
			}
		}
		//출력 
		for(int i=0; i<num; i++) {
			System.out.println(array[i]);
		}
	}

}
