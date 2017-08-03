#pragma once

//
//  vmmi.hpp
//  473p3
//
//  Created by Dimitri Fleuriot on 4/22/17.
//  Copyright © 2017 Dimitri Fleuriot. All rights reserved.
//

#ifndef vmmi_h
#define vmmi_h

#include "virtualMemoryManagerInterface.hpp"


class vmmi: public virtualMemoryManagerInterface{
public:
    vmmi(ReplacementPolicy p, unsigned int pS, unsigned int nF, unsigned int vA) : virtualMemoryManagerInterface(p, pS, nF, vA){}
    unsigned long long memoryAccess(unsigned long long address) override;
    void swap(unsigned int frameNumber, unsigned int pageNumber) ;
};


#endif /* vmmi_h */
