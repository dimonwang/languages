#include<iostream>


int main(void) {
    int *** nnnn = 0;
    int *** const cnnn = 0;
    int ** const * ncnn = 0;
    int * const ** nncn = 0;
    int * const * const * nccn = 0;
    int const *** nnnc = 0;
    int const * const * const * const cccc = 0;
    ncnn = cnnn;
    ncnn = nnnn;
    nncn = cnnn;
    nccn = cnnn;
    nnnn = cnnn;
    nccn = nncn;
    nncn = nccn;
    // cccc = cnnn;


    // int dst = 100;
    // int *p1 = &dst;
    // int **pp1 = &p1;
    // int const *cp1 = p1;
    // int * const cp2 = p1;
    // *cp2 = 300;

    return 0;
}
