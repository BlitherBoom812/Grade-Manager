/**
 * @file saves_manager.h
 * @author BlitherBoom812
 * @brief 存档文件管理。
 * @version 0.1
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#ifndef SAVES_MANAGER_H
#define SAVES_MANAGER_H

#include <string>
#include <list>
#include <fstream>
#include <iostream>
#include <string>
#include "info.h"
#include "utility.h"
#include "const.h"

bool CreateFolder(const char folderName[]);

bool MakeSaveFile(const char fileName[]);

void init_saves_dir();

template <class T>
/**
 * @brief 保存列表中的数据。
 *
 * @param list 要保存的列表。
 * @param file_name 保存的文件名称。
 * @return true 保存成功。
 * @return false 保存失败。
 */
bool save_data(const std::list<T> &list, const char *file_name)
{
    if (!CreateFolder(save_path))
    {
        return false;
    }
    std::string save_file_path = (save_path + std::string("/") + file_name);
    if (!MakeSaveFile(save_file_path.c_str()))
    {
        return false;
    }
    std::fstream fout(save_file_path, std::ios_base::out | std::ios_base::trunc);
    if (!fout.good())
    {
        std::cout << "文件" << file_name << "打开失败!" << std::endl;
        fout.close();
        return false;
    }
    else
    {
        fout << list.size() << std::endl;
        for (typename std::list<T>::const_iterator i = list.begin(); i != list.end(); i++)
        {
            fout << *i << std::endl;
        }
        fout.close();
        return true;
    }
}
/**
 * @brief 保存grade_info。
 *
 * @param grades
 * @return true 保存成功。
 * @return false 保存失败。
 */
bool save_grade_data(const std::list<grade_info> &grades);
/**
 * @brief 读取成绩数据。
 *
 * @param grades 读取的数据在这个表格中。
 * @param file_path 文件路径。
 * @param students 依赖的学生数据。
 * @param courses 依赖的成绩数据。
 * @return true 读取成功。
 * @return false 读取失败。
 */
bool read_grade_data(std::list<grade_info> &grades, const char *file_path, const std::list<student_info> &students, const std::list<course_info> &courses);
template <class T>
/**
 * @brief
 *
 * @param list
 * @param file_path
 * @return true
 * @return false
 */
bool read_data(std::list<T> &list, const char *file_path)
{
    std::fstream fin(file_path, std::ios_base::in);
    if (!fin.good())
    {
        std::cout << "文件" << file_path << "打开失败!" << std::endl;
        return false;
    }
    else
    {
        T buffer;
        int count = 0;
        fin >> count;
        for (int i = 0; i < count; i++)
        {
            fin >> buffer;
            list.push_back(buffer);
        }
        return true;
    }
}

#endif