# include <iostream>
# include <cstdio>
# include <vector>
# include <queue>
# include <map>
using namespace std;
# define MAX 100

int main(){
    int NC, CASE = 1;
    while(true){
        scanf("%d", &NC);
        if(NC == 0){
            return 0;
        }
        vector <int> v[MAX];
        map <int, int> m;
        int x, y, Assign = 0;
        for(int i = 0; i < NC; i++){
            scanf("%d %d", &x, &y);
            if(m.find(x) == m.end()){
                m[x] = Assign;
                Assign++;
            }
            if(m.find(y) == m.end()){
                m[y] = Assign;
                Assign++;
            }
            x = m[x];
            y = m[y];
            v[y].push_back(x);
            v[x].push_back(y);
        }
        int source, ttl, Sour;
        while(scanf("%d %d", &source, &ttl)){
            if(source == 0 && ttl == 0){
                break;
            }
            Sour = source;
            if(m.find(source) == m.end()){
                printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", CASE++, Assign, Sour, ttl);
                continue;
            }
            int rnode = 1;
            source = m[source];
            queue <int> q;
            q.push(source);
            int vis[MAX] = {0};
            int level[MAX] = {0};
            vis[source] = 1;
            int Q = 1;
            while(!q.empty()){
                int top = q.front();
                int len = v[top].size();
                for(int i = 0; i < len; i++){
                    if(vis[v[top][i]] == 0){
                        vis[v[top][i]] = 1;
                        q.push(v[top][i]);
                        level[v[top][i]] = level[top] + 1;
                        if(level[v[top][i]] <= ttl){
                            rnode++;
                        }
                        else{
                            Q = 0;
                        }
                    }
                }
                if(Q == 0){
                    break;
                }
                q.pop();

            }
            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n", CASE++, Assign-rnode, Sour, ttl);
        }
    }

}
