#include <vector>
#include <string>
#include <fstream>

#include "aresta.h"
#include "vertice.h"

using namespace std;

class Grafo
{
    public:
        //construtor do grafo
        Grafo ();
        //printa a(s) palavra(s) mais usada(s) no paragrafo do arquivo texto
        void getPalavraMaisUsada();
        //printa na tela a sequencia de N palavras consecutivas mais utilizadas
        void getMaiorSequenciaN(unsigned);

    private:
        //tamanho maximo da frase no texto
        int maximoN;
        //vetor de arestas (sequencia da palavra)
        vector <Aresta> arestas;
        //vetor de vertices (palavras)
        vector <Vertice> vertices;
        //adicionar aresta
        void addVertice(string);
        //adicionar vertice
        void addAresta(Vertice *, Vertice *);
};