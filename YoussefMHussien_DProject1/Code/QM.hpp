//
//  QM.hpp
//  digital_project_test
//
//  Created by Youssef Khalifa on 11/17/19.
//  Copyright © 2019 Youssef Khalifa. All rights reserved.
//
#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>
#include <iterator>
#include <sstream>
#include <stdio.h>
#include <stdlib.h>
#include <cstring>
#include <math.h>
using namespace std;
#ifndef QM_hpp
#define QM_hpp

class QM
{
public:
    string dontcares;
    QM(int a);
    vector<string> getVars();//get the boolean term letters
    string decToBin(int n);//convert decimal to binary
    string pad(string bin);//pad zeros to the binary equivalent of digits: e.g. 2 = 10 in binary becomes 010 (3 bits for 3 variables)
    bool TestBit(string a,string b);//check if two terms differ by just one bit
    string replace_complements(string a,string b);//replace complement terms with don't cares: e.g. 011 and 010 becomes 01-
    bool in_vector(vector<string> a,string b);//if string b exists in vector a
    vector<string> reduce(vector<string> minterms);//reduce minterms
    string getValue(string a);//Converting the boolean minterm into the variables: e.g 01- becomes a'b
    bool VectorsEqual(vector<string> a,vector<string> b);//check if 2 vectors are equal
    
};


#endif /* QM_hpp */
