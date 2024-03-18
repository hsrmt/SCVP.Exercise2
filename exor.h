#ifndef EXOR_H
#define EXOR_H

#include <systemc.h>

#include "nand.h"

// TODO: Insert your code here
SC_MODULE(exor)
{

    sc_in<bool> A, B;
    sc_out<bool> Z;

    sc_signal<bool> h1,h2,h3;
    nand n1,n2,n3,n4;

    void process(){

    }

    SC_CTOR(exor): A("A"), B("B"), Z("Z"), h1("h1"), h2("h2"), h3("h3"), n1("n1"), n2("n2"), n3("n3"), n4("n4")
    {

        n1.A(A);    
        n1.B(B);
        n1.Z(h1);


        n2.A(A);
        n2.B(h1);
        n2.Z(h2);

        n3.A(h1);
        n3.B(B);
        n3.Z(h3);


        n4.A(h2);
        n4.B(h3);
        n4.Z(Z);

        sensitive <<A<<B;
    }
};

#endif // EXOR_H
