#pragma once
#include "worker.h"
class Manager :public Worker
{
public:
	Manager(int id, std::string name, int dId);
	~Manager();
	virtual void show();
	virtual std::string getDepName();
};