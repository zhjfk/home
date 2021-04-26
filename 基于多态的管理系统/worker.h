#pragma once
#include<iostream>
using namespace std;
#include"string"
class worker
{
public:
	//显示信息
	virtual void showinfo()=0;
	//显示部门
	virtual string getbumen() = 0;
	//职员编号，姓名，部门编号；
	int id;
	string name;
	int bumenid;
};