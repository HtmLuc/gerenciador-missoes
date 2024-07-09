#ifndef VOOS_HPP
#define VOOS_HPP

#include <iostream>
#include <list>
#include <string>
#include "astronauta.hpp"

using namespace std;

enum VooStatus
{
    PLANEJANDO,
    EM_CURSO,
    FINALIZADO_SUCESSO,
    FINALIZADO_EXPLOSAO
};

class Voo
{
    private:
        int codigoVoo;
        list<string> passageiros;
        VooStatus status;
    public:
        Voo(int codigoVoo_);
        // ~Voo();

        int getCodigoVoo() const;
        const list<string> &getPassageiros() const;
        const VooStatus getStatus() const;

        void setStatus(VooStatus status_);
        void adicionarPassageiros(string &cpf);
        void removerPassageiros(string &cpf);
};
#endif