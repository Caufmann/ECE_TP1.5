#ifndef ARETE_H
#define ARETE_H

#include <iostream>
#include "sommet.h"

class Arete
{
    private:
        //Sommet de debut
        Sommet* m_SommetDepart;
        //Sommet de fin
        Sommet* m_SommetArrive;

    public:
        //Constructeur par défaut
        Arete();

        //Constructeur surcharge
        Arete(Sommet* SommetDepart, Sommet* SommetArrive);

        //Destructeur
        virtual ~Arete();

        //Getters
        Sommet* getSommetDepart() { return m_SommetDepart; }
        Sommet* getSommetArrive() { return m_SommetArrive; }

        //Setters
        void setSommetDepart(Sommet* SommetDepart) { m_SommetDepart = SommetDepart; }
        void setSommetArrive(Sommet* SommetArrive) { m_SommetArrive = SommetArrive; }

        //Methodes
        ///Fonction permettant de voir quel sommet est relié à quel autre sommet
        void afficheArete();


};

#endif // ARETE_H
