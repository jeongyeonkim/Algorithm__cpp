import java.util.Scanner;

public class Main {
    static Scanner sc = new Scanner(System.in);
    static int n, result;
    static boolean [] arr = new boolean[42];
    public static void main(String[] args){
        for(int i=0; i<10; i++){
            n = sc.nextInt();
            arr[n % 42] = true;
        }

        for(int i=0; i<42; i++){
            if(arr[i]){ result++; }
        }

        System.out.println(result);
    }
}