#include <iostream>
#include <string>
#include "CRIARCONTA.h"
#include "ENTRAR.h"
#include <tchar.h>
#include <fstream>
#include "Cadastro_Login.h"

int main() {
    _tsetlocale(LC_ALL, _T("portuguese"));
    int selecionar;
    int i = 0;

    std::cout << "Bem-vindo ao MatchMaker, Usuário!" << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << " " << std::endl;
    std::cout << "1. Crie uma conta" << std::endl;
    std::cout << "2. Entrar" << std::endl;
    std::cout << "----------------" << std::endl;
    std::cout << " " << std::endl;
    std::cin >> selecionar;

    while (i < 100) {
        if (selecionar == 1) {
            PaginaCriarConta();
            break;
        }
        else if (selecionar == 2) {
            PaginaEntrar();
            break;
        }
        else {
            while (selecionar != 1 && selecionar != 2) {
                std::cout << "Opção inválida." << endl;
                std::cout << " ";
                std::cin >> selecionar;
            }
        }
    }
}
