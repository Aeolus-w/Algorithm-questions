#include <iostream>
using namespace std;
int main (){
    int N = 0;
    cin>>N;
    int m[200000];
    int count1[20000];
    int count0[20000];
    for(int i = 0; i < N; i++){
        int n = 0;
        cin>>n;
        for(int j = 0; j < n; j++){
            cin>>m[j];
            int temp = m[j];
            int wei = 1;
            while(temp){
                if(temp & 1)
                    count1[wei++] += temp & 1;
                else
                    count0[wei++] += temp & 1;
                temp >>= 1;
            }
        }
        for(int i = 1; i < 20000; i++){
            if(count1[i] % 2 == 0)
                continue;
            if(count1[i] == 1){
                cout<<1<<endl;
                break;
            }
            else if(count1[i] % 2 == 1){
                if(count0[i] % 2 == 1){
                    cout<<0<<endl;
                }
                if(count0[i] % 2 == 0)
                    cout<<-1<<endl;
            }
        }
    }
    return 0;
}