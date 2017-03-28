//
//  AttitudeControlSystem.hpp
//  Playground
//
//  Created by Andrew  on 3/25/17.
//  Copyright © 2017 Creator: Andrew Byron. All rights reserved.
//

#ifndef AttitudeControlSystem_hpp
#define AttitudeControlSystem_hpp

#include <stdio.h>
class AttitudeControlSystem {

    
public:
    AttitudeControlSystem();
    ~AttitudeControlSystem();

    enum actuator_type
    {
        Thruster_Pair, // 0
        Reaction_Wheel
    }actuator;
    
    float computeRotationalTime(float degrees);
    float computeSolarTorque(float SolarPressure, float area, float radiusToCM);
};

#endif /* AttitudeControlSystem_hpp */
