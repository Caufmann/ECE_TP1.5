#ifndef GRAPHE_H
#define GRAPHE_H

#include "arete.h"

#include <vector>
#include <fstream>

class Graphe
{
    private:
        std::vector <Arete*> m_vectorAretes;
        std::vector <Sommet*> m_vectorSommets;
        int m_nbSommet;
        std::string m_nomFichier;

    public:
        //Constructeur par defaut
        Graphe();

        //Constructeur surchargé
        Graphe(std::string nomFichier);

        //Destructeur
        virtual ~Graphe();

        //Getters
        std::vector <Arete*> getVecArete() { return m_vectorAretes; }
        std::vector <Sommet*> getVecSommet() { return m_vectorSommets; }
        int getNbSommet() { return m_nbSommet; }
        std::string getNomFichier() { return m_nomFichier; }

        //Setters
        void setVecArete(std::vector <Arete*> vecArete) { m_vectorAretes = vecArete; }
        void setVecSommet(std::vector <Sommet*> vecSommet) { m_vectorSommets = vecSommet; }
        void setNbSommet(int nbSommet) {m_nbSommet = nbSommet; }
        void setNomFichier(std::string nomFichier) {m_nomFichier = nomFichier; }

        //Methodes
        ///Fonction qui permet d'ajouter un sommet
        ///En entrée il faut lui fournir un nom pour le sommet qui va être ajouté
        void ajouterSommet(std::string nomSommet);
        ///Fonction qui permet de recuperer les infos du fichier texte pour les utiliser
        void recupFichier();

};

#endif // GRAPHE_H
