#pragma once
#include<iostream>
#include<fstream>
#define FILENAME "empfile.txt"
using namespace std;
#include"worker.h"
class workermanger
{
public:
	//���캯��
	workermanger();
	//��ʾ�˵�
	 void showmenu();
	 //�˳�ϵͳ
	 void exitsys();
	 //��ӳ�Ա
	 void emppeo();

	 int empnum;
	 worker** emparr=NULL;
	 //��ʾְ����Ϣ
		//��д�ļ�
		void save();
		bool empfile=false;
		void showemp();
		int getnum();
		void initemp();
	//�ж�ְ���Ƿ����
		int isexit(int id);
		string isname(string name);
	//ɾ��ְ��
		void delemp();
	//�޸�Ա��
		void changeemp();
	//����Ա��
		void findemp();
	//���ձ������
		void maopao();
	//����ļ�
		void cleanfile();
	//��������
	~workermanger();
};