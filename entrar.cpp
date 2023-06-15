#include "pagina_entrar.h"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

void PaginaEntrar() {
    std::cout << "Faça login" << std::endl;

    std::string nomeUsuario;
    std::string senha;

    std::cout << "Nome de usuário: ";
    std::cin >> nomeUsuario;
    std::cout << "Senha: ";
    std::cin >> senha;

    std::ifstream arquivo("BancoDeDados.csv");

    if (arquivo.is_open()) {
        std::string linha;
        bool encontrou = false;

        while (std::getline(arquivo, linha)) {
            // Extrai as informações da linha do arquivo
            std::string usuarioSalvo, emailSalvo, senhaSalva, dataNascimentoSalva, saldoSalvo;
            std::istringstream iss(linha);
            std::getline(iss, usuarioSalvo, ';');
            std::getline(iss, senhaSalva, ';');

            // Verifica se as credenciais estão corretas
            if (usuarioSalvo == nomeUsuario && senhaSalva == senha) {
                encontrou = true;
                break;
            }
        }

        arquivo.close();

        if (encontrou) {
            std::cout << "Login realizado com sucesso!" << std::endl;
            // Restante do seu código para a página após o login
            // ...
        } else {
            std::cout << "Credenciais inválidas. Tente novamente." << std::endl;
            // Volta para a página de login
            PaginaEntrar();
        }
    } else {
        std::cout << "Não foi possível abrir o banco de dados." << std::endl;
        // Tratar o erro de abertura do arquivo
    }
}
