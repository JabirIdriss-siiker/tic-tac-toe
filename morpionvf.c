//@author Jabir Idriss
//Morpion tic-tac-toe

#include <stdlib.h>
#include <stdio.h>

void grille(char** morp, int lignes)// Fonction qui créer la grille du morpion
{
	int i,j;	
	printf("\n");

	for (i = 0; i < lignes; i++)
	{ 
		for (j = 0; j < lignes; j++)
		{
			printf("| %c  ",morp[i][j]);
		}
		printf("|");
		printf("\n");
	}
}
int remplissage(char** morp, int x, int y, int lignes)// Fonction qui permettra de servir de condition que la case est vide ou non
{	
	if(morp[x][y] != '_' && x >= 0 && y <= lignes-1)
	{	
		return 1;		
	}
    else
    {
        return 0;
    }
}

int testLigne(char** morp, int size)// Fonction qui permet de tester les lignes (Si tel ligne est rempli, alors c'est gagné)
{
    int i,j;
	 for(j=0;j<size;j++)
    {    
        for(i=0;i<size-1;i++)
        {
            if((morp[i][j]!=morp[i+1][j]) || (morp[i][j]=='_'))// On vérifie les lignes en avançant de 1 vers la droite en faisant i+1
            {
            	i=size-1;
            }
            else if (i==size-2)
            {
                return 1;
            }    
        }
    }
}
			
int testColonne(char** morp, int size)// Fonction qui permet de tester les colonnes (Si tel colonne est rempli, alors c'est gagné)
{
	int i,j;
    for(i=0;i<size;i++)
    {    
        for(j=0;j<size-1;j++)
        {
                if((morp[i][j]!=morp[i][j+1]) || (morp[i][j]=='_'))// On vérifie les colonnes en avançant de 1 vers le bas en faisant j+1
                {
                    j=size-1;
                }
                else if (j==size-2)
                {
                    return 1;
                }    
        }
    }
}

int diagonale_droite(char** morp,int size)// Fonction qui permet de tester la diagonale de droite  (Si la diagonal droite est rempli, alors c'est gagné)
{
    for(int i=0; i<size-1; i++)
    {
        if((morp[i][i]!=morp[i+1][i+1]) || (morp[i][i]=='_'))// On vérifie la diagonale droite en avançant de 1 vers la droite en faisant i+1 et en avançant de 1 vers le bas en faisant i+1 (dans le 2eme [])
        {
            i=size-1;
        }
        else if(i==size-2)
        {
            return 0;
        }
    }
    return 1;
}

int diagonale_gauche(char** morp,int size)// Fonction qui permet de tester la diagonale de gauche  (Si la diagonal gauche est rempli, alors c'est gagné)
{   
    for(int i=0; i<size-1; i++)
    {
        if((morp[i][size-1-i]!=morp[i+1][size-2-i]) || (morp[i][size-1-i]=='_'))// On vérifie la diagonale gauche en avançant de 1 vers la droite en faisant i+1 et en reculant de 2 par rapport à la taille du tableau et on soutrait i pour avoir la diagonal qui suit (dans le 2eme [])
        {
            i=size-1;
        }
        else if(i==size-2)
        {
            return 0;
        }
    }
    return 1;
}

int taille()// Fontion qui demande la taille du morpion à l'utilisateur	
{
	int lignes = 0;
	printf("Sur quel taille de Morpion souhaitez-vous jouer : ");
	scanf("%d",&lignes);
	return lignes;
}

void init(char** morp, int lignes)// Fonction qui initialise toute la grille (par défaut '_')
{
	int i;
	int n;

	for (i = 0; i < lignes; i++)
	{
		for (n = 0; n < lignes; n++)
		{
			morp[i][n] = '_';
		}
	}
}

