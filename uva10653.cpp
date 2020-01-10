# include <iostream>
# include <cstdio>
# include <queue>
# include <utility>
using namespace std;
# define pii pair<int, int>
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main(){
    int R, C;
    while(scanf("%d %d", &R, &C)){
        if(R == 0 && C == 0){
            return 0;
        }
        int boom[R][C] = {0};
        int level[R][C] = {0};
        int rownum, row, col, boomnum;
        scanf("%d", &rownum);
        for(int i = 1; i <= rownum; i++){
            scanf("%d %d", &row, &boomnum);
            for(int j = 1; j <= boomnum; j++){
                scanf("%d", &col);
                boom[row][col] = 1;
            }
        }
        int sx, sy, desx, desy;
        scanf("%d %d %d %d", &sx, &sy, &desx, &desy);
        level[sx][sy] = 1;
        int tx, ty, flag = 1;
        queue <pii> q;
        q.push(pii(sx, sy));
        while(!q.empty()){
            pii top = q.front();
            q.pop();
            for(int i = 0; i < 4; i++){
                tx = top.first + dx[i];
                ty = top.second + dy[i];
                if(tx >= 0 && tx < R && ty >= 0 && ty < C && boom[tx][ty] != 1 && level[tx][ty] == 0){
                    level[tx][ty] = level[top.first][top.second] + 1;
                    q.push(pii(tx,ty));
                    if(tx == desx && ty == desy){
                        flag = 0;
                        break;
                    }
                }
            }
            if(flag == 0){
                break;
            }
        }
        printf("%d\n", level[desx][desy]-1);
    }
}
