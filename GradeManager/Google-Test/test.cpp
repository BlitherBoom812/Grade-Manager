#include "pch.h"
#include "student_info.h"
#include "course_info.h"
#include "grade_info.h"
#include "enum.h"
#include "data.h"
#include <string>
#include <iostream>

student_info s1(student_id("2021012621"), "zhang san", "无12", "大二", "电子系");
student_info s2(student_id("2021012637"), "zhang si", "无23", "大一", "电子系");
course_info c1(course_id("202121", 1), "diandian", "2021春", "glgg", 2, CourseType::bixiu);
course_info c2(course_id("202122", 2), "diandian", "2021春", "mljj", 2, CourseType::bixiu);
grade_info g1(grade_id(s1.get_id(), c1.get_id()), GradeType::LEVEL, "A", 4.0, 92);
grade_info g2(grade_id(s2.get_id(), c2.get_id()), GradeType::LEVEL, "B+", 3.6, 80);


TEST(DataTest, nullptr) {
	data table;
	table.add(s1);
	table.add(s2);
	table.add(c1);
	table.add(c2);
	table.add(g1);
	table.add(g2);
	EXPECT_EQ(table.contains_id(s1.get_id()), true);
	student_info si(table.get_info(s1.get_id()));
	EXPECT_EQ(s1, si);
	si.set_value("姓名", string_type("asfd"));
	EXPECT_TRUE(table.revise(si));
	EXPECT_EQ(dynamic_cast<const student_info &>(table.get_info(student_id("2021012621"))).get_value("姓名"), string_type("asfd"));
	EXPECT_TRUE(table.contains_id(course_id("202121", 1)));
	EXPECT_TRUE(table.contains_id(g1.get_id()));
	//列表中删除s1，则g1消失
	EXPECT_TRUE(table.del(s1.get_id()));
	EXPECT_FALSE(table.contains_id(student_id("2021012621")));
	EXPECT_TRUE(table.contains_id(course_id("202121", 1)));
	EXPECT_FALSE(table.contains_id(grade_id(student_id("2021012621"), course_id("202121", 1))));
	//列表中删除g2,s2、c2存在
	EXPECT_TRUE(table.del(g2.get_id()));
	EXPECT_FALSE(table.contains_id(g2.get_id()));
	EXPECT_TRUE(table.contains_id(c2.get_id()));
	EXPECT_TRUE(table.contains_id(s2.get_id()));
}