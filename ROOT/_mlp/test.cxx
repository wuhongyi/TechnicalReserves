#include "test.h"
#include <cmath>

double test::Value(int index,double in0,double in1,double in2) {
   input0 = (in0 - 0.459987)/0.0509152;
   input1 = (in1 - 0.188581)/0.0656804;
   input2 = (in2 - 134.719)/16.5033;
   switch(index) {
     case 0:
         return neuron0x1c991e0();
     default:
         return 0.;
   }
}

double test::Value(int index, double* input) {
   input0 = (input[0] - 0.459987)/0.0509152;
   input1 = (input[1] - 0.188581)/0.0656804;
   input2 = (input[2] - 134.719)/16.5033;
   switch(index) {
     case 0:
         return neuron0x1c991e0();
     default:
         return 0.;
   }
}

double test::neuron0x1c859f0() {
   return input0;
}

double test::neuron0x1c85d30() {
   return input1;
}

double test::neuron0x1c96d10() {
   return input2;
}

double test::input0x1c97060() {
   double input = 1.78974;
   input += synapse0x1c97310();
   input += synapse0x1c97350();
   input += synapse0x1c97390();
   return input;
}

double test::neuron0x1c97060() {
   double input = input0x1c97060();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double test::input0x1c973d0() {
   double input = -0.17565;
   input += synapse0x1c97710();
   input += synapse0x1c97750();
   input += synapse0x1c97790();
   return input;
}

double test::neuron0x1c973d0() {
   double input = input0x1c973d0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double test::input0x1c977d0() {
   double input = 1.59447;
   input += synapse0x1c97b10();
   input += synapse0x1c97b50();
   input += synapse0x1c97b90();
   return input;
}

double test::neuron0x1c977d0() {
   double input = input0x1c977d0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double test::input0x1c97bd0() {
   double input = 1.26088;
   input += synapse0x1c97f10();
   input += synapse0x1c97f50();
   input += synapse0x1c97f90();
   return input;
}

double test::neuron0x1c97bd0() {
   double input = input0x1c97bd0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double test::input0x1c97fd0() {
   double input = -1.47209;
   input += synapse0x1c98310();
   input += synapse0x1c98350();
   input += synapse0x1c98390();
   return input;
}

double test::neuron0x1c97fd0() {
   double input = input0x1c97fd0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double test::input0x1c983d0() {
   double input = -1.07548;
   input += synapse0x1c98710();
   input += synapse0x1c98750();
   input += synapse0x1abcd50();
   input += synapse0x1abcd90();
   input += synapse0x1c988a0();
   return input;
}

double test::neuron0x1c983d0() {
   double input = input0x1c983d0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double test::input0x1c988e0() {
   double input = -1.29175;
   input += synapse0x1c98c20();
   input += synapse0x1c98c60();
   input += synapse0x1c98ca0();
   input += synapse0x1c98ce0();
   input += synapse0x1c98d20();
   return input;
}

double test::neuron0x1c988e0() {
   double input = input0x1c988e0();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double test::input0x1c98d60() {
   double input = 1.73506;
   input += synapse0x1c990a0();
   input += synapse0x1c990e0();
   input += synapse0x1c99120();
   input += synapse0x1c99160();
   input += synapse0x1c991a0();
   return input;
}

double test::neuron0x1c98d60() {
   double input = input0x1c98d60();
   return ((input < -709. ? 0. : (1/(1+exp(-input)))) * 1)+0;
}

double test::input0x1c991e0() {
   double input = 0.730952;
   input += synapse0x1c99400();
   input += synapse0x1c99440();
   input += synapse0x1c99480();
   return input;
}

double test::neuron0x1c991e0() {
   double input = input0x1c991e0();
   return (input * 1)+0;
}

double test::synapse0x1c97310() {
   return (neuron0x1c859f0()*-0.355968);
}

double test::synapse0x1c97350() {
   return (neuron0x1c85d30()*1.96518);
}

double test::synapse0x1c97390() {
   return (neuron0x1c96d10()*-2.48133);
}

double test::synapse0x1c97710() {
   return (neuron0x1c859f0()*-1.50229);
}

double test::synapse0x1c97750() {
   return (neuron0x1c85d30()*0.515171);
}

double test::synapse0x1c97790() {
   return (neuron0x1c96d10()*2.53801);
}

double test::synapse0x1c97b10() {
   return (neuron0x1c859f0()*0.419325);
}

double test::synapse0x1c97b50() {
   return (neuron0x1c85d30()*-0.203691);
}

double test::synapse0x1c97b90() {
   return (neuron0x1c96d10()*-2.67427);
}

double test::synapse0x1c97f10() {
   return (neuron0x1c859f0()*-3.05894);
}

double test::synapse0x1c97f50() {
   return (neuron0x1c85d30()*-3.62502);
}

double test::synapse0x1c97f90() {
   return (neuron0x1c96d10()*-0.048571);
}

double test::synapse0x1c98310() {
   return (neuron0x1c859f0()*-0.516819);
}

double test::synapse0x1c98350() {
   return (neuron0x1c85d30()*-3.44992);
}

double test::synapse0x1c98390() {
   return (neuron0x1c96d10()*1.02835);
}

double test::synapse0x1c98710() {
   return (neuron0x1c97060()*-1.93938);
}

double test::synapse0x1c98750() {
   return (neuron0x1c973d0()*-1.51327);
}

double test::synapse0x1abcd50() {
   return (neuron0x1c977d0()*-2.03467);
}

double test::synapse0x1abcd90() {
   return (neuron0x1c97bd0()*-1.36964);
}

double test::synapse0x1c988a0() {
   return (neuron0x1c97fd0()*1.46184);
}

double test::synapse0x1c98c20() {
   return (neuron0x1c97060()*-2.11641);
}

double test::synapse0x1c98c60() {
   return (neuron0x1c973d0()*1.00764);
}

double test::synapse0x1c98ca0() {
   return (neuron0x1c977d0()*1.764);
}

double test::synapse0x1c98ce0() {
   return (neuron0x1c97bd0()*-0.0770766);
}

double test::synapse0x1c98d20() {
   return (neuron0x1c97fd0()*-0.752908);
}

double test::synapse0x1c990a0() {
   return (neuron0x1c97060()*2.50398);
}

double test::synapse0x1c990e0() {
   return (neuron0x1c973d0()*-0.326893);
}

double test::synapse0x1c99120() {
   return (neuron0x1c977d0()*-0.556043);
}

double test::synapse0x1c99160() {
   return (neuron0x1c97bd0()*-0.924306);
}

double test::synapse0x1c991a0() {
   return (neuron0x1c97fd0()*-0.927853);
}

double test::synapse0x1c99400() {
   return (neuron0x1c983d0()*-2.35808);
}

double test::synapse0x1c99440() {
   return (neuron0x1c988e0()*2.4599);
}

double test::synapse0x1c99480() {
   return (neuron0x1c98d60()*-1.17076);
}

