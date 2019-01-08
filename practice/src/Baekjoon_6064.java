import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;

public class Baekjoon_6064 {
	static int M, N, x, y;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int num = Integer.parseInt(br.readLine());
		int output, X, Y;
		int[] kaing = new int[num];
		
		for(int i=0; i<num; i++) {
			X=0;Y=0;output=0;
			String[] input = br.readLine().split(" ");
			M=Integer.parseInt(input[0]);
			N=Integer.parseInt(input[1]);
			x=Integer.parseInt(input[2]);
			y=Integer.parseInt(input[3]);
			
			for(int k=0;k<(M*N); k++){
				X++;
				Y++;
				output++;
				if(X == M)
					X=0;
				if(Y == N)
					Y=0;
				if(X == x && Y==y) {
					break;
				}
			}
			if((M*N)==output) {
				kaing[i] = -1;
			}else {
				kaing[i] = output;
			}
		}
		for(int j=0; j<num; j++) {
			bw.write(String.valueOf(kaing[j]));
			bw.newLine();
		}
		bw.flush();
		bw.close();
	}
}
