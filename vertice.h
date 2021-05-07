#include <vector>
#include <string>

#include "aresta.h"

using namespace std;

class Vertice
{
    public:
        //contrutor do vertice
        Vertice (string);
        //retorna a palavra do vertice
        string getPalavra();
        //retorna o numero de repeticoes da palavra
        unsigned getPeso();
        //incrementa o peso
        void incrementaPeso();

    private:
        //palavra do vertice
        string palavra;
        //repeticoes da palavra
        unsigned peso;
};