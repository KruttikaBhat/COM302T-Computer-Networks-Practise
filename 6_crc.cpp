//6. Write a program to implement error detection using CRC
#include<iostream>
using namespace std;

int div(int n, int l,int data[],int key[], int rem[],int type)
{
  int index,rindex,i,j;
  //store first l bits as remainder to perform first XOR
  for(i=0;i<l;i++)
    rem[i]=data[i];
  for(index=l;index<=n;)
  {
    //perform XOR operation
    rindex=0;
    for(j=0;j<l;j++)
    {
      rem[rindex]=rem[rindex]^key[j];
      //cout<<r[rindex]<<endl;
      rindex++;
    }
    //shift bits to remove unnecessary zeroes
    if(!(type==2 && index==n))
      while(rem[0]==0)
      {
        for(j=0;j<rindex-1;j++)
          rem[j]=rem[j+1];
        rindex--;
      }
    cout<<"\nRemainder: ";
    for(j=0;j<rindex;j++)
        cout<<rem[j];
    cout<<endl;
    if(index==n)
      break;
    else
      while(rindex!=l && index<n)         //append bits for performing next XOR
        rem[rindex++]=data[index++];
    cout<<"\nAfter adding bits to the end: ";
    for(j=0;j<rindex;j++)
        cout<<rem[j];
    cout<<endl;
  }
  return rindex;
}

int main()
{
  int n,l,data[20],key[10],rem[10],i,j,rindex;
  //n is length of the data and l in the length of the key
  //get the input
  cout<<"Enter the length of the data and the key"<<endl;
  cin>>n>>l;
  cout<<"Enter the data"<<endl;
  for(i=0;i<n;i++)
    cin>>data[i];
  cout<<"Enter the key"<<endl;
  for(i=0;i<l;i++)
    cin>>key[i];
  int index;
  //append zeroes to data
  for(i=0;i<l-1;i++)
      data[n++]=0;
  //get the remainder
  rindex=div(n,l,data,key,rem,1);
  //add the remainder to the data and set remainder to 0
  for(j=0;j<rindex;j++)
  {
    data[n-l+1+j]=rem[j];
    rem[j]=0;
  }
  cout<<"\nAfter adding remainder and dividend:";
  for(j=0;j<n;j++)
    cout<<data[j];
  cout<<endl;
  //perform second division
  rindex=div(n,l,data,key,rem,2);
  for(i=0;i<rindex;i++)
    if(rem[i]!=0)
      break;
  if(i==rindex)
    cout<<"\nThe message was recieved successfully"<<endl;
  else
    cout<<"\nThere was an error"<<endl;
  int x;
  //induce an error
  cout<<"Enter the error index"<<endl;
  cin>>x;
  data[x]=data[x]^1;
  cout<<"The altered data is: ";
  for(j=0;j<n;j++)
    cout<<data[j];
  cout<<endl;
  for(j=0;j<rindex;j++)
    rem[j]=0;
  rindex=div(n,l,data,key,rem,2);
  for(i=0;i<rindex;i++)
      if(rem[i]!=0)
        break;
    if(i==rindex)
      cout<<"\nThe message was recieved successfully"<<endl;
    else
      cout<<"\nThere was an error"<<endl;

  return 0;
}
