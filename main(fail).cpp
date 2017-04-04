#include <iostream>

using namespace std;
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#define SIZE 32

//ADD METHOD FOR FILES

/* TRY USING ZEROES FOR SPECIFIC DECLARATIONS IN EVOLVE FUNCTIONS WHEN THEY ARE OUT OF SCOPE*/
void evolve39318(std::bitset<8> &s)
{
    int i;
    std::bitset<8> t;
    // VERY REPETITIVE RESULTS?
    // RULE 39318 4N
    t[0] = s[0] ^ s[1] ^ (s[6] | s[7]);
    t[1] = s[1] ^ s[2] ^ (s[7] | s[0]);
    t[7] = s[7] ^ s[1] ^ (s[5] | s[6]);
    for (i = 2; i < 7; i++)
    {
        t[i] = s[i] ^ s[i+1] ^ (s[i-2] | s[i-1]);

    }

    // REWRITE TO ARRAY
    for (i = 0; i < 7; i++)s[i] = t[i];
}
void evolve57630(std::bitset<8> &s)
{
    int i;
    std::bitset<8> t;

    // RULE 57630 4N
    t[0] = s[6] ^ s[7] ^ (s[0] | s[1]);
    t[1] = s[7] ^ s[0] ^ (s[1] | s[2]);
    t[7] = s[5] ^ s[6] ^ (s[6] | s[0]);
    for (i = 2; i < 7; i++)
    {
        t[i] = s[i-2] ^ s[i-1] ^ (s[i] | s[i+1]);


    }

    // REWRITE TO ARRAY
    for (i = 0; i <= 7; i++)s[i] = t[i];
}
////////////////////TODO
void devolve57630(std::bitset<8> &s)
{
    int i;
    std::bitset<8> t;

    // RULE 57630 4N
    t[0] = s[6] ^ s[7] ^ (s[0] | s[1]);
    t[1] = s[7] ^ s[0] ^ (s[1] | s[2]);
    t[7] = s[5] ^ s[6] ^ (s[6] | s[0]);
    for (i = 2; i < 7; i++)
    {
        t[i] = s[i-2] ^ s[i-1] ^ (s[i] | s[i+1]);
        //t[i] = s[i + 1] ^ (s[i] | s[i+1])).

    }

    // REWRITE TO ARRAY
    for (i = 0; i <= 7; i++)s[i] = t[i];
}
///////////////////TODO
std::bitset<8>  strTObit8(string str)
{
    std::bitset<8> out[str.size()];
    for (std::size_t i = 0; i < str.size(); ++i)
    {
        out[i]  =  bitset<8>(str[i]);

    }
    return *out;
}
void Printbit8(int s, std::bitset<8> b[1024])
{
    for(int ic=0; ic<s; ic++)
    {
        cout << char(b[ic].to_ulong());
    }
}
std::bitset<8> bit8XOR(std::bitset<8> a[1024],std::bitset<8> b[1024],int s)
{
    //XOR OPERATION ENCRYPTION
    std::bitset<8> out[s];
    for(int ic=0; ic<s; ic++)
    {
        for (int i = 0; i <= 7; i++)
            out[ic][i] = a[ic][i] ^  b[ic][i]; // XOR KEY WITH THE MESSAGE

        cout << char(out[ic].to_ulong()) ;    // ENCRYPTED OUTPUT
    }
    return *out;
}
int main()
{
    int gens;
    int ic;
    string M;
    string encM;
    string key;
    string line;
    string choice;
    system ("color 0A");
    int gen=0;
    fstream plain("plain.txt");
    fstream cipher("cipher.txt");
    bitset<8> bitM[1024];
    bitset<8> bitMs[1024];
    bitset<8> bitMd[1024];

    cout << "Input generation number: ";
    cin >> gens;
    cout <<"Input pass phrase: ";
    cin >> key;
    bitset<8> bitK[256]= strTObit8(key);

//        if(key.size() < M.size())
//    {
//        //TODO: CHECK WHEN DECRYPT
//        for(int i=key.size(); i<M.size(); i++)bitK[i] =  bitset<8>(key[i]);
//    }
    cout << "File input (Y/N) ";
    cin >> choice;
    if (choice == "n" || "N")
    {
        cout << "Input message: ";
        cin >> M;


        bitset<8>bitM[M.size()] = strTObit8(M);
        // EVOLUTION
        for(gen=0; gen<gens; gen++)
        {
            for(ic=0; ic<M.size(); ic++)
            {
                //evolve39318(bitK[ic]);
                evolve57630(bitK[ic]);
                //devolve57630(bitK[ic]);
                cout << bitM[ic].to_string() <<"                    "<<bitK[ic].to_string()<<endl;
            }
            Printbit8(M.size(),bitM);

            cout<<"                    ";
            Printbit8(key.size(),bitK);
            cout <<endl;
            // system ("CLS"); // COOL
        }
    }
    else
    {
        //FILE BITSET
        if (plain.is_open())
        {
            while ( getline (plain,line) )
            {
                bitset<8>bitM[1024] = strTObit8(line);
                        // EVOLUTION
        for(gen=0; gen<gens; gen++)
        {
            for(ic=0; ic<M.size(); ic++)
            {
                //evolve39318(bitK[ic]);
                evolve57630(bitK[ic]);
                //devolve57630(bitK[ic]);
                cout << bitM[ic].to_string() <<"                    "<<bitK[ic].to_string()<<endl;
            }
            Printbit8(M.size(),bitM);

            cout<<"                    ";
            Printbit8(key.size(),bitK);
            cout <<endl;
            // system ("CLS"); // COOL
                cout << line << '\n';
            }
            plain.close();
        }
    }
    else cout << "Unable to open file";
    }

    cout <<endl<< "Message"<<"                    "<<"KEY"<<endl;

    cout << "EVOLVED"<<endl;
    cout << "Encrypted message:";
    //XOR OPERATION ENCRYPTION
    for(ic=0; ic<M.size(); ic++)
    {
        for (int i = 0; i <= 7; i++)
            bitMs[ic][i] = bitM[ic][i] ^ bitK[ic][i]; // XOR KEY WITH THE MESSAGE

        cout << char(bitMs[ic].to_ulong()) ;    // ENCRYPTED OUTPUT
    }
    //DECRYPTION
    //KNOWN KEY MUST BE EVOLVED THEN XORED
    cout <<endl<< "Decrypted message:";
    for(ic=0; ic<M.size(); ic++)
    {
        for (int i = 0; i <= 7; i++)
            bitMd[ic][i] = bitMs[ic][i] ^ bitK[ic][i]; // XOR EVOLVED KEY WITH THE ENCRYPTED MESSAGE

        cout << char(bitMd[ic].to_ulong()) ;    // DECRYPTED OUTPUT
    }
    //TODO
    return 0;
}
