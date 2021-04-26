#include"boss.h"
boss::boss(int id, string name, int bumneid)
{
	this->id = id;
	this->name = name;
	this->bumenid = bumneid;
}
void boss::showinfo()
{
	cout << "职工编号: " << this->id
		<< "\t职工姓名: " << this->name
		<< "\t部门编号: " << this->bumenid
		<< "\t岗位职责: 下达任务" << endl;
}
string boss::getbumen()
{
	return ("老板");
}