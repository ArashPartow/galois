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
#include <vector>
#include "GaloisField.h"
#include "GaloisFieldElement.h"
#include "GaloisFieldPolynomial.h"


/*
   p(x) = 1x^8+1x^7+0x^6+0x^5+0x^4+0x^3+1x^2+1x^1+1x^0
          1    1    0    0    0    0    1    1    1
*/
unsigned int poly[9] = {1, 1, 0, 0, 0, 0, 1, 1, 1};
unsigned int poly1[3] = {1,1,1};

/*
  A Galois Field of type GF(2^8)
*/

galois::GaloisField gf(8,poly); //produces GF(2^8).
galois::GaloisField gf1(2,poly1); //produces GF(2^2).

galois::GaloisFieldElement gfe[10] = {
    galois::GaloisFieldElement(&gf, 1),
    galois::GaloisFieldElement(&gf, 2),
    galois::GaloisFieldElement(&gf, 3),
    galois::GaloisFieldElement(&gf, 4),
    galois::GaloisFieldElement(&gf, 5),
    galois::GaloisFieldElement(&gf, 6),
    galois::GaloisFieldElement(&gf, 7),
    galois::GaloisFieldElement(&gf, 8),
    galois::GaloisFieldElement(&gf, 9),
    galois::GaloisFieldElement(&gf,10)
                                     };

galois::GaloisFieldElement gfe1[4] = {
    galois::GaloisFieldElement(&gf, 1),
    galois::GaloisFieldElement(&gf, 1),
    galois::GaloisFieldElement(&gf, 1),
                                     };

galois::GaloisFieldPolynomial gfp(&gf, 8, gfe);
galois::GaloisFieldPolynomial gfp1(&gf, 2, gfe1);

bool is_root(galois::GaloisFieldPolynomial& p, galois::GFSymbol& a){
    return p(a) == 0;
}

std::vector<galois::GFSymbol> find_roots(galois::GaloisFieldPolynomial& p){
    std::vector<galois::GFSymbol> roots = {};

    for(galois::GFSymbol i = 0; i < gf.size()+1 ; i++){
        if(is_root(p, i)){
            roots.push_back(i);
        }
    }

    return roots;
}

int main(int argc, char *argv[])
{
    std::cout<< gf1 <<std::endl;
    std::cout<< "gfp1(x)=" << gfp1 <<std::endl;

    std::vector<galois::GFSymbol> roots = find_roots(gfp1);

    printf("gpf1 has %d roots.\n", roots.size());

    for(int i = 0; i < roots.size() ; i++){
        printf("gpf1(%d)=0\n", i);
    }
    printf("\n");

    exit(EXIT_SUCCESS);

    return 0;
}

