# include <bits/stdc++.h>
using namespace std;

# define pp pair <int, int>
const int INF = INT_MAX;

class Prioritize{
public:
    bool operator () (const pp& p1, const pp& p2){
        return p1.second < p2.second;
    }
};

int main(){

    int n, street, u, v, w, s, d, tc = 1, ans;
    int dis[15];
    int path[15];
    while(scanf("%d", &n) && n){
        priority_queue <pp, vector <pp>, Prioritize> q;
        vector <pp> g[15];
        for(u = 1; u <= n; u++){
            scanf("%d", &street);
            while(street--){
                scanf("%d %d", &v, &w);
                g[u].push_back(pp(v, w));
            }
        }
        scanf("%d %d", &s, &d);
        for(int i = 1; i <= n; i++){
            dis[i] = INF;
        }
        dis[s] = 0;
        q.push(pp(s, dis[s]));
        while(!q.empty()){
            u = q.top().first;
            q.pop();
            int Size = g[u].size();
            for(int i = 0; i < Size; i++){
                v = g[u][i].first;
                w = g[u][i].second;
                if(dis[v] > dis[u] + w){
                    dis[v] = dis[u] + w;
                    q.push(pp(v, dis[v]));
                    path[v] = u;
                }
            }
        }
        ans = dis[d];
        vector <int> Path;
        Path.push_back(d);
        while(s != d){
            Path.push_back(path[d]);
            d = path[d];
        }
        int Size = Path.size();
        printf("Case %d: Path =", tc++);
        for(int i = Size - 1; i >= 0; i--){
            printf(" %d", Path[i]);
        }
        printf("; %d second delay\n", ans);

    }
}
