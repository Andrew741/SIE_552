//
//  HWProcedures.cpp
//  Playground
//
//  Created by Andrew  on 3/7/17.
//  Copyright © 2017 Creator: Andrew Byron. All rights reserved.
//

#include "HWProcedures.hpp"
#include "CThruster.hpp"
#include "SpaceCraftStructure.hpp"
#include "AttitudeControlSystem.hpp"
#include "SystemRequirements.hpp"
#include <iostream>

HWProcedures::HWProcedures()
{
    
}
HWProcedures::~HWProcedures()
{
    
}

void HWProcedures::Assignment1Procedures()
{
    std::cout << "Nothing related to the project here" << std::endl;
}
void HWProcedures::Assignment2Procedures()
{
    SystemRequirements* SysReq = new SystemRequirements();
    int numInstruments = 6;
    SystemRequirements::Payload_type SciencePayload[numInstruments];
    int instNum = 0;
    // Narrow Angle Cameras
    SciencePayload[instNum].mass = 16.4;
    SciencePayload[instNum].orbital_avg_power = 6.4;
    SciencePayload[instNum].peak_power = 9.3;
    SciencePayload[instNum].output_data_rate = 30;
    SciencePayload[instNum].pointing_req = -1;
    instNum++;
    
    SciencePayload[instNum].mass = 16.4;
    SciencePayload[instNum].orbital_avg_power = 6.4;
    SciencePayload[instNum].peak_power = 9.3;
    SciencePayload[instNum].output_data_rate = 30;
    SciencePayload[instNum].pointing_req = -1;
    instNum++;
    
    // Wide Angle Camera
    SciencePayload[instNum].mass = 0.9;
    SciencePayload[instNum].orbital_avg_power = 2.6;
    SciencePayload[instNum].peak_power = 2.7;
    SciencePayload[instNum].output_data_rate = 2.5;
    SciencePayload[instNum].pointing_req = -1;
    instNum++;
    
    // Spectrometer
    SciencePayload[instNum].mass = 11.2;
    SciencePayload[instNum].orbital_avg_power = 14;
    SciencePayload[instNum].peak_power = 0;
    SciencePayload[instNum].output_data_rate = 1.17;
    SciencePayload[instNum].pointing_req = 0;
    instNum++;
    
    // Neutron Detector
    SciencePayload[instNum].mass = 26.3;
    SciencePayload[instNum].orbital_avg_power = 13;
    SciencePayload[instNum].peak_power = 0;
    SciencePayload[instNum].output_data_rate = .003;
    SciencePayload[instNum].pointing_req = 0;
    instNum++;
    
    // Laser Altimeter
    SciencePayload[instNum].mass = 25;
    SciencePayload[instNum].orbital_avg_power = 23.1;
    SciencePayload[instNum].peak_power = 33.1;
    SciencePayload[instNum].output_data_rate = 0;
    SciencePayload[instNum].pointing_req = 28;// sun... who knows
    instNum++;
    
    SysReq->InitSciencePayload(SciencePayload, instNum);
    SysReq->SetMassBudget();
}
void HWProcedures::Assignment3Procedures()
{
    
}
void HWProcedures::Assignment4Procedures()
{
    // Assignment 4
    
    int numLarge    = 6;
    int numMedium   = 6;
    int numSmall    = 12;
    
    // Thruster Analysis and Sizing
    std::ofstream fwriter ("./Assignment_4.txt", std::ofstream::out); // append to the file.
    
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

}
void HWProcedures::Assignment5Procedures()
{
    // Assignment 5
    float env_dia = 3850.0; // diameter of envelope in mm
    float env_height = 4000; // mm
    SpaceCraftStructure* structure = new SpaceCraftStructure();
    std::ofstream fwriter ("./Assignment_5.txt", std::ofstream::out); // append to the file.
    
    fwriter << env_dia << " is the diameter of the envelope in mm" << std::endl;
    fwriter << env_height << " is the height of the envelope in mm" << std::endl;
    fwriter << " 2.5g is the axial steady state load" << std::endl;
    fwriter << " 4.0g is the axial transient load" << std::endl;
    fwriter << " 3.0g is the lateral steady state load" << std::endl;
    fwriter << " First axial frequency is 25 Hz" << std::endl;
    fwriter << " First lateral frequency is 10 Hz" << std::endl;
    fwriter.close();
}

