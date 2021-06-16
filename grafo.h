#include <vector>
#include <string>

#include "aresta.h"
#include "vertice.h"

using namespace std;

#ifndef GRAFO_H
#define GRAFO_H

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
        unsigned maximoN;
        //vetor de arestas (sequencia da palavra)
        vector <Aresta> arestas;
        //vetor de vertices (palavras)
        vector <Vertice> vertices;
        //adicionar aresta
        void adicionaVertice(string);
        //adicionar vertice
        void adicionaAresta(Vertice *, Vertice *);
        //retorna o vertice pela palavra
        Vertice* getVertice(string);
};
#endif