#include <iostream>
#include <cstring>
using namespace std;
struct Data
{
	char ch;
	int count;
	Data()
	{
		ch='\0';
		count=0;
	}
};
//写法一,以时间换空间
//适用256字符以下
void FrequencyA(char str[])
{
	Data data[(strlen(str)<256)?strlen(str):256];
	int data_num=0;
	for(int i=0;str[i]!='\0';i++)
	{
		bool flag=0;
		for(int j=0;j<data_num;j++)
		{
			if(str[i]==data[j].ch)
			{
				data[j].count++;
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			data[data_num].ch=str[i];
			data[data_num].count=1;
			data_num++;
		}
	}
	for(int i=0;i<data_num;i++) cout<<data[i].ch<<"  ";
	cout<<endl;
	for(int i=0;i<data_num;i++) cout<<data[i].count<<"  ";
	cout<<endl;
}
//写法二,以空间换时间
//适用256字符以上
void FrequencyB(char str[])
{
	int count[256]={0};
	for(int i=0;str[i]!='\0';i++)
	{
		count[int(str[i])]++;
	}

	for(int i=0;i<256;i++) if(count[i]) cout<<char(i)<<"  ";
	cout<<endl;
	for(int i=0;i<256;i++) if(count[i]) cout<<count[i]<<"  ";
	cout<<endl;
}
int main()
{
	char str[1000];
	cout<<"请输入字符串，回车结束:"<<endl;
	cin.getline(str,1000);
	cout<<"以时间换空间:"<<endl;
	FrequencyA(str);
	cout<<"以空间换时间:"<<endl;
	FrequencyB(str);
	return 0;
}
