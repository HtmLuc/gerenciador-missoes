#include "../class/astronauta.hpp"

Astronauta::Astronauta(string cpf_, string nome_, int idade_)
{
    cpf = cpf_;
    nome = nome_;
    idade = idade_;
    status = LIVRE;
}

string Astronauta::getCPF() const
{
    return cpf;
}

string Astronauta::getNome() const
{
    return nome;
}

int Astronauta::getIdade() const
{
    return idade;
}

AstronautaStatus Astronauta::getStatus() const
{
    return status;
}

const list<int> &Astronauta::getParticipacoes() const
{
    return participacoes;
}


void Astronauta::setCPF(string cpf_)
{
    cpf = cpf_;
}

void Astronauta::setNome(string nome_)
{
    nome = nome_;
}

void Astronauta::setIdade(int idade_)
{
    idade = idade_;
}

void Astronauta::setStatus(AstronautaStatus status_)
{
    status = status_;
}

void Astronauta::adicionarParticipacoes(int codigoVoo)
{
    participacoes.push_back(codigoVoo);
}