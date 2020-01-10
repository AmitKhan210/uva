# include <iostream>
# include <cstring>
using namespace std;
int main()
{
    int l, sum;
    char word[21];
    while(cin>>word){
        l = strlen(word);
        sum = 0;
        for(int k = 0; k < l; k++){
            for(int a = 65, p = 27; a <= 90; a++, p++){
                if(word[k] == a){
                    sum += p;
                }
            }
            for(int a = 97, p = 1; a <= 122; a++, p++){
                if(word[k] == a){
                    sum += p;
                }
            }
        }
        int check = 0;
        for(int k = 2; k <= sum-1; k++){
            if(sum % k == 0){
                check = 1;
            }
        }
        if(check == 1)
            cout<<"It is not a prime word."<<endl;
        else
            cout<<"It is a prime word."<<endl;
    }
    return 0;
}
