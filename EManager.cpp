#include "boss.h"
#include "EManager.h"
#include "employee.h"
#include "manager.h"
#include<algorithm>
EManager::EManager()
{
	std::fstream fs;
	fs.open(FILE, std::ios::in);
	m_EmpNum = 0;
	if (!fs.is_open())
	{
		std::cout << "�ļ�������" << std::endl;
		
		
		m_EmpArray = nullptr;
		fs.close();
	}else if(fs.peek()==std::fstream::traits_type::eof())
	{
		std::cout << "�ļ�Ϊ��" << std::endl;
		
		m_EmpArray = nullptr;
		fs.close();
	}else 
	{
		int id;
		std::string name;
		int dId;
		while (fs >> id && fs >> name && fs >> dId) {
			m_EmpNum++;
		}
		
		fs.close();
		std::fstream fs;
		fs.open(FILE, std::ios::in);
		m_EmpArray = new Worker * [m_EmpNum];
		for (int i = 0; i < m_EmpNum; i++)
		{
			fs >> id >> name >> dId;
			if (dId == 1)
			{
				m_EmpArray[i] = new Employee(id, name, dId);
			}
			else if (dId == 2)
			{
				m_EmpArray[i] = new Manager(id, name, dId);
			}
			else
			{
				m_EmpArray[i] = new Boss(id, name, dId);
			}
		}
		fs.close();
		
	}
	

}
void EManager::show()
{
	if (m_EmpNum == 0)
	{
		std::cout << "�޼�¼" << std::endl;
	}
	else
	{
		for (int i = 0; i < m_EmpNum; i++)
		{
			m_EmpArray[i]->show();
		}
		
	}
	system("pause");
	system("cls");
}

void EManager::mod()
{
	std::cout << "������Ҫ�޸ĵ�Ա����ţ�" << std::endl;
	int id;
	std::cin >> id;
	int ind = Exist(id);
	if (ind != -1)
	{
		delete m_EmpArray[ind];

		int nid;
		int ndid;
		std::string nname;
		Worker* worker = nullptr;
		std::cout << "�鵽" << id << "��ְ��" << std::endl;
		std::cout << "�����±��" << std::endl;
		std::cin >> nid;

		std::cout << "����������" << std::endl;
		std::cin >> nname;
		std::cout << "������ְλ" << std::endl;
		std::cin >> ndid;
		switch (ndid)
		{
		case 1:
			worker = new Employee(nid,nname,ndid);
			break;
		case 2:
			worker = new Manager(nid,nname,ndid);
			break;
		case 3:
			worker = new Boss(nid,nname,ndid);
			break;
		default:
			break;
		}
		m_EmpArray[ind] = worker;
		
		save(); //ɾ��������ͬ�����ļ���
		std::cout << "�޸ĳɹ���" << std::endl;
	}
	else
	{
		std::cout << "�޸�ʧ�ܣ�δ�ҵ���ְ��" << std::endl;
	}
	system("pause");
	system("cls");
}

int EManager::Exist(int id)
{
	int ind = -1;
	for (int i = 0; i < m_EmpNum; i++)
	{
		if (m_EmpArray[i]->m_id == id)
		{
			ind = i;
			break;
		}
	}
	
	return ind;
}

void EManager::clearFile()
{
	std::fstream fs;
	fs.open(FILE, std::ios::out );
	m_EmpNum = 0;
	delete[] m_EmpArray; //�ͷ�ԭ�пռ�
	m_EmpArray = nullptr; //��ָ���ÿ�
	fs.close();
	std::cout << "��ճɹ���" << std::endl;
	system("pause");
	system("cls");
}



void EManager::ExitSys()
{
	std::cout << "��ӭ�´�ʹ��" << std::endl;
	system("pause");
	exit(0); //������ʲô�ط����������䣬������ʵ���˳�����
}

void EManager::Menu()
{
	std::cout << "********************************************" << std::endl;
	std::cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << std::endl;
	std::cout << "*************  0.�˳��������  *************" << std::endl;
	std::cout << "*************  1.����ְ����Ϣ  *************" << std::endl;
	std::cout << "*************  2.��ʾְ����Ϣ  *************" << std::endl;
	std::cout << "*************  3.ɾ����ְְ��  *************" << std::endl;
	std::cout << "*************  4.�޸�ְ����Ϣ  *************" << std::endl;
	std::cout << "*************  5.����ְ����Ϣ  *************" << std::endl;
	std::cout << "*************  6.���ձ������  *************" << std::endl;
	std::cout << "*************  7.��������ĵ�  *************" << std::endl;
	std::cout << "********************************************" << std::endl;
}

