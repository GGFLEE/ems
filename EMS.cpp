
using namespace std;
#include "EManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

void test()
{
	Worker* worker = NULL;
	worker = new Employee(1, "张三", 1);
	worker->show();
	delete worker;
	worker = new Manager(2, "李四", 2);
	worker->show();
	delete worker;
	worker = new Boss(3, "王五", 3);
	worker->show();
	delete worker;
}
int main() {
	EManager em;
	//test();
	while (true)
	{
		em.Menu();
		cout << "输入选择：" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 0: //退出系统
			em.ExitSys();
			break;
		case 1: //添加职工
			em.add();
			break;
		case 2: //显示职工
			em.show();
			break;
		case 3: //删除职工
			em.del();
			break;
		case 4: //修改职工
			em.mod();
			break;
		case 5: //查找职工
			em.find();
			break;
		case 6: //排序职工
			em.sort();
			break;
		case 7: //清空文件
			em.clearFile();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	
	system("pause");
	return 0;
}