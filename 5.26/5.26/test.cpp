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
////д��ȫ�ֺ���
//ostream& operator<<(ostream& _cout, const Data& d)// cout<<d1
//{
//	_cout << _year << "-" << _month << "-" << _day << endl;//�����޷�������˽�г�Ա
//	return _cout;
//}
//int main()
//{
//	Data d1;
//	//d1 << cout;//��Ȼ���Դ�ӡ�������������ϳ�����á�
//	cout << d1;//����Ӧ��������ʹ��
//}
//
//
////����<<��������غ�������д�������棬д��������ͻ��ɳ�Ա����������Ա�����ͻ�Ĭ�ϵ�һ�����������ص�thisָ�룬thisָ��������
////�洢���øú����Ķ���ĵ�ַ�ġ�
////���Ա���д�����⣬Ҳ����ȫ�ַ�Χ�ڣ�������һ�����⣬д�������棬
////����˽�еĳ�Ա�������޷������ˣ������ô���أ�
////�����ʩ����Ԫ
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
//	//��������<<�����,��������������������
//	//������д������cout<<д�� cout<<�����cout�ұ���Ҫ���������
//	//�����Ҫд��ostream& operator<<(ostream&_cout,&d),�����ֻ����һ�����⣬��һ�������������ص�thisָ�룬Ҳ���Ǳ����ǵ���
//	//�ú����Ķ����ָ�룬�ǵ��ú���ʱ�ͱ�������� d1<<cout,d1.operator<<(&d1,ostream&_cout)
//	//������д����cout<<d1.
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
//	_cout << d._year << "-" << d._month << "-" << d._day << endl;//�����޷�������˽�г�Ա
//	return _cout;
//}
//int main()
//{
//	Data d1;
//	//d1 << cout;//��Ȼ���Դ�ӡ�������������ϳ�����á�
//	cout << d1;//����Ӧ��������ʹ��
//}
//
//
////����<<��������غ�������д�������棬д��������ͻ��ɳ�Ա����������Ա�����ͻ�Ĭ�ϵ�һ�����������ص�thisָ�룬thisָ��������
////�洢���øú����Ķ���ĵ�ַ�ġ�
////���Ա���д�����⣬Ҳ����ȫ�ַ�Χ�ڣ�������һ�����⣬д�������棬
////����˽�еĳ�Ա�������޷������ˣ������ô���أ�
////�����ʩ����Ԫ

class Time
{
	friend class Data;//������������ʱ�������Ԫ�ࡣ
	//�����������У����еĳ�Ա�����������������ʱ����ĳ�Ա������
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
	//��ΪData����Time�����Ԫ�࣬����Data�����Գ�Ա���������Է���Time��ĳ�Ա������
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