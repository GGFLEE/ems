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
		std::cout << "文件不存在" << std::endl;
		
		
		m_EmpArray = nullptr;
		fs.close();
	}else if(fs.peek()==std::fstream::traits_type::eof())
	{
		std::cout << "文件为空" << std::endl;
		
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
		std::cout << "无记录" << std::endl;
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
	std::cout << "请输入要修改的员工编号：" << std::endl;
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
		std::cout << "查到" << id << "号职工" << std::endl;
		std::cout << "输入新编号" << std::endl;
		std::cin >> nid;

		std::cout << "输入新名字" << std::endl;
		std::cin >> nname;
		std::cout << "输入新职位" << std::endl;
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
		
		save(); //删除后数据同步到文件中
		std::cout << "修改成功！" << std::endl;
	}
	else
	{
		std::cout << "修改失败，未找到该职工" << std::endl;
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
	delete[] m_EmpArray; //释放原有空间
	m_EmpArray = nullptr; //将指针置空
	fs.close();
	std::cout << "清空成功！" << std::endl;
	system("pause");
	system("cls");
}



void EManager::ExitSys()
{
	std::cout << "欢迎下次使用" << std::endl;
	system("pause");
	exit(0); //不管在什么地方运行这个语句，都可以实现退出程序
}

void EManager::Menu()
{
	std::cout << "********************************************" << std::endl;
	std::cout << "*********  欢迎使用职工管理系统！ **********" << std::endl;
	std::cout << "*************  0.退出管理程序  *************" << std::endl;
	std::cout << "*************  1.增加职工信息  *************" << std::endl;
	std::cout << "*************  2.显示职工信息  *************" << std::endl;
	std::cout << "*************  3.删除离职职工  *************" << std::endl;
	std::cout << "*************  4.修改职工信息  *************" << std::endl;
	std::cout << "*************  5.查找职工信息  *************" << std::endl;
	std::cout << "*************  6.按照编号排序  *************" << std::endl;
	std::cout << "*************  7.清空所有文档  *************" << std::endl;
	std::cout << "********************************************" << std::endl;
}

void EManager::add()
{
	std::cout << "请输入增加职工数量： " << std::endl;
	int addNum = 0;
	std::cin >> addNum;
	if (addNum > 0)
	{
		//计算新空间大小
		int newSize = this->m_EmpNum + addNum;
		//开辟新空间
		Worker** newSpace = new Worker * [newSize];
		//将原空间下内容存放到新空间下
		if (this->m_EmpArray != nullptr)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//输入新数据
		for (int i = 0; i < addNum; i++)
		{
			int id;
			std::string name;
			int dSelect;
			std::cout << "请输入第 " << i + 1 << " 个新职工编号：" << std::endl;
			std::cin >> id;
			std::cout << "请输入第 " << i + 1 << " 个新职工姓名：" << std::endl;
			std::cin >> name;
			std::cout << "请选择该职工的岗位：" << std::endl;
			std::cout << "1、普通职工" << std::endl;
			std::cout << "2、经理" << std::endl;
			std::cout << "3、老板" << std::endl;
			std::cin >> dSelect;
			Worker* worker = nullptr;
			switch (dSelect)
			{
			case 1: //普通员工
				worker = new Employee(id, name, 1);
				break;
			case 2: //经理
				worker = new Manager(id, name, 2);
				break;
			case 3:  //老板
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}

		//释放原有空间
		delete[] this->m_EmpArray;
		//更改新空间的指向
		this->m_EmpArray = newSpace;
		//更新新的个数
		this->m_EmpNum = newSize;
		//提示信息
		std::cout << "成功添加" << addNum << "名新职工！" << std::endl;
		save();
	}
	else
	{
		std::cout << "输入有误" << std::endl;
	}
	system("pause");
	system("cls");
}
void EManager::del()
{
	std::cout << "请输入要删除的员工编号：" << std::endl;
	int id;
	std::cin >> id;
	int ind = Exist(id);
	if (ind != -1)
	{
		delete m_EmpArray[ind]; //释放该职工的空间
		for (int i = ind; i < m_EmpNum-1; i++)
		{
			m_EmpArray[i] = m_EmpArray[i + 1];
		}
		m_EmpNum--;
		save(); //删除后数据同步到文件中
		std::cout << "删除成功！" <<std::endl;
	}
	else
	{
		std::cout << "删除失败，未找到该职工" <<std::endl;
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
	std::cout << "请输入查找的方式：" << std::endl;
	std::cout << "1、按职工编号查找" << std::endl;
	std::cout << "2、按姓名查找" << std::endl;

	int select = 0;
	std::cin >> select;


	if (select == 1) //按职工号查找
	{
		int id;
		std::cout << "请输入查找的职工编号：" << std::endl;
		std::cin >> id;

		int ret = Exist(id);
		if (ret != -1)
		{
			std::cout << "查找成功！该职工信息如下：" << std::endl;
			this->m_EmpArray[ret]->show();
		}
		else
		{
			std::cout << "查找失败，查无此人" << std::endl;
		}
	}
	else if (select == 2) //按姓名查找
	{
		std::string name;
		std::cout << "请输入查找的姓名：" << std::endl;
		std::cin >> name;

		bool flag = false;  //查找到的标志
		for (int i = 0; i < m_EmpNum; i++)
		{
			if (m_EmpArray[i]->m_name == name)
			{
				std::cout << "查找成功,职工编号为："
					<< m_EmpArray[i]->m_id
					<< " 号的信息如下：" << std::endl;

				flag = true;

				this->m_EmpArray[i]->show();
			}
		}
		if (flag == false)
		{
			//查无此人
			std::cout << "查找失败，查无此人" << std::endl;
		}
	}
	else
	{
		std::cout << "输入选项有误" << std::endl;
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
	std::cout << "请选择排序方式：" << std::endl;
	std::cout << "1、升序" << std::endl;
	std::cout << "2、降序" << std::endl;
	int select = 0;
	std::cin >> select;
	if (select == 1) //升序
	{
		std::sort(m_EmpArray, m_EmpArray + m_EmpNum, up);
		std::cout << "排序成功！" << std::endl;
		save(); //排序后数据同步到文件中
		system("pause");
		system("cls");
	}
	else if (select == 2) //降序
	{
		std::sort(m_EmpArray, m_EmpArray + m_EmpNum, down);
		std::cout << "排序成功！" << std::endl;
		save(); //排序后数据同步到文件中
		system("pause");
		system("cls");
	}
	else
	{
		std::cout << "输入选项有误" << std::endl;
	}
}


EManager::~EManager()
{

}