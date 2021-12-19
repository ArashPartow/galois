#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <vector>
#include "GaloisField.h"
#include "GaloisFieldElement.h"
#include "GaloisFieldPolynomial.h"

typedef long long Long;

using namespace std;
using namespace galois;

// Takes a polynomial p and a positive integer t, and returs p^t(x).
GaloisFieldPolynomial pow(GaloisFieldPolynomial &p, Long t){
    if(t == 1){
        return p;
    }

    return p*pow(p, t-1);
}

// Takes a polynomial p and a element a in GF(2^s) and checks if a is a root.
bool is_root(GFSymbol a, GaloisFieldPolynomial p){
    return p(a) == 0;
}

// takes a polynomial p and counts the roots of p, and stores them in a vector.
int count_roots(GaloisFieldPolynomial &p, GaloisField &gf, vector<GFSymbol> &roots){
    int freq_c = 0;
    GaloisFieldElement gfe (&gf);

    for(GFSymbol i = 0; i < gf.size()-1; i++){
        gfe = i;
        if(is_root(gfe.poly(), p)){
            freq_c++;

            roots.push_back(i);
        }
    }

    return freq_c;
}


int main(int argc, char *argv[]){
    int s = 8; // take 2^s. // upper bound at s=14 (Intel i5-9300H (8) @ 4.1GHz).
    int t = 4; // inititialize the degree t of x^t+(x+1)^t.



    // Create GF(2^2) with generator polynomial poly.
    unsigned int poly[t+1] = {1,1,1,1};
    GaloisField gf(s, poly);



    // Create polynomial x^t.

    GaloisFieldElement gfe1[t+1];

    // set a_0=...=a_t-1=0 for x^t. set a_t=1.
    for(int i = 0; i < t; i++){
        gfe1[i] = GaloisFieldElement (&gf,0);
    }
   gfe1[t] = GaloisFieldElement (&gf,1);

   GaloisFieldPolynomial gfp1(&gf, t, gfe1);

    // Create polynomial (x+1)^t.

    GaloisFieldElement gfe2[2]={
        GaloisFieldElement (&gf, 1),
        GaloisFieldElement (&gf, 1)
    };

   GaloisFieldPolynomial gfp2(&gf, 1, gfe2); // define gfp2 = x+1.
   gfp2 = pow(gfp2,t); // take gfp2^t.



   // Create constant c.

    GaloisFieldElement gfe_c[1]={
        GaloisFieldElement (&gf, 1)
    };
    GaloisFieldPolynomial gfp_c (&gf, 0, gfe_c);

    // Create the polynomial x^t+(x+1)^t-c.

    GaloisFieldPolynomial gfp = gfp1+gfp2-gfp_c;

    // initialize vector to store the roots.
    vector<GFSymbol> roots = {};

    int freq_c = count_roots(gfp, gf, roots);

    std::cout<< gfp << " has " << freq_c << " roots: " <<std::endl;

    return 0;
}
