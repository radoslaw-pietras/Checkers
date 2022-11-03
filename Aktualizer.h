#pragma once
#include "PPlansza.h"

class PPlansza;
class Aktualizer

{
public:

	Aktualizer();
	~Aktualizer();


	int zapis_stanu(int **tab);
	int** odczyt_stanu();
};
