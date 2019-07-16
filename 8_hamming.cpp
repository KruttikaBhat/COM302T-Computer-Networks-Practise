//Hamming code
#include<iostream>
#include<cmath>
#include<stdlib.h>
using namespace std;

int main()
{
  int input[10],data[20],i,j,n,bin[20][10]={0},parity[10][5],count,pcount,index;
  cout<<"Enter the length of the data"<<endl;
  cin>>n;
  cout<<"Enter the data"<<endl;
  for(i=0;i<n;i++)
    cin>>input[i];
  //get the total length of the data to be sent including parity bits
  for(i=1,j=0;j<n;)
  {
    if(log2(i)-floor(log2(i))!=0)
      data[i++]=input[j++];
    else
      data[i++]=2;
  }
  int size=i;
  for(i=1;i<size;i++)
    cout<<data[i];
  cout<<endl;
  //get binary numbers from 1 to length of the string
  for(i=1;i<size;i++)
  {
    count=0;
    j=i;
    //cout<<"j:"<<j<<endl;
    while(j>0)
    {
      bin[i][count]=j%2;
      //cout<<bin[i][count]<<" "<<j<<endl;
      j=j/2;
      count++;
    }

  }
  //printing the binary numbers
  for(i=1;i<size;i++)
  {
    for(j=0;j<5;j++)
        cout<<bin[i][j];
    cout<<endl;
  }
  //This function will get the bits required for each parity bit and store in a 2D array called parity
  pcount=0;
  for(i=1;i<size;i++)
  {
    if(log2(i)-floor(log2(i))==0) //will get the data bits only for bits 1,2,4,8...
    {
      index=0;
      for(j=1;j<size;j++)
      {
        if(bin[j][pcount]==1 && log2(j)-floor(log2(j))!=0)
        {
          parity[pcount][index++]=j;
          //cout<<"j:"<<j<<endl;
        }
      }
      parity[pcount][index]=-1; //-1 is kept to indicate the end of the data bits
      pcount++;
    }
  }
  //Print parity array
  for(i=0;i<pcount;i++)
  {
    for(j=0;parity[i][j]!=-1 && j<size-n;j++)
      cout<<parity[i][j]<<" ";
    cout<<endl;
  }
  //Scan through parity array and XOR for each row to get the corresponding parity bit.
  for(i=0;i<pcount;i++)
  {
    j=0;
    int temp=data[parity[i][j]];
    cout<<"temp:"<<temp<<" parity:"<<parity[i][j]<<endl;
    j++;
    for(;parity[i][j]!=-1 && j<size-n;j++)
    {
      temp=temp^data[parity[i][j]];
      cout<<"updatedtemp:"<<temp<<endl;
    }
    data[int(pow(2,i))]=temp;
  }
  cout<<"\nSent data: ";
  for(i=1;i<size;i++)
    cout<<data[i];
  cout<<endl;  
  return 0;
}
