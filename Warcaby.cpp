#include "Warcaby.h"
#include "Aktualizer.h"
#include <set>

#define ROWS 8
#define COLS 8

#define EMPTY 1
#define RED 2 //strukturka na liczbe pionkow kompa, ktory ogarniemy
#define BLACK 3 //do strukturki na liczbe pionkow gracza
#define REDQUEEN 4
#define BLACKQUEEN 5


#define ISRED(c)  (c == RED || c == REDQUEEN)
#define ISBLACK(c) (c == BLACK || c == BLACKQUEEN))
#define ISEMPTY(c) (c == 1)

Warcaby::Warcaby()
{
	flaga1 = 0, flaga2 = 0;
	//PPlansza Plansza1;
	Gracz Gracz1(1, 'a', 1, 'a');
	Gracz Gracz2(8, 'h', 8, 'h');
}


Warcaby::~Warcaby()
{
}


int Warcaby::czyPrzymusBicia(int, int player, int i, int j, int k, int l)
{
	if (player == BLACK)
	{
		if (DajWartosc(i + 2, j + 2) == EMPTY && DajWartosc(i + 1, j + 1) == RED)
		{
			if (i + 2 != k || j + 2 != l)
			{
				cout << "Wykonaj bicie!"; return 0;
			}
			else { return -1; }
		}
		if (DajWartosc(i - 2, j - 2) == EMPTY && DajWartosc(i - 1, j - 1) == RED)
		{
			if (i - 2 != k || j - 2 != l)
			{
				cout << "Wykonaj bicie!"; return 0;
			}
			else { return -1; }
		}
		if (DajWartosc(i - 2, j + 2) == EMPTY && DajWartosc(i - 1, j + 1) == RED)
		{
			if (i - 2 != k || j + 2 != l)
			{
				cout << "Wykonaj bicie!"; return 0;
			}
			else { return -1; }
		}
		if (DajWartosc(i + 2, j - 2) == EMPTY && DajWartosc(i + 1, j - 1) == RED)
		{
			if (i + 2 != k || j - 2 != l)
			{
				cout << "Wykonaj bicie!"; return 0;
			}
			else { return -1; }
		}
	}
	if (player == RED)
	{
		if (DajWartosc(i + 2, j + 2) == EMPTY && DajWartosc(i + 1, j + 1) == BLACK)
		{
			if (i + 2 != k || j + 2 != l)
			{
				cout << "Wykonaj bicie!"; return 0;
			}
			else { return -1; }
		}
		if (DajWartosc(i - 2, j - 2) == EMPTY && DajWartosc(i - 1, j - 1) == BLACK)
		{
			if (i - 2 != k || j - 2 != l)
			{
				cout << "Wykonaj bicie!"; return 0;
			}
			else { return -1; }
		}
		if (DajWartosc(i - 2, j + 2) == EMPTY && DajWartosc(i - 1, j + 1) == BLACK)
		{
			if (i - 2 != k || j + 2 != l)
			{
				cout << "Wykonaj bicie!"; return 0;
			}
			else { return -1; }
		}
		if (DajWartosc(i + 2, j - 2) == EMPTY && DajWartosc(i + 1, j - 1) == BLACK)
		{
			if (i + 2 != k || j - 2 != l)
			{
				cout << "Wykonaj bicie!"; return 0;
			}
			else { return -1; }
		}
	}
	return -1;
}

