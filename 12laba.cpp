﻿#include <iostream>
#include <memory> 
#include <string>
#define MY_DEBUG

class Teacher;
class Student
{
public:
	Student(const std::string& name)
	{
		m_name = name;
#ifdef MY_DEBUG
		std::cout << "Student constructor" << std::endl;
#endif
	}
	~Student()
	{
#ifdef MY_DEBUG
		std::cout << "Student destrucor" << std::endl;
#endif
	}

	std::string NAMESTUDENT()
	{
		return m_name;
	}

	std::shared_ptr<Student> GETTEACHER()
	{
		m_teacher;
	}

	friend void TEACH(std::shared_ptr<Teacher>& T, std::shared_ptr<Student>& S);

private:
	std::string m_name;
	std::shared_ptr<Teacher> m_teacher;
};

class Teacher
{
public:
	Teacher(const std::string& name)
	{
		m_name = name;
		m_i = 0;
#ifdef MY_DEBUG
		std::cout << "Teacher constructor" << std::endl;
#endif
	}
	~Teacher()
	{
#ifdef MY_DEBUG
		std::cout << "Teacher destructor" << std::endl;
#endif
	}

	std::string NAMETEACHER()
	{
		return m_name;
	}

	std::shared_ptr<Student> GETSTUDENT()
	{
		return (m_student[m_i]);
	}

	void ALLSTUDENT()
	{
		for (int i = 0; i < m_i; i++)
			std::cout << m_student[m_i];
	}

	void ADDSTUDENT()
	{
		m_i = m_i + 1;
	}

	friend void TEACH(std::shared_ptr<Teacher>& T, std::shared_ptr<Student>& S);

private:
	std::string m_name;
	int m_i;
	std::shared_ptr<Student> m_student[5];

};

void TEACH(std::shared_ptr<Teacher>& T, std::shared_ptr<Student>& S)
{
	T->ADDSTUDENT();
	S->m_teacher = T;
	T->GETSTUDENT() = S;
	std::cout << T->m_name << " teach " << S->m_name << std::endl;
}

int main()
{
	std::shared_ptr<Student> student1 = std::make_shared<Student>("Klim");
	std::shared_ptr<Student> student2 = std::make_shared<Student>("Bob");
	std::shared_ptr<Teacher> teacher = std::make_shared<Teacher>("Misha");
	TEACH(teacher, student1);
	TEACH(teacher, student2);
}