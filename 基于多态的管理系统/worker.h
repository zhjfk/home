#pragma once
#include<iostream>
using namespace std;
#include"string"
class worker
{
public:
	//��ʾ��Ϣ
	virtual void showinfo()=0;
	//��ʾ����
	virtual string getbumen() = 0;
	//ְԱ��ţ����������ű�ţ�
	int id;
	string name;
	int bumenid;
};