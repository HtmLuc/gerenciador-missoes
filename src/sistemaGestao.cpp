#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include "../class/sistemaGestao.hpp"

using namespace std;

void SistemaGestao::cadastroAstronauta(string cpf, string nome, int idade)
{
    for (Astronauta &astronauta : listaAstronautas)
    {
        if (astronauta.getCPF() == cpf)
        {
            cout << "ERRO: Já existe astroanura com o CPF " << cpf << "!!!" << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            return;
        }
    }
    listaAstronautas.emplace_back(cpf, nome, idade);
    cout << "O astronauta " << nome << " acaba de ser registrado no banco de dados." << endl;

    this_thread::sleep_for(chrono::milliseconds(2000));
}

void SistemaGestao::cadastroVoo(int codigoVoo)
{
    for (Voo &voo : listaVoos)
    {
        if (voo.getCodigoVoo() == codigoVoo)
        {
            cout << "ERRO: Expedição com o código " << codigoVoo << " já existe!!!" << endl;
            this_thread::sleep_for(chrono::milliseconds(3000));
            return;
        }
    }
    listaVoos.emplace_back(codigoVoo);
    cout << "Expedição com código " << codigoVoo << " foi criada." << endl;

    this_thread::sleep_for(chrono::milliseconds(2000));
}

void SistemaGestao::adicionarAstronautaVoo(string cpf, int codigoVoo)
{
    Voo *vooEncontrado;
    Astronauta *astronautaEncontrado;
    for(Voo &voo : listaVoos)
    {
        if(voo.getCodigoVoo() == codigoVoo)
        {
            vooEncontrado = &voo;
            break;
        }
    }
    if(!vooEncontrado)
    {
        cout << "ERRO: Expedição com o código " << codigoVoo << " não encontrado!!!" << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
        return;
    }
    
    if(vooEncontrado->getStatus() != PLANEJANDO   )
    {
        cout << "ERRO: Astronauta não pode ser adicionado em voos quee já foram lançados!!!" << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
        return;
    }

    for(Astronauta &astronauta : listaAstronautas)
    {
        if(astronauta.getCPF() == cpf)
        {
            astronautaEncontrado = &astronauta;
            break;
        }
    }

    if(!astronautaEncontrado)
    {
        cout << "ERRO: Astronauta com o CPF " << cpf << " não foi encontrado" << endl;
        this_thread::sleep_for(chrono::milliseconds(2000));
        return;
    }

    vooEncontrado->adicionarPassageiros(cpf);
    astronautaEncontrado->adicionarParticipacoes(codigoVoo);
    cout << "SUCESSO!" << endl;
    cout << "Astronauta com CPF " << cpf << " foi adicionado ao voo " << codigoVoo << "." << endl;

    this_thread::sleep_for(chrono::milliseconds(2000));
}

void SistemaGestao::removerAstronautaVoo(string cpf, int codigoVoo)
{
    bool deuCerto = true;
    for(Voo &voo : listaVoos)
    {
        if(voo.getCodigoVoo() == codigoVoo && voo.getStatus() != PLANEJANDO)
        {
            voo.removerPassageiros(cpf);
            cout << "O astronauta de cpf " << cpf << " foi removido do voo " << codigoVoo << endl;
            deuCerto = true;
            break;
        }
        else
        {
            deuCerto = false;
        }
    }
    if(!deuCerto)
    {
        cout << "ERRO: O astronauta não pode ser adicionado em voos em andamento ou finalizados." << endl;
    }
    this_thread::sleep_for(chrono::milliseconds(2000));
}

void SistemaGestao::lancarVoo(int codigoVoo)
{
    bool astronautaDisponivel = true;
    for(Voo &voo : listaVoos)
    {
        if(voo.getCodigoVoo() == codigoVoo && voo.getStatus() == PLANEJANDO)
        {
            if(!voo.getPassageiros().empty())
            {
                for(auto &cpf : voo.getPassageiros())
                {
                    for(Astronauta &astronauta : listaAstronautas)
                    {
                        if(astronauta.getCPF() == cpf && astronauta.getStatus() != LIVRE)
                        {
                            astronautaDisponivel = false;
                            break;
                        }
                    }
                    if(!astronautaDisponivel)
                    {
                        break;
                    }
                }
                if(astronautaDisponivel)
                {
                    voo.setStatus(EM_CURSO);
                    for(auto &cpf : voo.getPassageiros())
                    {
                        for(Astronauta &astronauta : listaAstronautas)
                        {
                            if(astronauta.getCPF() == cpf)
                            {
                                astronauta.setStatus(EM_VIAGEM);
                                break;
                            }
                        }
                    }
                    cout << "Voo " << codigoVoo << " lançado com sucesso!!!" << endl;
                }
                else
                {
                    cout << "Nem todos os astronautas estão dispponíveis para o voo." << endl;
                }
            }
            else
            {
                cout << "ERRO: O voo " << codigoVoo << " precisa de pelo menos um astronauta para poder decolar!!!" << endl;
            }
            break;
        }
        else
        {
            cout << "ERRO: O voo " << codigoVoo << " precisa estar sendo planejado." << endl;
        }
    }

    this_thread::sleep_for(chrono::milliseconds(2000));
}

