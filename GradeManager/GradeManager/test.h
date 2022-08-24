#ifndef TEST_H
#define TEST_H
#include <iostream>
#include "value_type.h"
#include "attribute_info.h"
#include "content_type.h"
#include "field.h"
template <class T>
class m {
public:
	void print();
};
template <class T>
void m<T>::print() {
	std::cout << "test" << std::endl;
}
class n {
public:
	void print() {
		std::cout << "test n" << std::endl;
	}
};
void test_attribute();
void test_id();
#endif