/**
 * @file ui.h
 * @author BlitherBoom812
 * @brief uiϵͳ��
 * @version 0.1
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef UI_H
#define UI_h

#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>
#include <stdarg.h>

class ui
{
public:
	/// <summary>
	/// ��ʾѡ�����
	/// </summary>
	/// <param name="title">����</param>
	/// <param name="prompt">ѡ����ʾ</param>
	/// <param name="choice_count">ѡ�����</param>
	/// <param name="...">ѡ��(�ַ�����)</param>
	/// <returns>�û������ѡ��</returns>
	static char show_screen(const char *title, const char *prompt, char choice_count, ...);
	/// <summary>
	/// ����ѡ����棬ѡ�����ת����Ӧ����ͨ���������ྲ̬����
	/// </summary>
	/// <param name="choice_f">ѡ������顣����ֵ��ʾ�Ƿ�ѭ��������Ϊ������������ʾ����Ϣ��</param>
	/// <param name="title">����</param>
	/// <param name="prompt">ѡ����ʾ</param>
	/// <param name="count">ѡ�����</param>
	/// <param name="...">ѡ��(�ַ�����)</param>
	static void choose(bool (*const *const choice_f)(std::string &), const char *title, const char *prompt, char count, ...);
	/// <summary>
	/// ����ѡ����棬ѡ�����ת����Ӧ�ĳ�Ա����
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="t">ѡ�����ڵ�ʵ��</param>
	/// <param name="choice_f">ѡ������顣����ֵ��ʾ�Ƿ�ѭ��������Ϊ������������ʾ����Ϣ��</param>
	/// <param name="title">����</param>
	/// <param name="prompt">ѡ����ʾ</param>
	/// <param name="count">ѡ�����</param>
	/// <param name="...">ѡ��(�ַ�����)</param>
	template <class T>
	static void choose(T *t, bool (T::*const *const choice_f)(std::string &), const char *title, const char *prompt, char count, ...)
	{

		bool flag = true;

		std::string info;

		while (flag)
		{

			std::cout << '[' << title << ']' << std::endl;
			std::cout << prompt << ':' << std::endl;

			char i = 0;
			va_list va;

			va_start(va, count);

			const char *choice_name;

			while (i < count)
			{
				choice_name = va_arg(va, const char *);
				std::cout << '[' << char('A' + i) << ']' << choice_name << std::endl;
				i++;
			}

			char choice = std::tolower(peek_strip(std::cin)) - 'A';
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			if (choice < count && choice >= 0)
			{
				flag = (t->*choice_f[choice])(info);
				system("cls");

				std::cout << info << std::endl;
			}
			else
			{
				system("cls");

				std::cout << info << std::endl;
			}
		}
	}
	/// <summary>
	/// ������\��ͷ�����һ�ɷ���Сд��
	/// </summary>
	/// <returns>����\��Сд��������</returns>
	static const std::string command();
	/// <summary>
	/// �����ж�ȡ��һ���ǿհ��ַ�����������
	/// </summary>
	/// <returns>�ǿհ��ַ�</returns>
	static char peek_strip(std::istream &in);
};

typedef bool (*const choice)(std::string &);

#endif