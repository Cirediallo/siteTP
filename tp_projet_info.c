#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

#define MAX_NUMBER 6
#define MIN_NUMBER 1
#define SIMULATION_NUMBER 10
#define SIMULATION_MAX_EXPERIMENT 1000000
#define MIN_TOSSING 0
#define MAX_TOSSING 1
#define CENT 100
#define MILLE 1000

void coin_tossing_simulation()
{
  int randomNumber, 
      pile = 0,
      face = 0;

  for(int i = 0; i < SIMULATION_NUMBER; i++)
  {
     randomNumber = rand() % 2;

     if (randomNumber == 0)
     { 
	pile++;
     }	
     else 
     {
        face++;
     }
  }
  
  printf("pile = %d, face = %d\n", pile, face);
  
}

int dice_simulation(){
  //srand(time(NULL));
  int randomNumber = 0;
  for(int i = 0; i < SIMULATION_NUMBER; i++){
    randomNumber = rand() % (MAX_NUMBER - MIN_NUMBER);
  }
  return randomNumber;
}

void prob_10_throws_32(){
  int randomNumber = 0;
  int count_32 = 0;
  int toAdd = 0;

  for(int cpteur = 0; cpteur < SIMULATION_MAX_EXPERIMENT; cpteur++){

    toAdd = 0;

    for(int i = 0; i < SIMULATION_NUMBER; i++){

      randomNumber = rand() % 6 + 1;

      toAdd += randomNumber;
    }

    if(toAdd == 32){
      count_32++;
    }

    printf(" %d ",toAdd);
  }

  printf("Le nombre d'apparition de 32 est %d\n",count_32);
  printf("La probabilité d'apparition de 32 est: %f\n", (float)count_32/SIMULATION_MAX_EXPERIMENT);
}

void face_10_dice_simulation(){
  int apparenceFrequency[10] = {0};
  //int ret = dice_simulation();
  int randomNumber;
    for(int i = 0; i < MILLE; i++){

      randomNumber = rand() % 10 + 1;

      printf(" %d ",randomNumber);
      switch(randomNumber){
        case 1:
          apparenceFrequency[0]++;
          break;
        case 2:
          apparenceFrequency[1]++;
          break;
        case 3:
          apparenceFrequency[2]++;
          break;
        case 4:
          apparenceFrequency[3]++;
          break;
        case 5:
          apparenceFrequency[4]++;
          break;
        case 6:
          apparenceFrequency[5]++;
          break;
        case 7:
          apparenceFrequency[6]++;
          break;
        case 8:
          apparenceFrequency[7]++;
          break;
        case 9:
          apparenceFrequency[8]++;
          break;
        case 10:
          apparenceFrequency[9]++;
          break;
        default:
          printf("Eh ben c'est bizarre que ce message s'affiche\n");
          break;
      }
    }
    printf("\n===============  Sur une experience de %d lancé nous avons:\n",MILLE);
    for(int i = 0; i < 10; i++){
      printf("Frequence d'apparition de %d => %d\n",i+1,apparenceFrequency[i]);
    }
}

int main(){
  face_10_dice_simulation();
  //prob_10_throws_32();
  //coin_tossing_simulation();
  //dice_simulation();

  return EXIT_SUCCESS;
}
