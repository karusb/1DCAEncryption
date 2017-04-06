#include <iostream>

using namespace std;
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#define SIZE 32

#define nUSER_Input    //SET USER_Input to allow user input
#define NODEBUG_MODE // SET DEBUG_MODE FOR VISUAL
#define SHOW_Properties // SET SHOW_Properties for analysis
#define ManyBytes
#define nFAST_Decrypt
//ADD METHOD FOR FILES
const bool bitval [16*4]= {0,0,0,0,
0,0,0,1,
0,0,1,0,
0,0,1,1,
0,1,0,0,
0,1,0,1,
0,1,1,0,
0,1,1,1,
1,0,0,0,
1,0,0,1,
1,0,1,0,
1,0,1,1,
1,1,0,0,
1,1,0,1,
1,1,1,0,
1,1,1,1};
int statArr[16]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
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
int nonlinearity(std::bitset<8> &s)
{
    int oncount=0;
    for(int i=0;i < 8 ;i++)
    {
        (s[i] == 1)?oncount++:oncount=oncount;
    }
    return oncount;
}
int nonlinearityhalfone(std::bitset<8> &s)
{
    int oncount=0;
    for(int i=0;i < 4 ;i++)
    {
        (s[i] == 1)?oncount++:oncount=oncount;
    }
    return oncount;
}
int nonlinearityhalftwo(std::bitset<8> &s)
{
    int oncount=0;
    for(int i=4;i < 8 ;i++)
    {
        (s[i] == 1)?oncount++:oncount=oncount;
    }
    return oncount;
}
void pokertest(std::bitset<8> &s)
{

    for(int i=0;i < 5 ;i+=4)
    {
        for(int t=0; t<61;t+=4)
        {


        if(s[i] == bitval[t])
        {
            if(s[i+1] == bitval[t+1])
            {
                if(s[i+2] == bitval[t+2])
                {
                    if(s[i+3] == bitval[t+3])
                    {
                        if(t > 0)
                        {statArr[t/4] = statArr[t/4] +1;}
                        else {statArr[t]=statArr[t]+1;}
                    }
                }
            }

        }
        }

    }
}
int main()
{
    int gens;
    int ic;
    string M;
    string encM;
    string key;
    string choice;
    system ("color 0A");
    int gen=0;
#ifdef USER_Input
    cout << "Input generation number: ";
    cin >> gens;
    cout <<"Input pass phrase: ";
    cin >> key;
    cout << "File input (Y/N) ";
    cin >> choice;
    cout <<"Input message: ";
    cin >> M;
#else
    // SUBDIVIDE NON LINEARITY TOCREATE HISTOGRAM
    gens = 50;
    key = "Hgaj2q!zhquJ>Ak?qdk8wck;Subvol%18-0v_dnk49cvQjkzNUp&`aZqjv~-jsmdr}k£,@ajeI9MevK_jwQUH)yw<j4JNwqK$%ldshjbdKnQW^2u(hmls?ma}yLS=¬M"; //1024bit key
    //key = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    //M   = "This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER "; //Long message
     M   = "This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER "; //Long message 1024B
    //key=" ";
    choice = "n";

#endif // Static_Input
    bitset<8> bitM[M.size()];
    bitset<8> bitK[M.size()];
    //if(M.size()<128)bitset<8> bitKn[128];
    bitset<8> bitKn[M.size()];

    bitset<8> bitMs[M.size()];
    bitset<8> bitMd[M.size()];
    float nonlineardata [M.size()];

    // BITSET CONVERSIONS
    cout <<"Plain:";
    for (std::size_t i = 0; i < M.size(); ++i)
    {
        bitM[i] =  bitset<8>(M[i]);

        cout << char(bitM[i].to_ulong());

    }
    if(key.size() < M.size())
    {
        int t=0;
        for(int i=key.size(); i<M.size(); i++)
        {
            bitKn[i] =  bitset<8>(key[t]);
            bitK[i] = bitset<8>(key[t]);
            if(t==key.size())t=0;
            t+=1;
        }
    }
    cout <<endl<<endl<<"Key:";
    // TODO : NEED A BETTER IMPLEMENTATION
    if(key.size() < 128)
    {
        for(int i=0; i<128;i++)
        {   int cur=(i%key.size());

            bitKn[i] = bitset<8>(key[cur]);
            bitK[i] = bitset<8>(key[cur]);
            //for(int ic=0;i<128; i++)evolve39318(bitKn[ic]);
            cout << char(bitKn[i].to_ulong());
        }
    }
    else
    {
        for(int i=0;i<128;++i)
        {
            bitKn[i] =  bitset<8>(key[i]);
            bitK[i]=  bitset<8>(key[i]);
            cout << char(bitKn[i].to_ulong());
        }
    }



    #ifdef DEBUG_MODE
    cout <<endl<< "Message"<<"                    "<<"KEY"<<endl;
    #endif // DEBUG_MODE
    // TODO: RESHAPE USER KEY HERE TO OBTAIN 1024 bit key
    // EVOLUTION
    for(gen=0; gen<gens; gen++)
    {
        for(ic=0; ic<M.size(); ic++)
        {
            //evolve39318(bitM[ic]);
            evolve57630(bitKn[ic]);
            //evolve39318(bitK[ic]);
            //devolve57630(bitK[ic]);
            #ifdef DEBUG_MODE
            cout << bitM[ic].to_string() <<"                    "<<bitK[ic].to_string()<<endl;
            #endif // DEBUG_MODE
        }
#ifdef DEBUG_MODE
      for(ic=0;ic<M.size();ic++)cout << char(bitM[ic].to_ulong()); // OUTPUT STRING EQUIVALENT
      cout<<"                    ";
        for(ic=0;ic<key.size();ic++)cout << char(bitKn[ic].to_ulong());
        cout <<endl;
        // system ("CLS"); // COOL
#endif // DEBUG_MODE
    }

    cout <<endl<< "EVOLVED"<<endl<<endl;
    cout << "Encrypted message:";
    //XOR OPERATION ENCRYPTION
    int oncount=0;
    int oncountout=0;
    #ifdef SHOW_Properties
    ofstream linearityfile;
    ofstream linearityfiletwo;
    ofstream pokerfile;
    ofstream encfile;
    //ofstream pokerfiletwo;
    linearityfile.open("nonlinearitydata.txt");
    linearityfiletwo.open("nonlinearitydata8.txt");
    pokerfile.open("pokerfile.txt");
    encfile.open("encfile.txt");
    //pokerfiletwo.open("pokerfile2.txt");
    #endif // SHOW_Properties
    for(ic=0; ic<M.size(); ic++)
    {
        for (int i = 0; i <= 7; i++)
            bitMs[ic][i] = bitM[ic][i] ^ bitKn[ic][i]; // XOR KEY WITH THE MESSAGE
            #ifdef SHOW_Properties
            //TEST LINEARITY
            oncount += nonlinearity(bitMs[ic]);

            linearityfile << (nonlinearityhalfone(bitMs[ic])*100)/(4) <<endl;
            linearityfile << (nonlinearityhalftwo(bitMs[ic])*100)/(4) <<endl;
            linearityfiletwo << (nonlinearity(bitMs[ic])*100)/(8) <<endl;
            pokertest(bitMs[ic]);
            #endif // SHOW_Properties
        cout << char(bitMs[ic].to_ulong()) ;    // ENCRYPTED OUTPUT
        encfile << char(bitMs[ic].to_ulong());
    }
    for(int iw=0; iw<16;iw++)pokerfile << statArr[iw] << endl;
#ifdef SHOW_Properties
    cout <<endl <<"Non-linearity:" << (oncount*100)/(8*M.size()) << endl;
#endif // SHOW_Properties
    linearityfile.close();
    linearityfiletwo.close();
    pokerfile.close();
    encfile.close();
    //pokerfiletwo.close();
    //DECRYPTION
#ifdef FAST_Decrypt
    cout <<endl<<endl<< "Decrypted message:";
    for(ic=0; ic<M.size(); ic++)
    {
        for (int i = 0; i <= 7; i++)
            bitMd[ic][i] = bitMs[ic][i] ^ bitKn[ic][i]; // XOR EVOLVED KEY WITH THE ENCRYPTED MESSAGE

        cout << char(bitMd[ic].to_ulong()) ;    // DECRYPTED OUTPUT
    }
    ////////////////////////////////////////////////
#else
ofstream decfile;
decfile.open("decfile.txt");
    for(int gen=0; gen<gens; gen++)
    {
        for(ic=0; ic<M.size(); ic++)
        {
            //evolve39318(bitM[ic]);
            evolve57630(bitK[ic]);
            //evolve39318(bitK[ic]);
            //devolve57630(bitK[ic]);
            #ifdef DEBUG_MODE
            cout << bitM[ic].to_string() <<"                    "<<bitK[ic].to_string()<<endl;
            #endif // DEBUG_MODE
        }
#ifdef DEBUG_MODE
      for(ic=0;ic<M.size();ic++)cout << char(bitM[ic].to_ulong()); // OUTPUT STRING EQUIVALENT
      cout<<"                    ";
        for(ic=0;ic<key.size();ic++)cout << char(bitK[ic].to_ulong());
        cout <<endl;
        // system ("CLS"); // COOL
#endif // DEBUG_MODE
    }

        cout <<endl<<endl<< "Decrypted message:";
    for(ic=0; ic<M.size(); ic++)
    {
        for (int i = 0; i <= 7; i++)
            bitMd[ic][i] = bitMs[ic][i] ^ bitK[ic][i]; // XOR EVOLVED KEY WITH THE ENCRYPTED MESSAGE

        cout << char(bitMd[ic].to_ulong()) ;    // DECRYPTED OUTPUT
        decfile << char(bitMd[ic].to_ulong());
    }
#endif
    return 0;
}
