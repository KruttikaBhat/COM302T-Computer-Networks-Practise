//Character count
#include<iostream>
#include<string>
using namespace std;

int main()
{
  string data;
  cout<<"Enter the data"<<endl;
  cin>>data;
  cout<<"Sent data:"<<data.size()+1<<data<<endl;
  return 0;
}
