# include <iostream>
# include <string>

using namespace std;

int main()
{
    string a[5][5];

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++)
            cin>>a[i][j];
    }

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++)
            cout<<a[i][j]<<endl;
    }


    return 0;
}

