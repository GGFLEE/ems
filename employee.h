#pragma once
#include "worker.h"
class Employee:public Worker
{
public:
	Employee(int id, std::string name, int dId);
	~Employee();
	virtual void show();
	virtual std::string getDepName();
};