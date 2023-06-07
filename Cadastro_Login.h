#ifndef CADASTRO_H
#define CADASTRO_H

#include <string>

class Cadastro {
private:
    std::string nome;
    std::string senha;
    std::string email;

public:
    Cadastro();
    Cadastro(const std::string& nome, const std::string& senha, const std::string& email);

    std::string getNome() const;
    void setNome(const std::string& nome);

    std::string getSenha() const;
    void setSenha(const std::string& senha);

    std::string getEmail() const;
    void setEmail(const std::string& email);

    void salvarCadastro(std::ofstream& arquivo) const;
    void carregarCadastro(std::ifstream& arquivo);
};

#endif
