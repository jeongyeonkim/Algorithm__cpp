import java.awt.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

class Solution {
    static Scanner sc = new Scanner(System.in);
    static int N, startPoint, result;

    public static void main(String args[]) throws Exception {
        for (int test_case = 1; test_case <= 10; test_case++) {
            N = sc.nextInt();
            startPoint = sc.nextInt();
            result = 0;
            int[][] arr = new int[101][101];
            int[] visited = new int[101];
            int input = 0, input2 = 0;
            for(int i=0; i<N/2; i++){
                input = sc.nextInt(); input2 = sc.nextInt();
                arr[input][input2] = 1;
            }
            Queue<Integer> que = new LinkedList<Integer>();
            Queue<Integer> temp = new LinkedList<Integer>();
            que.offer(startPoint);
            visited[startPoint] = 1;

            while (!que.isEmpty()){
                int size_que = que.size();
                temp.clear();
                for(int i=0; i<size_que; i++){
                    int x = que.poll();
                    temp.offer(x);
                    for(int j=0; j<101; j++){
                        if(arr[x][j] == 1 && visited[j] == 0){
                            visited[j] = 1;
                            que.offer(j);
                        }
                    }
                }
            }

            while (!temp.isEmpty()){
                int x = temp.poll();
                if(x > result){
                    result = x;
                }
            }

            System.out.println("#" + test_case + " " + result);
        }
    }
}