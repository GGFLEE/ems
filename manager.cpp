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
	std::cout << "ְ����ţ� " << m_id
		<< " \tְ�������� " << m_name
		<< " \t��λ��" << getDepName()
		<< " \t��λְ������ϰ彻��������,���·������Ա��" << std::endl;
}
std::string  Manager::getDepName()
{
	return std::string("����");//"����"��һ��const char*�����ͣ������ڷ���ʱ���������Զ�����ת��Ϊstring����
}