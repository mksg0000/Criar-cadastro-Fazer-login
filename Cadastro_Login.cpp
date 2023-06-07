#include "Cadastro_Login.h"
#include <iostream>
#include <fstream>
#include <string>

Cadastro::Cadastro() {}

Cadastro::Cadastro(const std::string& nome, const std::string& senha, const std::string& email)
    : nome(nome), senha(senha), email(email) {
}

std::string Cadastro::getNome() const {
    return nome;
}

void Cadastro::setNome(const std::string& nome) {
    this->nome = nome;
}

std::string Cadastro::getSenha() const {
    return senha;
}

void Cadastro::setSenha(const std::string& senha) {
    this->senha = senha;
}

std::string Cadastro::getEmail() const {
    return email;
}

void Cadastro::setEmail(const std::string& email) {
    this->email = email;
}

void Cadastro::salvarCadastro(std::ofstream& arquivo) const {
    arquivo << nome << "," << senha << "," << email << std::endl;
}

void Cadastro::carregarCadastro(std::ifstream& arquivo) {
    std::string linha;
    if (std::getline(arquivo, linha)) {
        std::size_t pos1 = linha.find(",");
        if (pos1 != std::string::npos) {
            std::size_t pos2 = linha.find(",", pos1 + 1);
            if (pos2 != std::string::npos) {
                nome = linha.substr(0, pos1);
                senha = linha.substr(pos1 + 1, pos2 - pos1 - 1);
                email = linha.substr(pos2 + 1);
            }
        }
    }
}
