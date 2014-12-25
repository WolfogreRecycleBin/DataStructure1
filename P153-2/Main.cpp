#include <iostream>
#include <string>
#include <vector>
using namespace std;
struct Data
{
	char ch;
	int count;
};
void FrequencyA(string &str)
{
	vector<Data> data;
	for(string::iterator pch=str.begin();pch!=str.end();pch++)
	{
		bool flag=0;
		for(vector<Data>::iterator pda=data.begin();pda!=data.end();pda++)
		{
			if(*pch==pda->ch)
			{
				++(pda->count);
				flag=1;
				break;
			}
		}
		if(!flag)
		{
			Data temp;
			temp.ch=*pch;
			temp.count=1;
			data.push_back(temp); 
		}
	}
	for(vector<Data>::iterator pda=data.begin();pda!=data.end();pda++) cout<<pda->ch<<"  ";
	cout<<endl;
	for(vector<Data>::iterator pda=data.begin();pda!=data.end();pda++) cout<<pda->count<<"  ";
	cout<<endl;
}

void FrequencyB(string &str)
{
	int count[256]={0};
	for(string::iterator pch=str.begin();pch!=str.end();pch++)
	{
		count[*pch]++;
	}
	char ch;
	for(int i=0;i<256;i++) if(count[i]) cout<<(ch=i)<<"  ";
	cout<<endl;
	for(int i=0;i<256;i++) if(count[i]) cout<<count[i]<<"  ";
	cout<<endl;
}
int main()
{
	string str;
	cout<<"请输入字符串，回车结束:"<<endl;
	getline(cin,str);
	cout<<"以时间换空间:"<<endl;
	FrequencyA(str);
	cout<<"以空间换时间:"<<endl;
	FrequencyB(str);
	return 0;
}
