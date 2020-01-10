# include <bits/stdc++.h>
using namespace std;

# define infinity 1<<28
# define pp pair <int, int>
# define mx 105

double find_distance(pp p1, pp p2){
    double d = (p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second);
    d = sqrt(d);
    return d;
}

void floyd_warshall(int n, double g[][mx]){
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
}

int main(){
    int N, n, x, y;
    double g[mx][mx];
    pp p1, p2;
    double d, ans;
    vector <pp> town;
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        scanf("%d", &n);
        town.clear();
        for(int j = 0; j < n; j++){
            scanf("%d %d", &x, &y);
            town.push_back(pp(x, y));
        }
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                if(j == k){
                    g[j][k] = 0;
                }
                else{
                    g[j][k] = infinity;
                }
            }
        }
        for(int j = 0; j < n; j++){
            p1 = town[j];
            for(int k = j + 1; k < n; k++){
                p2 = town[k];
                d = find_distance(p1, p2);
                if(d <= 10){
                    g[j+1][k+1] = d;
                    g[k+1][j+1] = d;
                }
            }
        }
        floyd_warshall(n, g);
        ans = 0;
        for(int j = 1; j <= n; j++){
            for(int k = 1; k <= n; k++){
                ans = max(ans, g[j][k]);
            }
        }
        printf("Case #%d:\n", i);
        if(ans == infinity){
            printf("Send Kurdy\n");
        }
        else{
            printf("%.4lf\n", ans);
        }
        printf("\n");
    }
}