int jeu(char** morp, int size)// Fonction qui assemble les fonctions de la grille, de remplissage et de test de victoire
{
	int x = 0;
	int y = 0;
    int morpion_libre=0;
    int cpt=0;// Le compteur permettra de voir si il y a une égalité, on l'a compare avec la taille du tableau
	grille(morp,size);
	int tailles = (size*size);// On multiplie size par elle-meme dans le but d'avoir la taille du tableau et de donc de pouvoir le comparer avec cpt en cas d'égalité

while (testLigne(morp,size) != 1 || testColonne(morp,size) != 1 || diagonale_gauche(morp,size) != 1 || diagonale_droite(morp,size) != 1)// On test si une ligne, une colonne ou une diagonale respecte les conditons de victoire, sinon on continue.
	{

		if (cpt > tailles || cpt == tailles)// Condition qui vérifie si il y a une égalité
		{
			grille(morp,size);
			printf("\nOops, il y a eu une egalite !\n");
			break;
		}
		else
		{
			printf("\nAu tour de Joueur 1 \n");
	        printf("Entrez votre lignes : ");
			scanf("%d", &x);
	        printf("Entrez votre colonnes : ");
			scanf("%d",&y);
			cpt = cpt + 1;

			while (remplissage(morp,x,y,size) == 1)// Si joueur 1 se met sur une case déjà prise par joueur 2, on lui demande de choisir une autre case
			{
				printf("La case est deja rempli, reesayez Joueur 1 : ");
				printf("Entrez votre lignes : ");
				scanf("%d", &x);
	        	printf("Entrez votre colonnes : ");
				scanf("%d",&y);
			}
			morp[x][y] = 'X';// Par rapport à la ligne et à la colonne, on ajoute le caractère 'x' de Joueur 2
		}

		if (cpt > tailles || cpt == tailles)// Condition qui vérifie si il y a une égalité
		{
			grille(morp,size);
			printf("Oops, il y a eu une egalite !\n");
			break;
		}
		else
		{
			if (testLigne(morp,size) == 1 || testColonne(morp,size) == 1 || diagonale_gauche(morp,size) !=1 || diagonale_droite(morp,size) != 1)// On test les lignes, les colonnes et les diagonales pour le joueur 1
			{
				printf("Le Joueur 1 gagne !\n");
				grille(morp,size);
				return 0;
			}
			
			grille(morp,size);
			printf("\nAu tour de Joueur 2 \n");
	        printf("Entrez votre lignes : ");
			scanf("%d", &x);
	        printf("Entrez votre colonnes : ");
			scanf("%d",&y);
			cpt = cpt + 1;
			
			while (remplissage(morp,x,y,size) == 1)// Si joueur 2 se met sur une case déjà prise par joueur 1, on lui demande de choisir une autre case
			{
				printf("La case est deja rempli, reesayez Joueur 2 \n");
				printf("Entrez votre lignes : ");
				scanf("%d", &x);
	        	printf("Entrez votre colonnes : ");
				scanf("%d",&y);
			}
			morp[x][y] = 'O';// Par rapport à la ligne et à la colonne, on ajoute le caractère 'O' de Joueur 2
			
			if (testLigne(morp,size) == 1 || testColonne(morp,size) == 1 || diagonale_gauche(morp,size) !=1 || diagonale_droite(morp,size) != 1)// On test les lignes, les colonnes et les diagonales pour le joueur 2
			{
				printf("Le Joueur 2 gagne !\n");
				grille(morp,size);
				return 0;
			}
			grille(morp,size);
		
			}
			
			if (morp[x][y] == 'X')
			{
				printf("Le Joueur 1 gagne !\n");
			}
			}
}
int main()
{
	int i;
	int lignes = taille();// On déclare lignes pour y mettre la fonction taille et pouvoir l'utiliser après dans l'allocution de mémoire
	char** morpion = (char**)malloc(lignes * sizeof(char*));// On alloue de la mémoire

	for (i = 0; i < lignes; i++)// On alloue de la mémoire
		morpion[i] = (char*)malloc(sizeof(char));
	
	init(morpion,lignes);// On initialise le morpion
	jeu(morpion,lignes);// Le jeu se lance !
}
