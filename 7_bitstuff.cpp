//Bit stuffing
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
  char data[20],output[50];
  int i,j,index,count,k;
  cout<<"Enter the data"<<endl;
  cin>>data;
  char flag[]="01111110";
  strcpy(output,flag);
  j=strlen(output);  //j will be the index for adding bits to the output
  i=0;
  //scan the data and search for the sequence 011111
  while(i<strlen(data))
  {
    //cout<<data[i]<<" i:"<<i<<endl;
    if(data[i]==48 && data[i+1]==49)  //01(48=0;49=1) has been found, so now count to see if 1111 follows this
    {
      count=2;
      index=i+2;
      for(k=0;k<4;k++)
      {
        if(data[index]==49)
          count++;
        index++;
      }
      //cout<<"Count:"<<count<<endl;
      if(count==6) //011111 has been found
      {
        while(count!=0)
        {
            output[j++]=data[i++];  //this sequence is added to the output
            count--;
        }
        output[j]=48;  //0 is stuffed here
        //cout<<output[j]<<endl;
        j++;
      }
      else
        output[j++]=data[i++];
    }
    else
        output[j++]=data[i++];
    //cout<<"i:"<<i<<endl;
  }

  cout<<"Sent data:"<<output<<endl;
  return 0;
}
