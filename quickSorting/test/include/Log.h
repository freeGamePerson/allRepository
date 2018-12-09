#ifndef LOG_INCLUDED
#define LOG_INCLUDED

#include <iostream>
#include <ctime>
#include <cstring>

using namespace std;

time_t getTimeNow()
{
	time_t now;

	now = time(NULL);
	return now;
}

template <typename T>
void ERROR_LOG(T content);

template <typename T>
void print(T value);

string getTimestr()
{
    time_t rawtime;
    struct tm * timeinfo;
    char buffer [80];
    time (&rawtime);

    timeinfo = localtime (&rawtime);
    strftime (buffer,sizeof(buffer),"Now is %Y/%m/%d %H:%M:%S",timeinfo);
	return buffer;
}

template <typename T>
void ERROR_LOG(T content)
{
	cout <<"ERROR_LOG\t"<< getTimestr() <<"\t"  << "\t[DEBUG]]\t" << content <<endl;
}

template <typename T>
void print(T value)
{
	cout << value <<endl;
}
#endif // LOG_INCLUDED
