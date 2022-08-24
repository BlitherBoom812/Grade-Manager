#ifndef GRADE_ID_H
#define GRADE_ID_H

/*
³É¼¨id
*/

#include "student_id.h"
#include "course_id.h"

class grade_id : public student_id, public course_id{
public:
	grade_id(const student_id &stu, const course_id &cou) : student_id(stu), course_id(cou){}
	grade_id(const grade_id &cp) : student_id(cp), course_id(cp){}
	virtual void set(const value_type &new_value);
	virtual void set_id(const id_type &new_id);
	virtual void set_grade_id(const grade_id &new_grade_id);
	virtual bool operator==(const value_type &cmp) const;
	virtual bool operator<(const id_type &cmp) const;
	virtual const value_type &operator=(const value_type &value);
};

#endif