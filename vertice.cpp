#include <vector>
#include <string>

#include "vertice.h"
#include "aresta.h"

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

unsigned getPeso()
{
    return peso;
}

void Vertice::incrementaPeso()
{
    peso++;
}


