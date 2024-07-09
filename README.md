# Pré-requisitos
É necessário ter o compilador para a linguagem C++ instalado no computador. Caso não tenha, instale o compilador [GCC](https://gcc.gnu.org/).

Também é necessário ter o make instalado. Se não possuir, [clique aqui](https://www.gnu.org/software/make/) para baixar e instalar seguindo os passos.

Por fim, é necessário ter o [git](https://git-scm.com) baixado e configurado em sua máquina para que possa clonar o programa.

Concluído esses passos, agora, é só clonar o repositório:
```
git clone https://github.com/HtmLuc/gerenciador-missoes
```

E, por fim, executar os seguintes comandos.

# Comandos
- `make compile` - compilar
- `make run` - executar

# Descrição das funções
- cadastro astronauta:
    Irá cadastrar um novo astronauta;
- cadastroVoo:
    Irá cadastrar um novo voo;
- adicionarAstronautaVoo:
    Irá adicionar astronauta em voo (caso criado);
- removerAstronautaVoo:
    Irá remover astronauta de voo (caso já tenha sido adicionado);
- lancarVoo:
    Irá lançar voo;
- contatarVoo:
    Irá gerar um número aleatório, podendo explodir ou não o voo;
- finalizarVoo:
    Finaliza o voo, caso seja possível;
- listarVoos:
    Lista todos os voos;
- listarAstronautasMortos:
    Lista todos os astronautas que morreram em explosões.