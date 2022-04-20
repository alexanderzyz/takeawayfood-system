#include<fstream>
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
class manager
{
    public:
    string name;
    string password;
    string Loginjudge="0";
    string Option3;
    void show_course();
    void add_course();
    void Login();
    void ChangeThePassword();
    void delete_course();
};