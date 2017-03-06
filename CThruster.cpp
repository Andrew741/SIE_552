//
//  CThruster.cpp
//  Playground
//
//  Created by Andrew  on 2/24/17.
//  Copyright © 2017 Creator: Andrew Byron. All rights reserved.
//
 /********************************
  * This file was made as a supplement 
  * to SIE 552 Space Systems Engineering
  * Assignment 4 which deals with 
  * thruster and propulsion systems.
  *******************************/
#include "CThruster.hpp"
#include <math.h>
#define SPECIFIC_GAS_CONSTANT    1545   //ft*lbs/lbs(mass) * Mole * degree Kelvin
#define GRAV_CONSTANT_ENGLISH    32.174 //ft/s
CThruster::CThruster()
{
    // constructor
    this->Size = 'U';
    this->Thrust = 0.0;
    this->thrustCoefficient = 0.0;
    this->specificImpulse = 0.0;
    this->massFlowRate = 0.0;
    this->exitArea = 0.0;
    this->throatArea = 0.0;
    this->exitPressure = 0.0;
    this->chamberPressure = 0.0;
    this->chamberTemp = 0.0;
    this->molecularWeight = 0.0;
    this->specificWeight = 0.0;
    this->specificHeatRatio = 0.0;
    
}
CThruster::CThruster(char Size,         float Thrust,   float thrustCoefficient,  float specificImpulse,
                    float massFlowRate,  float exitArea, float throatArea,         float exitPressure,
                    float chamberPressure,               float chamberTemp,        float molecularWeight,
                    float specificWeight,                float specificHeatRatio)
{
    
    this->Size = Size;
    this->Thrust = Thrust;
    this->thrustCoefficient = thrustCoefficient;
    this->specificImpulse = specificImpulse;
    this->massFlowRate = massFlowRate;
    this->exitArea = exitArea;
    this->throatArea = throatArea;
    this->exitPressure = exitPressure;
    this->chamberPressure = chamberPressure;
    this->chamberTemp = chamberTemp;
    this->molecularWeight = molecularWeight;
    this->specificWeight = specificWeight;
    this->specificHeatRatio = specificHeatRatio;
}
CThruster::~CThruster()
{
    // destructor
}

void CThruster::computeSpecificImpulse()
{
    float k = this->specificHeatRatio;
    float Tc = this->chamberTemp;
    float PressureRatio = (this->exitPressure/this->chamberPressure);
    float AreaRatio = (this->exitArea/this->throatArea);

    if (this->massFlowRate >= 0)
    {
        // have already computed mass flow rate, so just use the easy way.
        this->specificImpulse = this->Thrust/ this->massFlowRate;
        
        
    }
    else
    {
        // haven't initialized mass flow rate yet. do it now
        // do it the hard way
        
        // two stage computation for readability
        this->specificImpulse = sqrtf(   2*k*SPECIFIC_GAS_CONSTANT*Tc* (1 - powf(PressureRatio, (k - 1)/k) ) /(GRAV_CONSTANT_ENGLISH*(k - 1))     );
        this->specificImpulse += (PressureRatio*AreaRatio)*sqrtf(SPECIFIC_GAS_CONSTANT*Tc)/((GRAV_CONSTANT_ENGLISH*k * powf( 2/(k + 1) , (k + 1)/k - 1)) );

        //printf("\n\r Specific Impulse = %f",this->specificImpulse);
        
    }
    
}
void CThruster::computePressureRatio()
{
    // assume that we have the area ratio
    // and that we are looking for the exit pressure
    
    float k = this->specificHeatRatio;
    float areaRatio = this->exitArea/this->throatArea;
    // don't like including temp variables in member functions, but gonna need to for readability
    float tempExitPressure = 0;
    float estimatedPressureRatio = tempExitPressure/this->chamberPressure;
    float numerator = 0;//sqrtf(k*powf((2/(k + 1)),(k+1)/(k-1)));
    float denominator = 0;//powf(estimatedPressureRatio,1/k)*sqrtf(2*k*powf(1 - (estimatedPressureRatio),(k-1)/k)/(k-1));
    bool achieved = false;
    float tempAreaRatio = 0.0;
    float tolerance = 10.0;
    int attempts = 1000;
    
    float tempEXP = 0.0;
    float tempBASE = 0.0;
    float tempRes = 0.0;

    while (!achieved && attempts > 0)
    {
        tempAreaRatio = numerator/denominator;
        if (tempAreaRatio >= (areaRatio - tolerance) && tempAreaRatio <= (areaRatio + tolerance))
        {
            achieved = true;
            this->exitPressure = estimatedPressureRatio*this->chamberPressure;
            printf("\n\r EXIT PRESSURE = %f found after %d attempts resulting in Area Ratio of %f\n\r", this->exitPressure, 1000-attempts, tempAreaRatio);
            break; // unnecessary but included for good measure
            
        }
        else
        {
            tempExitPressure += 0.10;
            estimatedPressureRatio = tempExitPressure/this->chamberPressure;
            numerator = sqrtf(k*powf((2/(k + 1)),(k+1)/(k-1)));
            tempBASE = estimatedPressureRatio;
            tempEXP = 1/k;
            tempRes = powf(tempBASE,tempEXP);
            denominator = tempRes;
            tempBASE = 1 - estimatedPressureRatio;
            tempEXP = (k-1)/k;
            tempRes = powf(tempBASE,tempEXP);
            denominator = denominator*sqrtf(2*k*tempRes/(k-1));

            attempts--;
            //printf("\n\rATTEMPT: %d \nestPressRatio = %f\n,numerator = %f\n, denom = %f\n, tempAreaRatio = %f\n",attempts,estimatedPressureRatio,numerator,denominator, numerator/denominator);
        }
        
    }

}
void CThruster::computeThroatArea()
{
    // Assuming that we already have F, Isp, and Cf...
    this->throatArea = this->Thrust/ (this->thrustCoefficient*this->chamberPressure);
}
void CThruster::computeThrustCoefficient()
{
    float Pe_c    = this->exitPressure/this->chamberPressure;
    float k     = this->specificHeatRatio;
    
    this->thrustCoefficient = sqrtf(2*powf(k,2)*powf(2/(k+1),(k+1)/(k-1))*(1 - powf(Pe_c,(k-1)/k) )/(k-1) );
    this->thrustCoefficient += Pe_c*this->exitArea/this->throatArea;
}
void CThruster::computeMassFlowRate()
{
    // Assume throat area is
    float Pc    = this->chamberPressure;
    float k     = this->specificHeatRatio;
    float Tc    = this->chamberTemp;
    
    this->massFlowRate = Pc*this->throatArea*k*sqrtf( powf(2/(k+1),(k+1)/(k-1)))/sqrtf(k*SPECIFIC_GAS_CONSTANT*Tc);
    //debug
    printf("\n\r Mass flow rate = %f", this->massFlowRate);
}
void CThruster::computeThrusterWeight()
{
    this->weight = .4 + this->Thrust*0.0033;
}
