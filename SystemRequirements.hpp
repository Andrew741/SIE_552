//
//  SystemRequirements.hpp
//  Playground
//
//  Created by Andrew  on 3/28/17.
//  Copyright © 2017 Creator: Andrew Byron. All rights reserved.
//

#ifndef SystemRequirements_hpp
#define SystemRequirements_hpp

#include <stdio.h>
#define LAUNCH_WEIGHT_CAPABILITY    2335    // Kgs
#define ORBIT_INSERTION_DELTA_V     2       // km/s
#define ACC_GRAV                    9.8     // m/s^2
#define ISP                         290
#define MARGIN                      .3
class SystemRequirements {
    
    
public:
    SystemRequirements();
    ~SystemRequirements();
    
    float payLoad_Mass;
    float orbital_Avg_Power;
    float peakPower;
    float data_OutputRate;
    float pointingRequirement;// string?
    
    float LaunchWeightCapability;
    float LaunchVehicleAdapterMass;
    float SCMassatOrbitInsertion;
    float PropellantNeeded;
    float MaxOnOrbitDryMass;
    float MaxBusMass;
    float TotalSubsystemMassforAllocation;
    
    
    
    struct Payload_type{
        float mass;
        float orbital_avg_power;
        float peak_power;
        float output_data_rate;
        float pointing_req;
    };
    struct Subsystem_type
    {
        float allocatedMass;
        int   percentEst;
    };
    
    void InitSciencePayload(Payload_type* Payload, int numItems);
    void SetMassBudget();
    
};
#endif /* SystemRequirements_hpp */
