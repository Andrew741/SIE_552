//
//  main.cpp
//  Assignment 4
//
//  Created by Andrew  on 2/11/17.
//  Copyright © 2017 Creator: Andrew Byron. All rights reserved.
//

#include <iostream>
#include <fstream> // for submitting hw
#include <math.h>
#include "CThruster.hpp"

int main(int argc, const char * argv[]) {
  
    int numLarge    = 6;
    int numMedium   = 6;
    int numSmall    = 12;
    
    // Thruster Analysis and Sizing
    std::ofstream fwriter ("./Assignment_4.txt", std::ofstream::out); // append to the file.
    if (fwriter.is_open())
    {
//        std::cout << " NO PROBLEM YO" << std::endl;
//        fwriter << " SAMPLE" << std::endl;
//        std::ifstream tester ("./Assignment_4.txt", std::ifstream::in);
//        if (fwriter.is_open())
//        {
//            char c = tester.get();
//            
//            while (tester.good()) {
//                std::cout << c;
//                c = tester.get();
//            }
//        }
    }
    // A: 6 large thrusters  (170N thrust each)
    // B: 6 medium thrusters (22N thrust each)
    // C: 12 small thrusters (.9N thrust each)
    
    // Assume monomethyl hydrazine
    
    /*
     * Initialization parameters
     */
    char Size = 'L';// S,M,L
    
    float Thrust            = 170;// Force, in Newtons
    float thrustCoefficient = -1; // TO BE COMPUTED
    float specificImpulse   = -1;
    float massFlowRate      = -1;
    
    //Chamber variables
    float exitArea          = 50; // only a ratio given so make it easy to work with
    float throatArea        = 1;
    float exitPressure      = -1;
    float chamberPressure   = 450;// psi
    float chamberTemp       = 2210; // this is in degrees R; 1750 Kelvin
    float molecularWeight   = 13;// in lbs
    float specificWeight    = -1;
    float specificHeatRatio = 1.27;// book mentioned 1.27
    
    /*
     * area ratio       = 50
     * chamber pressure = 450 psi
     *
     */
    
    CThruster* thrusterLarge = new CThruster(Size,Thrust,thrustCoefficient,specificImpulse,massFlowRate,exitArea,throatArea,exitPressure,chamberPressure,chamberTemp,molecularWeight,specificWeight,specificHeatRatio);
    
    // compute specific impulse for each
    thrusterLarge->computePressureRatio();
    thrusterLarge->computeSpecificImpulse();
    thrusterLarge->computeMassFlowRate();
    thrusterLarge->computeThrustCoefficient();
    thrusterLarge->computeThroatArea();
    thrusterLarge->computeThrusterWeight();
    
    // Now for the Medium Thruster set
     Size = 'M';// S,M,L
    
     Thrust            = 22;// Force, in Newtons
    CThruster* thrusterMedium = new CThruster(Size,Thrust,thrustCoefficient,specificImpulse,massFlowRate,exitArea,throatArea,exitPressure,chamberPressure,chamberTemp,molecularWeight,specificWeight,specificHeatRatio);
    
    // compute specific impulse for each
    thrusterMedium->computePressureRatio();
    thrusterMedium->computeSpecificImpulse();
    thrusterMedium->computeMassFlowRate();
    thrusterMedium->computeThrustCoefficient();
    thrusterMedium->computeThroatArea();
    thrusterMedium->computeThrusterWeight();
    
    // Now for the Medium Thruster set
    Size = 'S';// S,M,L
    
    Thrust            = .9;// Force, in Newtons
    CThruster* thrusterSmall = new CThruster(Size,Thrust,thrustCoefficient,specificImpulse,massFlowRate,exitArea,throatArea,exitPressure,chamberPressure,chamberTemp,molecularWeight,specificWeight,specificHeatRatio);
    
    // compute specific impulse for each
    thrusterSmall->computePressureRatio();
    thrusterSmall->computeSpecificImpulse();
    thrusterSmall->computeMassFlowRate();
    thrusterSmall->computeThrustCoefficient();
    thrusterSmall->computeThroatArea();
    thrusterSmall->computeThrusterWeight();
    fwriter << "A.a" << std::endl;
    fwriter << "------------------------------------------------------" << std::endl;
    fwriter<< " The specific Impulse (Isp) for a large Thruster is " << thrusterLarge->specificImpulse << std::endl;
    fwriter<< " Thus, for a group of " << numLarge << " Large thrusters the total Isp is " <<thrusterLarge->specificImpulse*numLarge << std::endl;
    fwriter<< " The specific Impulse (Isp) for a medium Thruster is " << thrusterMedium->specificImpulse << std::endl;
    fwriter << " Thus, for a group of " << numMedium << " Medium thrusters the total Isp is " <<thrusterMedium->specificImpulse*numMedium << std::endl;
    fwriter<< " The specific Impulse (Isp) for a small Thruster is " << thrusterSmall->specificImpulse << std::endl;
    fwriter << " Thus, for a group of " << numSmall << " Small thrusters the total Isp is " <<thrusterSmall->specificImpulse*numSmall << std::endl;
    
    fwriter<< "A.b" << std::endl;
    fwriter << "------------------------------------------------------" << std::endl;
    fwriter << " The Thruster Coefficient and Throat area for each set is as follows: " << std::endl;
    fwriter << "       Throat Area:      Thruster Coefficient:" << std::endl;
    fwriter << "Large :    "<<thrusterLarge->throatArea<<"\t\t"<<thrusterLarge->thrustCoefficient<<std::endl;
    fwriter << "Medium:    "<<thrusterMedium->throatArea<<"\t\t"<<thrusterMedium->thrustCoefficient<<std::endl;
    fwriter << "Small :    "<<thrusterSmall->throatArea<<"\t"<<thrusterSmall->thrustCoefficient<<std::endl;
    
    fwriter << "A.c" << std::endl;
    fwriter << "------------------------------------------------------" << std::endl;
    fwriter << " The steady state Isp and pulsing Isp for each set is as follows: " << std::endl;
    fwriter << "       Steady State:      Pulsing:" << std::endl;
    fwriter << "Large :    "<<thrusterLarge->specificImpulse*.93<<"\t\t"<<thrusterLarge->specificImpulse*.50<<std::endl;
    fwriter << "Medium:    "<<thrusterMedium->specificImpulse*.93<<"\t\t"<<thrusterMedium->specificImpulse*.50<<std::endl;
    fwriter << "Small :    "<<thrusterSmall->specificImpulse*.93<<"\t\t"<<thrusterSmall->specificImpulse*.50<<std::endl;
    
    fwriter << "A.d" << std::endl;
    fwriter << "------------------------------------------------------" << std::endl;
    fwriter << " The estimated thruster mass for each set is as follows: " << std::endl;
    fwriter << "Large :    "<<thrusterLarge->weight<<std::endl;
    fwriter << "Medium:    "<<thrusterMedium->weight<<std::endl;
    fwriter << "Small :    "<<thrusterSmall->weight<<std::endl;
    // Part B Mixtures
     Size = 'L';// S,M,L
    
     Thrust            = 170;// Force, in Newtons
     thrustCoefficient = -1; // TO BE COMPUTED
     specificImpulse   = -1;
     massFlowRate      = -1;
    float mixtureRatio = 1.6;
    
    //Chamber variables
     exitArea          = 90; // only a ratio given so make it easy to work with
     throatArea        = 1;
     exitPressure      = -1;
     chamberPressure   = 300;// psi
     chamberTemp       = 2210; // this is in degrees R; 1750 Kelvin
     molecularWeight   = 13;// in lbs
     specificWeight    = -1;
     specificHeatRatio = 1.27;// book mentioned 1.27
    
    
    // B
    fwriter << " B.a" << std::endl;
    fwriter << "------------------------------------------------------" << std::endl;
    fwriter<< " The specific Impulse (Isp) for a large Thruster is " << thrusterLarge->specificImpulse << std::endl;
    fwriter<< " Thus, for a group of " << numLarge << " Large thrusters the total Isp is " <<thrusterLarge->specificImpulse*numLarge << std::endl;
    fwriter<< " The specific Impulse (Isp) for a medium Thruster is " << thrusterMedium->specificImpulse << std::endl;
    fwriter << " Thus, for a group of " << numMedium << " Medium thrusters the total Isp is " <<thrusterMedium->specificImpulse*numMedium << std::endl;
    fwriter<< " The specific Impulse (Isp) for a small Thruster is " << thrusterSmall->specificImpulse << std::endl;
    fwriter << " Thus, for a group of " << numSmall << " Small thrusters the total Isp is " <<thrusterSmall->specificImpulse*numSmall << std::endl;
    
    fwriter<< "B.b" << std::endl;
    fwriter << "------------------------------------------------------" << std::endl;
    fwriter << " The Thruster Coefficient and Throat area for each set is as follows: " << std::endl;
    fwriter << "       Throat Area:      Thruster Coefficient:" << std::endl;
    fwriter << "Large :    "<<thrusterLarge->throatArea<<"\t\t"<<thrusterLarge->thrustCoefficient<<std::endl;
    fwriter << "Medium:    "<<thrusterMedium->throatArea<<"\t\t"<<thrusterMedium->thrustCoefficient<<std::endl;
    fwriter << "Small :    "<<thrusterSmall->throatArea<<"\t"<<thrusterSmall->thrustCoefficient<<std::endl;
    
    fwriter << "B.c" << std::endl;
    fwriter << "------------------------------------------------------" << std::endl;
    fwriter << " The steady state Isp and pulsing Isp for each set is as follows: " << std::endl;
    fwriter << "       Steady State:      Pulsing:" << std::endl;
    fwriter << "Large :    "<<thrusterLarge->specificImpulse*.93<<"\t\t"<<thrusterLarge->specificImpulse*.50<<std::endl;
    fwriter << "Medium:    "<<thrusterMedium->specificImpulse*.93<<"\t\t"<<thrusterMedium->specificImpulse*.50<<std::endl;
    fwriter << "Small :    "<<thrusterSmall->specificImpulse*.93<<"\t\t"<<thrusterSmall->specificImpulse*.50<<std::endl;
    
    fwriter << "------------------------------------------------------" << std::endl;
    fwriter << " Steady State Requirement Review " << std::endl;
    fwriter << " Large: " << thrusterLarge->specificImpulse*32.174*log(2212/656);
    fwriter << " Medium: " << thrusterMedium->specificImpulse*32.174*log(2212/656);
    fwriter << " Small: " << thrusterSmall->specificImpulse*32.174*log(2212/656);
    fwriter.close();
    
    return 0;
}
