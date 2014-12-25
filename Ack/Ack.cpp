#include <iostream>
using namespace std;
int Ack(int m,int n,int count)
{
	cout<<"Ack("<<m<<","<<n<<")"<<"	"<<++count<<endl;
	if(m==0) return n+1;
	if(m!=0 && n==0) return Ack(m-1,1,count);
	return Ack(m-1,Ack(m,n-1,count),count);
}
int main(void)
{
	int m,n;
	cout << "Input m,n:"<<endl;
	cin >> m>>n;
	cout<<Ack(m,n,0)<<endl;
	return 0;
}
