#include"boss.h"
boss::boss(int id, string name, int bumneid)
{
	this->id = id;
	this->name = name;
	this->bumenid = bumneid;
}
void boss::showinfo()
{
	cout << "ְ�����: " << this->id
		<< "\tְ������: " << this->name
		<< "\t���ű��: " << this->bumenid
		<< "\t��λְ��: �´�����" << endl;
}
string boss::getbumen()
{
	return ("�ϰ�");
}