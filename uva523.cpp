# include <bits/stdc++.h>
using namespace std;

# define infinity 1<<28
# define mx 505

void floydWarshall(int n, int g[][mx], int tax[mx], int path[][mx]){

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(g[i][j] > g[i][k] + g[k][j]){
                    g[i][j] = g[i][k] + g[k][j];
                    path[i][j] = path[i][k];
                }
            }
        }
    }

}

int main(){

    int m, s, d, n;
    int g[mx][mx];
    int path[mx][mx];
    int tax[mx];
    char c;
    scanf("%d", &m);
    while(m--){
        n = 0;
        while(true){
            scanf("%d%c", &g[1][++n], &c);
            if(g[1][n] == -1){
                g[1][n] = infinity;
            }
            if(c == '\n'){
                break;
            }
        }
        for(int i = 2; i <= n; i++){
            for(int j = 1; j <= n; j++){
                scanf("%d", &g[i][j]);
                if(g[i][j] == -1){
                    g[i][j] = infinity;
                }
            }
        }
        for(int i = 1; i <= n; i++){
            scanf("%d", &tax[i]);
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(g[i][j] == infinity || i == j){
                    continue;
                }
                else{
                    g[i][j] += tax[j];
                }
                path[i][j] = j;
            }
        }
        floydWarshall(n, g, tax, path);
        while(scanf("%d %d", &s, &d) == 2){
            printf("From %d to %d :\n", s, d);
            if(s == d){
                printf("Path: %d\n", s);
                printf("Total cost : 0\n");
                continue;
            }
            int totalCost = g[s][d] - tax[d];
            printf("Path: %d", s);
            while(s != d){
                s = path[s][d];
                printf("-->%d", s);
            }
            printf("\n");
            printf("Total cost : %d\n", totalCost);
        }
    }
}
