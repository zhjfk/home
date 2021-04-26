#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
class boss :public worker
{
public:
	boss(int id, string name, int bumneid);
	virtual void showinfo();
	virtual string  getbumen();
};