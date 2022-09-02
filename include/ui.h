/**
 * @file ui.h
 * @author BlitherBoom812
 * @brief ui系统。
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
	/// 显示选择界面
	/// </summary>
	/// <param name="title">标题</param>
	/// <param name="prompt">选项提示</param>
	/// <param name="choice_count">选项个数</param>
	/// <param name="...">选项(字符数组)</param>
	/// <returns>用户输入的选项</returns>
	static char show_screen(const char *title, const char *prompt, char choice_count, ...);
	/// <summary>
	/// 构建选择界面，选择后跳转至对应的普通函数或者类静态函数
	/// </summary>
	/// <param name="choice_f">选项函数数组。返回值表示是否循环，参数为函数结束后显示的信息。</param>
	/// <param name="title">标题</param>
	/// <param name="prompt">选项提示</param>
	/// <param name="count">选项个数</param>
	/// <param name="...">选项(字符数组)</param>
	static void choose(bool (*const *const choice_f)(std::string &), const char *title, const char *prompt, char count, ...);
	/// <summary>
	/// 构建选择界面，选择后跳转至对应的成员函数
	/// </summary>
	/// <typeparam name="T"></typeparam>
	/// <param name="t">选项所在的实例</param>
	/// <param name="choice_f">选项函数数组。返回值表示是否循环，参数为函数结束后显示的信息。</param>
	/// <param name="title">标题</param>
	/// <param name="prompt">选项提示</param>
	/// <param name="count">选项个数</param>
	/// <param name="...">选项(字符数组)</param>
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
	/// 返回以\开头的命令（一律返回小写）
	/// </summary>
	/// <returns>不含\的小写命令内容</returns>
	static const std::string command();
	/// <summary>
	/// 从流中读取第一个非空白字符，但不读掉
	/// </summary>
	/// <returns>非空白字符</returns>
	static char peek_strip(std::istream &in);
};

typedef bool (*const choice)(std::string &);

#endif