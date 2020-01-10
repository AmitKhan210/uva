# include <stdio.h>

int main(void)
{
    int T, i, h, m, j;
    char k;
    int hour[12] = {1, 2, 3, 4, 5, 6, 12, 11, 10, 9, 8, 7};
    int minute[60];

    for(i = 0; i < 60; i++){
        minute[i] = i;
    }

    scanf("%d", &T);

    for(i = 1; i <= T; i++){

        scanf("%d%c%d", &h, &c, &m);
        if(m == 0){
            if(h == 12 || h == 6){
                h = h;
            }
            else{
                for(j = 0; j < 5; j++){
                    if(hour[j] == h){
                        h = hour[j+7];
                    }

                }

                for(j = 7; j < 12; j++){
                    if(hour[j] == h){
                        h = hour[j-7];
                    }
                }
            }
        }
        else{}




    }







}