int Warcaby::czyDodatkoweBicie(int, int player, int k, int l, int pionek_damy)
{
	int decyzja;
	if (player == BLACK && ((DajWartosc(k + 2, l + 2) == EMPTY && DajWartosc(k + 1, l + 1) == RED) || (DajWartosc(k - 2, l - 2) == EMPTY && DajWartosc(k - 1, l - 1) == RED) || (DajWartosc(k - 2, l + 2) == EMPTY && DajWartosc(k - 1, l + 1) == RED) || (DajWartosc(k + 2, l - 2) == EMPTY && DajWartosc(k + 1, l - 1) == RED)))
	{
		cout << "Chcesz wykonac jeszcze 1 ruch?\n1 : TAK\n2 : NIE\n";
		cin >> decyzja;
		while (cin.fail() || decyzja < 1 || decyzja > 2)
		{
			char c;
			cin.ignore();
			cin.clear();
			//fflush(stdin);
			while ((c = getchar()) != '\n');
			cout << "Podaj poprawna liczbe: " << endl;
			cin >> decyzja;
		}
		if (decyzja == 1)
			return 0;
		else { return -1; }
	}
	if (player == RED && ((DajWartosc(k + 2, l + 2) == EMPTY && DajWartosc(k + 1, l + 1) == BLACK) || (DajWartosc(k - 2, l - 2) == EMPTY && DajWartosc(k - 1, l - 1) == BLACK) || (DajWartosc(k - 2, l + 2) == EMPTY && DajWartosc(k - 1, l + 1) == BLACK) || (DajWartosc(k + 2, l - 2) == EMPTY && DajWartosc(k + 1, l - 1) == BLACK)))
	{
		cout << "Chcesz wykonac jeszcze 1 ruch?\n1 : TAK\n2 : NIE\n";
		cin >> decyzja;
		while (cin.fail() || decyzja < 1 || decyzja > 2)
		{
			char c;
			cin.ignore();
			cin.clear();
			while ((c = getchar()) != '\n');
			cout << "Podaj poprawna liczbe: " << endl;
			cin >> decyzja;
		}
		if (decyzja == 1)
			return 0;
		else { return -1; }
	}
	return -1;
}

void Warcaby::swapIJKL(int, int i, int j, int k, int l)
{
	int temp;
	printf("Ruch: %d,%d to %d,%d\n", i, j, k, l);

	temp = DajWartosc(i, j);
	ZmienWartosc(i, j, DajWartosc(k, l));
	ZmienWartosc(k, l, temp);
}

