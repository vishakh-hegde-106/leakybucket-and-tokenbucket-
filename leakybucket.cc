#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
cout<<"\n\n..........CONGESTION CONTROL USING LEAKY BUCKET ALGORITHHM..........\n \n";
int bucket_size,outgoing_rate,n,stored,inc_pack_size;
cout<<"ENTER THE BUCKET SIZE\n\n";
cin>>bucket_size;
cout<<"ENTER THE OUTGOING RATE\n\n";
cin>>outgoing_rate;
if (outgoing_rate>bucket_size)
{
cout<<"\n\n OUTGOING RATE SHOULD BE LESS THAN BUCKET SIZE";
}
else
{
cout<<"enter the number of inputs\n\n";
cin>>n;
stored=0;
while (n!=0)
{
cout<<"enter the incoming packet size\n";
cin>>inc_pack_size;
if(inc_pack_size<=bucket_size-stored)
	{
               stored=stored+inc_pack_size;
               cout<<"\n\nBUCKET BUFFER SIZE "<<stored<<" OUT OF "<<bucket_size;
               }
               else
               {
               cout<<"DROPPED NUMBER OF PACKET :\n "<<inc_pack_size-bucket_size-stored;
               stored=bucket_size;
               cout<<"BUCKET BUFFER SIZE "<<stored<<" OUT OF "<<bucket_size;
               }
               stored=stored-outgoing_rate;
               if(stored<0)
	       {
               stored=0;
               }
               cout<<"AFTER OUTGOING "<<stored<<" PACKET LEFT OUT OF "<<bucket_size<<" IN BUFFER\n";
               n=n-1;
               }}
               cout<<"\n\n\n *****COMPLETED ******";
}

