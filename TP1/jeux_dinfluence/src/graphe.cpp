#include "graphe.h"

Graphe::Graphe()
    :m_nbSommet(0), m_matrice(NULL)
{
    //ctor
}

Graphe::Graphe(std::string nomFichier)
    :m_nbSommet(0), m_matrice(NULL), m_nomFichier(nomFichier)
{

}

Graphe::~Graphe()
{
    //Liberation de la memoire allouée pour la matrice
    if(m_matrice != NULL)
    {
        liberationMatrice();
    }

    //Liberation de memoire allouée pour le vecteur de sommets
    for(auto temp : m_vectorSommets)
    {
        delete temp;
    }

    //Liberation de memoire allouée pour le vecteur d'aretes
    for(auto temp : m_vectorAretes)
    {
        delete temp;
    }
}

bool Graphe::allocationMatrice()
{

    //On verifie dans le cas où on n'a pas de sommet
    if(m_nbSommet == 0)
    {
        std::cerr << "Aucun sommet" << std::endl;
    }

    //Allocation memoire matrice
    m_matrice = new int*[m_nbSommet];
    for(int i = 0; i < m_nbSommet; i++)
    {
        m_matrice[i] = new int[m_nbSommet];
    }

    //Allocation réussie
    return true;
}

bool Graphe::liberationMatrice()
{

    //On verifie dans le cas où il n'y a pas de matrice
    if(m_matrice == NULL)
    {
        std::cerr << "Aucune matrice a desallouer" << std::endl;
    }

    //Liberation de la memoire allouée à la matrice
    for(int i = 0; i < m_nbSommet; i++)
    {
        delete m_matrice[i];
    }
    delete m_matrice;

    //Memoire libérée
    return true;
}

void Graphe::ajoutSommet(std::string nomSommet)
{
    m_vectorSommets.push_back(new Sommet(nomSommet));
}

bool Graphe::recupFichier()
{
    if(m_nomFichier == "")
    {
        std::cerr << "Le nom de fichier n'a pas de correspondance" << std::endl;
    }

    std::ifstream fichierCA(m_nomFichier, std::ios::in);

    if(fichierCA == NULL)
    {
        std::cerr << "Le fichier n'existe pas" << std::endl;
    }

    try
    {
        //Recuperation du nombre de sommets indiqués en debut du fichier
        fichierCA >> m_nbSommet;

        //Dans le cas où l'allocation echoue
        if( !allocationMatrice() )
        {
            return false;
        }

        std::string temp;

        //Ajout de des sommets au vecteur sommets
        for(int i = 0; i < m_nbSommet; i++)
        {
            fichierCA >> temp;
            ajoutSommet(temp);
        }

        //Recuperation de la matrice
        for(int i = 0 ; i < m_nbSommet; i ++)
        {
            for(int j = 0; j < m_nbSommet; j ++)
            {
                fichierCA >> m_matrice[i][j];

            }
        }

    }
    catch(...)
    {
        fichierCA.close();
        std::cerr << "Le format du fichier ne correspond pas" << std::endl;
    }

    fichierCA.close();

    return true;
}

void Graphe::affichageMatrice()
{
    std::cout << "La matrice est la suivante : \n" << std::endl;

    for(int i = 0 ; i < m_nbSommet; i ++)
    {
        std::cout << m_vectorSommets[i] -> getNom() << " ";
        for(int j = 0; j < m_nbSommet; j ++)
        {
            std::cout << m_matrice[i][j] <<" ";
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void Graphe::affichageArete()
{
    std::cout << "Les relations du conseil d'administration sont : \n" << std::endl;
    for(const auto elem : m_vectorAretes)
    {
        elem -> afficheArete();
        std::cout << std::endl;
    }

    std::cout << "\n Il n'a a plus de relations a afficher." << std::endl;
}

void Graphe::ajoutArete(int a, int b)
{
    m_vectorAretes.push_back(new Arete(m_vectorSommets[a], m_vectorSommets[b]));
}

void Graphe::lierArete()
{
    for(int i = 0; i < m_nbSommet; i++)
    {
        for(int j = 0; j < m_nbSommet; j++)
        {
            if(m_matrice[i][j] == 1)
            {
                ajoutArete(i, j);
            }
        }
    }
    std::cout << "Les aretes ont toutes ete ajoutees.\n" << std::endl;
}



