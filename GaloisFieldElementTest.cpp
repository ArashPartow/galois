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
#include "GaloisFieldElement.h"


/*
   p(x) = 1x^8+1x^7+0x^6+0x^5+0x^4+0x^3+1x^2+1x^1+1x^0
          1    1    0    0    0    0    1    1    1
*/
unsigned int poly[5] = {1,1,1,1,1};

/*
  A Galois Field of type GF(2^8)
*/

galois::GaloisField gf(4,poly);
galois::GaloisFieldElement gfe(&gf, 0);


int main(int argc, char *argv[])
{

    printf("Print out the element 5 of GF(4))\n");
    std::cout<< gfe <<std::endl;
    printf("\n");

    printf("Cycle through elemenents with 0 as the seed.\n");
    printf("Addition\n");
    for(galois::GFSymbol i = 0; i < gf.size()+1 ; i++){
        gfe += i;
        std::cout<< gfe <<std::endl;
    }
    printf("\n");

    printf("Subtraction\n");
    for(galois::GFSymbol i = 0; i < gf.size()+1 ; i++){
        gfe -= i;
        std::cout<< gfe <<std::endl;
    }
    printf("\n");

    gfe += 1;       // Add one to test multiplication and division.

    printf("Multiplication\n");
    for(galois::GFSymbol i = 1; i < gf.size()+1 ; i++){
        gfe *= i;
        std::cout<< gfe <<std::endl;
    }
    printf("\n");

    printf("Division\n");
    for(galois::GFSymbol i = 1; i < gf.size()+1 ; i++){
        gfe /= i;
        std::cout<< gfe <<std::endl;
    }
    printf("\n");

    gfe += 5;   // Re seed gfe to 5 for exponentiation.
    printf("Exponentiation\n");
    for(galois::GFSymbol i = 1; i < gf.size()+1 ; i++){
        gfe += 5;                   // This is to avoid having all 1s.
        gfe ^= i;
        std::cout<< gfe <<std::endl;
    }

    exit(EXIT_SUCCESS);

    return 0;
}

