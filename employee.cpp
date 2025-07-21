#include"employee.h"

Employee::Employee(int id, std::string name, int dId)
{
	m_id = id;
	m_name = name;
	m_DepId = dId;

}
Employee::~Employee()
{
	

}
void Employee::show() 
{
	std::cout << "职工编号： " << m_id
		<< " \t职工姓名： " << m_name
		<< " \t岗位：" << getDepName()
		<< " \t岗位职责：完成经理交给的任务" << std::endl;
}
std::string Employee::getDepName()
{
	return std::string("员工");//"员工"是一个const char*的类型，但是在返回时编译器会自动将其转换为string类型
}