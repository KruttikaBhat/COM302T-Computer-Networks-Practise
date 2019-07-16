//Dijkstra algorithm to find shortest path
#include<iostream>
using namespace std;

class dijkstra
{
     int v,s,adj[20][20],d[20],m[20],pre[20],result[20][3];
     public:
           void enter()
           {
                int i,j;
                cout<<"Enter the number of vertices"<<endl;
                cin>>v;
                for(i=1;i<=v;i++)
                {
                     for(j=1;j<=v;j++)
                     {
                        if(i!=j)
                        {
                          cout<<"Enter the weight of edge "<<i<<" "<<j<<endl;
                          cin>>adj[i][j];
                        }
                        else
                          adj[i][j]=999; //999->infinity

                     }
                }
                for(i=1;i<=v;i++)
                {
                    for(j=1;j<=v;j++)
                       cout<<adj[i][j]<<" ";
                    cout<<endl;
                }
           }
           void SSSP();
           int findmin();
           void updateDistance(int u);
};

dijkstra D;

void dijkstra::updateDistance(int u)
{
      int i;
      m[u]=1;
      for(i=1;i<=v;i++)
      {
          //if the edge exists, the node isn't marked and the new distance is less than the current distance, then update
           if(adj[u][i]!=999 && m[i]==0 && d[i]>adj[u][i]+d[u])
           {
                d[i]=adj[u][i]+d[u];
                pre[i]=u;  //previous array stores the previous node for each node
           }
      }
      cout<<"\nAfter updating d and m arrays, the present graph is"<<endl;
      for(i=1;i<=v;i++)
      {
        if(pre[i]!=999)
        {
          cout<<pre[i]<<" "<<i<<" "<<"Distance:"<<adj[pre[i]][i]<<endl;
        }
      }
      cout<<"\nDistance array: ";
      for(i=1;i<=v;i++)
        cout<<d[i]<<" ";
      cout<<"\nMarked array: ";
      for(i=1;i<=v;i++)
        cout<<m[i]<<" ";
}

int dijkstra::findmin()
{
     int i,min=1000;
     for(i=1;i<=v;i++)
     {
       //if the node isn't marked, it is not the source node and it is less than the current min distance
          if(m[i]==0)
          {
               if(d[i]!=0 && d[i]<min)
               {
                    min=i;
               }
          }
     }

     return min;
}

void dijkstra::SSSP()
{
     int i,index,u;
     cout<<"Enter the source vertex"<<endl;
     cin>>s;
     //Initialise d, m and pre arrays
     for(i=1;i<=v;i++)
     {
         d[i]=adj[s][i];
         m[i]=0;
         pre[i]=s;
     }
     d[s]=0;
     m[s]=1;
     pre[s]=999;
     cout<<"\nInitially: "<<endl;
     for(i=1;i<=v;i++)
     {
       if(pre[i]!=999)
       {
         cout<<pre[i]<<" "<<i<<" Distance:"<<adj[pre[i]][i]<<endl;
       }
     }
     for(index=1;index<v-1;index++)
     {
          u=findmin();  //returns the node with min distance
          updateDistance(u);  //the distace is updated with respect to this node
     }
     int count=0;
     for(i=1;i<=v;i++)
     {
          if(pre[i]!=999)
          {
               result[count][0]=pre[i];
               result[count][1]=i;
               result[count][2]=adj[pre[i]][i];
               count++;
          }
     }
     cout<<"The final tree is"<<endl;
     for(i=0;i<count;i++)
     {
          cout<<result[i][0]<<" "<<result[i][1]<<" Weight: "<<result[i][2]<<endl;
     }

}


int main()
{
     D.enter();
     D.SSSP();
return(0);
}
