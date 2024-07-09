#ifndef ASTRONAUTAS_HPP
#define ASTRONAUTAS_HPP

#include <string>
#include <list>

using namespace std;

enum AstronautaStatus
{
    LIVRE,
    EM_VIAGEM,
    MORTO
};

class Astronauta
{
    private:
        string cpf;
        string nome;
        int idade;
        AstronautaStatus status;
        list<int> participacoes;
    public:
        Astronauta(string cpf_, string nome_, int idade_);
        // ~Astronauta();

        string getCPF() const;
        string getNome() const;
        int getIdade() const;
        AstronautaStatus getStatus() const;
        const list<int> &getParticipacoes() const;


        void setCPF(string cpf_);
        void setNome(string nome_);
        void setIdade(int idade_);
        void setStatus(AstronautaStatus status_);
        void adicionarParticipacoes(int codigoVoo);
};
#endif