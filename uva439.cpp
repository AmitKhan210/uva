# include <iostream>
# include <cstdio>
# include <cstring>
# include <queue>
# include <utility>
# define pii pair<int, int>
using namespace std;
int dix[8] = {-2, -2, -1, 1, -1, 1, 2, 2};
int diy[8] = {-1, 1, -2, -2, 2, 2, 1, -1};
int main(){
    char s1[4], s2[4];
    int sx, sy, dx, dy;
    while(scanf("%s %s", s1, s2) != EOF){

        int vis[8][8] = {0};
        int level[8][8] = {0};
        sy = s1[0] - 'a';
        sx = s1[1] - '0' - 1;
        dy = s2[0] - 'a';
        dx = s2[1] - '0' - 1;

        vis[sx][sy] = 1;
        level[sx][sy] = 0;
        queue <pii> q;
        q.push(pii(sx,sy));
        while(!q.empty()){
            pii top = q.front();
            q.pop();
            int tx, ty;
            for(int k = 0; k < 8; k++){
                tx = top.first + dix[k];
                ty = top.second + diy[k];
                if(tx >= 0 && tx <= 7 && ty >= 0 && ty <= 7 && vis[tx][ty] == 0){
                    vis[tx][ty] = 1;
                    level[tx][ty] = level[top.first][top.second] + 1;
                    q.push(pii(tx,ty));

                }
                if(tx == dx && ty == dy){
                    break;
                }
            }
            if(tx == dx && ty == dy){
                    break;
            }
        }
        printf("To get from %s to %s takes %d knight moves.\n", s1, s2, level[dx][dy]);
    }

}
