#include "customers.h"
#include <time.h>
using namespace std;

void customers::Login()
{
	while(true)
	{
	ofstream write;int judge=0;
	ifstream fin;
	cout<<"Please input your name"<<endl;
	cin>>name;
	cout<<"Please input your password"<<endl;
	cin>>password;
	fin.open("allcustomers.txt",ios::app);
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
		write.open("allcustomers.txt",ios::app);
		write<<name<<endl;
		write.close();
		write.open("../customers/"+name+".txt");
	    write<<"name:"<<name<<endl;
	    write<<"password:"<<password<<endl;
	    write.close();
		cout<<"Register Successfully!"<<endl;
		break;
	}
	if(flag==1)
	{
		fin.open("../customers/"+name+".txt",ios::app);
		string str;
	    getline(fin,str);
	    getline(fin,str);
	    string d=("password:"+password);
		if(str==d)
		{cout<<"Login Successfully!"<<endl;fin.close();break;}
		else 
	    {
			cout<<"User name or password is incorrect!"<<endl;
             cout<<"1. Retry"<<endl;
             cout<<"2. Exit"<<endl;
			 fin.close();
			 cin>>Option1;
			while(Option1=="1")
			{
				cout<<"Please input your name"<<endl;
	            cin>>name;
	            cout<<"Please inout your password"<<endl;
	            cin>>password;
				d=("password:"+password);
				if(str==d)
		        {cout<<"Login Successfully!"<<endl;judge=1;break;}
				else 
	            {
			    cout<<"User name or password is incorrect!"<<endl;
                cout<<"1. Retry"<<endl;
                cout<<"2. Exit"<<endl;
			    cin>>Option1;
				}
			}
			if(Option1=="2")
			Loginjudge="1";
		}
	}
	if(judge==1 || Option1=="2")
	break;
	}
}


	void customers::ChangeThePassword()
	{
		string  newpassword;string S="";
		cout<<"Please input your new password:"<<endl;
		cin>>newpassword;
		ifstream fin;
		fin.open("../customers/"+name+".txt");
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
			fin.open("../customers/"+name+".txt");
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
		write.open("../customers/"+name+".txt",ios::out);
		write<<S<<endl;
		write.close();
	}


	void customers::Order()
	{
		time_t timep;
        time (&timep);
        char tmp[64];
        strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&timep));
		system("cat ../manager/restaurant/courses.txt");cout<<endl;
		int Choice;
		cin>>Choice;
		ofstream write;
		ifstream fin;
		fin.open("../manager/restaurant/courses.txt",ios::app);
		int line=1;
		string s;
		while (getline(fin,s))
		{
			if(line==Choice)
			{write.open("../customers/"+name+".txt",ios::app);write<<"Ordering time："<<tmp<<endl<<s<<endl;write.close();break;}
			line++;
		}
	    fin.close();
		string  sid="1";int id=1;line =0;int fsum=0;int flag=0;int FLAG=0;
		stringstream sstream;
		while(true)
		{
			flag=0;line=0;
			fin.open("../riders/"+sid+".txt",ios::in);
			if(!fin)
			break;
			fin.close();
			fin.open("../riders/"+sid+".txt",ios::in);
			while(getline(fin,s))
			{line++;}
			fin.close();
			fin.open("../riders/"+sid+".txt",ios::in);
			int temp=0;
			while(getline(fin,s))
			{
				temp++;
				if(temp==line)
				{
					if( s=="State:Avalible")
					{
						write.open("../customers/"+name+".txt",ios::app);
						write<<"Successful!"<<endl;
						cout<<"Ordered Successfully!"<<endl;
						write.close();
						write.open("../riders/"+sid+".txt",ios::in | ios::app);
						write<<"State:Busying"<<endl;
						write.close();
						flag=1;
						id=1;
						break;
					}
					else
					{fsum++;break;}
				}
			}//cout <<id<<" "<<fsum<<" "<<flag<<"  "<<s;
			fin.close();
			if(flag==1)
			{fin.open("../riders/"+sid+".txt",ios::in);write.open("../customers/"+name+".txt",ios::in | ios::app);getline(fin,s);getline(fin,s);write<<"Rider  "<<s<<"  received the order."<<endl;cout<<"Rider  "<<s<<"  received the order."<<endl;fin.close();write.close();break;}
			sstream.str("");
			sstream.clear();
			id++;FLAG=1;
			sstream << id;
	     	sstream>> sid;
		}
		if(FLAG==1)
		{id--;
		sstream.str("");
		sstream.clear();
		sstream << id;
	    sstream>> sid;}
			if(fsum==id)
		{
			write.open("../customers/"+name+".txt",ios::app);
			write<<"Failed!"<<endl;
			cout<<"Failure!All Riders Are Busying!"<<endl;
			write.close();
		}
		//cout<<id<<endl<<fsum;
    }

