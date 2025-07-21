#include"boss.h"

Boss::Boss(int id,std::string name,int dId)
{
	m_id = id;
	m_name = name;
	m_DepId = dId;

}
Boss::~Boss()
{
	

}

void Boss::show()
{
	std::cout << "职工编号： " << m_id
		<< " \t职工姓名： " << m_name
		<< " \t岗位：" << getDepName()
		<< " \t岗位职责：：管理公司所有事务" << std::endl;
}
std::string Boss::getDepName()
{
	return std::string("老板");
}