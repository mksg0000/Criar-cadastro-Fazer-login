#include <iostream>
#include <string>
#include "CRIARCONTA.h"
#include "usuario.h"
#include "ENTRAR.h"
#include "sair.h"
#include <fstream>


void PaginaCriarConta() {

    int j = 0;
    int selecionar2;
    cout << "Crie sua conta" << endl;

    std::string email;
    std::string nomeUsuario;
    std::string senha;
    std::string dataNascimento;

    std::cout << "Nome de usuario: ";
    std::cin >> nomeUsuario;
    std::cout << "E-mail: ";
    std::cin >> email;
    std::cout << "Senha: ";
    std::cin >> senha;
    std::cout << "Data de nascimento (por favor use o modelo 'ddmmaa'): ";
    std::cin >> dataNascimento;

    Usuario usuario(nomeUsuario, senha, email, dataNascimento);

    fstream arquivo;
    arquivo.open ("BancoDeDados.csv", std::fstream::in | std::fstream::out | std::fstream::app);
  
    /*
    * 
        std::cout << "abriu";


    }
    else {
        std::cout << "deu ruim";
    }
    */
   
    arquivo << nomeUsuario << ";" << email << ";" << senha << ";" << dataNascimento << ";0;" << std::endl;
    arquivo.close();
    

    std::cout << " " << std::endl;
    std::cout << "Seus dados são:" << std::endl;
    std::cout << "Nome de usuário: " << usuario.getNomeUsuario() << std::endl;
    std::cout << "Email: " << usuario.getEmail() << std::endl;
    std::cout << "Senha: " << usuario.getSenha() << std::endl;

    std::cout << "Conta criada!" << std::endl;
    std::cout << "Cheque seu e-mail para confirmar sua conta." << std::endl;

    std::cout << "1. Continuar" << std::endl;
    std::cout << "2. Sair" << std::endl;
    std::cout << " " << std::endl;
    std::cin >> selecionar2;

    while (j < 100) {
        if (selecionar2 == 1) {
            PaginaEntrar();
            break;
        }
        else if (selecionar2 == 2) {
            PaginaSair();
            break;
        }
        else {
            while (selecionar2 != 1 && selecionar2 != 2) {
                std::cout << "Opção inválida." << std::endl;
                std::cout << " ";
                std::cin >> selecionar2; {

                }
            }
        }
    }
}
