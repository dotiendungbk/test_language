//#include "axiif.cpp"
// #include "bufcam.cpp"
#include "axiif.h"
#include <systemc.h>
#include <map>
#include <vector>
#include "rvc_common_model.h"
#include <iostream>

int sc_main(int argc, char* argv[]){

    sc_signal <sc_int<32> >  signal_a;
    sc_signal   <bool> signal_rst;

    axiif   axi("axiif");
    // // bufc = bufcam("bufcam");
     axi.axi_in(signal_a);
     signal_a.write(1);
     sc_start(20,SC_PS);
     signal_a.write(1);
    sc_start(20,SC_PS);
    signal_a.write(0);
    sc_start(20,SC_PS);
}