import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Baekjoon_1316 {
	public static void main(String[] args) throws IOException{
		// TODO Auto-generated method stub
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int num = Integer.parseInt(br.readLine());
		String[] array = new String[num];
		int group =0;
		
		for(int i=0; i<num; i++) {
			array[i] = br.readLine();
			group += check(array[i]);
			}
		System.out.println(group);
		}
	
	private static int check(String array) {
		char[] array_list = new char[array.length()];
		for(int i=0; i<array.length(); i++) {
			array_list[i] = array.charAt(i);
		}
		
		for(int j=1; j<array.length(); j++) {
			if(array_list[j] != array_list[j-1]) {
				for(int k=0; k<j; k++) {
					if(array_list[j] == array_list[k])
						return 0;
				}
			}
		}
		return 1;
	}
	}

