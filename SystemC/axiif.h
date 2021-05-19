#ifndef AXIIF_H_
#define AXIIF_H_
#include <systemc.h>
#include <map>
#include <vector>
#include "rvc_common_model.h"
#include <iostream>
#include "bufcam.h"

class axiif: public sc_module{

    public:
    sc_in <sc_int<32> > axi_in;
    sc_int<32>        axi_test;
     sc_signal <sc_int<32>> axi2bufcam;

    void counter();
    SC_HAS_PROCESS(axiif);
    axiif(sc_module_name name);
    ~axiif();

    bufcam *bufc;
    // SC_METHOD(counter);
    // sensitive << axi_in;

    // void counter(){
    //     axi_test +=1;
    //     std::cout << "value of test counter = " << axi_test << std::endl;
    // }
};

#endif