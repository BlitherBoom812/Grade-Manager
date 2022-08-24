#ifndef TEST_CPP
#define TEST_CPP

#include <iostream>
#include "test.h"
#include "student_id.h"
#include "course_id.h"
#include "grade_id.h"


void print(const char *c);
//m<int> y;
//void test() {
//	y.print();
//}
void test_attribute() {
	value_type &vt = *(new content_type<std::string>("wang"));
	field f(std::string("name"), vt);
	field f2[] = { field("name", vt), field("id", (value_type &)content_type<int>(2)) };

	f.set_value(vt);
	attribute_info a(f2, 2);
	if (((const content_type<std::string> &)a.get_value("name")).get_content() == "wang") {
		std::cout << "name correct" << std::endl;
	}
	else {
		std::cout << "name wrong" << std::endl;
	}
	if (((const content_type<int> &)a.get_value("id")).get_content() == 2) {
		std::cout << "id correct" << std::endl;
	}
	else {
		std::cout << "id wrong" << std::endl;
	}
	if (a.get_key_count() == 2) {
		std::cout << "key count correct" << std::endl;
	}
	else {
		std::cout << "key count wrong" << std::endl;
	}
	if (!a.contains_key("alpha")) {
		std::cout << "not contain key" << std::endl;
	}
	else {
		std::cout << "contain key" << std::endl;
	}
	delete &vt;
}
void test_id() {
	student_id zs("zhang san");
	course_id dd("202102", 1);
	course_id dd2("202102", 2);
	grade_id cj(zs, dd);
	//student
	print("get student id ");
	if (zs.get_student_id() == "zhang san") {
		print("correct");
	}
	else {
		print("wrong");
	}
	//course
	print("get course first id ");
	if (dd.get_course_first_id() == "202102") {
		print("correct");
	}
	else {
		print("wrong");
	}
	print("get course second id ");
	if (dd.get_course_second_id() == 1) {
		print("correct");
	}
	else {
		print("wrong");
	}
	//grade
	print("get grade id ");
	print("course first id ");
	if (cj.get_course_first_id() == "202102") {
		print("correct");
	}
	else {
		print("wrong");
	}
	print("get course second id ");
	if (cj.get_course_second_id() == 1) {
		print("correct");
	}
	else {
		print("wrong");
	}
	print("get student id ");
	if (cj.get_student_id() == "zhang san") {
		print("correct");
	}
	else {
		print("wrong");
	}

	print("compare course");
	if (dd < dd2) {
		print("correct");
	}
	else {
		print("wrong");
	}
	return dd.get_course_first_id();
}
void print(const char *c) {
	std::cout << c << std::endl;
}
#endif // !TEST_CPP
