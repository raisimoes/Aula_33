#include <iostream>
#include <vector>

using namespace std;

class Cliente{
    string nome, cpf;
    
    public:
        Cliente(string _nome, string _cpf){
            this->nome = _nome;
            this->cpf  = _cpf;
        }
        
        string getNome(){
            return this->nome;
        }

        void setNome(string _nome){
            this->nome = _nome;
        }

        //todo: fazer getters e setters
};

class Dependente{
    string nome;
    Cliente *responsavel;
    public:
        Dependente(string _nome, Cliente *_responsavel){
            this->nome = _nome;
            this->responsavel = _responsavel;
        }
        // todo: fazer getters e setters
        Cliente* getResponsavel(){
            return this->responsavel;
        }
};

class Evento{
    protected:
        int duracao;

        Evento(int _duracao){
            this->duracao = _duracao;
        }

    public:
        virtual void imprimir () = 0; // Método virtual puro obriga o programador a colocar métodos nas subclasses
                                      // Método virtual tem uma mensagem genérica que aparece quando uma subclasse não tem um método espcífico definido
                                      // Interface é quando as todas as superclasses utilizam método virtual puro.
};

class Roteiro : public Evento{
    string titulo;
    int ordem;
    public:
        Roteiro(int _duracao, string _titulo, int _ordem):Evento(_duracao){
            this->titulo = _titulo;
            this->ordem = _ordem;
        }

    public:
        virtual void imprimir () {
            std::cout << "----- Roteiro -----" << std::endl;
            std::cout << "- Local: " << this->titulo << std::endl;
        }
};

class Deslocamento : public Evento{
    string origem;
    string destino;
    public:
        Deslocamento(int _duracao, string _origem, string _destino):Evento(_duracao){
            this->origem = _origem;
            this->destino = _destino;
        }

    public:
        virtual void imprimir () {
            std::cout << "----- Deslocamento -----\n- Van coletiva" << std::endl;
            std::cout << "- Origem: " << this->origem << std::endl;
            std::cout << "- Destino: " << this->destino << std::endl;
        }
};

class Pernoite : public Evento{
    string local;
    public:
        Pernoite(int _duracao,string _local=""):Evento(_duracao){
            this->local = _local;
        }

        public:
        virtual void imprimir () {
            std::cout << "----- Pernoite -----\n- Hostel da Jô\n\n" << std::endl;
        }
};

class Pacote{
    public:
        vector<Evento*> listaEventos;
    
        Pacote(Evento *_evento){
            listaEventos.push_back(_evento);
        }

        void inserirEvento(Evento *_evento){
            listaEventos.push_back(_evento);
        }
        //todo: métodos para acessar (inserir, listar) eventos
};

class Reserva{
    public:
        Cliente *cliente;
        Pacote *pacote;
        Reserva(Cliente *_cliente, Pacote *_pacote){
            this->cliente = _cliente;
            this->pacote = _pacote;
        }
};

int main(){
    
    Cliente *cli01 = new Cliente("Bruno","111111");
    Dependente *dep01 = new Dependente("Leane",cli01);
    Dependente *dep02 = new Dependente("Vinicius", cli01);

    cout << dep01->getResponsavel()->getNome() << endl;
    cout << dep02->getResponsavel()->getNome() << endl;

    cli01->setNome("Bruno Santana");
    
    cout << dep01->getResponsavel()->getNome() << endl;
    cout << dep02->getResponsavel()->getNome() << endl;

    Roteiro *r1 = new Roteiro(4,"Noite no Parque do Povo",1);

    Deslocamento *d1 = new Deslocamento(1,"Hotel","Noite Parque do Povo");

    Pernoite *p1 = new Pernoite(10);

    Pacote *bronze = new Pacote(r1); //polimorfismo
    bronze->inserirEvento(d1);
    bronze->inserirEvento(p1);

    for(auto el : bronze->listaEventos) {
        cout << endl;
        el->imprimir();
    }
    

    Reserva *reserva01 = new Reserva(cli01,bronze);
    
    return 0;
}