//
//  QM.cpp
//  digital_project_test
//
//  Created by Youssef Khalifa on 11/17/19.
//  Copyright © 2019 Youssef Khalifa. All rights reserved.
//

#include "QM.hpp"
QM::QM(int a)
{
    dontcares.append(a,'-');
}

vector<string> QM::getVars()
{
    vector<string> expression;
    string letters[]={"A","B","C"};
    for(int i=0;i<3;i++)
        expression.push_back(letters[i]);
    return expression;
}

string QM::decToBin(int n)
{
    if ( n == 0 )
        return n+"";
    if ( n % 2 == 0 )
        return decToBin(n / 2) + "0";
    else
        return decToBin(n / 2) + "1";
}

string QM::pad(string bin)
{
    long max=3-bin.length();
    for(int i=0; i<max; i++)
        bin="0"+bin;
    return bin;
}

bool QM::TestBit(string a,string b)
{
    int flag=0;
    for(int i=0;i<a.length();i++)
    {
        if(a[i]!=b[i])
            flag++;
    }
    return (flag==1);
}

string QM::replace_complements(string a,string b)
{
    string temp="";
    for(int i=0;i<a.length();i++)
        if(a[i]!=b[i])
            temp=temp+"-";
        else
            temp=temp+a[i];
    
    return temp;
}

bool QM::in_vector(vector<string> a,string b)
{
    for(int i=0;i<a.size();i++)
        if(a[i].compare(b)==0)
            return true;
    return false;
}

vector<string> QM::reduce(vector<string> minterms)
{
    vector<string> newminterms;
    int max=minterms.size();
    int* checked = new int[max];
    for(int i=0;i<max;i++)
    {
        for(int j=i;j<max;j++)
        {
            if(TestBit(minterms[i],minterms[j]))
            {
                checked[i]=1;
                checked[j]=1;
                if(!in_vector(newminterms,replace_complements(minterms[i],minterms[j])))
                    newminterms.push_back(replace_complements(minterms[i],minterms[j]));
            }
        }
    }
    
    for(int i=0;i<max;i++)
    {
        if(checked[i]!=1 && ! in_vector(newminterms,minterms[i]))
            newminterms.push_back(minterms[i]);
    }
    
    delete[] checked;
    
    return newminterms;
}

string QM::getValue(string a)
{
    string temp="";
    vector<string> vars=this->getVars();
    if(a==dontcares)
        return "1";
    
    for(int i=0;i<a.length();i++)
    {
        if(a[i]!='-')
        {
            if(a[i]=='0')
                temp=temp+vars[i]+"\'";
            else
                temp=temp+vars[i];
        }
    }
    return temp;
}

bool QM::VectorsEqual(vector<string> a,vector<string> b)
{
    if(a.size()!=b.size())
        return false;
    
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    for(int i=0;i<a.size();i++)
    {
        if(a[i]!=b[i])
            return false;
    }
    return true;
}
