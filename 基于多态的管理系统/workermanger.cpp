#include"manger.h"
#include"boss.h"
#include"worker.h"
#include"emp.h"
#include"workermanger.h"
#include<string>
workermanger::workermanger()
{
	//判断文件是否存在
		//不存在的情况下
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
		if(!ifs.is_open())
		{
			/*cout << "文件不存在" << endl;*/
			//初始化为0
			this-> empnum = 0;
			this->emparr = NULL;
			this->empfile = true;
			ifs.close();
			return;
		}
		//文件存在但文件为空
		char ch;
		ifs >> ch;
		if (ifs.eof())
		{
			/*cout << "文件为空" << endl;*/
			//初始化为0
			this-> empnum = 0;
			this->emparr = NULL;
			this->empfile = true;
			ifs.close();
			return;
		}
		//文件不为空
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
	cout<<  "******************欢迎使用职工管理系统************" << endl;
	cout << "*********************0.退出管理程序***************" << endl;
	cout << "*********************1.增加职工信息***************" << endl;
	cout << "*********************2.显示职工信息***************" << endl;
	cout << "*********************3.删除离职职工***************" << endl;
	cout << "*********************4.修改职工信息***************" << endl;
	cout << "*********************5.查找职工讯息***************" << endl;
	cout << "*********************6.按照编号排序***************" << endl;
	cout << "*********************7.清空文本文档***************" << endl;
	cout << "**************************************************" << endl;
}
void workermanger::exitsys()
{
	cout << "欢迎下次使用" << endl;
	system("pause");
	exit(0);
}
void workermanger::emppeo()
{
	int addnum;
	cout << "请输入你要添加的的人数" << endl;
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
				cout << "请输入第" << i + 1 << "个人的职员编号" << endl;
				cin >> id;
				cout << "请输入第" << i + 1 << "个人的职员姓名" << endl;
				cin >> name;
				worker* worker = NULL;
				cout << "请输入部门编号" << endl;
				cout << "1.员工" << endl;
				cout << "2.经理" << endl;
				cout << "3.老板" << endl;
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
			//释放原有空间
			delete []this->emparr;
			//将新的指针数组保存到emparr中
			this->emparr = newspace;
			//将人数更新
			this->empnum = newsize;
			this->empfile = false;
			cout << "成功添加" << endl;
			this->save();
		}
	else
	{
		cout << "输入有误" << endl;
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
		if (bumenid == 1)//职员
			worker = new emp(id, name, bumenid);
		if (bumenid == 2)//经理
			worker = new manger(id, name, bumenid);
		if (bumenid == 3)//老板
			worker = new boss(id, name, bumenid);
		this->emparr[index] = worker;
		index++;
	}
	//关闭文件
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
		cout << "文件不存在或文件存在但未添加职工" << endl;
	}
	else
	{
		if (this->empnum == 0)
		{
			cout << "请添加职工人员" << endl;
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
	return "查无此人";
}
void workermanger::delemp()
{
	if (this->empfile)
	{
		cout << "文件不存在或者文件尚未添加人员" << endl;
	}
	else
	{
		int id;
		cout << "输入你想删除的职员编号" << endl;
		cin >> id;
		int index=isexit(id);
		if (index == -1)
		{
			cout << "该职员不存在" << endl;
		}
		else
		{
			delete emparr[index];
			for (int i = index; i < this->empnum - 1; i++)
			{
				this->emparr[i] = this->emparr[i + 1];
			}
			//删除后人数同步
			this->empnum--;
			//将数据同步到文件夹中
			this->save();
			cout << "删除成功" << endl;
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
	cout << "输入你想修改的职员编号" << endl;
	cin >> id;
	int index = isexit(id);
	if (index == -1)
	{
		cout << "该职员不存在" << endl;
	}
	else
	{
		//找到职工
		delete this->emparr[index];
		cout << "找到了" << id << "号的职员" << endl;
		cout << "请输入修改后的职员姓名:" << endl;
		cin >> name;
		cout << "请输入修改后的职员部门编号" << endl;
		cout << "1.员工" << endl;
		cout << "2.经理" << endl;
		cout << "3.老板" << endl;
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
		cout << "修改成功" << endl;
		//数据保存
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
	cout << "请输入你的查找方式:" << endl;
	cout << "1.按照编号查找" << endl;
	cout << "2.按照姓名查找" << endl;
	cin >> ch;
	switch (ch)
	{
	case 1:
	{
		cout << "输入你想查找的职员编号" << endl;
		cin >> id;
		int index = isexit(id);
		if (index == -1)
		{
			cout << "该职员不存在" << endl;
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
		cout << "请输入你想查找的员工的姓名:" << endl;
		cin >> name;
		string nam = isname(name);
		if(nam!="查无此人")
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
			cout << "查无此人" << endl;
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
		cout << "文件不存在或者文件为空" << endl;
	}
	else
	{
		int ch;
		cout << "职工排序方法" << endl;
		cout << "1.升序" << endl;
		cout << "2.降序" << endl;
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
		cout << "已经按照编号排序" << endl;
		//保存文件
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
	cout << "确定清空文件吗?" << endl;
	cout << "1.确定" << endl;
	cout << "2.返回" << endl;
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
		cout << "清空成功" << endl;
		this->save();
	}
	system("pause");
	system("cls");
}