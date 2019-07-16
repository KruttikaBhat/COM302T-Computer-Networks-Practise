//Character stuffing
#include<iostream>
#include<cstring>
using namespace std;

int main()
{
  char data[20],output[30];
  int i,j,k;
  cout<<"Enter the data"<<endl;
  cin>>data;
  char beg[]="DLESTX";
  strcpy(output,beg);
  j=strlen(output);
  for(i=0;i<strlen(data);i++)
  {
    if(data[i]=='D' && data[i+1]=='L' && data[i+2]=='E')
    {
      char mid[]="DLEDLE";
      for(k=0;k<strlen(mid);k++)
        output[j++]=mid[k];
      i+=2;
    }
    else
      output[j++]=data[i];
  }
  char end[]="DLEETX";
  for(k=0;k<strlen(end);k++)
    output[j++]=end[k];
  cout<<"Sent data:"<<output<<endl;
  return 0;
}
