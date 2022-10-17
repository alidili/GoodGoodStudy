#include <iostream>
using namespace std;

class Base
{
public:
	virtual void className() = 0;
};

class A :public Base {
private:
	string a;
public:
	void setA(string a) {
		this->a = a;
	}

	string getA() {
		return a;
	}

	void className() {
		cout << "A类名：" << a << endl;
	}
};

class B :public Base {
private:
	string b;
public:
	void setB(string b) {
		this->b = b;
	}

	string getB() {
		return b;
	}

	void className() {
		cout << "B类名：" << b << endl;
	}
};

class C :public Base {
private:
	string c;
public:
	void setC(string c) {
		this->c = c;
	}

	string getC() {
		return c;
	}

	void className() {
		cout << "C类名：" << c << endl;
	}
};

int main()
{
	Base *ptr[3];
	A a;
	a.setA("A");
	B b;
	b.setB("B");
	C c;
	c.setC("C");
	ptr[0] = &a;
	ptr[1] = &b;
	ptr[2] = &c;
	for (int i = 0; i < 3;i++) {
		ptr[i]->className();
	}
	return 0;
}