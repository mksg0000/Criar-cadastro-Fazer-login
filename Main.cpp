#include <iostream>
#include <fstream>
#include <string>
#include "Cadastro_Login.h"


void cadastrarPessoa(const std::string& nomeArquivo) {
      std::ofstream arquivo(nomeArquivo, std::ios::app);
    if (!arquivo.is_open()) {
          return;
    }
  
      std::string nome, senha, email;
    
      std::cout << "Cadastro" << std::endl;

    while (true) {
        std::cout << "Digite seu nome (mínimo 4 dígitos): ";
        std::getline(std::cin, nome);

      if (nome.length() >= 4) {
        break;
    } 
        else {
        std::cout << "Nome inválido! O nome deve ter no mínimo 4 dígitos." << std::endl;
      }
    }

    while (true) {
        std::cout << "Digite sua senha (mínimo 4 dígitos): ";
        std::getline(std::cin, senha);

      if (senha.length() >= 4) {
          break;
    } 
      else {
        std::cout << "Senha inválida! A senha deve ter no mínimo 4 dígitos." << std::endl;
        }
    }
  
        std::cout << "Digite seu email: ";
        std::getline(std::cin, email);

    Cadastro cadastro(nome, senha, email);
    cadastro.salvarCadastro(arquivo);
    arquivo.close();

        std::cout << "Cadastro realizado com sucesso!" << std::endl;
}

bool fazerLogin(const std::string& nomeArquivo) {
        std::ifstream arquivo(nomeArquivo);
    if (!arquivo.is_open()) {
          return false;
    }

       std::string nome, senha;
       std::cout << "Login" << std::endl;
       std::cout << "Digite seu nome: ";
       std::getline(std::cin, nome);
       std::cout << "Digite sua senha: ";
       std::getline(std::cin, senha);

    Cadastro cadastro;
      while (!arquivo.eof()) {
        cadastro.carregarCadastro(arquivo);
        if (nome == cadastro.getNome() && senha == cadastro.getSenha()) {
            arquivo.close();
          std::cout << "Login bem-sucedido!" << std::endl;
            return true;
        }
    }

    arquivo.close();
          std::cout << "Nome de usuário ou senha incorretos." << std::endl;
            return false;
}

int main() {
          std::string nomeArquivo = "cadastro.txt";

    while (true) {
          std::cout << "Escolha uma opção:" << std::endl;
          std::cout << "1 - Cadastrar" << std::endl;
          std::cout << "2 - Fazer login" << std::endl;
          std::cout << "3 - Sair" << std::endl;

          int opcao;
          std::cin >> opcao;
          std::cin.ignore();

        switch (opcao) {
            case 1:
                cadastrarPessoa(nomeArquivo);
                break;
            case 2:
                if (fazerLogin(nomeArquivo))
                    return 0;
                break;
            case 3:
                std::cout << "Saindo do programa..." << std::endl;
                return 0;
            default:
                std::cout << "Opção inválida. Tente novamente." << std::endl;
                break;
        }

          std::cout << std::endl;
    }

return 0;
}
