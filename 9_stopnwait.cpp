//9/9/18
#include<iostream>
using namespace std;

int main()
{
  int i,n,x,count,total,retrans;
  cout<<"Enter the number of packets to be sent"<<endl;
  cin>>n;
  cout<<"Enter which packet will be dropped"<<endl;
  cin>>x;
  count=0;
  total=0;
  retrans=0;
  for(i=1;i<=n;)
  {
    cout<<"S"<<i<<endl;
    count++;
    if(count==x)
    {
      count=0;
      retrans++;
      cout<<"NACK"<<i<<endl;
    }
    else
    {
      i++;
      cout<<"ACK"<<i<<endl;
    }
    total++;
  }
  cout<<"\nRetransmissions:"<<retrans<<" Total packets sent:"<<total<<endl;
  return 0;
}
