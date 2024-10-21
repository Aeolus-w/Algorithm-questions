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
        //printf("%d %d\n",i,j);
      }
        
      if (s[i] == s[j]){
        ans += seek(s, i, j);
        //if(seek(s,i,j)==1)
            //printf("%d %d\n",i,j);
      }
        
    }
  }
  printf("%d", ans);
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