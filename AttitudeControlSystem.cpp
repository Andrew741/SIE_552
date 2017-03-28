//
//  AttitudeControlSystem.cpp
//  Playground
//
//  Created by Andrew  on 3/25/17.
//  Copyright © 2017 Creator: Andrew Byron. All rights reserved.
//

#include "AttitudeControlSystem.hpp"
#include <iostream>
#include <math.h>
AttitudeControlSystem::AttitudeControlSystem()
{
    
}
AttitudeControlSystem::~AttitudeControlSystem()
{
    
}
float AttitudeControlSystem::computeRotationalTime(float degrees)
{
    float time = -1.0;
    float momInertia = 1.0;
    float lengthToThruster = 1.0;
    int numThrusters = 2;
    float ThrusterForce = 22;
    // Assuming 3-axis-stabilized system
    // check if we are using an actuator or reaction wheels
    switch (this->actuator)
    {
        case Thruster_Pair:
            std::cout << "Assumption: using moment of inertia and length to thruster for spacecraft as unity. For future calculations use real numbers" << std::endl;
            time = sqrtf(momInertia*degrees/(float)numThrusters/ThrusterForce/lengthToThruster);
            break;
        case Reaction_Wheel:
            std::cout << "Reaction wheel processing not implemented" << std::endl;
            break;
        default:
            std::cout << "Error, unknown actuator type" << std::endl;
            
            
    }
    return time;
}
float AttitudeControlSystem::computeSolarTorque(float SolarPressure, float area, float radiusToCM)
{
    float SolarTorque = -1.0;
    float incidentAngleDEG = 0.0; // assuming normal to the surface
    float reflectivity = .3; // for absorbers via section 5.2.1.4
    // Total Solar Torque is defined as the sum of the torques due to absorption and reflection (specular and diffuse)
    float Absorbed = SolarPressure*area*cosf(incidentAngleDEG*M_PI/180.0); // eq 5.1
    float refSpec = 2*SolarPressure*area*cosf(incidentAngleDEG*M_PI/180.0);// eq 5.2
    float refDiff = Absorbed/3.0; // via section 5.2.1.3
    
    SolarTorque = (Absorbed + refSpec + refDiff)*area*(1 + reflectivity) * radiusToCM;
    
    return SolarTorque;
}

