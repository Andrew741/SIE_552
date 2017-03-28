//
//  SpaceCraftStructure.hpp
//  Playground
//
//  Created by Andrew  on 3/7/17.
//  Copyright © 2017 Creator: Andrew Byron. All rights reserved.
//

#ifndef SpaceCraftStructure_hpp
#define SpaceCraftStructure_hpp

#include <stdio.h>

class SpaceCraftStructure {
    float LV_Envelope;
    float Axial_LoadFactor_SS;
    float Axial_LoadFactor_trans;
    float Lateral_Lf_SS;
    float Lateral_Lf_trans;
    float Safety_Factor;
    
    float axial_load_unc_factor;
    float lateral_load_unc_factor;
    
    // dimensions
    float height;
    float width;
    
    float density;
    float mass;
    
    // material properties
    float Young_Mod;
    float Poisson_Ratio;
    float Density;
    float Tensile_Strength;
    
public:
    SpaceCraftStructure();
    ~SpaceCraftStructure();
    void CalcDensity();
    void SetLoadFactors(float SSAx, float SSLat, float tAx, float tLat );
    void CalcLoadUnc();
    void detRigidity();
    
};
#endif /* SpaceCraftStructure_hpp */
