#ifndef SOMMET_H
#define SOMMET_H

#include <string>

class Arete;

class Sommet
{
    private:
        std::string m_nomSommet;
        int m_numeroSommet;

    public:
        //Constructeur par defaut
        Sommet();

        //Constructeur surcharge
        Sommet(std::string nomSommet);

        //Destructeur
        virtual ~Sommet();

        //Getters
        std::string getNom() { return m_nomSommet; }
        int getNum() { return m_numeroSommet; }

        //Setters
        void setNom(std::string nomSom) { m_nomSommet = nomSom; }
        void setNumero(int numSom) { m_numeroSommet = numSom; }

        //Methodes

};

#endif // SOMMET_H
