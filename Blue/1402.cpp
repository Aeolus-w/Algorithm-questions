#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  int ans = 0;
  for(int j = 1; j <= 100000000; j++){
    int n = j;
    int _n = n;
    int num = 0;
    int f = 0, t = 0;//一定要记得全都初始化啊啊啊啊啊啊

    while(_n > 0){
        num++; 
        _n /= 10;
    }

    if(num%2==0){
        for(int i = 0; i < num / 2; i++){
            t += n % 10;
            n /= 10; 
        }
        for(int i = num/2; i < num; i++){
            f += n % 10;
            n /= 10;
        }
        if(f==t)
            ans++;
    }
  }
  printf("%d\n",ans);
  return 0;
}

/*
#include <stdio.h>
int a[5][10000]={0};
void judge(int x)
{
  int sum=0,i=0;
  while(x>0){
    sum+=x%10;
    i++;
    x/=10;
  }
  a[i][sum]++;              //计算i位数和为sum的数有多少个
}
int main()
{
  int count=0;
  for(int i=1;i<=9999;i++)
    judge(i);               //遍历1到9999去进行运算（拆分100000000）（左边的数）
  for(int i=1;i<=4;i++){
    for(int j=1;j<=9*i;j++){
      for(int k=1;k<=i;k++){
        count+=a[i][j]*a[k][j]; //左边的种数数乘以右边的种数，右边不够位数可补零（左边不可补零所以选右边）
      }
    }
  }
  printf("%d\n",count);
  return 0;
}*/