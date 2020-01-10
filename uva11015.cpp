# include <bits/stdc++.h>
using namespace std;

# define infinity 1<<28;
# define mx 25

void floydWarshall(int n, int G[][mx]){

    for(int mid = 1; mid <= n; mid++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                G[i][j] = min(G[i][j], G[i][mid] + G[mid][j]);
            }
        }
    }
}

int main(){

    int n, m, i, j, k, mincost, ans, tc = 0;
    int G[mx][mx];
    int totalcost[mx];
    string s;
    vector <string> name;
    scanf("%d %d", &n, &m);
    while(n != 0){
        tc++;
        name.clear();
        mincost = infinity;
        memset(totalcost, 0, sizeof(totalcost));
        for(int x = 1; x < mx; x++){
            for(int y = 1; y < mx; y++){
                if(x == y){
                    G[x][y] = 0;
                }
                else{
                    G[x][y] = infinity;
                }
            }
        }
        for(int x = 1; x <= n; x++){
            cin >> s;
            name.push_back(s);
        }
        for(int x = 0; x < m; x++){
            scanf("%d %d %d", &i, &j, &k);
            G[i][j] = k;
            G[j][i] = k;
        }
        floydWarshall(n, G);
        for(int x = n; x >= 1; x--){
            for(int y = 1; y <= n; y++){
                totalcost[x] += G[x][y];
            }
            if(mincost >= totalcost[x]){
                mincost = totalcost[x];
                ans = x;
            }
        }
        cout << "Case #" << tc << " : " << name[ans-1] << endl;
        scanf("%d %d", &n, &m);
    }

}
