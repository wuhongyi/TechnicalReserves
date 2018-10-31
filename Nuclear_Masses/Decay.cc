// Decay.cc --- 
// 
// Description: 
// Author: Hongyi Wu(吴鸿毅)
// Email: wuhongyi@qq.com 
// Created: 三 10月 31 19:25:10 2018 (+0800)
// Last-Updated: 三 10月 31 19:54:57 2018 (+0800)
//           By: Hongyi Wu(吴鸿毅)
//     Update #: 12
// URL: http://wuhongyi.cn 

void Decay()
{
  // Random number generator
  TRandom3 theRandomGenerator;

  // Event generator TGenPhaseSpace
  TGenPhaseSpace theEvent;
  
  // Mass values
  double MassProton = 9.382720e+02; //MeV
  double Mass16Ne = 1.492278e+04; //MeV
  double Mass17Na = Mass16Ne+MassProton; //MeV. Approximation last proton zero-binding energy
  double Mass18Na = Mass17Na+MassProton; //MeV. Approximation last proton zero-binding energy
  double Mass14O = 1.304484e+04; //MeV
  
  // Simulation of 18Mg decay in p+17Na*(3.00 MeV) ---------------
  int event = 10000;
  for (int i = 0; i < event; ++i)
    {
      // Quadri-Momentum of 18Mg*(5.506)
      double Ex18Mg = 5.506; // MeV
      double EKin18Mg = theRandomGenerator.Uniform(0,100); // MeV, uniformly ditributed 0 -> 100 MeV
      double ETot18Mg = EKin18Mg + Mass18Na + Ex18Mg;
      double P18Mg = sqrt(pow(ETot18Mg,2)-pow(Mass18Na + Ex18Mg,2)); //MeV/c
      double theta18Mg = 0.; //rad
      double phi18Mg = 0.; //rad
      double Ex17Na = 3.; //MeV
  
      TLorentzVector q18Mg (P18Mg*sin(theta18Mg)*cos(phi18Mg), P18Mg*sin(theta18Mg)*sin(phi18Mg), P18Mg*cos(theta18Mg), ETot18Mg);  // (MeV/c, MeV)

      
      int NumParticles18Mg=2;
      double masses18Mg[NumParticles18Mg];
      masses18Mg[0]=MassProton; //mass of first particle in MeV/c2
      masses18Mg[1]=Mass17Na+Ex17Na; //mass of the second particle in MeV/c2, consider also the excitation energy
  
      //Set the decay
      Bool_t flag = theEvent.SetDecay(q18Mg, NumParticles18Mg, masses18Mg,"");
  
      //Generate the decay
      Double_t weight = theEvent.Generate();
  
      //Get the particles from the decay
      TLorentzVector * qproton18Mg = theEvent.GetDecay(0);
      TLorentzVector * q17Na18Mg = theEvent.GetDecay(1);

      std::cout<<EKin18Mg<<" "<<weight<<" "<<q18Mg.M()<<" "<<qproton18Mg->M()<<" "<<q17Na18Mg->M()<<std::endl;
      if(flag==false) std::cout<<i<<std::endl;
    }


  
}

// 
// Decay.cc ends here
