#pragma once
#include<iostream>
#include<string>
class Worker
{
public:
	int m_id;
	int m_DepId;
	
	std::string m_name;
	virtual void show() = 0;
	virtual std::string getDepName() = 0;
};
