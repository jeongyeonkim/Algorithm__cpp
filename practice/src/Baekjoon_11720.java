import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_11720 {

	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int num = Integer.parseInt(br.readLine());
		int output=0;
		String num2 = br.readLine();
		int sum[] = new int[num];
		
		for(int i=0; i<num; i++) {
			sum[i] = Integer.parseInt(num2.substring(i,i+1));
			output = output + sum[i];
	}
		System.out.println(output);
	}

}
