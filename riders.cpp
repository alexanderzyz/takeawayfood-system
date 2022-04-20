#include "riders.h"
#include<iostream>
#include <time.h>
using namespace std;


void riders::Login()
{
	while(true)
	{
	ofstream write;int judge=0;
	ifstream fin;
	cout<<"Please input your id"<<endl;
	cin>>selfid;
	cout<<"Please input your name"<<endl;
	cin>>name;
	cout<<"Please inout your password"<<endl;
	cin>>password;
	fin.open("allriders.txt",ios::app);
    string s;
	int flag=0;
	while (getline(fin,s))
	{
		if(s==name)
		{
			flag=1;
			break;
		}
	}
	fin.close();
	if(flag==0)
	{
		write.open("allriders.txt",ios::app);
		write<<name<<endl;
		write.close();
		write.open("../riders/"+selfid+".txt");
		write<<"id:"<<selfid<<endl;
	    write<<"name:"<<name<<endl;
	    write<<"password:"<<password<<endl;
		write<<"State:Avalible"<<endl;
	    write.close();
		cout<<"Register Successfully!"<<endl;Loginjudge="1";
		id++;
		break;
	}
	if(flag==1)
	{
		fin.open("../riders/"+selfid+".txt",ios::app);
		string str;
	    getline(fin,str);
	    getline(fin,str);
		getline(fin,str);
	    string d=("password:"+password);
		if(str==d)
		{cout<<"Login Successfully!"<<endl;Loginjudge="1";fin.close();break;}
		else 
	    {
			cout<<"User name or password is incorrect!"<<endl;
             cout<<"1. Retry"<<endl;
             cout<<"2. Exit"<<endl;
			 fin.close();
			 cin>>Option2;
			while(Option2=="1")
			{
				cout<<"Please input your name"<<endl;
	            cin>>name;
	            cout<<"Please input your password"<<endl;
	            cin>>password;
				d=("password:"+password);
				if(str==d)
		        {cout<<"Login Successfully!"<<endl;Loginjudge="1";judge=1;break;}
				else 
	            {
			    cout<<"User name or password is incorrect!"<<endl;
                cout<<"1. Retry"<<endl;
                cout<<"2. Exit"<<endl;
			    cin>>Option2;
				}
			}
			if(Option2=="2")
			Loginjudge="1";
		}
	}
	if(judge==1 || Option2=="2")
	break;
	}
}

void riders::ChangeThePassword()
	{
		string  newpassword;string S="";
		cout<<"Please input your new password:"<<endl;
		cin>>newpassword;
		ifstream fin;
		fin.open("../riders/"+selfid+".txt");
		string str;
	    getline(fin,str);
	    getline(fin,str);
		while(str==("password:"+newpassword))
		{
			cout<<"Same Password!Please input your newpassword again:"<<endl;
			cin>>newpassword;
			fin.close();
		}
		
			fin.close();
			fin.open("../riders/"+selfid+".txt");
			string s;int line=1;
			while (getline(fin,s))
			{
				if(line!=2)
				{
					S+=s;S+="\n";
				}
				else
				{
					S+=("password:"+newpassword);
				}
				line++;
			}
			fin.close();
			cout<<"Changed Successfully!"<<endl;
		
		ofstream write;
		write.open("../riders/"+selfid+".txt",ios::out);
		write<<S<<endl;
		write.close();
	}


void riders::State()
{
	time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&timep));
	Ntime=clock();
	ofstream write;
	write.open("../riders/"+sid+".txt",ios::in | ios::out);
	if(Ntime-Ltime>3600)
	{
		avalible=true;write<<"State:Avalible"<<endl;}
	else
	{avalible=false;write<<"State:Busying"<<endl;}
	if(avalible)
	{
		write<<"Receiving time:"<<tmp<<endl;
		cout<<"NO."<<sid<<"Rider Received"<<endl<<"Rider's name:"<<name<<endl;
		avalible=false;
		Ltime=Ntime;
	}
	write.close();
}