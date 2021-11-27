#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;
double GetDoubleFromString(char * str)
{
   static char * s;
   if(str)
   s = str;
   double q = 0;
   for(;* s && (* s < '0' || * s > '9');++ s)
   if(* s == 0)
   return 0;
   for(;* s >= '0' && *s <= '9'; ++ s)
   q = q * 10 + *s - '0';
   if(* s == '.')
   {
   	++ s;
   	double i = 10;
   	while(* s >= '0' && *s <= '9')
    	{
   	    	q = q + (* s -'0')/i;
   	    	++ s;
   		    i *= 10;
    	}
   }
   return q;
}

int main()
{
	char line[300];
	while(cin.getline(line,280)) {
		double n;
		n = GetDoubleFromString(line);
		while( n > 0) {
			cout << fixed << setprecision(6) << n << endl;
			n = GetDoubleFromString(NULL);
		}
	}
	return 0;
}
