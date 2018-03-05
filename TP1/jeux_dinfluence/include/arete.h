#ifndef ARETE_H
#define ARETE_H

#include "sommet.h"

class Arete
{
    private:
        Sommet* m_SommetDepart;
        Sommet* m_SommetArrive;

    public:
        //Constructeur par défaut
        Arete();

        //Constructeur surcharge
        Arete(Sommet* SommetDepart, Sommet* SommetArrive);

        //Destructeur
        ~Arete();

        //Setters
        void setSommetDepart(Sommet* SommetDepart) { m_SommetDepart = SommetDepart; }
        void setSommetArrive(Sommet* SommetArrive) { m_SommetArrive = SommetArrive; }

        //Getters
        Sommet* getSommetDepart() { return m_SommetDepart; }
        Sommet* getSommetArrive() { return m_SommetArrive; }

        //Methodes

};

#endif // ARETE_H
