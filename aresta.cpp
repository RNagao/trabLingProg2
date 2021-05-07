#include <vector>
#include <string>

#include "vertice.h"
#include "aresta.h"

using namespace std;

Aresta::Aresta(Vertice *verticeOrigem, Vertice *verticeDestino)
{
    origem = verticeOrigem;
    destino = verticeDestino;
    peso = 1;
}

unsigned Aresta::getPeso()
{
    return peso;
}

void Aresta::incrementaPeso()
{
    peso++;
}

Vertice Aresta::getOrigem()
{
    return origem;
}

Vertice Aresta::getDestino()
{
    return destino;
}