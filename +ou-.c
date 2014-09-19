#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 1000
#define MIN 1

int demander (int nbr_aleatoire);

int main(void)
 {
   int number,
       essai;

   srand(time(NULL));
   number = rand();
   
   srand(time(NULL));
   number = (rand() % (MAX - MIN + 1)) + MIN;
   printf("Devinette d'un nombre aleatoire\n");
   essai = demander(number);
   
   printf("Felicitations ! Vous avez trouve la reponse [%d] en %d essais !\n", number, essai);
   
   system ("pause");
   return 0;
 }

int demander (int nbr_aleatoire)
{
  int nb_entre,
      nbr_essai = 0,
      bmax=32767,
      bmin=0;
  
  do
  {
    do
    {
      printf("Entrez un nombre entre %d et %d : ", bmin, bmax);    
      scanf("%d", &nb_entre);
    } while ((nb_entre<0)||(nb_entre>32767));
    
    nbr_essai++;
    
    if (nbr_aleatoire > nb_entre)
       {
         printf("Ce nombre est trop petit !\n");
         if(bmin < nb_entre)
           bmin = nb_entre;
       }
    else
       if (nbr_aleatoire < nb_entre)
          {
            printf("Ce nombre est trop grand !\n");
            if(bmax > nb_entre)
              bmax = nb_entre;
          }
  }
  while (nbr_aleatoire != nb_entre);
  
  return(nbr_essai);
}
