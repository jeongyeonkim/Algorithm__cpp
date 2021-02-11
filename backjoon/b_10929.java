package sol_java;
import java.util.*;

public class b_10828 {
    public static void main(String[] args){
       Scanner sc = new Scanner(System.in);
       int N = sc.nextInt();
       String input;
       int [] arr = new int[N]; // 스택 저
       int top = -1; // 정수가 없는 경우 -1
       
       for(int i=0; i<N; i++) {
    	   input = sc.next();
    	   if(input.equals("push")) {
    		   top++;
    		   arr[top] = sc.nextInt();
    	   }
    	   
    	   else if(input.equals("pop")) {
    		   if(top == -1) { System.out.println(-1); }
    		   else {
    			   System.out.println(arr[top]);
    			   top--;
    		   }
    	   }
    	   
    	   else if(input.equals("size")) {
    		   System.out.println(top + 1);
    	   }
    	   
    	   else if(input.equals("empty")) {
    		   if(top == -1) { System.out.println(1); }
    		   else { System.out.println(0); }
    	   }
    	   
    	   else if(input.equals("top")) {
    		   if(top == -1) { System.out.println(-1); }
    		   else { System.out.println(arr[top]); }
    	   }
       }
    }
}