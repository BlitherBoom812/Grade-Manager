#include "const.h"
#include "info.h"
const char *student_file_name = "student.dat";
const char *course_file_name = "course.dat";
const char *grade_file_name = "grade.dat";

const char *student_path = "./saves/student.dat";
const char *course_path = "./saves/course.dat";
const char *grade_path = "./saves/grade.dat";
const char *save_path = "./saves";

const student_info null_student = student_info();
const course_info null_course = course_info();
const grade_info null_grade = grade_info();
const student_info title_student = student_info("ѧ��", "����", "�༶", "�꼶", "Ժϵ");
const course_info title_course = course_info("�γ̺�", "�����", "�γ���", "�ڿ�ѧ��", "�ο���ʦ", "ѧ��");
const grade_info title_grade = grade_info(
    "ѧ��", "����", "�༶", "�꼶", "Ժϵ",
    "�γ̺�", "�����", "�γ���", "�ڿ�ѧ��", "�ο���ʦ", "ѧ��",
    "������", "�γ�����", "�ȼ�", "����", "�ٷ��Ƴɼ�");

const int width_id = 12;
const int width_name = 10;
const int width_course_first_id = 12;
const int widtch_course_second_id = 8;
const int width_course_name = 30;