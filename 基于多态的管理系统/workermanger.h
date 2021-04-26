#pragma once
#include<iostream>
#include<fstream>
#define FILENAME "empfile.txt"
using namespace std;
#include"worker.h"
class workermanger
{
public:
	//构造函数
	workermanger();
	//显示菜单
	 void showmenu();
	 //退出系统
	 void exitsys();
	 //添加成员
	 void emppeo();

	 int empnum;
	 worker** emparr=NULL;
	 //显示职工信息
		//读写文件
		void save();
		bool empfile=false;
		void showemp();
		int getnum();
		void initemp();
	//判断职工是否存在
		int isexit(int id);
		string isname(string name);
	//删除职工
		void delemp();
	//修改员工
		void changeemp();
	//查找员工
		void findemp();
	//按照编号排序
		void maopao();
	//清空文件
		void cleanfile();
	//析构函数
	~workermanger();
};