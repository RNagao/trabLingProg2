#include <vector>
#include <string>

#include "vertice.h"

using namespace std;

Vertice::Vertice(string palavraLida)
{
    peso = 1;
    palavra = palavraLida;
}

string Vertice::getPalavra()
{
    return palavra;
}

unsigned Vertice::getPeso()
{
    return peso;
}

void Vertice::incrementaPeso()
{
    peso++;
}


