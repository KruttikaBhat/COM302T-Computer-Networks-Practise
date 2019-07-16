//9/9/18
#include<iostream>
using namespace std;

int main()
{
  int i,n,x,w,count,bow,eow,flag=0;
  cout<<"Enter the number of packets to be sent"<<endl;
  cin>>n;
  cout<<"Enter which packet will be dropped"<<endl;
  cin>>x;
  cout<<"Enter the window size"<<endl;
  cin>>w;
  bow=1;
  eow=w;
  count=0;
  for(;bow<=n;)
  {
    if(count==0)
    {
      for(i=bow;i<=eow && i<=n;i++)
      {
        cout<<"S"<<i<<endl;
        if(bow!=1)
          count++;
      }
      if(bow==1)
        count++;

    }
    else if(count==x)
    {
      count=0;
      cout<<"NACK"<<bow<<endl;
    }
    else
    {
      bow++;
      if(flag!=1)
        eow++;
      cout<<"ACK"<<bow<<endl;
      if(flag!=1)
        cout<<"S"<<eow<<endl;
      count++;
      if(eow==n)
        flag=1;
    }

  }

  return 0;
}
