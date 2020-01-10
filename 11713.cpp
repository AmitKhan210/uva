# include <iostream>
# include <cstring>

using namespace std;

int main()
{
    int c, l1, l2;
    char n1[20], n2[20], v[5] = {'a','e','i','o','u'};

    cin>>c;

    for(int i = 1; i <= c; i++){

        int f = 0;
        cin>>n1>>n2;
        l1 = strlen(n1);
        l2 = strlen(n2);
        if(l1 != l2){
            cout<<"No"<<endl;
            f = 1;
        }
        else{
            for(int j = 0; j < l1; j++){
                if(n1[j] == n2[j])
                    continue;
                else{
                    int m = 0, n = 0;
                    for(int k = 0; k < 5; k++){
                        if(n1[j] == v[k])
                            m = 1;
                        if(n2[j] == v[k])
                            n = 1;

                    }
                    if(m == 1 && n == 1)
                        continue;
                    else{
                        cout<<"No"<<endl;
                        f = 1;
                        break;
                    }
                }




            }

        }

    if(f == 0)
        cout<<"Yes"<<endl;

    }

    return 0;
}
