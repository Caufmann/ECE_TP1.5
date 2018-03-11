#include "graphe.h"

Graphe::Graphe()
        :nbSommet(0)
{
    //ctor
}

Graphe::Graphe(std::string nomFichier)
        :nbSommet(0), m_nomFichier(nomFichier)
{

}

Graphe::~Graphe()
{
    //Liberation de memoire pour le vecteur de sommets
    for(auto temp : m_vectorSommets){
        delete temp;
    }

    //Liberation de memoire pour le vecteur d'aretes
    for(auto temp : m_vectorAretes){
        delete temp;
}
}

void Graphe::recupFichier()
{

}

void Graphe::ajouterSommet(std::string nomSommet)
{
    m_vectorSommets.push_back(new Sommet(nomSommet));
}
