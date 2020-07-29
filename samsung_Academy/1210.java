import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;

class Solution {
    public static void main(String args[]) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        for (int test_case = 1; test_case <= 10; test_case++) {
            int[][] ladder = new int[100][100];
            br.readLine();

            int x = 99, y = 99;
            for (int i = 0; i < 100; i++) {
                StringTokenizer st = new StringTokenizer(br.readLine());

                for (int j = 0; j < 100; j++) {
                    ladder[i][j] = Integer.parseInt(st.nextToken());
                    if (ladder[i][j] == 2) {
                        x = i;
                        y = j;
                    }
                }
            }

            while (x != 0) {
                if (y > 0 && ladder[x][y - 1] == 1) {
                    ladder[x][y] = 0;
                    y--;
                } else if (y < 99 && ladder[x][y + 1] == 1) {
                    ladder[x][y] = 0;
                    y++;
                } else
                    x--;
            }

            System.out.println("#" + test_case + " " + y);
        }
    }
}