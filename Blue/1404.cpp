/**
 * 
 * 210102
 * 201012
 * 010122
 * 101202
 * 012102
 * 120102
 * 201012
 * 201102
 * 210012
 * 
 * 01234567
 * 
 * 30140143  
 * 10410343  0 5
 * 04103143  0 4
 * 10340143  0 2
 * 03140143  0 1
 * 30104143  2 5
 * 30041143  2 4
 * 30104143  3 4
 * 30110443  3 5
 * 30134104  3 7
 * 30140134  6 7
 * 
 * 
0 5
0 4
0 2
0 1
2 4
3 7
3 5
3 4
6 7
9


0 1
0 2
0 4
0 5
2 4
2 5
3 4
3 5
3 7
6 7
*/

#include <stdio.h>
#include <string.h>
int main (){
    char num[5005];
    scanf("%s", &num);
    int n = strlen(num);
    int ans = 0;
    int front = 0;
    int tail = n - 1;
    for(front = 0; front <= n - 2; front++){
        for(tail = n-1; tail > front; tail--){
            if(num[front] > num[tail]){
                ans++;
                //printf("%d %d\n",front, tail);
            }
                
            if(num[front] < num[tail])
                continue;
            if(num[front] == num[tail]){//位数相同要考虑里面的位数大小,如果符合要求的话是可以从外面开始换的
                int _tail = tail - 1;
                int _front = front + 1;
                while(_tail != _front&& _tail >= _front){//判定条件仔细想想,注意越界情况
                    if(num[_front] > num[_tail]){
                        ans++;
                        //printf("%d %d\n",front, tail);
                        break;
                    }
                    if(num[_front] < num[_tail])
                        break;
                    _front++;
                    _tail--;
                }
            }
        }
    }
    printf("%d",ans);
    return 0;
}


/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int seek(char s[], int i, int j);

int main()
{
  char s[5000];
  scanf("%s", s);
  int n = strlen(s);
  int ans = 0;
  for (int i = 0; i <= n - 2; i++)
  {
    for (int j = i; j <= n - 1; j++)
    {
      if (s[i] > s[j]){
        ans++;
        printf("%d %d\n",i,j);
      }
        
      if (s[i] == s[j]){
        ans += seek(s, i, j);
        if(seek(s,i,j)==1)
            printf("%d %d\n",i,j);
      }
        
    }
  }
  printf("ams:%d\n", ans);
  return 0;
}

int seek(char s[], int i, int j)
{
  if (j - i < 3)
    return 0;

  if (s[i + 1] > s[j - 1])
    return 1;
  else if (s[i + 1] == s[j - 1])
    return seek(s, i + 1, j - 1);
  else
    return 0;
}
*/