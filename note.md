实现类的强制转换

~~~C++
#include<iostream>
#include<cassert>
#define DEBUG
class A {
public:
	virtual bool operator==(const A &cmp) = 0;
	virtual bool operator<(const A &cmp) = 0;
};

class B : public A{
private:
	int id;
public:
	B(const int& id): id(id){

	}
	int getId() {
		return id;
	}
	void setId(int new_id) {
		id = new_id;
	}
	virtual bool operator==(const A &cmp) {

		if (typeid(B) != typeid(cmp)) {
			return false;
		}
		else {
			return ((const B &)cmp).id == id;
		}

	}
	virtual bool operator<(const A &cmp) {

#ifdef DEBUG
		assert(typeid(B) == typeid(cmp));
#endif // DEBUG

		return id < ((const B &)cmp).id;
	}
};
class C : public A {
private:
	char id;
public:
	C(char id): id(id) {

	}
	virtual bool operator==(const A &cmp) {

		if (typeid(C) != typeid(cmp)) {
			return false;
		}
		else {
			return ((const C&)cmp).id == id;
		}

	}
	virtual bool operator<(const A &cmp) {

#ifdef DEBUG
		assert(typeid(C) == typeid(cmp));
#endif // DEBUG

		return id < ((const C &)cmp).id;

	}
};
int main() {
	B *b1 = new B(12);
	B *b2 = new B(13);
	B *b11 = new B(12);
	C *c1 = new C(12);
	std::cout << (*b1 == *b2) << std::endl;
	std::cout << (*b1 == *b11) << std::endl;
	std::cout << (*b1 == *c1) << std::endl;
	std::cout << (*b1 < *c1) << std::endl;
	return 0;
}
~~~

单例模式

~~~C++
#include<iostream>
class singleton {
private:
	static singleton instance;
	singleton() {

	}
public:
	static singleton& get_singleton() {
		return instance;
	}
	void show_message() {
		std::cout << "singleton hello" << std::endl;
	}
};
singleton singleton::instance;
int main(){
    singleton::get_singleton().show_message();
}
~~~

C++03支持的map::insert

~~~C++
	std::map<int, std::string > m;
	const std::map<int, std::string> &n = m;
	n.begin();
	m.begin();
	m.insert(std::make_pair(11, "hello"));
~~~

