import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class b_2178 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static int N, M, result;
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};
    static Queue<Info> que = new LinkedList<Info>();

    public static void main(String[] args) throws Exception {
        String[] str = br.readLine().split(" ");
        N = Integer.parseInt(str[0]);
        M = Integer.parseInt(str[1]);

        int[][] arr = new int[N+1][M+1];
        int[][] visited = new int[N+1][M+1];
        for(int i=0; i<N; i++){
            String s = br.readLine();
            for(int j=0; j<M; j++){ arr[i][j] = s.charAt(j) - '0'; visited[i][j] = 0; }
        }
        que.add(new Info(0, 0, 1));
        visited[0][0] = 1;

        while (!que.isEmpty()){
            int x = que.peek().x;
            int y = que.peek().y;
            int cnt = que.poll().cnt;

            if(x == N-1 && y == M-1){
                result = cnt;
                break;
            }

            for(int i=0; i<4; i++){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(nx < 0 || ny < 0 || nx >= N || ny >= M){ continue; }
                if(arr[nx][ny] == 0 || visited[nx][ny] == 1){ continue; }
                que.add(new Info(nx, ny, cnt + 1));
                visited[nx][ny] = 1;
            }
        }

        System.out.println(result);
    }
}

class Info{
    int x, y, cnt;
    Info(int x, int y, int cnt){
        this.x = x; this.y = y; this.cnt = cnt;
    }
}