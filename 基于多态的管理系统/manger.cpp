#include"manger.h"
manger::manger(int id, string name, int bumneid)
{
	this->id = id;
	this->name = name;
	this->bumenid = bumneid;
}
void manger::showinfo()
{
	cout << "ְ�����: " << this->id
		<< "\tְ������: " << this->name
		<< "\t���ű��: " << this->bumenid
		 << "\t��λְ��: ����ϰ�������Լ��ලԱ��" << endl;
}
string manger::getbumen()
{
	return ("����");
}