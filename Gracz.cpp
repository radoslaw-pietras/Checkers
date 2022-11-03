#include "Gracz.h"



Gracz::Gracz(int y, char x, int yy, char xx)
{
	wspY = y;
	wspX = x;
	ruchnaY = yy;
	ruchnaX = xx;
}


Gracz::~Gracz()
{
}

void Gracz::UstPozycjeWej(int y, char x)
{
	wspY = y;
	wspX = x;
}

void Gracz ::UstPozycjeWyj(int yy, char xx)
{
	ruchnaY = yy;
	ruchnaX = xx;
}

int Gracz ::DajwspY()
{
	return wspY;
}

char Gracz ::DajwspX()
{
	return wspX;
}

int Gracz::DajwspWyjY()
{
	return ruchnaY;
}

char Gracz::DajwspWyjX()
{
	return ruchnaX;
}