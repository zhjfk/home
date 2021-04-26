#include"manger.h"
#include"boss.h"
#include"worker.h"
#include"emp.h"
#include"workermanger.h"
#include<string>
workermanger::workermanger()
{
	//�ж��ļ��Ƿ����
		//�����ڵ������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
		if(!ifs.is_open())
		{
			/*cout << "�ļ�������" << endl;*/
			//��ʼ��Ϊ0
			this-> empnum = 0;
			this->emparr = NULL;
			this->empfile = true;
			ifs.close();
			return;
		}
		//�ļ����ڵ��ļ�Ϊ��
		char ch;
		ifs >> ch;
		if (ifs.eof())
		{
			/*cout << "�ļ�Ϊ��" << endl;*/
			//��ʼ��Ϊ0
			this-> empnum = 0;
			this->emparr = NULL;
			this->empfile = true;
			ifs.close();
			return;
		}
		//�ļ���Ϊ��
		int n = this->getnum();
		/*cout << n << endl;*/
		this->empnum = n;
		this->emparr = new worker * [this->empnum];
		this->initemp();
}
workermanger::~workermanger()
{

}
void workermanger::showmenu()
{
	cout << "**************************************************" << endl;
	cout<<  "******************��ӭʹ��ְ������ϵͳ************" << endl;
	cout << "*********************0.�˳��������***************" << endl;
	cout << "*********************1.����ְ����Ϣ***************" << endl;
	cout << "*********************2.��ʾְ����Ϣ***************" << endl;
	cout << "*********************3.ɾ����ְְ��***************" << endl;
	cout << "*********************4.�޸�ְ����Ϣ***************" << endl;
	cout << "*********************5.����ְ��ѶϢ***************" << endl;
	cout << "*********************6.���ձ������***************" << endl;
	cout << "*********************7.����ı��ĵ�***************" << endl;
	cout << "**************************************************" << endl;
}
void workermanger::exitsys()
{
	cout << "��ӭ�´�ʹ��" << endl;
	system("pause");
	exit(0);
}
void workermanger::emppeo()
{
	int addnum;
	cout << "��������Ҫ��ӵĵ�����" << endl;
	cin >> addnum;
	if (addnum > 0)
	{

			int newsize = this->empnum + addnum;
			worker** newspace = new worker * [newsize];
			if (this->emparr != NULL)
			{
				for (int i = 0; i < empnum; i++)
				{
					newspace[i] = this->emparr[i];
				}
			}
			for (int i = 0; i < addnum; i++)
			{
				int id;
				string name;
				cout << "�������" << i + 1 << "���˵�ְԱ���" << endl;
				cin >> id;
				cout << "�������" << i + 1 << "���˵�ְԱ����" << endl;
				cin >> name;
				worker* worker = NULL;
				cout << "�����벿�ű��" << endl;
				cout << "1.Ա��" << endl;
				cout << "2.����" << endl;
				cout << "3.�ϰ�" << endl;
				int sel;
				cin >> sel;
				switch (sel)
				{
				case 1:
					worker = new emp(id, name, 1);
					break;
				case 2:
					worker = new manger(id, name, 3);
					break;
				case 3:
					worker = new boss(id, name, 3);
					break;
				}
				newspace[this->empnum + i] = worker;
			}
			//�ͷ�ԭ�пռ�
			delete []this->emparr;
			//���µ�ָ�����鱣�浽emparr��
			this->emparr = newspace;
			//����������
			this->empnum = newsize;
			this->empfile = false;
			cout << "�ɹ����" << endl;
			this->save();
		}
	else
	{
		cout << "��������" << endl;
	}
	system("pause");
	system("cls");
}
void workermanger::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);
	for (int i = 0; i < this->empnum; i++)
	{
		ofs << this->emparr[i]->id << " "
			<< this->emparr[i]->name << " "
			<< this->emparr[i]->bumenid << endl;
	}
	ofs.close();
}
void workermanger::initemp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int bumenid;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> bumenid)
	{
		worker* worker = NULL;
		if (bumenid == 1)//ְԱ
			worker = new emp(id, name, bumenid);
		if (bumenid == 2)//����
			worker = new manger(id, name, bumenid);
		if (bumenid == 3)//�ϰ�
			worker = new boss(id, name, bumenid);
		this->emparr[index] = worker;
		index++;
	}
	//�ر��ļ�
	ifs.close();

}
int  workermanger::getnum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int bumenid;
	int num=0;
	while (ifs >> id && ifs >> name && ifs >> bumenid)
	{
		num++;
	}
	ifs.close();
	return num;
}
void workermanger::showemp()
{
	if (this->empfile)
	{
		cout << "�ļ������ڻ��ļ����ڵ�δ���ְ��" << endl;
	}
	else
	{
		if (this->empnum == 0)
		{
			cout << "�����ְ����Ա" << endl;
		}
		else
		{
			for (int i = 0; i < this->empnum; i++)
			{
				this->emparr[i]->showinfo();
			}
		}
		
	}
	system("pause");
	system("cls");
}
int workermanger::isexit(int id)
{
	for (int i = 0; i < this->empnum; i++)
	{
		if (this->emparr[i]->id == id)
			return i;
	}
	return -1;
}
string workermanger::isname(string name)
{
	for (int i = 0; i < this->empnum; i++)
	{
		if (this->emparr[i]->name == name)
			return name;
	}
	return "���޴���";
}
void workermanger::delemp()
{
	if (this->empfile)
	{
		cout << "�ļ������ڻ����ļ���δ�����Ա" << endl;
	}
	else
	{
		int id;
		cout << "��������ɾ����ְԱ���" << endl;
		cin >> id;
		int index=isexit(id);
		if (index == -1)
		{
			cout << "��ְԱ������" << endl;
		}
		else
		{
			delete emparr[index];
			for (int i = index; i < this->empnum - 1; i++)
			{
				this->emparr[i] = this->emparr[i + 1];
			}
			//ɾ��������ͬ��
			this->empnum--;
			//������ͬ�����ļ�����
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
		system("pause");
		system("cls");
		
	}
}
void workermanger::changeemp()
{
	int id;
	string name;
	int bumenid;
	cout << "���������޸ĵ�ְԱ���" << endl;
	cin >> id;
	int index = isexit(id);
	if (index == -1)
	{
		cout << "��ְԱ������" << endl;
	}
	else
	{
		//�ҵ�ְ��
		delete this->emparr[index];
		cout << "�ҵ���" << id << "�ŵ�ְԱ" << endl;
		cout << "�������޸ĺ��ְԱ����:" << endl;
		cin >> name;
		cout << "�������޸ĺ��ְԱ���ű��" << endl;
		cout << "1.Ա��" << endl;
		cout << "2.����" << endl;
		cout << "3.�ϰ�" << endl;
		cin >> bumenid;
		worker* worker = NULL;
		switch (bumenid)
		{
		case 1:
			worker = new emp(id, name, bumenid);
			break;
		case 2:
			worker = new manger(id, name, bumenid);
			break;
		case 3:
			worker = new boss(id, name, bumenid);
			break;
		}	
		cout << "�޸ĳɹ�" << endl;
		//���ݱ���
		this->save();
	}
	system("pause");
	system("cls");
}
void workermanger::findemp()
{
	int id;
	string name;
	int ch;
	cout << "��������Ĳ��ҷ�ʽ:" << endl;
	cout << "1.���ձ�Ų���" << endl;
	cout << "2.������������" << endl;
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		cout << "����������ҵ�ְԱ���" << endl;
		cin >> id;
		int index = isexit(id);
		if (index == -1)
		{
			cout << "��ְԱ������" << endl;
		}
		else
		{
			for (int i = 0; i < this->empnum; i++)
			{
				if (this->emparr[i]->id == id)
				{
					this->emparr[i]->showinfo();
				}
			}
		}
	}
		break;
	case 2:
	{
		cout << "������������ҵ�Ա��������:" << endl;
		cin >> name;
		string nam = isname(name);
		if(nam!="���޴���")
		{
			for (int i = 0; i < this->empnum; i++)
			{
				if (this->emparr[i]->name == name)
				{
					this->emparr[i]->showinfo();
				}
			}
		}	
		else
		{
			cout << "���޴���" << endl;
		}
	}
		break;
	}
	system("pause");
	system("cls");
}
void workermanger::maopao()
{
	if (this->empfile)
	{
		cout << "�ļ������ڻ����ļ�Ϊ��" << endl;
	}
	else
	{
		int ch;
		cout << "ְ�����򷽷�" << endl;
		cout << "1.����" << endl;
		cout << "2.����" << endl;
		cin >> ch;
		for (int i = 0; i < this->empnum - 1; i++)
		{
			for (int j = 0; j < this->empnum - i - 1; j++)
			{
				//if (this->emparr[j]->id > this->emparr[j+ 1]->id)
				//{
				//	worker* worker=NULL;
				//	 worker= this->emparr[j];
				//	 /*delete this->emparr[j+1];*/
				//	 /*this->emparr[j + 1] = NULL;*/
				//	this->emparr[j] = this->emparr[j+1];
				//	this->emparr[j+1] = worker;
				//	delete worker;
				//}
				if (ch == 1) 
				{
					if (this->emparr[j]->id > this->emparr[j + 1]->id)
					{
						int minormax = j;
						worker* temp = this->emparr[j + 1];
						this->emparr[j + 1] = this->emparr[minormax];
						this->emparr[minormax] = temp;
					}
				}
				else
				{
					if (this->emparr[j]->id < this->emparr[j + 1]->id)
					{
						int minormax = j;
							worker* temp = this->emparr[j + 1];
							this->emparr[j + 1] = this->emparr[minormax];
							this->emparr[minormax] = temp;
					}
				
				}
				

			}
		}
		cout << "�Ѿ����ձ������" << endl;
		//�����ļ�
		this->save();
	}

	for (int i = 0; i < this->empnum; i++)
	{
		this->emparr[i]->showinfo();
	}
	system("pause");
	system("cls");
}
void workermanger::cleanfile()
{
	int sel;
	cout << "ȷ������ļ���?" << endl;
	cout << "1.ȷ��" << endl;
	cout << "2.����" << endl;
	cin >> sel;
	if (sel == 1)
	{
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->emparr != NULL)
		{
			for (int i = 0; i < this->empnum; i++)
			{
				delete this->emparr[i];
				this->emparr[i] = NULL;
			}
			delete[]this->emparr;
			this->emparr = NULL;
			this->empnum = 0;
			this->empfile = true;
		}
		cout << "��ճɹ�" << endl;
		this->save();
	}
	system("pause");
	system("cls");
}