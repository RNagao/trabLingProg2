#include <string>
#include <iostream>
#include <vector>

#include "grafo.h"

using namespace std;

#define SUCESSO             0
#define ERROR_LER_ARQUIVO   1

unsigned menu()
{
    unsigned opcao;
    cout << "Menu" << endl;
    cout << "0 - Sair" << endl;
    cout << "1 - Palavra mais usada no texto" << endl;
    cout << "2 - Sequencia de 2 palavra consecutivas mais usada no texto" << endl;
    cout << "3 - Sequencia de N palavras consecutivas mais utilizada no texto" << endl;
    cout << "Digite o numero da funcionalidade desejada" << endl;
    cin >> opcao;
    return opcao;
}

int main()
{
    unsigned opcao;
    unsigned n;

    Grafo grafo();

    opcao = menu();
    while (opcao != 0)
    {
        switch (opcao)
        {
            case 1:
                cout << "\nPALAVRA MAIS UTILIZADA" << endl;
                grafo.getPalavraMaisUsada();
                cout << endl;
                break;
            case 2:
                cout << "\nSEQUENCIA DE 2 PALAVRAS MAIS UTILIZADA" << endl;
                grafo.getMaiorSequenciaN(2);
                cout << endl;
                break;
            case 3:
                cout << "\nSEQUENCIA DE N PALAVRAS MAIS UTILIZADA" << endl;
                cout << "De o valor de N: " << endl;
                cin >> n;
                grafo.getMaiorSequenciaN(n);
                cout << endl;
                break;
            default:
                cout << "Opcao invalida" << endl;
                cout << endl;
                exit(OPCAO_INVALIDA);
        }

        opcao = menu();
    }

    return SUCESSO
}