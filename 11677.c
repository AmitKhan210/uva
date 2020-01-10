# include <stdio.h>

int main(void)
{
    int H1, M1, H2, M2, s;

    while(1){
        scanf("%d %d %d %d", &H1, &M1, &H2, &M2);
        s = 0;

        if(H1 == 0 && M1 == 0 && H2 == 0 && M2 == 0)
            break;
        if(H1 < H2){
        s = abs(H1-H2)*60 - M1 + M2;

        printf("%d\n", s);
        }

        else if(H1 > H2){
            s = H2*60+M2+(24-H1)*60-M1;
            printf("%d\n", s);
        }
        else{
            if(M1 <= M2){
                s = M2 - M1;
                printf("%d\n", s);
            }
            else{
                s = 1440 - (M1-M2);
                printf("%d\n", s);

            }

        }

    }

    return 0;





}
