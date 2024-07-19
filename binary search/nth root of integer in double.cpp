#include<bits/stdc++.h>
using namespace std;

double mult (double num,int d){
    double ans=1;
    // for(int i=0;i<d;i++){
    //     ans*=num;
    // }
    while(d!=0){

      if(d&1)
      ans*=num;

      num*=num;
      d=d>>1;
    }
    
    return ans;
}

double precision=1e-8;

double bs_nthroot(double num,int d){
  double  lo=1,hi=num;
  double mid=0;

  while(hi-lo>precision){   // time complexity is log(d)*O(log(n*10^8))

    mid=lo+(hi-lo)/2;

    if(mult(mid,d)<=num)
    lo=mid;
    else
    hi=mid;
  }

  return hi;

}
 
int main()
{

double num;
cout<<"enter the number: \n";
cin>>num;

int d;
cout<<"enter the degree to calculate nth root: \n";
cin>>d;

cout<<fixed<<setprecision(7);

cout<<bs_nthroot(num,d)<<endl;
cout<<"by using inbuilt function \n";
cout<<pow(num,1.0/d);
 
    return 0;
}