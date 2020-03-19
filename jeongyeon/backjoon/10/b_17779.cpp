#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <climits>
using namespace std;

int N;
int map[21][21];
int visit[21][21];

int mv[4][2] = { {1,1},{1,-1},{-1,-1},{-1,1} };
int mv2[4][2] = { {-1,0},{0,1},{0,-1},{1,0} };
int result = INT_MAX;
void make_square(int r, int c) {
   for (int d1 = 1; d1 < N; d1++)
   {
      for (int d2 = 1; d2 < N; d2++)
      {
         if (r + d1 >= N || c - d1 < 0) continue;
         if (r + d2 >= N || c + d2 >= N) continue;
         if (r + d1 + d2 >= N || c + d2 - d1 >= N) continue;

         int right[2] = {r+d2, c+d2};
         int left[2] = {r+d1, c-d1};
         int down[2] = {r+d1+d2, c+d2-d1};

         visit[r][c] = 5;
         int d = 0;
         int nr = r + mv[d][0];
         int nc = c + mv[d][1];
         while (nr != r ||  nc != c)
         {
            if ((nr == right[0] && nc == right[1]) || (nr == left[0] && nc == left[1]) || (nr == down[0] && nc == down[1])) {
               d++;
            }
            visit[nr][nc] = 5;
            nr += mv[d][0];
            nc += mv[d][1];
         }

         for (int i = 0; i < N; i++)
         {
            bool flag = false;
            for (int j = 0; j < N; j++)
            {
               if (visit[i][j] == 5) {   
                  if ((i == r && j == c) || (i == r + d1 + d2 && j == c + d2 - d1));
                  else flag = !flag;
                  continue;
               }

               if (flag) {
                  visit[i][j] = 5;
               }
               else if ((i >= 0 && i < r+d1) && (j >= 0 && j <= c)) {
                  visit[i][j] = 1;
               }
               else if ((i >= 0 && i <= r+d2) && (j > c && j < N)) {
                  visit[i][j] = 2;
               }
               else if ((i >= r+d1 && i < N) && (j >= 0  && j < c-d1+d2)) {
                  visit[i][j] = 3;
               }
               else if ((i > r+d2 && i < N) && (j >= c - d1 + d2 && j < N)) {
                  visit[i][j] = 4;
               }
            }
         }

         int sum_of_area[6] = {0};
         for (int i = 0; i < N; i++)
         {
            for (int j = 0; j < N; j++)
            {
               sum_of_area[visit[i][j]] += map[i][j];
               visit[i][j] = 0;
            }
         }

         int min_value = INT_MAX;
         int max_value = 0;
         for (int i = 1; i < 6; i++)
         {
            min_value = min(min_value, sum_of_area[i]);
            max_value = max(max_value, sum_of_area[i]);
         }

         result = min(result, max_value - min_value);
      }
   }
}

int main() {
   ios::sync_with_stdio(0);
   cin.tie(NULL);
   cout.tie(NULL);

   cin >> N;
   for (int i = 0; i < N; i++)
   {
      for (int j = 0; j < N; j++)
      {
         cin >> map[i][j];
      }
   }

   // r >= 0 && r < N-2 && c >= 1 && c < N-1
   for (int i = 0; i < N - 1; i++)
   {
      for (int j = 1; j < N - 1; j++)
      {
         make_square(i, j);
      }
   }

   cout << result;
}