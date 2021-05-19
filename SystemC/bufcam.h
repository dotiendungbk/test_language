#ifndef _BUFCAM_H_
#define _BUFCAM_H_

#include <systemc.h>
#include <map>
#include <vector>
#include "rvc_common_model.h"
#include    <iostream>

class bufcam: public sc_module, public rvc_common_model{

    public:
    sc_in <sc_int<32>> bufcam_in;
    sc_int<32>         bufcam_test;
    void counter();
    SC_HAS_PROCESS(bufcam);
    bufcam(sc_module_name name);
    ~bufcam(){};
};
#endif