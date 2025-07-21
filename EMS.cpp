
using namespace std;
#include "EManager.h"
#include "worker.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"

void test()
{
	Worker* worker = NULL;
	worker = new Employee(1, "����", 1);
	worker->show();
	delete worker;
	worker = new Manager(2, "����", 2);
	worker->show();
	delete worker;
	worker = new Boss(3, "����", 3);
	worker->show();
	delete worker;
}
int main() {
	EManager em;
	//test();
	while (true)
	{
		em.Menu();
		cout << "����ѡ��" << endl;
		int choice;
		cin >> choice;
		switch (choice)
		{
		case 0: //�˳�ϵͳ
			em.ExitSys();
			break;
		case 1: //���ְ��
			em.add();
			break;
		case 2: //��ʾְ��
			em.show();
			break;
		case 3: //ɾ��ְ��
			em.del();
			break;
		case 4: //�޸�ְ��
			em.mod();
			break;
		case 5: //����ְ��
			em.find();
			break;
		case 6: //����ְ��
			em.sort();
			break;
		case 7: //����ļ�
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