#include "PPlansza.h"
#include <windows.h>


PPlansza::PPlansza()
{
	int k = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int gracz = 0; //do struktury ewentualnej
			int wartosc = 0;
			if (((i % 2) == 0 && (j % 2) == 0) || ((i % 2) == 1 && (j % 2) == 1))
			{
				gracz = 0;
				wartosc = 0;
			}
			if (((i == 0) && (j % 2) == 1) || ((i == 1) && (j % 2) == 0) || ((i == 2) && (j % 2) == 1))
			{
				gracz = 1;
				wartosc = 2;
			}
			if (((i == 5) && (j % 2) == 0) || ((i == 6) && (j % 2) == 1) || ((i == 7) && (j % 2) == 0))
			{
				gracz = 2;
				wartosc = 3;
			}
			if (((i == 3) && (j % 2) == 0) || ((i == 4) && (j % 2) == 1))
			{
				gracz = 0;
				wartosc = 1;
			}
			TablicaPionkow[i][j] = wartosc;
		}
	}
}


PPlansza::~PPlansza()
{
}


char PPlansza::WartSymbol(int i)
{
	HANDLE hConsole = GetStdHandle(STD_ERROR_HANDLE);
	SetConsoleTextAttribute(hConsole, 7);

	switch (i)
	{
	case 0:
		return ' ';
	case 1:
		return 250;
	case 2:
		SetConsoleTextAttribute(hConsole, 12); // czerwony
		return 254;
	case 3:
		SetConsoleTextAttribute(hConsole, 9); // niebieski
		return 254;
	case 4:
		SetConsoleTextAttribute(hConsole, 12);
		return 219;
		//return 'd';
	case 5:
		SetConsoleTextAttribute(hConsole, 9);
		return 219;
		//return 'D';
	}
	return ('?');
}

void PPlansza::DrukujPPlansze()
{
	int i, j, pp;

	printf("  +---+---+---+---+---+---+---+---+\n");
	HANDLE hConsole = GetStdHandle(STD_ERROR_HANDLE);

	for (i = 0; i < 8; ++i)
	{
		cout << i + 1 << " |";
		//printf("%d |", i + 1);
		for (j = 0; j < 8; ++j)
		{
			//cout <<" "<< TablicaPionkow[i][j] <<" |";

			cout << " " << WartSymbol(TablicaPionkow[i][j]);
			SetConsoleTextAttribute(hConsole, 7);
			cout << " |";
			/*printf(" %c |", wart_symbol(d[rr][cc]));*/
		}
		printf("\n");
		printf("  +---+---+---+---+---+---+---+---+\n");
	}

	printf("    a   b   c   d   e   f   g   h\n\n");
	printf("W celu zakonczenia gry, wybierajac pionka wpisz \"0f\"\n\n");
}

int PPlansza::DajWartosc(int i, int j)
{
	return TablicaPionkow[i][j];
}

void PPlansza::ZmienWartosc(int i, int j, int wartosc)
{
	TablicaPionkow[i][j] = wartosc;
}


/*#include "PPlansza.h"



PPlansza::PPlansza()
{
	int k = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			int gracz = 0; //do struktury ewentualnej
			int wartosc = 0;
			if (((i % 2) == 0 && (j % 2) == 0) || ((i % 2) == 1 && (j % 2) == 1))
			{
				gracz = 0;
				wartosc = 0;
			}
			if (((i == 0) && (j % 2) == 1) || ((i == 1) && (j % 2) == 0) || ((i == 2) && (j % 2) == 1))
			{
				gracz = 1;
				wartosc = 2;
			}
			if (((i == 5) && (j % 2) == 0) || ((i == 6) && (j % 2) == 1) || ((i == 7) && (j % 2) == 0))
			{
				gracz = 2;
				wartosc = 3;
			}
			if (((i == 3) && (j % 2) == 0) || ((i == 4) && (j % 2) == 1))
			{
				gracz = 0;
				wartosc = 1;
			}
			TablicaPionkow[i][j] = wartosc;
		}
	}
}


PPlansza::~PPlansza()
{
}


char PPlansza::WartSymbol(int i)
{
	switch (i)
	{
	case 0:
		return ' ';
	case 1:
		return 250;
	case 2:
		return 254;
	case 3:
		return 219;
	case 4:
		return 'd';
	case 5:
		return 'D';
	}
	return ('?');
}

void PPlansza::DrukujPPlansze() 
{
	int i, j, pp;

	printf("  +---+---+---+---+---+---+---+---+\n");

	for (i = 0; i < 8; ++i)
	{
		cout << i + 1 << " |";
		//printf("%d |", i + 1);
		for (j = 0; j < 8; ++j)
		{
			//cout <<" "<< TablicaPionkow[i][j] <<" |";
			cout << " " << WartSymbol(TablicaPionkow[i][j]) << " |";
		}
		printf("\n");
		printf("  +---+---+---+---+---+---+---+---+\n");
	}

	printf("    a   b   c   d   e   f   g   h\n\n");
	printf("W celu zakonczenia gry, wybierajac pionka wpisz \"0f\"\n\n");
}

int PPlansza :: DajWartosc(int i, int j) 
{ 
	return TablicaPionkow[i][j];
}

void PPlansza::ZmienWartosc(int i, int j, int wartosc)
{
	TablicaPionkow[i][j] = wartosc;
}*/