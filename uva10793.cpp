# include <bits/stdc++.h>
using namespace std;

# define infinity 10000000
# define mx 105

void floyd_warshall(int l, int g[][mx]){
    for(int k = 1; k <= l; k++){
        for(int i = 1; i <= l; i++){
            for(int j = 1; j <= l; j++){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

int main(){

    int t, l, d, u, v, c, dis;
    int g[mx][mx];
    vector <int> rallyPoint;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++){
        rallyPoint.clear();
        scanf("%d %d", &l, &d);
        for(int j = 1; j <= l; j++){
            for(int k = 1; k <= l; k++){
                if(j == k){
                    g[j][k] = 0;
                }
                else{
                    g[j][k] = infinity;
                }
            }
        }
        for(int j = 1; j <= d; j++){
            scanf("%d %d %d", &u, &v, &c);
            g[u][v] = min(g[u][v], c);
            g[v][u] = min(g[v][u], c);
        }
        floyd_warshall(l, g);
        for(int j = 6; j <= l; j++){
            dis = g[j][1];
            if(dis != infinity && g[j][2] == dis && g[j][3] == dis && g[j][4] == dis && g[j][5] == dis){
                rallyPoint.push_back(j);
            }
        }
        int Size = rallyPoint.size();
        int ans = infinity;
        for(int j = 0; j < Size; j++){
            int point = rallyPoint[j];
            int pointmax = 0;
            for(int k = 1; k <= l; k++){
                pointmax = max(pointmax, g[point][k]);
            }
            if(ans > pointmax){
                ans = pointmax;
            }
        }
        if(ans == infinity){
            printf("Map %d: -1\n", i);
        }
        else{
            printf("Map %d: %d\n", i, ans);
        }
    }

}
