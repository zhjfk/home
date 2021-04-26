#include"emp.h"
emp::emp(int id, string name, int bumneid)
{
	this->id = id;
	this->name = name;
	this->bumenid = bumneid;
}
void emp::showinfo()
{
	cout << "职工编号: " << this->id
		<< "\t职工姓名: " << this->name
		<< "\t部门编号: " << this->bumenid
		<< "\t岗位职责: 完成经理下达的任务" << endl;
}
string emp::getbumen()
{
	return ("员工");
}