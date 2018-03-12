#ifndef GRAPHE_H
#define GRAPHE_H

#include "arete.h"

#include <vector>
#include <fstream>

class Graphe
{
    private:
        std::string m_nomFichier;
        int** m_matrice;
        std::vector <Arete*> m_vectorAretes;
        std::vector <Sommet*> m_vectorSommets;
        int m_nbSommet;

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
        int** getMatrice() { return m_matrice; }

        //Setters
        void setVecArete(std::vector <Arete*> vecArete) { m_vectorAretes = vecArete; }
        void setVecSommet(std::vector <Sommet*> vecSommet) { m_vectorSommets = vecSommet; }
        void setNbSommet(int nbSommet) { m_nbSommet = nbSommet; }
        void setNomFichier(std::string nomFichier) { m_nomFichier = nomFichier; }
        void setMatrice(int** matrice) { m_matrice = matrice; }

        //Methodes
        ///Fonction qui permet d'ajouter un sommet
        ///En entrée il a le nom du sommet a ajouter
        void ajoutSommet(std::string nomSommet);


        ///Fonction qui permet de recuperer les infos du fichier texte pour les utiliser
        ///Renvoie true si tout est ok
        bool recupFichier();

        ///Fonction qui permet d'allouer la memoire à la matrice
        ///Renvoie true si tout est ok
        bool allocationMatrice();

        ///Fonction qui permet de liberer la memoire allouée à la matrice
        ///Renvoie true si tout est ok
        bool liberationMatrice();


        ///Fonction qui permet d'ajouter les aretes
        ///En entrée on a les coordonnées pour le vecteur de d'aretes
        void ajoutArete(int a, int b);

        ///Fonction qui permet de relier les sommets entre eux pour former une arete
        void lierArete();

        ///Fonction permettant d'afficher les aretes
        void affichageArete();

        ///Fonction permettant d'afficher la matrice
        void affichageMatrice();

};

#endif // GRAPHE_H
