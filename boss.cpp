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
	std::cout << "ְ����ţ� " << m_id
		<< " \tְ�������� " << m_name
		<< " \t��λ��" << getDepName()
		<< " \t��λְ�𣺣�����˾��������" << std::endl;
}
std::string Boss::getDepName()
{
	return std::string("�ϰ�");
}