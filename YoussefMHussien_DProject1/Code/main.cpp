#include "QM.hpp"
int main ()
{
        QM q(3);
        int kmap[2][4]={0,0,0,0,0,0,0,0};
        string temp="";
label:
        cout<<"Enter the minterms [0-7] separated by commas:"<<endl;
        cin>>temp;
        vector<string> minterms;

        //splitting the input
        istringstream f(temp);
        string s;
        while (getline(f, s, ','))
        {
            int t=atoi(s.data());
            minterms.push_back(q.pad(q.decToBin(t)));
        }
    
    for(int i=0;i<minterms.size();i++)
    {
        if(minterms[i].size()>3)//[0-8] are represented by 3 bits any integers beyond that need more bits for representation
        {
            cout<<"ERROR! Minterm out of bounds"<<endl;
            goto label;//in case error is encountered code returns to previously set label and prompts the user to re-enter his minterms
        }
    }
    for(int i=0;i<minterms.size();i++)
    {
        if(minterms[i]=="000")
            kmap[0][0]=1;
        if(minterms[i]=="001")
            kmap[0][1]=1;
        if(minterms[i]=="010")
            kmap[0][3]=1;
        if(minterms[i]=="011")
            kmap[0][2]=1;
        if(minterms[i]=="100")
            kmap[1][0]=1;
        if(minterms[i]=="101")
            kmap[1][1]=1;
        if(minterms[i]=="110")
            kmap[1][3]=1;
        if(minterms[i]=="111")
            kmap[1][2]=1;
       
    }
        do
        {
            minterms=q.reduce(minterms);
            sort(minterms.begin(),minterms.end());
        }while(!q.VectorsEqual(minterms,q.reduce(minterms)));
        
    cout<<endl<<"kmap = "<<endl;
        for(int i=0; i<2;i++)
        {
            for(int j=0; j<4; j++)
            {
                cout<<"  "<<kmap[i][j]<<"  ";
            }
            cout<<endl;
        }
        int i;
    cout << "F = " << endl<<"  "<<"\"";
    
        for (i=0;i<minterms.size()-1; i++)
            cout <<q.getValue(minterms[i])<<" + ";
    cout<<q.getValue(minterms[i])<<"\""<<endl;
    
    return 0;
    
}
