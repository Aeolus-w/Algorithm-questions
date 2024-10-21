#include <iostream>
using namespace std;
typedef long long ll;
ll N;
ll f[200];
ll max = 0;
ll ans = 0;
int dp[200][200000];

int abs(int a){
    return a>0?a:-a;
}

int main()
{
  // 请在此输入您的代码
  cin>>N;
  int max = 0;
  for(int i = 1; i <= N; i ++){//n个数
      cin>>f[i];
      max+=f[i];
  }
  for(int i = 1; i <= N; i++){
    for(int j = 1; j <= max; j++){
        dp[i][j] = dp[i - 1][j];
        if(dp[i][j] == 0){
            if(f[i] == j)
                dp[i][j] = 1;
            if(dp[i - 1][j + f[i]])
                dp[i][j] = 1;
            if(dp[i - 1][abs(j - f[i])])
                dp[i][j] = 1;
        }
    }
  }
  for(int i = 1; i <= max; i++){
        if(dp[N][i])
            ans++;
    }
  cout<<ans;
  return 0;
}