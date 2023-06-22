#include <iostream>
using namespace std;
//class A
//{
//public:
//	explicit A(int a=0)
//		:_a(a)
//	{
//
//	}
//	/*A(const A& a1)
//	{
//		_a = a1._a;
//	}*/
//private:
//	int _a;
//};
////malloc /calloc /realloc 有什么区别呢？
//int main()
//{
//	int* a1 = (int*)malloc(sizeof(int));
//	free(a1);
//
//	int* a2 = (int*)calloc(4,sizeof(int));
//
//	int* a3 = (int*)realloc(a2, sizeof(int) * 5);
//	//a2还需要释放嘛？
//}
//int main()
//{
//	int* p3 = (int*)malloc(sizeof(int));//C
//	int* p4 = new int;
//	free(p3);
//	delete p4;
//	/*A* p1 = (A*)malloc(sizeof(A) * 10);*/
//	/*A* p2 = new A[4]{ A(1),A(2),A(3) };*/
//	A* p7 = new A[4]; 
//	A* p8 = new A[4]{A(1),A(2),A(3),A(4)};
//	delete[] p7;int* p1 = nullptr;
//	p1 = new int[1024 * 1024];
//}

//typedef int DataType;
//class Stack
//{
//public:
//	Stack(size_t capacity = 3)
//	{
//		cout << "Stack(size_t capacity = 3)" << endl;
//
//		_array = (DataType*)malloc(sizeof(DataType) * capacity);
//		if (NULL == _array)
//		{
//			perror("malloc申请空间失败!!!");
//			return;
//		}
//
//		_capacity = capacity;
//		_size = 0;
//	}
//
//	void Push(DataType data)
//	{
//		// CheckCapacity();
//		_array[_size] = data;
//		_size++;
//	}
//
//	// 其他方法...
//
//	~Stack()
//	{
//		cout << "~Stack()" << endl;
//
//		if (_array)
//		{
//			free(_array);
//			_array = NULL;
//			_capacity = 0;
//			_size = 0;
//		}
//	}
//
//private:
//	DataType* _array;
//	int       _capacity;
//	int       _size;
//};
////int main()
////{
////	try
////	{
////		//需要申请一个堆上的栈对象
////		Stack* p1 = new Stack;
////		delete p1;
////	}
////	catch (const exception& e)
////	{
////		cout << e.what() << endl;
////	}
////}
////int main()
////{
////	A* p1 = (A*)malloc(sizeof(A));
////	//p1指向的只不过是与A对象相同大小的一段空间，还不是对象，因为构造函数没有执行。
////	new(p1)A(1);//显式的调用构造函数
////	free(p1);
////}
////int main()
////{
////	char* p1 = new char[1024 * 1024 * 1024] {'t', 'e', 'w', '\0'};
////	cout << p1 << endl;
////}
////int main()
////{
////	//自定义类型会去调用它的默认构造
////	//对于自定义类型，malloc不会初始化，而new会自动调用构造函数，来初始化。
////	A* a2 = (A*)malloc(sizeof(A));
////	A* a1 = new A;
////}
////int main()
////{
////	int* p2 = (int*)malloc(sizeof(int) * 10);
////	//申请10个int大小的数组
////	int* p3 = new int[10];
////	delete[] p3;
////	//申请一个数组，初始化为10
////	int* p8 = new int(10);
////	delete p8;
////	//申请一个10个int大小的数组
////	int* p5 = new int[10] {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
////	delete[] p5;
////}
struct ListNode
{
	int _val;
	struct ListNode* _next;

	ListNode(int x = 0)
		:_val(x)
		, _next(NULL)
	{}
};
struct ListNode* BuyListNode(int x)
{
	//C  malloc单纯的开空间,还需要自己转化类型
	struct ListNode* newnode = (struct ListNode*)malloc(sizeof(struct ListNode));
	//还需要检查
	if (newnode == NULL)
	{
		perror("malloc");
	}
	//需要开完空间自己手动初始化
	newnode->_next = NULL;
	newnode->_val = x;
	return newnode;
}
int main()
{
	struct ListNode* n1 = BuyListNode(1);
	struct ListNode* n2 = BuyListNode(2);

	//但C++的new就不一样了，new是开完空间后还可以自己初始化
	//怎么初始化的呢？会调用构造函数初始化
	struct ListNode* n3 = new ListNode(6);
	struct ListNode* n4 = new ListNode;
}
//template<typename T>
//void Swap(T& x1, T& x2)
//{
//	T tmp = x1;
//	x1 = x2;
//	x2 = tmp;
//}
//int main()
//{
//	int a = 0, b = 1;
//	double c = 1.1, d = 2.2;
//	Swap(a, b);
//	Swap(c, d);
//	int* p1 = &a, * p2 = &b;
//	Swap(p1, p2);
//	A a1(1), a2(2);
//	Swap(a1, a2);//会自动识别类型，然后模板实例化
//}
//int main()
//{
//	int* p1 = (int*)malloc(sizeof(int) * 10);//C
//	int* p2 = (int*)malloc(sizeof(int));//C
//	int* p3 = new int;//C++。
//	int* p4 = new int(1);//C++
//	int* p5 = new int[10];//C++
//	free(p1);
//	free(p2);
//	delete p3;
//	delete p4;
//	delete[] p5;
//}
//class A
//{
//public:
//	explicit A(int a = 0)
//		:_a(a)
//	{
//
//	}
//	A(const A& a1)
//	{
//		_a = a1._a;
//	}
//	~A()
//	{
//		cout << "~A()" << endl;
//   }
//private:
//	int _a;
//};
//
//int main()
//{
//	//aa1可不是对象，aa1现在只不过是指向与A对象一样大的空间，不能算作对象，因为构造函数没有执行，没有实例化。
//	A* aa1 = (A*)malloc(sizeof(A));
//	
//	new(aa1)A;//显式的调用构造函数，要注意如果A的构造函数有参数需要传参。
//
//	aa1->~A();//手动的调用析构函数
//
//	free(aa1);//手动的调用free
//
//	//同理如下
//	A* aa2 = (A*)operator new(sizeof(A));
//	new(aa2)A(10);
//	aa2->~A();
//	free(aa2);
//}
//int main()
//{
//	//动态开辟一个A类型的空间
//	A* aa1 = (A*)malloc(sizeof(A));//C
//	A* aa2 = new A(1);
//	free(aa1);
//	delete aa2;
//
//	//动态开辟一个10个A类型大小的数组
//	A* aa3 = (A*)malloc(sizeof(A) * 10);//C++
//	A* aa4 = new A[10];
//	free(aa3);
//	delete[] aa4;
//
//}