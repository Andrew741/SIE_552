//
//  SpaceCraftStructure.cpp
//  Playground
//
//  Created by Andrew  on 3/7/17.
//  Copyright © 2017 Creator: Andrew Byron. All rights reserved.
//

#include "SpaceCraftStructure.hpp"
#include <math.h>
SpaceCraftStructure::SpaceCraftStructure()
{
    
}
SpaceCraftStructure::~SpaceCraftStructure()
{
    
}
void SpaceCraftStructure::CalcDensity()
{
    //assume cylinder
}
void SpaceCraftStructure::SetLoadFactors(float SSAx, float SSLat, float tAx, float tLat)
{
    
    
}
void SpaceCraftStructure::CalcLoadUnc()
{
     axial_load_unc_factor = Axial_LoadFactor_SS + Axial_LoadFactor_trans;
     lateral_load_unc_factor = Lateral_Lf_SS + Lateral_Lf_trans;
    
}
void SpaceCraftStructure::detRigidity()
{
    
}
