#include <iostream>
#include <iomanip>
using namespace std;
double GetDoubleFromString(char * str)
{
    static char * start;
    if(str)
    start = str;
    double q = 0;
    for(;* start && (*start < '0' || *start > '9'); ++ start);
    if(* start == 0)
    return -1;
    for(;*start >= '0' && *start <= '9';++ start)
    q = q * 10 + * start - '0';
    if(* start == '.')
    {
        ++ start;
        double i = 10;
        while(*start >= '0' && *start <= '9')
        {
            q = q + (*start - '0')/i;
            ++ start;
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