#pragma once
#include <iostream>
using namespace std;

class PPlansza
{
	friend class Aktualizer;
	int TablicaPionkow[8][8];
public:
	PPlansza();
	~PPlansza();
	char WartSymbol(int);
	void DrukujPPlansze();
	int DajWartosc(int, int);
	void ZmienWartosc(int, int, int);
};