void HWProcedures::Assignment6Procedures()
{
    // Assignment 6
    
    std::ofstream fwriter ("./Assignment_6.txt", std::ofstream::out); // append to the file.
    AttitudeControlSystem* ACS = new AttitudeControlSystem();
    fwriter << "Introduction: This assignment deals with the design and sizing of an attitude control system" << std::endl;
    
    fwriter << "Part 1: Define the Mission Attitude Control Modes, then define System-Level Requirements for each control Mode." << std::endl;
    
    fwriter << "Control Mode 1: Launch Mode" << std::endl;
    fwriter << "\t During Launch Mode the Spacecraft will have all of the science payloads stored in the respective compartments. This means that there will be no pointing requirements." << std::endl;
    fwriter << "Control Mode 1: Launch Mode" << std::endl;
    fwriter << "\t During Launch Mode the Spacecraft will have all of the science payloads stored in the respective compartments. This means that there will be no pointing requirements." << std::endl;
    
    fwriter << "Control Mode 2: Cruise" << std::endl;
    fwriter << "\t During Cruise Mode the Spacecraft will not have all of the science payloads stored in the respective compartments." << std::endl;
    fwriter << "\t For example, the star scanners need to be able to see the surrounding solar landscape. Furthermore, the solar panels will be deployed and need to be angled such that they are perpendicular to the solar rays for as much time as possible. In addition, the high gain antenna will need to be oriented toward earth to maintain communication lines. These requirements naturally lead to a 3-axis-stabilized system." << std::endl;
    
    fwriter << "Control Mode 3: Oriting Mars" << std::endl;
    fwriter << "\t During Mars Orbital Mode the Spacecraft will have all of the science payloads exposed." << std::endl;
    fwriter << "\t In addition to the cruising requirements the spacecraft will also need to have the previously unused payload devices angled in the appropriate direction. Specifically, there are several nadir-pointing components such as the wide and narrow angle cameras. Also there is the spectrometer that must be pointing toward the surface of Mars." << std::endl;
    
    fwriter << "Part 2: Select the ACS system-type and explain the choice." << std::endl;
    fwriter << "\t The decision to go with the 3-axis-stabilized control system was simple to make. By using the Mission Suitability Matrix provided in the book, it was clear that since many mission-critical objectives could only be met with nadir-pointing science payloads that the decision was between the 3-axis option and the momentum biased configurations. The fact that planetary observance was poor with the momentum biased option meant that although the 3-axis choice was far more expensive, it was the best choice for meeting the mission requirements." << std::endl;
    
    fwriter << "Part 3: Determine the minimum thrust level of the thrusters for a three-axis system in order to comply with the rotational maneuver time limit in the SRD." << std::endl;
    fwriter << "\t The rotational maneuver time limit is the following..."  << std::endl;
    fwriter << "\t\t \"It  must  be  possible  to  make  a  180  degree rotational maneuver about any axis in 30 second. The solar arrays shall be pointed to the Sun within 5 degrees maximum array pointing error.\"" << std::endl;
    fwriter << "\t This assumes the thrusters are fired in pair and are at the same thrust level." << std::endl;
    ACS->actuator = AttitudeControlSystem::Thruster_Pair;
    float rotTime = ACS->computeRotationalTime(180.0/*degrees*/);
    fwriter << "\t The maximum rotational time is " << rotTime << " which is less than 30 seconds. Therefore each of the possible axis of rotation meet the requirement." << std::endl;
    
    fwriter << "Part 4: Characterize the environmental torques acting on the orbiter. "<<std::endl;
    fwriter << "\t The Solar Torque acting on the left solar panel when the spacecraft is near earth's orbit is " << ACS->computeSolarTorque(4.59E-6, 7.6, 1.312) << std::endl;
    fwriter << "\t The Solar Torque acting on the right solar panel when the spacecraft is near earth's orbit is " << ACS->computeSolarTorque(4.59E-6, 6.3, 1.261) << std::endl;
    fwriter.close();
}
