# include <bits/stdc++.h>
using namespace std;

# define infinity 1<<28
# define mx 85
# define pp pair <int, int>

void floydWarshall(int C, pp G[][mx]){
    int itoj;
    for(int k = 1; k <= C; k++){
        for(int i = 1; i <= C; i++){
            for(int j = 1; j <= C; j++){
                itoj = max(G[i][k].second, G[k][j].second);
                G[i][k].first -= G[i][k].second;
                G[k][j].first -= G[k][j].second;
                if(G[i][j].first > G[i][k].first + G[k][j].first + itoj){
                    G[i][j].first = G[i][k].first + G[k][j].first + itoj;
                    G[i][j].second = itoj;
                }
                G[i][k].first += G[i][k].second;
                G[k][j].first += G[k][j].second;
            }
        }
    }
}

int main(){

    int C, R, Q, a, b, w, s, d, mcost, tc = 0;
    pp G[mx][mx];
    int cost[mx];
    scanf("%d %d %d", &C, &R, &Q);
    while(C != 0 && R != 0 && Q != 0){
        if(tc != 0){
            printf("\n");
        }
        for(int i = 1; i <= C; i++){
            for(int j = 1; j <= C; j++){
                if(i == j){
                    G[i][j].first = 0;
                    G[i][j].second = 0;
                }
                else{
                    G[i][j].first = infinity;
                    G[i][j].second = 0;
                }
            }
        }
        for(int i = 1; i <= C; i++){
            scanf("%d", &cost[i]);
        }
        for(int i = 1; i <= R; i++){
            scanf("%d %d %d", &a, &b, &w);
            G[a][b].first = w;
            G[b][a].first = w;
            mcost = max(cost[a], cost[b]);
            G[a][b].second = mcost;
            G[b][a].second = mcost;
            G[a][b].first += G[a][b].second;
            G[b][a].first += G[b][a].second;
        }
        for(int i = 0; i < C; i++){
            floydWarshall(C, G);
        }
        printf("Case #%d\n", ++tc);
        for(int i = 1; i <= Q; i++){
            scanf("%d %d", &s, &d);
            if(G[s][d].first == infinity){
                printf("-1\n");
            }
            else{
                printf("%d\n", G[s][d].first);
            }
        }
        scanf("%d %d %d", &C, &R, &Q);
    }

}
