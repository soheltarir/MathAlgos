/**
 * @file Probability.cpp
 * @brief 
 *        A function that generates one of 3 numbers according to given probabilities
 * @author Sohel Tarir
 * @version 1.0
 * @date 2014-09-18
 */
#include <stdio.h>
#include <stdlib.h>

// This function generates 'x' with probability px/100, 'y' with 
// probability py/100  and 'z' with probability pz/100:
// Assumption: px + py + pz = 100 where px, py and pz lie 
// between 0 to 100 
int randProb(int x, int y, int z, int px, int py, int pz)
{       
        // Generate a number from 1 to 100
        int r = rand() % 100 + 1;
      
        // r is smaller than px with probability px/100
        if (r <= px)
            return x;
 
         // r is greater than px and smaller than or equal to px+py 
         // with probability py/100 
        if (r <= (px+py))
            return y;
 
         // r is greater than px+py and smaller than or equal to 100 
         // with probability pz/100 
        else
            return z;
}

int main()
{
   int x,y,z;
   int px,py,pz;
   printf("ENter x\n");
   scanf("%d",&x);
   printf("ENter y\n");
   scanf("%d",&y);
   printf("ENter z\n");
   scanf("%d",&z);
   printf("ENter px\n");
   scanf("%d",&px);
   printf("ENter py\n");
   scanf("%d",&py);
   printf("ENter pz\n");
   scanf("%d",&pz);
   int ans=randProb(x,y,z,px,py,pz);
   printf("Yo %d\n",ans);
   return 0;
}
