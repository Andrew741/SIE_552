//
//  CThruster.hpp
//  Playground
//
//  Created by Andrew  on 2/24/17.
//  Copyright © 2017 Creator: Andrew Byron. All rights reserved.
//

#ifndef CThruster_hpp
#define CThruster_hpp

#include <stdio.h>
#include <string.h>

class CThruster
{

public:
    CThruster();// constructor
    CThruster(char Size,         float Thrust,   float thrustCoefficient,  float specificImpulse,
              float massFlowRate, float exitArea, float throatArea,         float exitPressure,
              float chamberPressure,              float chamberTemp,        float molecularWeight,
              float specificWeight,               float specificHeatRatio); // explicit initialization constructor
    ~CThruster();
    char Size;// S,M,L
    float Thrust;// Force, in Newtons
    float thrustCoefficient; //
    float specificImpulse;
    float massFlowRate;
    
    //Chamber variables
    float exitArea;
    float throatArea;
    float exitPressure;
    float chamberPressure;
    float chamberTemp;
    float molecularWeight;
    float specificWeight;
    float specificHeatRatio;
    float mixtureRatio;
    
    // Other variables
    float weight;
    void computeSpecificImpulse();
    void computeMassFlowRate();
    void computePressureRatio();
    void computeThrustCoefficient();
    void computeThroatArea();
    void computeThrusterWeight();
    
};

#endif /* CThruster_hpp */
