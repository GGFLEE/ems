#pragma once
#include "worker.h"
class Boss :public Worker
{
public:
	Boss(int id, std::string name, int dId);
	~Boss();
	virtual void show();
	virtual std::string getDepName();
};