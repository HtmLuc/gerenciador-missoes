#include "../class/voos.hpp"

Voo::Voo(int codigoVoo_)
{
    codigoVoo = codigoVoo_;
    status = PLANEJANDO;
}

int Voo::getCodigoVoo() const
{
    return codigoVoo;
}

const list<string> &Voo::getPassageiros() const
{
    return passageiros;
}

const VooStatus Voo::getStatus() const
{
    return status;
}

void Voo::setStatus(VooStatus status_)
{
    status = status_; 
}

void Voo::adicionarPassageiros(string &cpf)
{
    passageiros.push_back(cpf);
}

void Voo::removerPassageiros(string &cpf)
{
    passageiros.remove(cpf);
}