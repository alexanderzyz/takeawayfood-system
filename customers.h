#include <iostream>
#include <cstring>
#include <fstream>
#include <stdlib.h>
#include <cstdio>
#include <vector>
#include <errno.h>
#include  <sys/wait.h>
#include <sstream>
#define MAXLINE 20
using namespace std;
class customers
{
public:
    string name;
    string password;
    string Option1;
    string Loginjudge="0";
    string Orderjudge="0";
    void Login();
    void Order();
    void ChangeThePassword();
    void CancelTheOrder();
};