#include<string>
#include <time.h>
#include <sstream>
#include <fstream>
using namespace std;
class riders
{
public:
	string name;
	string password;
	string Option2;
	bool avalible=true;
	 void Login();
	 void State();
	 void ChangeThePassword();
	 double Ltime;
	 double Ntime;
	  int id;
	 string selfid;
	 string Loginjudge="0";
	 string  sid;
	 riders()
	 {
		Ltime=0;
		stringstream sstream;
		sstream << id;
		sstream>> sid;
	 }
};