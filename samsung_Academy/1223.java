import java.util.Scanner;
import java.util.Stack;

public class Solution {
    static Scanner sc = new Scanner(System.in);
    static int N, result, temp;
    static String str, s;

    public static void main(String args[]) throws Exception {
        for(int test_case = 1; test_case <= 10; test_case++){
            N = sc.nextInt();
            str = sc.next();
            result = 0;
            Stack<String> arr = new Stack<>();
            boolean flag = false;
            int before_num = 0;

            for(int i=0; i<N; i++){
                s = ""; s += str.charAt(i);
                if(flag){
                    flag = false;
                    arr.push(String.valueOf(before_num * Integer.parseInt(s)));
                    continue;
                }
                if(s.equals("*")){
                    flag = true;
                    s = ""; s += arr.peek();
                    arr.pop();
                    before_num = Integer.parseInt(s);
                }else{
                    arr.push(s);
                }
            }

            int stack_size = arr.size();
            for(int i=0; i<stack_size; i++){
                if(arr.peek().equals("+")){
                    arr.pop();
                    continue;
                }
                s = arr.peek();
                result += Integer.parseInt(s);
                arr.pop();
            }

            System.out.println("#" + test_case + " " + result);
        }
    }
}
