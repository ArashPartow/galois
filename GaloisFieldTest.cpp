/*
  *********************************************************************
  *                                                                   *
  *               Galois Field Arithmetic Library                     *
  * Prototype: Galois Field LUT Test                                  *
  * Author: Arash Partow - 2000                                       *
  * URL: http://www.partow.net/projects/galois/index.html             *
  *                                                                   *
  * Copyright Notice:                                                 *
  * Free use of this library is permitted under the guidelines and    *
  * in accordance with the most current version of the Common Public  *
  * License.                                                          *
  * http://www.opensource.org/licenses/cpl.php                        *
  *                                                                   *
  *********************************************************************
*/


#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "GaloisField.h"


/*
   p(x) = 1x^8+1x^7+0x^6+0x^5+0x^4+0x^3+1x^2+1x^1+1x^0
          1    1    0    0    0    0    1    1    1
*/
unsigned int poly[4] = {1, 1, 1, 1};

/*
  A Galois Field of type GF(2^8)
*/

galois::GaloisField gf(3,poly);


int main(int argc, char *argv[])
{

    printf("The main purpose of this program is to show that the finite field\n");
    printf(" implimentation in C++ works as expected. These results should be\n");
    printf(" compared to known results for the relevant field.\n");

    printf("Properties of gf:\n");

    printf("size:\n");
    printf("ord(gf)=%d\n", gf.size());

    printf("The dimension of gf:\n");
    printf("dim(gf)=%d\n", gf.pwr());
    printf("\n");

    printf("Orders of elements:\n");
    for(int i = 0; i < gf.size()+1 ; i++){
        printf("ord(%d)=%d\n",i, gf.alpha(i));
    }
    printf("\n");

    printf("Addition.\n");
    for(int i = 0; i < gf.size()+1 ; i++){
        for(int j = 0; j < gf.size()+1 ; j++){
            printf("%d+%d=%d\n", i, j, gf.add(i,j));
        }
    }
    printf("\n");

    printf("Subtraction.\n");
    for(int i = 0; i < gf.size()+1 ; i++){
        for(int j = 0; j < gf.size()+1 ; j++){
            printf("%d-%d=%d\n", i, j, gf.sub(i,j));
        }
    }
    printf("\n");

    printf("Multiplication.\n");
    for(int i = 0; i < gf.size()+1 ; i++){
        for(int j = 0; j < gf.size()+1 ; j++){
            printf("%d*%d=%d\n", i, j, gf.mul(i,j));
        }
    }
    printf("\n");

    printf("Division.\n");
    for(int i = 0; i < gf.size()+1 ; i++){
        for(int j = 0; j < gf.size()+1 ; j++){
            printf("%d*%d^-1=%d\n", i, j, gf.div(i,j));
        }
    }
    printf("\n");

    printf("Expnentiation.\n");
    for(int i = 0; i < gf.size()+1 ; i++){
        for(int j = 0; j < gf.size()+1 ; j++){
            printf("%d^%d=%d\n", i, j, gf.exp(i,j));
        }
    }
    printf("\n");

    printf("Inversion.\n");
    for(int i = 0; i < gf.size()+1 ; i++){
        printf("%d^-1=%d\n", gf.inverse(i));
    }

   exit(EXIT_SUCCESS);

   return 0;
}

