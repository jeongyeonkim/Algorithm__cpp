import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.LinkedList;
import java.util.Queue;

public class b_7576 {
    static BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    public static int N, M, cnt;
    static int[] dx = {0, 0, 1, -1};
    static int[] dy = {1, -1, 0, 0};
    static boolean check = true;
    static Queue<Info> que = new LinkedList<Info>();

    public static void main(String[] args) throws Exception{
        String[] str = br.readLine().split(" ");
        N = Integer.parseInt(str[1]);
        M = Integer.parseInt(str[0]);
        int[][] arr = new int[N][M];
        int[][] visited = new int[N][M];
        cnt = 0;
        for(int i=0; i<N; i++){
            str = br.readLine().split(" ");
            for(int j=0; j<M; j++){
                arr[i][j] = Integer.parseInt(str[j]);
                if(arr[i][j] == 0){ check = false; }
                else if(arr[i][j] == 1){
                    que.add(new Info(i, j));
                    visited[i][j]++;
                }
            }
        }

        if(check){ System.out.println(0); System.exit(0); } // input 모두가 익은 토마토일 경우

        while (true){
            Queue<Info> q = new LinkedList<Info>();

            while (!que.isEmpty()){
                int x = que.peek().x;
                int y = que.poll().y;

                for(int i=0; i<4; i++){
                    int nx = x + dx[i];
                    int ny = y + dy[i];
                    if(nx < 0 || ny < 0 || nx >= N || ny >= M){ continue; }
                    if(visited[nx][ny] == 1 || arr[nx][ny] != 0){ continue; }

                    visited[nx][ny]++;
                    arr[nx][ny] = 1;
                    q.add(new Info(nx, ny));
                }
            }

            que = q;
            if(que.isEmpty()){ break; } // 더이상 확인할 토마토가 없는 경
            cnt++;
        }

        for(int i=0; i<N; i++){
            for(int j=0; j<M; j++){
                if(arr[i][j] == 0){
                    System.out.println(-1);
                    System.exit(0);
                }
            }
        }
        System.out.println(cnt);
    }
}

class Info{
    int x, y;
    Info(int x, int y){ this.x = x; this.y = y; }
}