#include"manger.h"
manger::manger(int id, string name, int bumneid)
{
	this->id = id;
	this->name = name;
	this->bumenid = bumneid;
}
void manger::showinfo()
{
	cout << "职工编号: " << this->id
		<< "\t职工姓名: " << this->name
		<< "\t部门编号: " << this->bumenid
		 << "\t岗位职责: 完成老板的任务以及监督员工" << endl;
}
string manger::getbumen()
{
	return ("经理");
}