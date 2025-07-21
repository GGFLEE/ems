#pragma once
#include<iostream>
#include<vector>
#include"worker.h"
#include<fstream>
#define FILE "FILE.txt"
class EManager
{
public:
	int m_EmpNum;

	Worker** m_EmpArray;
	EManager();
	void Menu();
	void ExitSys();
	void add();
	void del();
	void save();
	void show();
	void mod();
	int Exist(int id);
	void clearFile();
	void find();
	void sort();
	~EManager();
};