void EManager::add()
{
	std::cout << "����������ְ�������� " << std::endl;
	int addNum = 0;
	std::cin >> addNum;
	if (addNum > 0)
	{
		//�����¿ռ��С
		int newSize = this->m_EmpNum + addNum;
		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];
		//��ԭ�ռ������ݴ�ŵ��¿ռ���
		if (this->m_EmpArray != nullptr)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//����������
		for (int i = 0; i < addNum; i++)
		{
			int id;
			std::string name;
			int dSelect;
			std::cout << "������� " << i + 1 << " ����ְ����ţ�" << std::endl;
			std::cin >> id;
			std::cout << "������� " << i + 1 << " ����ְ��������" << std::endl;
			std::cin >> name;
			std::cout << "��ѡ���ְ���ĸ�λ��" << std::endl;
			std::cout << "1����ְͨ��" << std::endl;
			std::cout << "2������" << std::endl;
			std::cout << "3���ϰ�" << std::endl;
			std::cin >> dSelect;
			Worker* worker = nullptr;
			switch (dSelect)
			{
			case 1: //��ͨԱ��
				worker = new Employee(id, name, 1);
				break;
			case 2: //����
				worker = new Manager(id, name, 2);
				break;
			case 3:  //�ϰ�
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}

		//�ͷ�ԭ�пռ�
		delete[] this->m_EmpArray;
		//�����¿ռ��ָ��
		this->m_EmpArray = newSpace;
		//�����µĸ���
		this->m_EmpNum = newSize;
		//��ʾ��Ϣ
		std::cout << "�ɹ����" << addNum << "����ְ����" << std::endl;
		save();
	}
	else
	{
		std::cout << "��������" << std::endl;
	}
	system("pause");
	system("cls");
}
void EManager::del()
{
	std::cout << "������Ҫɾ����Ա����ţ�" << std::endl;
	int id;
	std::cin >> id;
	int ind = Exist(id);
	if (ind != -1)
	{
		delete m_EmpArray[ind]; //�ͷŸ�ְ���Ŀռ�
		for (int i = ind; i < m_EmpNum-1; i++)
		{
			m_EmpArray[i] = m_EmpArray[i + 1];
		}
		m_EmpNum--;
		save(); //ɾ��������ͬ�����ļ���
		std::cout << "ɾ���ɹ���" <<std::endl;
	}
	else
	{
		std::cout << "ɾ��ʧ�ܣ�δ�ҵ���ְ��" <<std::endl;
	}
	system("pause");
	system("cls");

}
void EManager::save()
{
	std::fstream fs;
	fs.open(FILE, std::ios::out);
	for (int i = 0; i < m_EmpNum; i++) {
		fs<< m_EmpArray[i]->m_id << " "
		   << m_EmpArray[i]->m_name << " "
			<< m_EmpArray[i]->m_DepId << std::endl;
	}
	fs.close();
	
	
}

void  EManager::find()
{
	std::cout << "��������ҵķ�ʽ��" << std::endl;
	std::cout << "1����ְ����Ų���" << std::endl;
	std::cout << "2������������" << std::endl;

	int select = 0;
	std::cin >> select;


	if (select == 1) //��ְ���Ų���
	{
		int id;
		std::cout << "��������ҵ�ְ����ţ�" << std::endl;
		std::cin >> id;

		int ret = Exist(id);
		if (ret != -1)
		{
			std::cout << "���ҳɹ�����ְ����Ϣ���£�" << std::endl;
			this->m_EmpArray[ret]->show();
		}
		else
		{
			std::cout << "����ʧ�ܣ����޴���" << std::endl;
		}
	}
	else if (select == 2) //����������
	{
		std::string name;
		std::cout << "��������ҵ�������" << std::endl;
		std::cin >> name;

		bool flag = false;  //���ҵ��ı�־
		for (int i = 0; i < m_EmpNum; i++)
		{
			if (m_EmpArray[i]->m_name == name)
			{
				std::cout << "���ҳɹ�,ְ�����Ϊ��"
					<< m_EmpArray[i]->m_id
					<< " �ŵ���Ϣ���£�" << std::endl;

				flag = true;

				this->m_EmpArray[i]->show();
			}
		}
		if (flag == false)
		{
			//���޴���
			std::cout << "����ʧ�ܣ����޴���" << std::endl;
		}
	}
	else
	{
		std::cout << "����ѡ������" << std::endl;
	}
	system("pause");
	system("cls");
}

void EManager::sort()
{
	auto down = [](Worker* a, Worker* b) {
		return a->m_id > b->m_id;
		};
	auto up = [](Worker* a, Worker* b) {
		return a->m_id < b->m_id;
		};
	std::cout << "��ѡ������ʽ��" << std::endl;
	std::cout << "1������" << std::endl;
	std::cout << "2������" << std::endl;
	int select = 0;
	std::cin >> select;
	if (select == 1) //����
	{
		std::sort(m_EmpArray, m_EmpArray + m_EmpNum, up);
		std::cout << "����ɹ���" << std::endl;
		save(); //���������ͬ�����ļ���
		system("pause");
		system("cls");
	}
	else if (select == 2) //����
	{
		std::sort(m_EmpArray, m_EmpArray + m_EmpNum, down);
		std::cout << "����ɹ���" << std::endl;
		save(); //���������ͬ�����ļ���
		system("pause");
		system("cls");
	}
	else
	{
		std::cout << "����ѡ������" << std::endl;
	}
}


EManager::~EManager()
{

}