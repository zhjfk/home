#include"emp.h"
emp::emp(int id, string name, int bumneid)
{
	this->id = id;
	this->name = name;
	this->bumenid = bumneid;
}
void emp::showinfo()
{
	cout << "ְ�����: " << this->id
		<< "\tְ������: " << this->name
		<< "\t���ű��: " << this->bumenid
		<< "\t��λְ��: ��ɾ����´������" << endl;
}
string emp::getbumen()
{
	return ("Ա��");
}