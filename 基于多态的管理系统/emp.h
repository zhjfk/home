#pragma once
#include<iostream>
using namespace std;
#include"worker.h"
class emp:public worker
{
public:
	emp(int id,string name,int bumneid);
	virtual void showinfo();
	virtual string  getbumen();
};