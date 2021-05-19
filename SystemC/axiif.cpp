#include     "axiif.h"
axiif::axiif(sc_module_name name):sc_module(name){
    bufc = new bufcam("bufcam");
    bufc->bufcam_in(axi2bufcam);
    SC_METHOD(counter);
    dont_initialize();
    sensitive << axi_in;
}

void axiif::counter(){
    axi_test += 1;
    axi2bufcam.write(axi_test);
    std::cout << "the value of counter = " << axi_test << std::endl;
}
axiif::~axiif(){
    return;
}