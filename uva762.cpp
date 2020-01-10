# include <iostream>
# include <cstdio>
# include <string>
# include <vector>
# include <map>
using namespace std;
# define pii pair<int, string>
int main(){
    int E;
    while(scanf("%d", &E) != EOF){
        map<string, vector<string> > graph;
        map<string, pii> path;
        string s1, s2;
        for(int i = 0; i < E; i++){
            cin >> s1 >> s2;
            path[s1].first = 0;
            path[s2].first = 0;
            graph[s1].push_back(s2);
            graph[s2].push_back(s1);
        }
        string source, destination;
        cin >> source >> destination;
        map<string, vector<string> > :: iterator it = graph.begin();
        while(it != graph.end()){
            vector <string> v = it -> second;
            for(int i = 0; i < v.size(); i++){
                if(path[v[i]].first == 0){
                    path[v[i]].first = 1;
                    path[v[i]].second = it -> first;
                }
            }
            it++;
        }
        vector <string> v2;
        v2.push_back(destination);
        string n = destination;
        while(n != source){
            v2.push_back(path[n].second);
            n = path[n].second;
        }
        int len = v2.size();
        for(int i = len - 1; i >= 0; i--){
            cout << v2[i] << endl;
        }
    }
    return 0;
}
