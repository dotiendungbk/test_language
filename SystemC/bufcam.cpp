#include "bufcam.h"
bufcam::bufcam(sc_module_name name):sc_module(name){
    
    SC_METHOD(counter);
    dont_initialize();
    sensitive << bufcam_in;
}

void bufcam::counter(){
    bufcam_test = bufcam_in.read();
    std::cout << "the value of bufcam = " << bufcam_test << std::endl;
}