void SistemaGestao::contatarVoo(int codigoVoo)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, 100);

    for(Voo &voo : listaVoos)
    {
        if (voo.getCodigoVoo() == codigoVoo && voo.getStatus() == EM_CURSO)
        {
            int numeroAleatorio = distrib(gen);
            if(numeroAleatorio < 20)
            {
                voo.setStatus(FINALIZADO_EXPLOSAO);
                for(auto &cpf : voo.getPassageiros())
                {
                    for(Astronauta &astronauta : listaAstronautas)
                    {
                        if(astronauta.getCPF() == cpf)
                        {
                            astronauta.setStatus(MORTO);
                            break;
                        }
                    }
                }
                cout << "Voo " << codigoVoo << " explodiu!!!" << endl;
                break;
            }
            else
            {
                cout << "Voo " << codigoVoo << " não explodiu explodiu!!!" << endl;
            }
        }
    }

    this_thread::sleep_for(chrono::milliseconds(2000));
}

void SistemaGestao::finalizarVoo(int codigoVoo)
{
    for(Voo &voo : listaVoos)
    {
        if(voo.getCodigoVoo() == codigoVoo && voo.getStatus() == EM_CURSO)
        {
            voo.setStatus(FINALIZADO_SUCESSO);
            for(auto &cpf : voo.getPassageiros())
            {
                for(Astronauta &astronauta : listaAstronautas)
                {
                    if(astronauta.getCPF() == cpf)
                    {
                        astronauta.setStatus(LIVRE);
                        break;
                    }
                }
            }
            cout << "Voo " << codigoVoo << " finalizado com sucesso!!" << endl;
        }
        else
        {
            cout << "ERRO: Não é possível cancelar o voo " << codigoVoo << " visto que ele está em planejamento ou foi explodido." << endl;
        }
    }

    this_thread::sleep_for(chrono::milliseconds(2000));
}

void SistemaGestao::listarVoos()
{
    string status;
    cout << "O sistema possui os seguintes voos:" << endl;
    for(Voo &voo : listaVoos)
    {  
        switch (voo.getStatus()) {
            case PLANEJANDO: 
                status = "Planejando";
                break;
            case EM_CURSO:
                status = "Em curso";
                break;
            case FINALIZADO_SUCESSO:
                status = "Finalizado com sucesso";
                break;
            case FINALIZADO_EXPLOSAO:
                status = "Finalizado (Explosão)";
                break;
        }
        cout << "Voo " << voo.getCodigoVoo() << " (" << status << "):" << endl;
        cout << "Passageiros:" << endl;
        for(auto &cpf : voo.getPassageiros())
        {
            for(Astronauta &astronauta : listaAstronautas)
            {
                if(astronauta.getCPF() == cpf)
                {
                    cout << "- " << astronauta.getNome() << endl;
                    break;
                }
            }
        }
    }

    this_thread::sleep_for(chrono::milliseconds(10000));
}

void SistemaGestao::listarAstronautasMortos()
{
    cout << "O luto é o preço que se paga pelo amor. - Anne with an E" << endl << endl;
    for (Astronauta &astronauta : listaAstronautas)
    {
        if(astronauta.getStatus() == MORTO)
        {
            cout << "Em memória de " << astronauta.getNome() << " (" << astronauta.getCPF() << ") que tinha só " << astronauta.getIdade() << " anos." << endl;
            cout << "Participou dos seguintes voos:" << endl;
            for(const auto &codigo : astronauta.getParticipacoes())
            {
                cout << codigo << endl;
            }
        }
    }
    cout << "Façamos 10 segundos de silêncio..." << endl;
    this_thread::sleep_for(chrono::milliseconds(10000));
}