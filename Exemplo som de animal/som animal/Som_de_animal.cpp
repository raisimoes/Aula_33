#include <iostream>

class Animal {
    public:
        virtual void som () {
            std::cout << "Som genérico de um animal" << std::endl;
        }
};

class Cachorro : public Animal {
    public:
        void som () override {
            std::cout << "Latido de cachorro" << std::endl;
        } 
};

class Gato : public Animal {
    public:
        void som() override {
            std::cout << "Miado de gato" << std::endl;
        }
};



int main() {
    Animal* animal;

    Cachorro cachorro;
    Gato gato;

    animal = &cachorro;
    animal->som(); // Chama o método som() da classe Cachorro

    animal = &gato;
    animal->som(); // Chama o método som() da classe Gato

    return 0;
} 