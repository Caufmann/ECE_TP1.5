#ifndef SOMMET_H
#define SOMMET_H

#include <string>

class Arete;

class Sommet
{
    private:
        std::string m_nomSommet;

    public:
        //Constructeur par defaut
        Sommet();

        //Constructeur surcharge
        Sommet(std::string nomSommet);

        //Destructeur
        ~Sommet();

        //Setters
        void setNom(std::string nomSom) { m_nomSommet = nomSom; }

        //Getters
        std::string getNom() { return m_nomSommet; }

        //Methodes

};

#endif // SOMMET_H