int Warcaby::RuchGracza(int, int player, int i, int j, int k, int l)
{
	int jmp_r;
	int jmp_c;

	if (player == RED)
	{
		printf("Gracz 1. zmienil pozycje %d,%d na %d,%d\n", i, j, k, l);
	}
	else
	{
		printf("Gracz 2. zmienil pozycje %d,%d na %d,%d\n", i, j, k, l);
	}

	if (i < 0 && ROWS <= i)
	{
		printf("Pozycja poza plansza gry \nNiepoprawny ruch, sprobuj ponownie!\n");
		return -1;
	}
	if (j < 0 && COLS <= j)
	{
		printf("Pozycja poza plansza gry \nNiepoprawny ruch, sprobuj ponownie!\n");
		return -1;
	}

	if (k < 0 && ROWS <= k)
	{
		printf("Pozycja poza plansza gry \nNiepoprawny ruch, sprobuj ponownie!\n");
		return -1;
	}
	if (l < 0 && COLS <= l)
	{
		printf("Pozycja poza plansza gry \nNiepoprawny ruch, sprobuj ponownie!\n");
		return -1;
	}

	if (player == RED)
	{
		if (DajWartosc(i, j) != RED && DajWartosc(i, j) != REDQUEEN)
		{
			printf("Ruszaj swoje pionki! \nNiepoprawny ruch, sprobuj ponownie!\n");
			return -1;
		}
	}
	else
	{
		if (DajWartosc(i, j) != BLACK && DajWartosc(i, j) != BLACKQUEEN)
		{
			printf("Ruszaj swoje pionki! \nNiepoprawny ruch, sprobuj ponownie!\n");
			return -1;
		}
	}

	if (DajWartosc(k, l) != EMPTY)
	{
		printf("Mozesz wybierac tylko puste pozycje! \nNiepoprawny ruch, sprobuj ponownie!\n");
		return -1;
	}
	//komenda na damki
	if (DajWartosc(i, j) == REDQUEEN)
	{
		int inkrement[14] = { 1,2,3,4,5,6,7,-1,-2,-3,-4,-5,-6,-7 };
		int inkX, inkY;
		std::set < int > zbior;

		for (int i = 0; i < 14; ++i)		// lub wszystkie naraz (para iteratorów) zbior.insert(dane, dane + 10);
		{
			zbior.insert(inkrement[i]);
		}
		inkY = k - i;
		inkX = l - j;
		if (zbior.find(inkX) == zbior.end() || zbior.find(inkY) == zbior.end()) //inkrement powyzej 7 daje pozycje poza plansza, w sumie niepotrzebne, bo wczesniej sprawdzane
		{
			cout << "Pozycja poza plansza. Niepoprawny ruch, sprobuj ponownie!" << endl;
			return -1;
		}
		else if(inkX != inkY && inkX != -inkY)
		{
			cout << "Mozesz poruszac sie wylacznie po skosie. Niepoprawny ruch, sprobuj ponownie!" << endl;
			return -1;
		}
		else
		{
			if (inkY > 0 && inkX > 0)
			{
				for (int ii = 1; ii < inkX; ii++) //kwestia inkrementacji gdzie czasami trzeba dekrementowac w zaleznosci od znaku inkY oraz inkX
				{
					if (DajWartosc(i + ii, j + ii) == EMPTY)
					{
						;
					}
					else if (DajWartosc(i + ii, j + ii) == BLACK || DajWartosc(i + ii, j + ii) == BLACKQUEEN)
					{
						// musi byc for sprawdzajacy co za
						for (int iidod = ii + 1; iidod < inkX; iidod++)
						{
							if (DajWartosc(i + iidod, j + iidod) == (BLACK || BLACKQUEEN || RED || REDQUEEN))
							{
								cout << "Nie mozesz przeskakiwac nad 2 figurami na raz!" << endl << "Niepoprawny ruch, sprobuj ponownie!" << endl;
								return -1;
							}
						}
						DajWartosc(i + ii, j + ii);
						system("PAUSE");
						ZmienWartosc(i + ii, j + ii, 1); //nie zmienia wartosci zbitego pionka (swapuje, ale nie podaje wartosci)
						break;
					}
					else
					{
						cout << "Niepoprawny ruch, sprobuj ponownie!" << endl;
						return -1;
					}
				}
			}
			else if(inkY>0 && inkX<0)
			{
				int ii = 1; // za ruch po Y
				int jj = -1;
				while ( ii < inkY && jj > inkX) //kwestia inkrementacji gdzie czasami trzeba dekrementowac w zaleznosci od znaku inkY oraz inkX
				{
					if (DajWartosc(i + ii, j + jj) == EMPTY)
					{
						;
					}
					else if (DajWartosc(i + ii, j + jj) == BLACK || DajWartosc(i + ii, j + jj) == BLACKQUEEN)
					{
						int iidod = ii + 1;
						int jjdod = jj - 1;		
						while ( iidod < inkY && jjdod > inkX)	// musi byc while sprawdzajacy co za
						{
							if (DajWartosc(i + iidod, j + jjdod) == (BLACK || BLACKQUEEN || RED || REDQUEEN))
							{
								cout << "Nie mozesz przeskakiwac nad 2 figurami na raz!" << endl << "Niepoprawny ruch, sprobuj ponownie!" << endl;
								return -1;
							}
							iidod++;
							jjdod--;
						}
						cout<<DajWartosc(i + iidod, j + jjdod);
						system("PAUSE");
						ZmienWartosc(i + ii, j + jj, 1); //nie zmienia wartosci zbitego pionka (swapuje, ale nie podaje wartosci)
						break;
					}
					else
					{
						cout << "Niepoprawny ruch, sprobuj ponownie!" << endl;
						return -1;
					}
					ii++;
					jj--;
				}
			}
			else if (inkY<0 && inkX>0) //zbi³a pierwszego pionka, drugiego zostawi³a i ustawi³a siê za drugim
			{
				int ii = -1; //za ruch po Y
				int jj = 1;
				while ( ii > inkY && jj < inkX) //kwestia inkrementacji gdzie czasami trzeba dekrementowac w zaleznosci od znaku inkY oraz inkX
				{
					if (DajWartosc(i + ii, j + jj) == EMPTY)
					{
						;
					}
					else if (DajWartosc(i + ii, j + jj) == BLACK || DajWartosc(i + ii, j + jj) == BLACKQUEEN)
					{
						int iidod = ii - 1;		
						int jjdod = jj + 1;	
						while (iidod > inkY && jjdod < inkX)	// musi byc while sprawdzajacy co za
						{
							if (DajWartosc(i + iidod, j + jjdod) == (BLACK || BLACKQUEEN || RED || REDQUEEN))
							{
								cout << "Nie mozesz przeskakiwac nad 2 figurami na raz!" << endl << "Niepoprawny ruch, sprobuj ponownie!" << endl;
								return -1;
							}
							iidod--;
							jjdod++;
						}
						DajWartosc(i + ii, j + jj);
						system("PAUSE");
						ZmienWartosc(i + ii, j + jj, 1); //nie zmienia wartosci zbitego pionka (swapuje, ale nie podaje wartosci)
						break;
					}
					else
					{
						cout << "Niepoprawny ruch, sprobuj ponownie!" << endl;
						return -1;
					}
					ii--;
					jj++;
				}
			}
			else //gdy inkY oraz inkX ujemne
			{
				for (int ii = -1; ii > inkX; ii--) //kwestia inkrementacji gdzie czasami trzeba dekrementowac w zaleznosci od znaku inkY oraz inkX
				{
					if (DajWartosc(i + ii, j + ii) == EMPTY)
					{
						;
					}
					else if (DajWartosc(i + ii, j + ii) == BLACK || DajWartosc(i + ii, j + ii) == BLACKQUEEN)
					{
						// musi byc for sprawdzajacy co za
						for (int iidod = ii - 1; iidod > inkX; iidod--)
						{
							if (DajWartosc(i + iidod, j + iidod) == (BLACK || BLACKQUEEN || RED || REDQUEEN))
							{
								cout << "Nie mozesz przeskakiwac nad 2 figurami na raz!" << endl << "Niepoprawny ruch, sprobuj ponownie!" << endl;
								return -1;
							}
						}
						DajWartosc(i + ii, j + ii);
						system("PAUSE");
						ZmienWartosc(i + ii, j + ii, 1); //nie zmienia wartosci zbitego pionka (swapuje, ale nie podaje wartosci)
						break;
					}
					else
					{
						cout << "Niepoprawny ruch, sprobuj ponownie!" << endl;
						return -1;
					}
				}
			}
			swapIJKL(DajWartosc(i, j), i, j, k, l);
			return 0;
		}
		
		/*for (int i = 1; i < 8; i++)
		{
			;
		}*/
	}
	//przymus bicia
	if (i - k == -1 || i - k == 1)
	{
		if (j - l == 1 || j - l == -1)
		{
			if (player == RED)
			{
				if (i >= k)
				{
					printf("Gracz 1. musi poruszac sie w dol! \nNiepoprawny ruch, sprobuj ponownie!\n");
					return -1;
				}
			}
			else if (player != RED)
			{
				if (i <= k)
				{
					printf("Gracz 2. musi poruszac sie do gory! \nNiepoprawny ruch, sprobuj ponownie!\n");
					return -1;
				}
			}
			//ew. funkcja WykPrzymusBicia
			if (czyPrzymusBicia(DajWartosc(i, j), player, i, j, k, l) == 0)
			{
				return 2;
			}
			else
			{
				swapIJKL(DajWartosc(i, j), i, j, k, l);
				if(player==RED && k==7 && DajWartosc(k, l)==RED)
				{
					ZmienWartosc(k, l, REDQUEEN);
				}
				if (player == BLACK && k == 0 && DajWartosc(k, l)==BLACK)
				{
					ZmienWartosc(k, l, BLACKQUEEN);
				}
				return 0;
			}
		}
	}
	if (i - k == -2 || i - k == 2)
	{
		if (j - l == -2 || j - l == 2)
		{
			if (i < k)
			{
				jmp_r = i + 1;
			}
			else
			{
				jmp_r = i - 1;
			}
			if (j < l)
			{
				jmp_c = j + 1;
			}
			else
			{
				jmp_c = j - 1;
			}

			if (player == RED && DajWartosc(jmp_r, jmp_c) != BLACK)
			{
				cout << "Mozesz skakac (bic) jedynie nad wrogiem!\nNiepoprawny ruch, sprobuj ponownie!\n";
				return -1;
			}
			if (player == BLACK && DajWartosc(jmp_r, jmp_c) != RED)
			{
				cout << "Mozesz skakac (bic) jedynie nad wrogiem!\nNiepoprawny ruch, sprobuj ponownie!\n";
				return -1;
			}

			ZmienWartosc(jmp_r, jmp_c, 1);
			swapIJKL(DajWartosc(i, j), i, j, k, l);
			int pionek_damy = DajWartosc(k, l);
			if (player == RED && k == 7 && pionek_damy== RED)
			{
				ZmienWartosc(k, l, REDQUEEN);
			}
			if (player == BLACK && k == 0 && pionek_damy== BLACK)
			{
				ZmienWartosc(k, l, BLACKQUEEN);
			}
			if (czyDodatkoweBicie(DajWartosc(i, j), player, k, l, pionek_damy) == 0)
			{
				if (player == RED && k == 7 && pionek_damy == RED && DajWartosc(k, l) == REDQUEEN)
				{
					ZmienWartosc(k,l, RED);
				}
				if (player == BLACK && k == 0 && pionek_damy == BLACK && DajWartosc(k, l) == BLACKQUEEN)
				{
					ZmienWartosc(k, l, BLACK);
				}
				return 1;
			}
			else { return 0; }
		}
	}
	printf("Mozesz poruszac sie tylko po skosie\n");
	return -1;
}


