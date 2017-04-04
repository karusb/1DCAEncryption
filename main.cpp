#include <iostream>

using namespace std;
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#define SIZE 32
/* TRY USING ZEROES FOR SPECIFIC DECLARATIONS IN EVOLVE FUNCTIONS WHEN THEY ARE OUT OF SCOPE*/
void evolve39318(std::bitset<8> &s) {
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
void evolve57630(std::bitset<8> &s) {
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
void devolve57630(std::bitset<8> &s) {
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
int main()
{
    int gens;
    int ic;
    string M;
    string encM;
    string key;
    system ("color 0A");
    int gen=0;
    cin >> gens;
    cin >> M;
    cin >> key;
    bitset<8> bitM[M.size()];
    bitset<8> bitK[M.size()];
    bitset<8> bitMs[M.size()];
    bitset<8> bitMd[M.size()];
    // BITSET CONVERSIONS
      for (std::size_t i = 0; i < M.size(); ++i)
  {
      bitM[i] =  bitset<8>(M[i]);

      cout << char(bitM[i].to_ulong());

  }
      for (std::size_t i = 0; i <key.size(); ++i)
  {
      bitK[i] =  bitset<8>(key[i]);
      cout << char(bitK[i].to_ulong());
  }
cout <<endl<< "Message"<<"                    "<<"KEY"<<endl;
    // EVOLUTION
    for(gen=0;gen<gens;gen++)
    {
      for(ic=0;ic<M.size();ic++)
      {
          evolve39318(bitM[ic]);
          evolve39318(bitK[ic]);
          cout << bitM[ic].to_string() <<"                    "<<bitK[ic].to_string()<<endl;
      }

      for(ic=0;ic<M.size();ic++)cout << char(bitM[ic].to_ulong()); // OUTPUT STRING EQUIVALENT
      cout<<"                    ";
      for(ic=0;ic<key.size();ic++)cout << char(bitK[ic].to_ulong());
      cout <<endl;
      //system ("CLS"); // COOL
    }

    cout << "EVOLVED"<<endl;
    cout << "Encrypted message:";
    //XOR OPERATION ENCRYPTION
    for(ic=0;ic<M.size();ic++){
            for (int i = 0; i <= 7; i++)
            bitMs[ic][i] = bitM[ic][i] ^ bitK[ic][i]; // XOR KEY WITH THE MESSAGE

        cout << char(bitMs[ic].to_ulong()) ;    // ENCRYPTED OUTPUT
    }
    //DECRYPTION /////TODO
    cout <<endl<< "Decrypted message:";
    for(ic=0;ic<M.size();ic++){
            for (int i = 0; i <= 7; i++)
            bitMd[ic][i] = bitMs[ic][i] ^ bitK[ic][i]; // XOR KEY WITH THE ENCRYPTED MESSAGE

        //cout << char(bitMd[ic].to_ulong()) ;    // ENCRYPTED OUTPUT
    }
    //TODO
    return 0;
}
