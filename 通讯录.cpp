#include<iostream>
using namespace std;
#include<string>
#define Max 1000
struct  peopre 
{
	string name;
	int sex;
	int age;
	string calling;
	string add;
}peopreArr[Max];
struct  connect 
{
	peopre peopreArr[Max];
	int M_size;
}ab;
void showmenu()
{
	cout <<"*******************************************************************" << endl;
	cout <<"************************1.�������ϵ��****************************" << endl;
	cout <<"************************2.��ʾ��ϵ��   ***************************" << endl;
	cout <<"************************3.ɾ����ϵ��   ***************************" << endl;
	cout <<"************************4.������ϵ��   ***************************" << endl;
	cout <<"************************5.�޸���ϵ��   ***************************" << endl;
	cout <<"************************6.�����ϵ��   ***************************" << endl;
	cout <<"------------------------------------------------------------------" << endl;
}
void addpeopre(connect* ab ) 
{
	if (ab->M_size == Max)
	{
		cout << "ͨѶ¼�������޷������" << endl;
	}
	else {
		//�������
		string name;
		cout << "����:" << endl;
		cin >> name;
		ab->peopreArr[ab->M_size].name = name;
		//�Ա�
		cout << "�������Ա�:" << endl;
		cout << "1-----man" << endl;
		cout<<"2------woman"<<endl;
		int  sex=0 ;
		
		while(1){
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				ab->peopreArr[ab->M_size].sex = sex;
				break;
			}
			else {
				cout << "�����������������" << endl;
			}
		}
		//����
		int age;
		cout << "����������:"<<endl;
		cin >> age;
		ab->peopreArr[ab->M_size].age= age;
		//�绰����
		string calling;
		cout << "������绰����:" << endl;
		cin >> calling;
		ab->peopreArr[ab->M_size].calling =calling;
		//סַ
		string add;
		cout << "�������û���ַ:" << endl;
		cin >> add;
		ab->peopreArr[ab->M_size].add = add;
		//ʹM-��size��ͳ������
		ab->M_size++;
		//��������
		system("pause");
		system("cls");
	}
}
void xianshi(connect* ab)
{
	int i = 0;
	if (i == ab->M_size)
	{
		cout << "ͨѶ¼���һ�δ�����" << endl;
	}
	else {
		for (; i < ab->M_size; i++)
		{
			cout << "������" << ab->peopreArr[i].name << "\t";
			cout << "�Ա�" << ab->peopreArr[i].sex << "\t";
			cout << "���䣺" << ab->peopreArr[i].age << "\t";
			cout << "�绰���룺" << ab->peopreArr[i].calling << "\t";
			cout << "��ͥסַ��" << ab->peopreArr[i].add << endl;;
		}
	}
	system("pause");
	system("cls");
}
//ɾ����ϵ��
//�����ҵ���ϵ�˲�����M-size
int isExit(connect *ab, string name)
{
	int i = 0;
	for (; i < ab->M_size; i++)
	{
		if (ab->peopreArr[i].name == name)
		{
			cout << "�ҵ�����ϵ��" << endl;
			return i;
		}
		else
		{
			cout << "�����ڸ��û�" << endl;
		}
	}
	return -1;

}
void deletepeopre(connect* ab)
{
	string name;
	cout << "����������ɾ�����û�����" << endl;
	cin >> name;
	int  r= isExit(ab, name);
	if (r!= -1)
	{
		for (; r < ab->M_size; r++)
		{
			ab->peopreArr[r] = ab->peopreArr[r + 1];
		}
		ab->M_size--;
		cout << "�ɹ�ɾ������" << endl;
	}
	else
	{
		cout << "���޴���" << endl;
	}
	system("pause");
	system("cls");
}
//������ϵ��
void findpeopre(connect *ab)
{
	string name;
	while(1)
	{
		cout << "����������Ҫ���ҵ���ϵ�ˣ����������ӣ��������˳���:" << endl;
		cin >> name;
		if (name != "�˳�")
		{
			for (int i = 0; i < ab->M_size; i++)
			{
				if (ab->peopreArr[i].name == name)
				{
					cout << "������" << ab->peopreArr[i].name << "\t";
					cout << "���䣺" << ab->peopreArr[i].age << "\t";
					cout << "�Ա�" << ab->peopreArr[i].sex << "\t";
					cout << "�绰���룺" << ab->peopreArr[i].calling << "\t";
					cout << "��ͥסַ��" << ab->peopreArr[i].add << endl;
				}
			}
		}
		else
			{
				break;
			}
	}
	system("pause");
	system("cls");
}
void xiugai(connect *ab)
{
	if (ab->M_size != 0)
	{
		string name;
		cout << "�����������޸ĵ����֣�";
		cin >> name;
		for (int i = 0; i < ab->M_size; i++)
		{
			if (ab->peopreArr[i].name == name)
			{
				cout << "�������޸�Ϊ��";
				cin >> name;
				ab->peopreArr[i].name = name;
				cout << "�޸����" << endl;
			}
			else
			{
				cout << "�Ҳ�������ϵ��" << endl;
			}
		}
	}
	else
	{
		cout << "���������ϵ�ˣ�" << endl;
	}
	system("pause");
	system("cls");
}
void qingkong(connect *ab)
{
	string name;
	cout << "��ȷ�����ͨѶ¼��" << endl;
	cin >> name;
	if (name == "ȷ��")
	{
		ab->M_size = 0;
		cout << "��ͨѶ¼�����" << endl;
	}
	system("pause");
	system("cls");
}
int main()
{

	while (true)
	{
		showmenu();
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
			addpeopre(&ab);
			break;
		case 2:
			xianshi(&ab);
			break;
		case 3:
			//���Ժ���isExit
			/*	string name;
			cout << "����������ɾ�����û�����:" << endl;
			cin >> name;
			if (isExit(&ab, name) == 0)
			{
				cout << "���޴���" << endl;
				system("pause");
				system("cls");
			}*/
			deletepeopre(&ab);
			break;
		case 4:
			findpeopre(&ab);
			break;
		case 5:
			xiugai(&ab);
			break;
		case 6:
			qingkong(&ab);
			break;
		default:
			break;
		}
	}
}