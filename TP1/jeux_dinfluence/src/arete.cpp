#include "arete.h"

Arete::Arete()
{
    //ctor
}

Arete::Arete(Sommet* SommetDepart, Sommet* SommetArrive)
    : m_SommetDepart(SommetDepart), m_SommetArrive(SommetArrive)
{

}

Arete::~Arete()
{
    //dtor
}

void Arete::afficheArete()
{
    std::cout << m_SommetDepart -> getNom() << " influence " << m_SommetArrive -> getNom() << std::endl;
}
