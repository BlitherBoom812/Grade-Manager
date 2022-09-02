/**
 * @file saves_manager.h
 * @author BlitherBoom812
 * @brief �浵�ļ�����
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
 * @brief �����б��е����ݡ�
 *
 * @param list Ҫ������б�
 * @param file_name ������ļ����ơ�
 * @return true ����ɹ���
 * @return false ����ʧ�ܡ�
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
        std::cout << "�ļ�" << file_name << "��ʧ��!" << std::endl;
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
 * @brief ����grade_info��
 *
 * @param grades
 * @return true ����ɹ���
 * @return false ����ʧ�ܡ�
 */
bool save_grade_data(const std::list<grade_info> &grades);
/**
 * @brief ��ȡ�ɼ����ݡ�
 *
 * @param grades ��ȡ���������������С�
 * @param file_path �ļ�·����
 * @param students ������ѧ�����ݡ�
 * @param courses �����ĳɼ����ݡ�
 * @return true ��ȡ�ɹ���
 * @return false ��ȡʧ�ܡ�
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
        std::cout << "�ļ�" << file_path << "��ʧ��!" << std::endl;
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