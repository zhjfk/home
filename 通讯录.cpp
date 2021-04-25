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
	cout <<"************************1.请添加联系人****************************" << endl;
	cout <<"************************2.显示联系人   ***************************" << endl;
	cout <<"************************3.删除联系人   ***************************" << endl;
	cout <<"************************4.查找联系人   ***************************" << endl;
	cout <<"************************5.修改联系人   ***************************" << endl;
	cout <<"************************6.清空联系人   ***************************" << endl;
	cout <<"------------------------------------------------------------------" << endl;
}
void addpeopre(connect* ab ) 
{
	if (ab->M_size == Max)
	{
		cout << "通讯录已满，无法添加人" << endl;
	}
	else {
		//添加姓名
		string name;
		cout << "姓名:" << endl;
		cin >> name;
		ab->peopreArr[ab->M_size].name = name;
		//性别
		cout << "请输入性别:" << endl;
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
				cout << "输入错误，请重新输入" << endl;
			}
		}
		//年龄
		int age;
		cout << "请输入年龄:"<<endl;
		cin >> age;
		ab->peopreArr[ab->M_size].age= age;
		//电话号码
		string calling;
		cout << "请输入电话号码:" << endl;
		cin >> calling;
		ab->peopreArr[ab->M_size].calling =calling;
		//住址
		string add;
		cout << "请输入用户地址:" << endl;
		cin >> add;
		ab->peopreArr[ab->M_size].add = add;
		//使M-》size来统计人数
		ab->M_size++;
		//清屏处理
		system("pause");
		system("cls");
	}
}
void xianshi(connect* ab)
{
	int i = 0;
	if (i == ab->M_size)
	{
		cout << "通讯录尚且还未添加人" << endl;
	}
	else {
		for (; i < ab->M_size; i++)
		{
			cout << "姓名：" << ab->peopreArr[i].name << "\t";
			cout << "性别：" << ab->peopreArr[i].sex << "\t";
			cout << "年龄：" << ab->peopreArr[i].age << "\t";
			cout << "电话号码：" << ab->peopreArr[i].calling << "\t";
			cout << "家庭住址：" << ab->peopreArr[i].add << endl;;
		}
	}
	system("pause");
	system("cls");
}
//删除联系人
//首先找到联系人并返回M-size
int isExit(connect *ab, string name)
{
	int i = 0;
	for (; i < ab->M_size; i++)
	{
		if (ab->peopreArr[i].name == name)
		{
			cout << "找到了联系人" << endl;
			return i;
		}
		else
		{
			cout << "不存在该用户" << endl;
		}
	}
	return -1;

}
void deletepeopre(connect* ab)
{
	string name;
	cout << "请输入你想删除的用户名：" << endl;
	cin >> name;
	int  r= isExit(ab, name);
	if (r!= -1)
	{
		for (; r < ab->M_size; r++)
		{
			ab->peopreArr[r] = ab->peopreArr[r + 1];
		}
		ab->M_size--;
		cout << "成功删除此人" << endl;
	}
	else
	{
		cout << "查无此人" << endl;
	}
	system("pause");
	system("cls");
}
//查找联系人
void findpeopre(connect *ab)
{
	string name;
	while(1)
	{
		cout << "请输入你想要查找的联系人（如果不想添加，请输入退出）:" << endl;
		cin >> name;
		if (name != "退出")
		{
			for (int i = 0; i < ab->M_size; i++)
			{
				if (ab->peopreArr[i].name == name)
				{
					cout << "姓名：" << ab->peopreArr[i].name << "\t";
					cout << "年龄：" << ab->peopreArr[i].age << "\t";
					cout << "性别：" << ab->peopreArr[i].sex << "\t";
					cout << "电话号码：" << ab->peopreArr[i].calling << "\t";
					cout << "家庭住址：" << ab->peopreArr[i].add << endl;
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
		cout << "请输入你想修改的名字：";
		cin >> name;
		for (int i = 0; i < ab->M_size; i++)
		{
			if (ab->peopreArr[i].name == name)
			{
				cout << "将名字修改为：";
				cin >> name;
				ab->peopreArr[i].name = name;
				cout << "修改完成" << endl;
			}
			else
			{
				cout << "找不到该联系人" << endl;
			}
		}
	}
	else
	{
		cout << "请先添加联系人！" << endl;
	}
	system("pause");
	system("cls");
}
void qingkong(connect *ab)
{
	string name;
	cout << "你确定清空通讯录吗？" << endl;
	cin >> name;
	if (name == "确定")
	{
		ab->M_size = 0;
		cout << "该通讯录已清空" << endl;
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
			//测试函数isExit
			/*	string name;
			cout << "请输入你想删除的用户名字:" << endl;
			cin >> name;
			if (isExit(&ab, name) == 0)
			{
				cout << "查无此人" << endl;
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