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

    int n, val, d;
    char str[20];
    scanf("%d", &n);
    vector <pp> G[n+1];
    for(int i = 2; i <= n; i++){
        for(int j = 1; j < i; j++){
            scanf("%s", str);
            if(strcmp(str, "x")){
                val = atoi(str);
                G[i].push_back(pp(j, val));
                G[j].push_back(pp(i, val));
            }
        }
    }
    int dis[n+1];
    for(int i = 1; i <= n; i++){
        dis[i] = INF;
    }
    dis[0] = 0;
    dis[1] = 0;
    priority_queue <pp, vector <pp>, Prioritize> q;
    q.push(pp(1, dis[1]));
    while(!q.empty()){
        int a = q.top().first;
        q.pop();
        int s = G[a].size();
        for(int i = 0; i < s; i++){
            int b = G[a][i].first;
            int w = G[a][i].second;
            if(dis[b] > dis[a] + w){
                dis[b] = dis[a] + w;
                q.push(pp(b, dis[b]));
            }
        }
    }
    sort(dis, dis + n + 1);
    printf("%d\n", dis[n]);

}
