#include "Aktualizer.h"
#include <stdio.h>
#include <conio.h>
#include <string>
#include <iostream>
#include <fstream>
#include "PPlansza.h"


Aktualizer::Aktualizer()
{
}


Aktualizer::~Aktualizer()
{
}


int Aktualizer::zapis_stanu(int **tab)
{
	int **buf = tab;
	int do_zapisu[8][8];

	int i, j;

	for (i = 0; i < 8; i++)
	{
		for (j = 0; j < 8; j++)
		{
			do_zapisu[i][j] = buf[i][j];
		}
	}
	fstream file("zapis.txt", ios::out);

	if (file.good() == false)
	{
		cout << "Nie mozna otworzyc pliku!\n" << endl;
		return 0;
	}
	else
	{
		for (i = 0; i < 8; i++)
		{
			for (j = 0; j < 8; j++)
			{
				file << do_zapisu[i][j] << ";";
			}
			file << "\n";
		};
	}

	file.close();
	cout << "Plik zostal zapisany jako \'zapis.txt\'\n";
	system("pause");
}

int** Aktualizer::odczyt_stanu()
{
	int i, j, k;
	int z_zapisu;

	char linijka[128]; // tutaj bedzie zapisywana kazda linijka pokolei z pliku
	int liczba = 0;

	int** tab;
	tab = new int*[8]; //przydzielenie pamiêci na w wierszy
	for (int i = 0; i < 8; i++)
		tab[i] = new int[8]; //przydzielenie dla ka¿dego wiersza po k komórek

	fstream file("zapis.txt", ios::in);

	if (file.good() == false)
	{
		cout << "Nie mozna otworzyc pliku!." << endl;
		return 0;
	}
	else
	{
		for (i = 0; i < 8; i++)
		{
			k = 0;
			file >> linijka;
			for (j = 0; j < 15;)
			{
				liczba = linijka[j] - 48; // - 48 bo w char 1 to 49 wiec zeby uzyskac 1 w int to trzeba odjac 48
				tab[i][k] = liczba; // k a nie j bo j jest iterowane co 2
				j = j + 2;
				k++;
			}
		}
	}

	file.close();

	for (i = 0; i < 128; i++)
		linijka[i] = NULL;

	return tab;
}