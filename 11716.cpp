# include <iostream>
# include <cstring>

using namespace std;

int main()
{
    int T, i, l;
    char s1[10000], s2[10000];

    cin>>T;

    for(i = 1; i <= T; i++){

        cin>>s1;
        l = strlen(s1);
        int n = -1;

        if(l == 1)
            n = 1;
        else if(l == 4)
            n = 2;
        else if(l == 9)
            n = 3;
        else{
            for(int j = 1; j <= l / 4; j++){
                if(l == j*j){
                    n = j;
                    break;
                }
            }
        }
        if(n == -1){
            cout<<"INVALID"<<endl;
            continue;
        }

        for(int j = 0; j <= n; j++){
            int m = (j - 1) * n;
            for(int k = j; k <= n*n; k += n){
                s2[m] = s1[k];
                m++;
            }
        }

        cout<<s2<<endl;
    }

    return 0;
}
