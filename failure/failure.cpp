#include<iostream>
#include<cstring>
using namespace std;

void GetFailure(const char pat[], int f[],int length)

{
	f[0]=-1;
	int j=0,k =-1;
	while (j<length-1){
		if (k==-1||pat[k]==pat[j])
			f[++j]=++k;
		else
			k=f[k];

       }
}
int main()
{
	char s[80],ch;
	int length,i,t;
	for(t=1;t<=3;t++){
    cout<<"Case "<<t<<":"<<endl;
	cout<<"input length"<<endl;
	cin>>length;
	cin.get(ch);
	cin.getline(s,length+1);
	int *f = new int[length];      // 为失效函数值数组f分配空间;
	GetFailure(s,f,length);         // 求模式串s的f数组的元素值
	cout<<"output f()"<<endl;
	cout<<"pat   ";
	for(i=0;i<length;i++)
    {
        cout<<s[i]<<"  ";
    }
    cout<<endl;
    cout<<"  j   ";
    for(i=0;i<length;i++)
    {
        cout<<i<<"  ";
    }
    cout<<endl;
    cout<<"f[j] ";
    for(i=0;i<length;i++)
    {
        cout<<f[i]<<"  ";
    }
    cout<<endl;
    cout<<endl;
	}
    return 0;
}
