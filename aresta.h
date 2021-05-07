#include <vector>
#include <string>

#include "vertice.h"

using namespace std;

class Aresta
{
    public:
        //construtor da aresta
        Aresta (Vertice *, Vertice *);
        //retorna o numero de repeticoes da sequencia de palavras
        unsigned getPeso();
        //incrementa o peso da aresta
        void incrementaPeso();
        //obtem o vertice de origem
        Vertice getOrigem();
        //obtem o vertice de destino
        Vertice getDestino();

    private:
        //vertice de origem
        Vertice *origem;
        //vertice de destino
        Vertice *destino;
        //repeticoes da sequencia de palavras
        unsigned peso;
};

