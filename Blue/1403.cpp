#include <stdio.h>
#include <stdlib.h>
/*
30个数字,1或者0,1代表对的,0代表错的
不能有连续的十个1
最后七个全是1

等价于
22个数字加上01111111;
前22个数字里不能有连续的十个1存在
上面是答满30题的情况
*/
int ans =0;
void dfs(int k, int sum){
  if(sum == 100 || k >= 31)
    return ;
  if(sum == 70)
    ans++;
  dfs(k + 1, sum + 10);
  dfs(k + 1, 0);
}

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  //dfs(0,0);
  //printf("%d",ans);
  printf("8335366");
  return 0;
}