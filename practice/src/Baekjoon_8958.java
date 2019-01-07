import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_8958 {
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		String input = br.readLine();
		int num = Integer.parseInt(input);
		String[] array = new String[num];
		int[] output = new int[num];
		
		for(int i=0; i<num; i++) {
			array[i] = br.readLine(); 
			output[i] = score(array[i]);
		}
		for(int i=0; i<num; i++)
			System.out.println(output[i]);
	}
	
	private static int score(String array) {
		int sum = 0;
		int score = 0;
		char[] ox = new char[array.length()];
		
		for(int i=0; i<array.length(); i++) {
			ox[i] = (array.charAt(i));
			if(ox[i] == 'O') {
				score++;
			}else {
				score =0;
				}
			sum += score;
		}
		return sum;
	}
}
