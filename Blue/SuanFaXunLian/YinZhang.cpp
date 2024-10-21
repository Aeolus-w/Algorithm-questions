/**
 * 共有n种图案的印章，每种图案的出现概率相同。
 * 小A买了m张印章，求小A集齐n种印章的概率。
*/
#include <stdio.h>
#include <math.h>

long long nCr(int n, int r){//n选r
    if(r > n - r){
        r = n - r;
    }
    long long result = 1;
    for(int i = 0; i < r; i++){
        result *= (long long)(n - i);
        result /= (long long)(i + 1);
    }
    return result;
}

long long f(int n){
    long long result = 1;
    while(n){
        result *= n--;
    }
    return result;
}
int main (){
    int n, m;
    scanf("%d %d",&n,&m);
    if(m < n)
        printf("0");
    else if(m == n){
        long long total = pow(n, m);
        long long pro = 1 * f(n);
        printf("%.4lf",(double)pro/(double)total); 
    }
    else{
        long long total = pow(n, m);
        long long pro = nCr(m + n - 1,  m -1);//思考一下
        printf("%.4lf",(double)pro/(double)total);
    }
    return 0;
}