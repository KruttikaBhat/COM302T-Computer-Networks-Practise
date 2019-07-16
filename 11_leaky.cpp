//Leaky bucket implementation
#include<iostream>
using namespace std;

int main()
{
  int l,x,bsize=0;
  cout<<"Enter the limit"<<endl;
  cin>>l;
  cout<<"Enter -1 when you don't want to send anymore packets"<<endl;
  while(x!=-1)
  {
    cout<<"\nEnter the burst size: "<<endl;
    cin>>x;
    if( x==-1 || (bsize==0 && x==0) )    //if the bucket is empty and we aren't recieving any packets then exit while loop
      break;
    cout<<"Bucket state:"<<bsize<<"\nComing inside:"<<x<<"\nAfter adding to bucket:"<<bsize<<"+"<<x<<"=";
    bsize+=x;   //add the number of packets to the bucket, if it exceeds the limit then drop packets till bucket size=limit
    if(bsize>l)
    {
      int diff=bsize-l;
      bsize=l;
      cout<<bsize<<"\nDropped packets:"<<diff<<"\nTransmitting:"<<2<<endl;
    }
    else
      cout<<bsize<<"\nTransmitting:"<<2<<endl;
    if(bsize!=0)    //1 packet is transmitted
      bsize-=2;
  }
  return 0;
}
