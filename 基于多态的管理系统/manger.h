#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
class manger :public worker
{
public:
	manger(int id, string name, int bumneid);
	virtual void showinfo();
	virtual string  getbumen();
};