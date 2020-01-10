# include <iostream>
# include <cstring>

using namespace std;

class carst{
public:
    char s[1000000];
    char t[1000000];

};
int main()
{
    carst o;

    while(cin>>o.s>>o.t){
        int l = 0;
        int len = strlen(o.t);
        int len2 = strlen(o.s);
        int t1 = 0;
        for(int s1 = 0; s1 < len2; s1++){
            int k = 0;
            for(; t1 < len; t1++){
                if(o.s[s1] == o.t[t1]){
                    l++;
                    t1++;
                    k = 1;
                    break;
                }
            }
            if(k == 0)
                break;

        }

        if(l == len2)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;


    }
    return 0;
}
