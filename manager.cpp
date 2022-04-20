#include "manager.h"
#include <iostream>
#include <sstream>
using namespace std;
void manager::Login()
{
	while(true)
	{
	ofstream write;int judge=0;
	ifstream fin;
	cout<<"Please input your name"<<endl;
	cin>>name;
	cout<<"Please input your password"<<endl;
	cin>>password;
	fin.open("allmanagers.txt",ios::app);
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
		write.open("allmanagers.txt",ios::app);
		write<<name<<endl;
		write.close();
		write.open("../manager/"+name+".txt");
	    write<<"name:"<<name<<endl;
	    write<<"password:"<<password<<endl;
	    write.close();
		cout<<"Register Successfully!"<<endl;
		Loginjudge="1";
		break;
	}
	if(flag==1)
	{
		fin.open("../manager/"+name+".txt",ios::app);
		string str;
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
			 cin>>Option3;
			while(Option3=="1")
			{
				cout<<"Please input your name"<<endl;
	            cin>>name;
	            cout<<"Please inout your password"<<endl;
	            cin>>password;
				d=("password:"+password);
				if(str==d)
		        {cout<<"Login Successfully!"<<endl;Loginjudge="1";judge=1;break;}
				else 
	            {
			    cout<<"User name or password is incorrect!"<<endl;
                cout<<"1. Retry"<<endl;
                cout<<"2. Exit"<<endl;
			    cin>>Option3;
				}
			}
			if(Option3=="2")
			Loginjudge="0";
		}
	}
	if(judge==1 || Option3=="2")
	break;
	}
}

    void manager::ChangeThePassword()
	{
		string  newpassword;
		cin>>newpassword;
		ifstream fin;
		fin.open("../manager/"+name+".txt",ios::app);
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
			fin.open("../manager/"+name+".txt",ios::app);
			string s;int line=0;
			while (getline(fin,s))
			{
				string str="";
				if(line!=2)
				{
					str+=s;str+="\n";
				}
				else
				{
					str+=("password:"+newpassword);str+="\n";
				}
				line++;
			}
			fin.close();
			cout<<"Changed Successfully!"<<endl;
		
		ofstream write;
		write.open("../manager/"+name+".txt",ios::out);
		write<<str<<endl;
		write.close();
	}

void manager::show_course()
{
    ifstream cs("../manager/restaurant/courses.txt");
		string s;
		while (getline(cs, s))
		{
			cout << s << endl;
		}
}
void manager::add_course()
	{
		ifstream cs("../manager/restaurant/courses.txt");
		string s , num ;
		int weishu = 0, id = 0;
		if (!getline(cs, s))
		{
			string na;
			cout << "Please add a course:";
			cin >> na ;
			ofstream cs("../manager/restaurant/courses.txt", ios_base::app);
			cs << id + 1 << '.' << na ;
		}
		else 
		{
			while (cs.peek()!=EOF)   
			{
				getline(cs, s);
			}
			for (int i = 0;s[i] != '.';i++)
			{
				num[i] = s[i];
				weishu++;
			}
			for (int i = 0;i < weishu;i++)
			{
				id = id * 10 + ((int)num[i]-48);
			}
			string na ;
			cout << "Please add a course:" << endl;
			cin >> na ;
			ofstream cs("../manager/restaurant/courses.txt", ios_base::app);
			cs << endl << id + 1 << '.' << na << ' ' ;
		}
	}


	void manager::delete_course()
	{
		ifstream file("../manager/restaurant/courses.txt",ios::app);
		string line;
		int n, count = 0;
		ofstream outfile("test2.txt", ios::out | ios::trunc);
		cout << "Please input the line number you want to del:" << endl;
		cin >> n;
		int l = 1;//删行后的序号
		while (!file.eof()) {
			getline(file, line);
			if (count != n - 1)//修改内容就在这修改line的内容,更改菜的序号
			{
				string no;
				int weishu = 0;
				for (int i = 0;line[i] != '.';i++)
				{
					weishu++;
				}
				line.erase(0, weishu);
				stringstream ss;
				ss << l;
				ss >> no;
				line = no + line;
				l++;
				outfile << line << endl;
			}
			count++;
		}
		outfile.close();
		file.close();
		ofstream outfile1("../manager/restaurant/courses.txt", ios::out | ios::trunc);
		fstream file1("test2.txt");
		while (!file1.eof()) {
			getline(file1, line);
			outfile1 << line << endl;
		}
		outfile1.close();
		file1.close();
		system("del test2.txt");//删除中间文件
		string str = "", s;//删除空行
		ifstream fil("../manager/restaurant/courses.txt", ios::in);
		while (getline(fil, s))    //换行有问题（明早记得看！！！）
		{
			str = str + s;
			if (s != "")
				str = str + '\n';
		}
		str = str.substr(0, str.length() - 1);
		ofstream cs("../manager/restaurant/courses.txt");
		cs << str;
	}