#include "../include/ui.h"
#include <iostream>
#include <cstdarg>
#include <algorithm>

char ui::show_screen(const char *title, const char *prompt, char choice_count, ...)
{

	std::cout << '[' << title << ']' << std::endl;
	std::cout << prompt << ':' << std::endl;

	char i = 0;

	va_list va;

	va_start(va, choice_count);

	const char *choice_name;

	while (i < choice_count)
	{
		choice_name = va_arg(va, const char *);
		std::cout << '[' << char('A' + i) << ']' << choice_name << std::endl;
		i++;
	}

	i = std::toupper(peek_strip(std::cin));
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	return i;
}

void ui::choose(bool (*const *const choice_f)(std::string &), const char *title, const char *prompt, char count, ...)
{
	bool flag = true;

	std::string info; //ªÿœ‘–≈œ¢

	system("cls");

	std::cout << info << std::endl;
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

		char choice = std::toupper(peek_strip(std::cin)) - 'A';
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

		if (choice < count && choice >= 0)
		{
			flag = (choice_f[(int)choice])(info);

			system("cls");

			std::cout << info << std::endl;
		}
		else
		{

			system("cls");

		}
	}
}

const std::string ui::command()
{

	if (peek_strip(std::cin) == '\\')
	{
		std::string command;
		std::cin >> command;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::transform(command.begin(), command.end(), command.begin(), ::tolower);
		return (command.substr(1));
	}
	else
	{
		return "";
	}
}

char ui::peek_strip(std::istream &in)
{
	while (in.peek() <= 32 && in.peek() != EOF)
	{
		in.get();
	}
	return in.peek();
}
