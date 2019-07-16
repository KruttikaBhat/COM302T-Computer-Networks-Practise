//9/9/18
#include<iostream>
using namespace std;

int main()
{
  int i,j,n,x,w,count,total,retrans,sent;
  cout<<"Enter the number of packets to be sent"<<endl;
  cin>>n;
  cout<<"Enter which packet will be dropped"<<endl;
  cin>>x;
  cout<<"Enter the window size"<<endl;
  cin>>w;
  count=0;
  total=0;
  bow=1;
  eow=w;
  for(i=1;i<=n;)
  {
    count++;
    if(count==x)
    {
      count=0;
      for(j=0;j<w && i+j<=n;j++)
      {
        sent[++size]=i+j;
        if(j!=0)
          count++;
        total++;
      }
      sent[++size]=i;
      count++;
      i+=w;
      retrans++;
    }
    else
    {
      sent[++size]=i++;
      total++;
    }
  }
  for(;bow<=n;)
  {
    if(bow==1)
    {
      for(i=bow;i<=eow && i<=n;i++)
        cout<<"S"<<i<<endl;
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
  for(i=1;i<=size;i++)
    cout<<sent[i]<<" ";
  cout<<"\nRetransmissions:"<<retrans<<" Total packets sent:"<<total<<endl;
  return 0;
}
