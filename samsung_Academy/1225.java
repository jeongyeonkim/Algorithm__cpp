import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Solution {
    static Scanner sc = new Scanner(System.in);
    static int T;

    public static void main(String args[]) throws Exception {
        for (int test_case = 1; test_case <= 10; test_case++) {
            T = sc.nextInt();
            Queue<Integer> que = new LinkedList<Integer>();
            int input = 0;
            int num = 1;
            for(int i=0; i<8; i++){
                input = sc.nextInt();
                que.offer(input);
            }

            while (true){
                int x = que.poll() - num++;
                if(x <= 0){
                    que.offer(0);
                    break;
                }

                que.offer(x);
                if(num == 6){
                    num = 1;
                }
            }

            System.out.print("#" + test_case + " ");
            for(int i=0; i<8; i++){
                System.out.print(que.poll() + " ");
            }
            System.out.println();
        }
    }
}