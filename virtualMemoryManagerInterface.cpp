//
//  virtualMemoryManagerInterface.cpp
//  473p3
//
//  Created by Dimitri Fleuriot n on 4/19/17.
//  Copyright © 2017 Dimitri Fleuriot. All rights reserved.
//

#include <stdio.h>
#include"vmmi.hpp"

#include<iostream>
#include<map>
#include <cmath>

//map<unsigned long long, unsigned long long> fToPMap;
//map<unsigned long long, unsigned long long> vToNum;


struct Page{
    unsigned int pageNumber;
    int counter;
    bool isMapped;
};

map<unsigned int, Page> frame;


unsigned long long vmmi::memoryAccess(unsigned long long address){
    
    //cout<<"frame size beginning: "<< frame.size()<< endl;
    for(int i = 0; i < frame.size(); i++){
        frame[i].counter ++;
    }
    
    /// N = Page Address bits size, 2^ N = The physical frame/virtual page size to manage (bytes)
    //how many addresses per page
    unsigned int pageSizeBytes = pow(2, N);
    
    //numframs is number of frames
    
    // Phy mem size = numFrames * 2^N
    //number of addresses for physical memory
    //unsigned int physMemSize = numFrames * pageSizeBytes;
    
    ///  2^virtualAddressSpaceSize = total virtual address space (bytes)
    //total number of addresses in virtual space
    int virtualAddSpaceSizeBytes = pow(2, virtualAddressSpaceSize);
    
    //find out what page the address is on
    
    //unsinged long long has to be positive
    if(address > (virtualAddSpaceSizeBytes-1)){
        return NULL;
    }
    
    unsigned int page;
    
    unsigned int offset;
    
    unsigned long long physicalAddress = 0;
    
    page = floor(address/pageSizeBytes);
    
    offset = floor(address - (page * pageSizeBytes));
    
    if(frame.size() > 0){
        for(int i = 0; i < frame.size(); i++){
            if(page == frame[i].pageNumber){
                physicalAddress = (i * pageSizeBytes) + offset;
                
                if(policy == LRU){
                    frame[i].counter = 0;
                }
                return physicalAddress;
            }
        }
    }
    
    //cout<<"frame.size: " << frame.size()<< endl;
    
    if(frame.size() < numFrames){
        
        
        for(int i = 0; i<numFrames; i++){
            if(frame[i].isMapped == false){
                //swap function
                frame[i].pageNumber = page;
                frame[i].isMapped = true;
                frame[i].counter = 0;
                
                physicalAddress = (i * pageSizeBytes) + offset;
                
                return physicalAddress;
            }
            
            
        }
    }else{
        //replacment policy
        
        int highestCount = 0;
        int highestIndex = 0;
        
        for(int i = 0; i < numFrames; i++){
            if(frame[i].counter > highestCount){
                highestCount = frame[i].counter;
                highestIndex = i;
            }
        }
        
        swap(highestIndex,page);
        
        physicalAddress = (highestIndex * pageSizeBytes) + offset;
        
        //return physicalAddress;
        
    }
    
    
    return physicalAddress;
}


void vmmi::swap(unsigned int frameNumber, unsigned int pageNumber){
    frame[frameNumber].pageNumber = pageNumber;
    frame[frameNumber].isMapped = true;
    frame[frameNumber].counter = 0;
    numSwaps++;
}
