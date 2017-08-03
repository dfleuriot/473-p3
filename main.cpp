//
//  main.cpp
//  473p3
//
//  Created by Dimitri Fleuriot on 4/19/17.
//  Copyright © 2017 Dimitri Fleuriot. All rights reserved.
//

#include"vmmi.hpp"
#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    
    ReplacementPolicy p;
    unsigned int N; //pS
    unsigned int numFrames; //nF
    unsigned int virtualAddressSpaceSize; //vA
    
    p = LRU;
    N = 2;
    numFrames = 2;
    virtualAddressSpaceSize = 5;
    
    vmmi vmmi(p, N, numFrames, virtualAddressSpaceSize);
    
    unsigned long long phyAdd;
    
    cout<<"virtual address: " << 14 << endl;
    phyAdd = vmmi.memoryAccess(14);
    cout<<"physical address: " << phyAdd << endl;
    
    cout<<"virtual address: " << 2 << endl;
    phyAdd = vmmi.memoryAccess(2);
    cout<<"physical address: " << phyAdd << endl;
    
    cout<<"virtual address: " << 10 << endl;
    phyAdd = vmmi.memoryAccess(10);
    cout<<"physical address: " << phyAdd << endl;
    
    cout<<"virtual address: " << 6 << endl;
    phyAdd = vmmi.memoryAccess(6);
    cout<<"physical address: " << phyAdd << endl;
    
    cout<<"virtual address: " << 14 << endl;
    phyAdd = vmmi.memoryAccess(14);
    cout<<"physical address: " << phyAdd << endl;
    
    cout<<"virtual address: " << 32 << endl;
    phyAdd = vmmi.memoryAccess(32);
    cout<<"physical address: " << phyAdd << endl;
    
    cout<<"virtual address: " << 29 << endl;
    phyAdd = vmmi.memoryAccess(29);
    cout<<"physical address: " << phyAdd << endl;
    
    cout<<"virtual address: " << 19 << endl;
    phyAdd = vmmi.memoryAccess(19);
    cout<<"physical address: " << phyAdd << endl;
    
    
    unsigned long long numberPageSwaps;
    numberPageSwaps = vmmi.numberPageSwaps();
    
    cout<<"num page swaps: "<< numberPageSwaps<<endl;
    
    return 0;
}
