# include <iostream>
# include <string>

using namespace std;

int main()
{
    string a;

    while(cin>>a){
        for(int i = 0; i < a.length(); i++){
            a.at(i) -= 7;
        }
        cout<<a<<endl;
    }

    return 0;
}
