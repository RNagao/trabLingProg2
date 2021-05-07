#include "grafo.h"
#include "aresta.h"
#include "vertice.h"

Grafo::Grafo
{
    string palavra;

    file.open("texto.txt", fstream::in);

    if (!file.is_open())
    {
        cout << "Erro ao abrir arquivo." << endl;
        return;
    }

    while (file.good())
    {
        file >> palavra;
        cout << palavra << endl;
    }
}

void Grafo::getPalavraMaisUsada()
{
    vector string lista;
    unsigned indice, valor = 0;

    for (indice = 0; indice < vertices.size(); indice++)
    {
        if (vertices[indice].getPeso() > valor)
        {
            lista.clear();
            lista.push_back(vertices[indice].getPalavra());
            valor = vertices[indice].getPeso();
        }
        else if (vertices[indice].getPeso() == valor)
        {
            lista.push_back(vertices[indice].getPalavra())
        }
    }

    for (indice = 0; indice < lista.size(); indice++)
    {
        cout << lista[indice] << " ";
    }

    cout << endl << "Valor: " << valor << endl;
}

void Grafo::getMaiorSequenciaN(unsigned n)
{
    vector Aresta lista;
    unsigned indice, peso = 0;

    if (n < 2)
    {
        cout << "O valor da sequencia nao pode ser menor que 3" << endl;
        exit();
    }
    else if (n > maximoN)
    {
        cout << "Nao existe uma sequencia com esse numero de palavras" << endl;
        exit();
    }
    else if (n = 2)
    {
        for (indice = 0; indice < arestas.size(); indice++)
        {
            if (arestas[indice].getPeso() > peso)
            {
                lista.clear();
                lista.push_back(arestas[indice].getOrigem());
                lista.push_back(arestas[indice].getDestino());
                valor = arestas[indice].getPeso();
            }
            else if (arestas[indice].getPeso() == valor)
            {
                lista.push_back(arestas[indice].getOrigem());
                lista.push_back(arestas[indice].getDestino());
            }
        }

        for (indice = 0; indice < lista.size();)
        {
            cout << lista[indice].getPalavra() << " --> " << lista[indice + 1].getPalavra() << endl;
            indice += 2;
        }

        cout << "Valor: " << valor << endl;
    }
}

void Grafo::adicionaVertice(string palavra)
{
    unsigned indice;
    bool palavraExiste = false;

    if (vertices.size() == 0)
    {
        vertices.push_back(Aresta(origem, destino));
    }
    else
    {
        for (indice = 0; indice < vertices.size(); indice++)
        {
            if (vertices[indice].getPalavra() == palavra)
            {
                palavraExiste = true;
                vertices[indice].incrementaPeso();
                break;
            }
        }

        if (palavraExiste == false)
        {
            vertices.push_back(Aresta(origem, destino));
        }
    }
}

void Grafo::adicionaAresta(Vertice *origem, Vertice *destino)
{
    unsigned indice;
    bool arestaExiste = false;

    if (arestas.size() == 0)
    {
        arestas.push_back(Aresta(origem, destino));
    }
    else
    {
        for (indice = 0; indice < arestas.size(); indice++)
        {
            if (arestas[indice].getDestino() == destino)
            {
                arestas[indice].incrementaPeso();
                arestaExiste = true;
                break;
            }
        }

        if (arestaExiste == false)
        {
            arestas.push_back(Aresta(origem, destino));
        }
    }
}
