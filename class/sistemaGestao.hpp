#ifndef SISTEMAGESTAO_HPP
#define SISTEMAGESTAO_HPP

#include <list>
#include <string>
#include "astronauta.hpp"
#include "voos.hpp"

using std::list, std::string;

class SistemaGestao
{
    private:
        list<Astronauta> listaAstronautas;
        list<Voo> listaVoos;

    public:
        void cadastroAstronauta(string cpf, string nome, int idade);
        void cadastroVoo(int codigoVoo);

        void listarAstronautasMortos();
        void listarVoos();

        void adicionarAstronautaVoo(string cpf, int codigoVoo);
        void removerAstronautaVoo(string cpf, int codigoVoo);

        void lancarVoo(int codigoVoo);
        void finalizarVoo(int codigoVoo);
        void contatarVoo(int codigoVoo);
};
#endif