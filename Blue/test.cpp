#include <stdio.h>
int main (){
    int a, b;
    double y;
    int guajian;
    int origin_price ;
    for(int a = 17; a <= 30; a++){
        for(int b = 4; b <= 8; b++){
            for(int guajian = 10; guajian <=20; guajian++){
                origin_price = 125*a+90*b+guajian*35;
                int total_discount = (origin_price/300)*50;
                y = (double) total_discount/origin_price;
                if(y>0.166)
                    printf("a = %d, b = %d, gaujian = %d,y = %lf\n",a,b,guajian,y);
            }
        }
    }
    return 0;
}