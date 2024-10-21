#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* plus(int* X, int* Y, int L){
    int carry = 0;
    int* ans= (int*)malloc(L * sizeof(int));
    if (ans == NULL) {
        perror("Memory allocation failed");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < L; i++) {
        ans[i] = 0;
    }
    for(int i = 0; i < L; i++){
      if(X[i] + Y[i] + carry <= 9){
        ans[i] = X[i] + Y[i] + carry;
        carry = 0;
      }
      else{
        ans[i] = X[i] + Y[i] + carry - 10;
        carry = 1;
      }
    }
    int nl = L;
    while(nl > 0 && ans[nl - 1] == 0){
      nl--;
    }
    if(nl < L){
      int *newans = (int*)realloc(ans, nl * sizeof(int));
      if(newans == NULL){
        free(ans);
        exit(EXIT_FAILURE);
      }
      ans = newans;
    }
    return ans;
}

char* minus(char* X, char* Y, int L){
    char* ans;
    int a[105], b[105];
    for(int i = 0; i < L; i++){
      a[i] = X[i] - '0';
      b[i] = Y[i] - '0';
    }
    for(int i = L - 1; i >= 0; i--){
      if(a[i] >= b[i]){
        ans[i] = a[i] - b[i] + '0';
      }
      else{
        ans[i] = a[i] - b[i] + 10 + '0';
        a[i+1] -= 1;
      }
    }
    return ans;
}

int main(int argc, char *argv[])
{
  // 请在此输入您的代码
  char A[105] = {}, B[105] = {};
  int* C;
  scanf("%s",&A);
  scanf("%s",&B);
  int L, la, lb = 0;
  la = strlen(A);
  lb = strlen(B);
  L = la>lb?la:lb;

  int X[105] = {}, Y[105] = {};
  for(int i = 0; i < L; i++){
      X[i] = A[L - 1 - i] - '0';
      Y[i] = B[L - 1 - i] - '0';
  }
  
  C = plus(X, Y, L);
  if (C == NULL) {
        perror("Memory allocation failed for plus function");
        exit(EXIT_FAILURE);
    }
  for(int i = L-1; i >= 0; i--){
    printf("%d",C[i]);
  }
  free(C);
  return 0;
}