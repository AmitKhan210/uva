# include <iostream>

using namespace std;

int main()
{
    int N, M;

    while(cin>>N>>M){

        int goal[N][M];
        int nofp = 0;

        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                cin>>goal[i][j];
            }
            int check = 0;

            for(int k = 0; k < M; k++){
                if(goal[i][k] == 0){
                    check = 1;
                    break;
                }
            }
            if(check == 0)
                nofp++;
        }

        cout<<nofp<<endl;

        continue;
    }

    return 0;
}
