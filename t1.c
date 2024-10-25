#include <stdio.h>

typedef struct {
    char rue[50];
    char ville[50];
    int codePostal;
} Adresse;

typedef struct {
    char nom[50];
    int age;
    Adresse adresse;
} Personne;

int main() {
    Personne pers1[50];
    int nbpers = 0;
    int choix, i, indice;

    while (1) {
        printf("\n---------------Menu:-----------------\n");
        printf("1. Ajouter une personne\n");
        printf("2. Afficher toutes les personnes\n");
        printf("3. Modifier une personne\n");
        printf("4. Supprimer une personne\n");
        printf("5. Quitter\n");
        printf("Votre choix: ");
        scanf("%d", &choix);

        switch (choix) {
            case 1: 
                if (nbpers < 50) {
                    printf("Entrer les informations\n");
                    printf("Nom: ");
                    scanf("%s", pers1[nbpers].nom);
                    printf("Age: ");
                    scanf("%d", &pers1[nbpers].age);
                    printf("Ville: ");
                    scanf("%s", pers1[nbpers].adresse.ville);
                    printf("Rue: ");
                    scanf("%s", pers1[nbpers].adresse.rue);
                    printf("Code postal: ");
                    scanf("%d", &pers1[nbpers].adresse.codePostal);
                    nbpers++;
                } else {
                    printf("Tableau plein.\n");
                }
                break;

            case 2:
                if (nbpers == 0) {
                    printf("Aucune personne enregistrée.\n");
                } else {
                    printf("Liste des personnes:\n");
                    for (i = 0; i < nbpers; i++) {
                        printf("Personne %d:\n", i + 1);
                        printf("Nom: %s\n", pers1[i].nom);
                        printf("Age: %d ans\n", pers1[i].age);
                        printf("Adresse: %s, %s (%d)\n", pers1[i].adresse.ville, pers1[i].adresse.rue, pers1[i].adresse.codePostal);
                    }
                }
                break;

            case 3:
                if (nbpers == 0) {
                    printf("Aucune personne enregistrée.\n");
                } else {
                    printf("Entrer l'indice de la personne a modifier: ");
                    scanf("%d", &indice);
                    if (indice >= 1 && indice <= nbpers) {
                        indice--; 
                        printf("Nouvelles informations pour la personne %d :\n", indice + 1);
                        printf("Nom: ");
                        scanf("%s", pers1[indice].nom);
                        printf("Age: ");
                        scanf("%d", &pers1[indice].age);
                        printf("Ville: ");
                        scanf("%s", pers1[indice].adresse.ville);
                        printf("Rue: ");
                        scanf("%s", pers1[indice].adresse.rue);
                        printf("Code postal: ");
                        scanf("%d", &pers1[indice].adresse.codePostal);
                    } else {
                        printf("Indice invalide.\n");
                    }
                }
                break;

            case 4:
                if (nbpers == 0) {
                    printf("Aucune personne a supprimer.\n");
                } else {
                    printf("Entrez l'indice de la personne a supprimer: ");
                    scanf("%d", &indice);
                    if (indice >= 1 && indice <= nbpers) {
                        indice--; 
                        for (i = indice; i < nbpers - 1; i++) {
                            pers1[i] = pers1[i + 1];
                        }
                        nbpers--;
                        printf("Personne supprimee.\n");
                    } else {
                        printf("Indice invalide.\n");
                    }
                }
                break;

            case 5:
                printf("Au revoir!\n");
                return 0;

            default:
                printf("Choix invalide.\n");
        }
    }

    return 0;
}
