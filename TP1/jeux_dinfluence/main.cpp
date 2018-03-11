#include "graphe.h"

int main()
{
    std::string nomF;

    std::cout << "Veuillez entrer le nom du fichier a charger : " << std::endl;

    //Le nom du fichier a entrer est "ConseilAdministration.txt"
    std::cin >> nomF;

    Graphe CA(nomF);

    if(( &CA ) -> recupFichier())
    {
        ( &CA ) -> affichageMatrice();
        ( &CA ) -> lierArete();
        ( &CA ) -> affichageArete();
    }

    return 0;
}
