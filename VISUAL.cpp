#include <iostream>

using namespace std;
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 32
/* TRY USING ZEROES FOR SPECIFIC DECLARATIONS IN EVOLVE FUNCTIONS WHEN THEY ARE OUT OF SCOPE*/

void evolve39318(std::bitset<100> &s)
{
    int i;
    std::bitset<100> t;
    // VERY REPETITIVE RESULTS?
    // RULE 39318 4N
    t[0] = s[0] ^ s[1] ^ (s[98] | s[99]);
    t[1] = s[1] ^ s[2] ^ (s[99] | s[0]);
    t[99] = s[99] ^ s[1] ^ (s[97] | s[98]);
    for (i = 2; i < 100; i++)
    {
        t[i] = s[i] ^ s[i+1] ^ (s[i-2] | s[i-1]);

    }

    // REWRITE TO ARRAY
    for (i = 0; i < 100; i++)s[i] = t[i];
}
void evolve39318s(std::bitset<100> &s)
{
    int i;
    std::bitset<100> t;
    // VERY REPETITIVE RESULTS?
    // RULE 39318 4N
    t[0] = s[0] ^ s[1] ^ (0);
    t[1] = s[1] ^ s[2] ^ (0 | s[0]);
    t[99] = s[99] ^ 0 ^ (s[97] | s[98]);
    for (i = 2; i < 100; i++)
    {
        t[i] = s[i] ^ s[i+1] ^ (s[i-2] | s[i-1]);

    }

    // REWRITE TO ARRAY
    for (i = 0; i < 100; i++)s[i] = t[i];
}
void evolve57630(std::bitset<100> &s,std::bitset<100> &r,double &n)
{
    int i;
    std::bitset<100> t;

    // RULE 57630 4N
    t[0] = s[98] ^ s[99] ^ (s[0] | s[1]);
    t[1] = s[99] ^ s[0] ^ (s[1] | s[2]);
    t[99] = s[97] ^ s[98] ^ (s[98] | s[0]);
    for (i = 2; i < 100; i++)
    {
        t[i] = s[i-2] ^ s[i-1] ^ (s[i] | s[i+1]);
        if(i == 50)
        {
           r[n] = t[i];
           n++;
        }


    }

    // REWRITE TO ARRAY
    for (i = 0; i < 100; i++)s[i] = t[i];
}
void evolve57630s(std::bitset<100> &s)
{
    int i;
    std::bitset<100> t;

    // RULE 57630 4N
    t[0] = 0 ^ 0 ^ (s[0] | s[1]);
    t[1] = 0 ^ s[0] ^ (s[1] | s[2]);
    t[99] = s[97] ^ s[98] ^ (s[98] | 0);
    for (i = 2; i < 100; i++)
    {
        t[i] = s[i-2] ^ s[i-1] ^ (s[i] | s[i+1]);


    }

    // REWRITE TO ARRAY
    for (i = 0; i < 100; i++)s[i] = t[i];
}
void evolve30s(std::bitset<100> &s)
{
    int i;
    std::bitset<100> t;

    // RULE 30 3N
    t[0] = 0 ^ (s[0] | s[1]);
    t[1] = s[0] ^ (s[1] | s[2]);
    t[99] =s[98] ^ (s[98] | 0);
    for (i = 2; i < 100; i++)
    {
        t[i] = s[i-1] ^ (s[i] | s[i+1]);


    }

    // REWRITE TO ARRAY
    for (i = 0; i < 100; i++)s[i] = t[i];
}
void evolve30(std::bitset<100> &s)
{
    int i;
    std::bitset<100> t;

    // RULE 30 3N
    t[0] = s[99] ^ (s[0] | s[1]);
    t[1] = s[0] ^ (s[1] | s[2]);
    t[99] =s[98] ^ (s[98] | s[0]);
    for (i = 2; i < 100; i++)
    {
        t[i] = s[i-1] ^ (s[i] | s[i+1]);


    }

    // REWRITE TO ARRAY
    for (i = 0; i < 100; i++)s[i] = t[i];
}
int main()
{

    string restart;
    do
    {


        int gens;
        int ic;
        int rule=0;
        string change;
        string M;
        system ("color 0A");
        int gen=0;
        cout<< "Enter generation number:";
        cin >> gens;
        double nforgen=0;
        cout<<endl<<"Enter rule (30,57630,39318):";
        cin>> rule;

//        cout<<endl<<"Enter a pass phrase :";
//        cin>> M;
//        bitset<8> bitM[M.size()];

        // BITSET CONVERSIONS
        bitset<100> bitM[0];
        bitset<100> bitRandGen;
        bitM[0].set(50,1);
        cout<< "Use zeroes for out of scope cells?(Y/N)"<<endl;
        cin >> change;
        cout << bitM[0]<<endl;
//    for (std::size_t i = 0; i < M.size(); ++i)
//  {
//      bitM[i] =  bitset<8>(M[i]);
//
//      cout << char(bitM[i].to_ulong());
//
//  }
        // EVOLUTION
        for(gen=0; gen<gens; gen++)
        {

            if(change=="y" || change=="Y")
            {
                switch (rule)
                {
                case 57630:
                    evolve57630s(bitM[0]);
                    break;
                case 30:
                    evolve39318s(bitM[0]);
                    break;
                case 39318:
                    evolve30s(bitM[0]);
                    break;
                default:
                    cout<<"Not an implemented rule"<<endl;
                    break;
                }
            }
            else
            {
                switch (rule)
                {
                case 57630:
                    evolve57630(bitM[0],bitRandGen,nforgen);
                    break;
                case 30:
                    evolve39318(bitM[0]);
                    break;
                case 39318:
                    evolve30(bitM[0]);
                    break;
                default:
                    cout<<"Not an implemented rule"<<endl;
                    break;
                }
            }
            cout << bitM[0]<<endl; // OUTPUT STRING EQUIVALENT
            //cout << bitRandGen.to_ulong()<<endl;
        }
        cout << "EVOLVED"<<endl;
        cout<< "Re-run the process?(Y/N)"<<endl;
        cin >> restart;
        system ("CLS"); // Clear screen
    }
    while(restart =="Y" || restart =="y");

    return 0;
}
