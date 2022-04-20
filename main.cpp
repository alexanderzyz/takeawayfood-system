#include <iostream>
#include <cstring>
#include <fstream>
#include "customers.h"
#include "riders.h"
#include "manager.h"
using namespace std;
int global=0;
int main()
{
    while(true)
    {
        cout<<"Please input your option."<<endl;
        cout<<"1. I am a customer."<<endl;
        cout<<"2. I am a rider."<<endl;
        cout<<"3. I am a manager"<<endl;
         cout<<"4. Exit"<<endl;
        string  Option;
        cin>>Option;
        if(Option=="1")
        {
            customers usr;
            usr.Login();
            if(usr.Loginjudge=="1")
            break;
        else
        {
            string Choice="0";
            while(Choice!="3")
            {
                usr.Orderjudge="0";
                cout<<"1. Change the password"<<endl;
                cout<<"2. Order"<<endl;
                cout<<"3. Exit"<<endl;
                cin>>Choice;
                if(Choice=="1")
                {
                    usr.ChangeThePassword();
                    cout<<"1. Order"<<endl;
                    cout<<"2. Exit"<<endl;
                    cin>>Choice;
                    if(Choice=="1")
                    {usr.Order();usr.Orderjudge="1";}
                    else
                    {break;}
                }
                if(Choice=="2")
                {usr.Order();usr.Orderjudge="1";}
                if(usr.Orderjudge=="1")
                global=1;
             }
         }
         }
         if(Option=="2")
         {
             riders usr;
             usr.Login();
             if(usr.Loginjudge=="1" )
            {
                cout<<"State is "<<usr.avalible<<endl;
                if(global==1)
                {
                    usr.State();
                }
            }
             else 
             break;
         }
         if(Option=="3")
         {
            manager usr;
	        usr.Login();
	     if(usr.Loginjudge=="1")
	     {
		     string Choice="0";
             while(Choice!="4")
             {
             cout<<"1. Show the list of Courses"<<endl;
		     cout<<"2. Add a course"<<endl;
		     cout<<"3. Delete a course"<<endl;
             cout<<"4. Exit"<<endl;
             cin>>Choice;
		     if(Choice=="1")
		     {usr.show_course();cout<<"Done"<<endl;}
		     if(Choice=="2")
		     {usr.add_course();cout<<"Done"<<endl;}
		     if(Choice=="3")
			{usr.delete_course();cout<<"Done"<<endl;}
            if(Choice=="4")
            {break;}
             }
	     }
         }
         if(Option=="4")
         {break;}
    }
    cout<<"Welcome for your use!"<<endl;
}
 
