#include"manager.h"

Manager::Manager(int id, std::string name, int dId)
{
	m_id = id;
	m_name = name;
	m_DepId = dId;


}
Manager::~Manager()
{


}
void Manager::show()
{
	std::cout << "职工编号： " << m_id
		<< " \t职工姓名： " << m_name
		<< " \t岗位：" << getDepName()
		<< " \t岗位职责：完成老板交给的任务,并下发任务给员工" << std::endl;
}
std::string  Manager::getDepName()
{
	return std::string("经理");//"经理"是一个const char*的类型，但是在返回时编译器会自动将其转换为string类型
}