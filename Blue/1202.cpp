#include<iostream>
#include<set>
using namespace std;
int main()
{
    set<pair<double,double> > line;
    double k,b;
    for(int x1=0;x1<20;x1++){
        for(int y1=0;y1<21;y1++){
            for(int x2=x1+1;x2<20;x2++){
                for(int y2=0;y2<21;y2++){
                    k=(double)(y1-y2)/(x1-x2);
                    b=(double)(x1*y2-x2*y1)/(x1-x2);
                    line.insert({k,b});
                }
            }
        }
    }
    cout<<line.size()+20;
    return 0;
}