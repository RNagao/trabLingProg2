#include <iostream>
#include <string.h>
#include <fstream>
#include <stdio.h>

#include "grafo.h"

Grafo::Grafo()
{
    unsigned indice, indiceAux;
    int espaco, pontuacao = 0;
    ifstream file("texto.txt");
    string linha;
    vector <string> palavras;
    vector <vector <string>> frase;
    unsigned Nmax = 0;
    
    while(getline(file, linha))
    {
        string palavra = "";
        unsigned indice;

        for (indice = 0; indice <= linha.length(); indice++)
        {
            espaco = strncmp(&linha[indice], " ", 1);
            pontuacao = ispunct(linha[indice]);
            
            if ((espaco != 0) && (pontuacao == 0))
            {
                palavra += tolower(linha[indice]);
            }
            else if (strncmp(&linha[indice], "-", 1) == 0)
            {
                palavra += tolower(linha[indice]);
            }
            else if (espaco == 0)
            {
                if (palavra.length() > 0)
                {
                    palavras.push_back(palavra);
                    palavra = "";
                }
            }
            else if (pontuacao != 0)
            {
                if (palavra.length() > 0)
                {
                    palavras.push_back(palavra);
                    palavra = "";
                }
                for (indiceAux = 0; indiceAux < palavras.size(); indiceAux++)
                {
                    adicionaVertice(palavras[indiceAux]);
                }
                
                frase.push_back(palavras);
                
                palavras.clear();
            }
        }
    }
    file.close();
    cout << vertices.size() <<endl;
    for (indice = 0; indice < vertices.size(); indice++)
    {
        cout << vertices[indice].getPalavra() << vertices[indice].getPeso() << endl;
    }
    
    for (indice = 0; indice < frase.size(); indice++)
    {
        for (indiceAux = 0; indiceAux < (frase[indice].size() - 1); indiceAux++)
        {
            adicionaAresta(getVertice(frase[indice][indiceAux]), getVertice(frase[indice][indiceAux + 1]));
        }
    }
    
    for (indice = 0; indice < frase.size(); indice++)
    {
        if (frase[indice].size() > Nmax)
        {
            Nmax = frase[indice].size();
        }
    }
    maximoN = Nmax;
    //periodos = frase;
}

void Grafo::getPalavraMaisUsada()
{
    vector <string> lista;
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
            lista.push_back(vertices[indice].getPalavra());
        }
    }

    for (indice = 0; indice < lista.size(); indice++)
    {
        cout << lista[indice] << endl;
    }

    cout << endl << "Valor: " << valor << endl;
}

void Grafo::getMaiorSequenciaN(unsigned n)
{
    vector <Vertice> lista;
    unsigned indice, peso = 0;

    if (n < 2)
    {
        cout << "O valor da sequencia nao pode ser menor que 3" << endl;
        return;
    }
  /*   else if (n > maximoN)
    {
        cout << "Nao existe uma sequencia com esse numero de palavras" << endl;
        return;
    } */
    else //if (n == 2)
    {
        for (indice = 0; indice < arestas.size(); indice++)
        {
            if (arestas[indice].getPeso() > peso)
            {
                lista.clear();
                lista.push_back(arestas[indice].getOrigem());
                lista.push_back(arestas[indice].getDestino());
                peso = arestas[indice].getPeso();
            }
            else if (arestas[indice].getPeso() == peso)
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

        cout << "Valor: " << peso << endl;
    }
   /*  else
    {
        for (indice = 0; indice < periodos.size(); indice++)
        {
            if (periodos[indice].size() >= n)
            {
                
            }
        }
    } */
}

void Grafo::adicionaVertice(string palavra)
{
    unsigned indice;
    bool palavraExiste = false;
    
    if (vertices.size() == 0)
    {
        vertices.push_back(Vertice(palavra));
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
            vertices.push_back(Vertice(palavra));
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
            if (arestas[indice].getDestino(). getPalavra() == destino->getPalavra())
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

Vertice* Grafo::getVertice(string palavra)
{
    unsigned indice;
    
    for (indice = 0; indice < vertices.size(); indice++)
    {
        if (vertices[indice].getPalavra() == palavra)
        {
            return &vertices[indice];
        }
    }
    return NULL;
}
