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
	std::cout << "ְ����ţ� " << m_id
		<< " \tְ�������� " << m_name
		<< " \t��λ��" << getDepName()
		<< " \t��λְ����ɾ�����������" << std::endl;
}
std::string Employee::getDepName()
{
	return std::string("Ա��");//"Ա��"��һ��const char*�����ͣ������ڷ���ʱ���������Զ�����ת��Ϊstring����
}