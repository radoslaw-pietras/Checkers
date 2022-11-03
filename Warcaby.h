#pragma once
#include "PPlansza.h"
#include "Gracz.h"


class Warcaby
	:public PPlansza
{
	int flaga1, flaga2;
public:
	Warcaby();
	~Warcaby();
	int czyPrzymusBicia(int, int player, int i, int j, int k, int l);
	int czyDodatkoweBicie(int, int player, int k, int l, int pionek_damy);
	void swapIJKL(int, int i, int j, int k, int l);
	int RuchGracza(int, int player, int i, int j, int k, int l);
	void gra();
};