void Warcaby::gra()
{
	Aktualizer aktualizer;

	Gracz Gracz1(1, 'a', 1, 'a');
	Gracz Gracz2(8, 'h', 8, 'h');
	int decyzja, i, k;
	char c, j, l;
	do {
		system("cls");
		printf("MENU: \n 1. Rozpocznij gre (Gracz1 vs Gracz2) \n 2. Zapis do pliku \n 3. Odczyt z pliku \n 4. Zakoncz gre: warcaby \n");
		cin >> decyzja;
		while (cin.fail() || decyzja < 1 || decyzja > 4)
		{
			cin.ignore();
			cin.clear();
			while ((c = getchar()) != '\n');
			cout << "Podaj poprawna liczbe: " << endl;
			cin >> decyzja;
		}
		switch (decyzja)
		{
		case 1:
			if (decyzja == 1)
			{
				do 
				{
					DrukujPPlansze();
					while (flaga1 == 0)
					{
						int pomoc_zwracana;
						cout << "Gracz 1. Ruch pionka: ";
						//je¿eli wpiszemy ciagiem miejsce startowe i docelowe, przejdzie
						cin >> i >> j;
						while (cin.fail())
						{
							cin.ignore();
							cin.clear();
							while ((c = getchar()) != '\n');
							cout << "Podaj poprawna liczbe: " << endl;
							cin >> i >> j;
						}
						if (i == 0 && j == 'f') { flaga1++; break; };
						Gracz1.UstPozycjeWej(i, j);
						cout << "na pozycje: ";
						cin >> k >> l;
						while (cin.fail())
						{
							cin.ignore();
							cin.clear();
							while ((c = getchar()) != '\n');
							cout << "Podaj poprawna liczbe: " << endl;
							cin >> k >> l;
						}
						Gracz1.UstPozycjeWyj(k, l);
						pomoc_zwracana = RuchGracza(DajWartosc(i, j), RED, Gracz1.DajwspY() - 1, Gracz1.DajwspX() - 'a', Gracz1.DajwspWyjY() - 1, Gracz1.DajwspWyjX() - 'a');
						if (pomoc_zwracana == 2) //funkcja do sprawdzania obowiazkowego bicia
						{
							while (pomoc_zwracana == 2 || pomoc_zwracana == -1)
							{
								cout << "Ruch na pozycje: ";
								cin >> k >> l;
								while (cin.fail())
								{
									cin.ignore();
									cin.clear();
									while ((c = getchar()) != '\n');
									cout << "Podaj poprawna liczbe: " << endl;
									cin >> k >> l;
								}
								Gracz1.UstPozycjeWyj(k, l);
								pomoc_zwracana = RuchGracza(DajWartosc(i, j), RED, Gracz1.DajwspY() - 1, Gracz1.DajwspX() - 'a', Gracz1.DajwspWyjY() - 1, Gracz1.DajwspWyjX() - 'a');
								//while ((c = getchar()) != '\n');
							}
						}
						if (pomoc_zwracana == 0) break;
						if (pomoc_zwracana == 1)
						{
							i = k;
							j = l;
							Gracz1.UstPozycjeWej(i, j);
							while (pomoc_zwracana == 1 || pomoc_zwracana == -1)
							{
								cout << "Ruch na pozycje: ";
								cin >> k >> l;
								while (cin.fail())
								{
									cin.ignore();
									cin.clear();
									while ((c = getchar()) != '\n');
									cout << "Podaj poprawna liczbe: " << endl;
									cin >> k >> l;
								}
								Gracz1.UstPozycjeWyj(k, l);
								pomoc_zwracana = RuchGracza(DajWartosc(i, j), RED, Gracz1.DajwspY() - 1, Gracz1.DajwspX() - 'a', Gracz1.DajwspWyjY() - 1, Gracz1.DajwspWyjX() - 'a');
								if (pomoc_zwracana == 1)
								{
									Gracz1.UstPozycjeWej(k, l);
								}
							}
						}
						if (pomoc_zwracana == 0)break;
					}

					DrukujPPlansze();
					while (flaga1 == 0)
					{
						int pomoc_zwracana = 0;
						printf("%d", pomoc_zwracana);
						printf("Gracz 2. Ruch pionka: ");
						cin >> i >> j;
						while (cin.fail())
						{
							cin.ignore();
							cin.clear();
							while ((c = getchar()) != '\n');
							cout << "Podaj poprawna liczbe: " << endl;
							cin >> i >> j;
						}
						if (i == 0 && j == 'f') { flaga1++; break; };
						Gracz2.UstPozycjeWej(i, j);
						//sprawdzanie czy dama z tablicy i bicie z funckji + zaprogramowac alokacje dynamiczna liczby pionkow gracz
						printf("na pozycje: ");
						cin >> k >> l;
						while (cin.fail())
						{
							cin.ignore();
							cin.clear();
							while ((c = getchar()) != '\n');
							cout << "Podaj poprawna liczbe: " << endl;
							cin >> k >> l;
						}
						Gracz2.UstPozycjeWyj(k, l);
						pomoc_zwracana = RuchGracza(DajWartosc(i, j), BLACK, Gracz2.DajwspY() - 1, Gracz2.DajwspX() - 'a', Gracz2.DajwspWyjY() - 1, Gracz2.DajwspWyjX() - 'a');
						if (pomoc_zwracana == 2) //funkcja do sprawdzania obowiazkowego bicia
						{
							while (pomoc_zwracana == 2 || pomoc_zwracana == -1)
							{
								cin >> k >> l;
								while (cin.fail())
								{
									cin.ignore();
									cin.clear();
									while ((c = getchar()) != '\n');
									cout << "Podaj poprawna liczbe: " << endl;
									cin >> k >> l;
								}
								Gracz2.UstPozycjeWyj(k, l);
								pomoc_zwracana = RuchGracza(DajWartosc(i, j), BLACK, Gracz2.DajwspY() - 1, Gracz2.DajwspX() - 'a', Gracz2.DajwspWyjY() - 1, Gracz2.DajwspWyjX() - 'a');
								if (pomoc_zwracana == 1)
								{
									Gracz1.UstPozycjeWej(k, l);
								}
								//aktualizacja pozcyji if(pomoc_zwracana==2){}
							}
						}
						/*if (pomoc_zwracana == 3) //funkcja do sprawdzania obowiazkowego bicia
						{
							while (pomoc_zwracana == 3 || pomoc_zwracana == -1)
							{
								printf("Ruch na pozycje: ");
								while (scanf("%d%c", &k, &l) == 0)
								{
									printf("Podaj poprawna odpowiedz! \n");
									while ((c = getchar()) != '\n');
								}
								pomoc_zwracana = RuchGracza(d, BLACK, i - 1, j - 'a', k - 1, l - 'a');
							}
						}*/
						if (pomoc_zwracana == 0) break;
						if (pomoc_zwracana == 1)
						{
							i = k;
							j = l;
							Gracz2.UstPozycjeWej(i, j);
							while (pomoc_zwracana == 1 || pomoc_zwracana == -1)
							{
								printf("Ruch na pozycje: ");
								cin >> k >> l;
								while (cin.fail())
								{
									cin.ignore();
									cin.clear();
									while ((c = getchar()) != '\n');
									cout << "Podaj poprawna liczbe: " << endl;
									cin >> k >> l;
								}
								Gracz2.UstPozycjeWyj(k, l);
								pomoc_zwracana = RuchGracza(DajWartosc(i, j), BLACK, Gracz2.DajwspY() - 1, Gracz2.DajwspX() - 'a', Gracz2.DajwspWyjY() - 1, Gracz2.DajwspWyjX() - 'a');
								if (pomoc_zwracana == 1)
								{
									i = k;
									j = l;
									Gracz2.UstPozycjeWej(i, j);
								}
							}
							/*printf("%d", pomoc_zwracana);
							system("pause");//pomoc_zwracana = 0;*/
						}
						if (pomoc_zwracana == 0) break;
					}
				} while (flaga1 == 0);
			}
			else break;

		case 2:
			if (decyzja == 2)
			{
				int **tab;
				flaga1 = 0;
				tab = new int*[ROWS]; //przydzielenie pamiêci na w wierszy
				int j;
				for (int i = 0; i < ROWS; i++)
					tab[i] = new int[COLS]; //przydzielenie dla ka¿dego wiersza po k komórek

				for (i = 0; i < ROWS; i++)
				{
					for (j = 0; j < COLS; j++)
					{
						tab[i][j] = DajWartosc(i, j);
					}
				}

				aktualizer.zapis_stanu(tab);
				break;
			}
			else break;
		case 3:
			if (decyzja == 3)
			{
				int** tab_odczyt;
				flaga1 = 0;
				tab_odczyt = new int*[ROWS]; //przydzielenie pamiêci na w wierszy
				for (int i = 0; i < ROWS; i++)
					tab_odczyt[i] = new int[COLS]; //przydzielenie dla ka¿dego wiersza po k komórek

				tab_odczyt = aktualizer.odczyt_stanu();
				for (i = 0; i < ROWS; i++)
				{
					for (j = 0; j < COLS; j++)
					{
						ZmienWartosc(i, j, tab_odczyt[i][j]); // przepisujemy do pionkow
					}
				}

				cout << "Udalo sie odczytac plik\n";
				DrukujPPlansze();
				system("pause");
				break;
			} else break;
		case 4:
			if (decyzja == 4)
			{
				system("cls");
				printf("Zamykanie programu. \n");
				flaga2++;
				break;
			}
			else break;
		default:
			break;

		}
	} while (flaga2 == 0);
}