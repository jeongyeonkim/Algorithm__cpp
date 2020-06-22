import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;

public class b_2667 {
    public static ArrayList<Integer> result = new ArrayList<Integer>();
    public static int N, cnt;
    static int[][] arr, visited;
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int[] dx = {0, 1, -1, 0};
    static int[] dy = {1, 0, 0, -1};

    public static void dfs(int x, int y){
        cnt++;
        for(int i=0; i<4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx < 0 || ny < 0 || nx >= N || ny >= N){ continue; }
            if(arr[nx][ny] == 1 && visited[nx][ny] == 0){
                visited[nx][ny] = 1;
                dfs(nx, ny);
            }
        }
    }

    public static void main(String[] args) throws IOException {
        N = Integer.parseInt(br.readLine());
        arr = new int[N][N];
        visited = new int[N][N];

        for(int i=0; i<N; i++){
            String input = br.readLine();
            for(int j=0; j<N; j++){
                arr[i][j] = Integer.parseInt(input.substring(j, j+1));
            }
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<N; j++){
                if(visited[i][j] == 0 && arr[i][j] == 1){
                    cnt = 0;
                    visited[i][j] = 1;
                    dfs(i, j);
                    result.add(cnt);
                }
            }
        }

        Collections.sort(result);
        System.out.println(result.size());
        for(int i=0; i<result.size(); i++){
            System.out.println(result.get(i));
        }
    }
}