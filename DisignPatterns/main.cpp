#include<iostream>
#include<string>
#include<time.h>
using namespace std;

class Singleton
{
	static Singleton* instance;
	string last_name;
	string first_name;
	tm birth_date;
	Singleton()
	{
		cout << "Constructor:\t" << this << endl;
	}
public:
	const string& get_last_name()const { return last_name; }
	const string& get_first_name()const { return first_name; }
	tm get_birth_date() { return birth_date; }
	void set_last_name(const std::string& last_name)
	{
		this->last_name;
	}
	void set_first_name(const std::string& first_name)
	{
		this->first_name;
	}
	void set_birth_date(size_t year, size_t month, size_t day)
	{
		this->birth_date.tm_year = year;
		this->birth_date.tm_mon = month;
		this->birth_date.tm_wday = day;
	}
	~Singleton()
	{
		cout << "Destructor:\t" << this << endl;
	}
	static Singleton* getInstance()
	{
		if (instance == nullptr)instance = new Singleton;
		return instance;
	}
	void print()const
	{
		cout << last_name << " " << first_name << endl;
	}
};
void main()
{
	setlocale(LC_ALL, "");
	Singleton* director = Singleton::getInstance();
	director->get_last_name("Василий");
}