#pragma once
class Gracz
{
	int wspY, ruchnaY; //pozycje zadane przez uzytkownika, zatwierdzane przez Warcaby
	char wspX, ruchnaX;
public:
	Gracz(int, char, int, char);
	~Gracz();
	void UstPozycjeWej(int, char);
	void UstPozycjeWyj(int, char);
	int DajwspY();
	char DajwspX();
	int DajwspWyjY();
	char DajwspWyjX();
	
};

