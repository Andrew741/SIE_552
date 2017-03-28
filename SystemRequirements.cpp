//
//  SystemRequirements.cpp
//  Playground
//
//  Created by Andrew  on 3/28/17.
//  Copyright © 2017 Creator: Andrew Byron. All rights reserved.
//

#include "SystemRequirements.hpp"
#include <math.h>
SystemRequirements::SystemRequirements()
{
    
}
SystemRequirements::~SystemRequirements()
{
    
}
void SystemRequirements::InitSciencePayload(Payload_type* Payload, int numItems)
{
    Payload_type tempPayload = *Payload;
    float tempMass = 0.0;
    float tempavgOrbPower = 0.0;
    float temppeakPower = 0.0;
    
    for (int i = 0; i < numItems; i++)
    {
        tempPayload = (Payload_type)*(&Payload)[i*sizeof(Payload_type)];
        tempMass        += tempPayload.mass;
        temppeakPower   += tempPayload.peak_power;
        tempavgOrbPower += tempPayload.orbital_avg_power;
    }
    this->orbital_Avg_Power = tempavgOrbPower;
    this->peakPower         = temppeakPower;
    this->payLoad_Mass      = tempMass;
    
}
void SystemRequirements::SetMassBudget()
{
    this->LaunchWeightCapability    = LAUNCH_WEIGHT_CAPABILITY;
    this->LaunchVehicleAdapterMass  = .755*this->payLoad_Mass + 50;
    this->SCMassatOrbitInsertion    = LAUNCH_WEIGHT_CAPABILITY - LaunchVehicleAdapterMass;
    this->PropellantNeeded = 1000*SCMassatOrbitInsertion*(1-expf(-ORBIT_INSERTION_DELTA_V/(ACC_GRAV*ISP)));
    this->MaxOnOrbitDryMass = this->SCMassatOrbitInsertion - this->PropellantNeeded;
    
    this->MaxBusMass = this->MaxOnOrbitDryMass - this->payLoad_Mass;
    
    this->TotalSubsystemMassforAllocation = this->MaxBusMass/(1 + MARGIN);
}
