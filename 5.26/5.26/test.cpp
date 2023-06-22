#include <iostream>

using namespace std;
//class  Data
//{
//public:
//	
//	Data(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//
//	}
//	
//private:
//	int _year;
//	int _month;
//	int _day;
//};
////写成全局函数
//ostream& operator<<(ostream& _cout, const Data& d)// cout<<d1
//{
//	_cout << _year << "-" << _month << "-" << _day << endl;//问题无法访问类私有成员
//	return _cout;
//}
//int main()
//{
//	Data d1;
//	//d1 << cout;//虽然可以打印出来，但不符合常规调用。
//	cout << d1;//正常应该是这样使用
//}
//
//
////所以<<运算符重载函数不能写在类里面，写在类里面就会变成成员函数，而成员函数就会默认第一个参数是隐藏的this指针，this指针是用来
////存储调用该函数的对象的地址的。
////所以必须写到类外，也就是全局范围内，但又有一个问题，写到类外面，
////那类私有的成员变量就无法访问了，这该怎么办呢？
////解决措施：友元
//using namespace std;
//class  Data
//{
//public:
//	friend ostream& operator<<(ostream& _cout, const Data& d);
//	Data(int year = 1, int month = 1, int day = 1)
//		:_year(year)
//		, _month(month)
//		, _day(day)
//	{
//
//	}
//	//尝试重载<<运算符,让它可以输出对象的数据
//	//但这样写不符合cout<<写法 cout<<左边是cout右边是要输出的数据
//	//但如果要写成ostream& operator<<(ostream&_cout,&d),这样又会出现一个问题，第一参数必须是隐藏的this指针，也就是必须是调用
//	//该函数的对象的指针，那调用函数时就变成这样了 d1<<cout,d1.operator<<(&d1,ostream&_cout)
//	//但正常写法是cout<<d1.
//	/*ostream& operator<<(ostream& _cout)
//	{
//		_cout << _year << "-" << _month << "-" << _day << endl;
//		return _cout;
//	}*/
//private:
//	int _year;
//	int _month;
//	int _day;
//};
//ostream& operator<<(ostream& _cout, const Data& d)// cout<<d1
//{
//	_cout << d._year << "-" << d._month << "-" << d._day << endl;//问题无法访问类私有成员
//	return _cout;
//}
//int main()
//{
//	Data d1;
//	//d1 << cout;//虽然可以打印出来，但不符合常规调用。
//	cout << d1;//正常应该是这样使用
//}
//
//
////所以<<运算符重载函数不能写在类里面，写在类里面就会变成成员函数，而成员函数就会默认第一个参数是隐藏的this指针，this指针是用来
////存储调用该函数的对象的地址的。
////所以必须写到类外，也就是全局范围内，但又有一个问题，写到类外面，
////那类私有的成员变量就无法访问了，这该怎么办呢？
////解决措施：友元

class Time
{
	friend class Data;//声明日期类是时间类的友元类。
	//则在日期类中，所有的成员函数都可以随意访问时间类的成员变量。
public:
	Time(int year = 2, int month = 2, int day = 2)
		:_year(year)
		, _month(month)
		, _day(day)
	{

	}
	
private:
	int _year;
	int _month;
	int _day;
};

class  Data
{
public:

	Data(int year = 1, int month = 1, int day = 1)
		:_year(year)
		, _month(month)
		, _day(day)
	{

	}
	//因为Data类是Time类的友元类，所以Data的所以成员函数都可以访问Time类的成员变量。
	void ChangeTime(int year = 2023, int month = 5, int day = 20)
	{
		_t._year = year;
		_t._month = month;
		_t._day = day;
	}
private:
	int _year;
	int _month;
	int _day;
	Time _t;
};
int main()
{
	Data d1;
	d1.ChangeTime();
}