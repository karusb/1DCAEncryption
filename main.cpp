#define nUSER_Input    //SET USER_Input to allow user input
#define NODEBUG_MODE // SET DEBUG_MODE FOR VISUAL
#define SHOW_Properties // SET SHOW_Properties for show analysis results
#define nFAST_Decrypt // SET FAST ENCRYPTION ONLY TO DEMONSTRATE!
#define KEY     "nottingham"
#define GENERATIONS 3354
#define MESSAGE "alicansokaksanatcisi"


#include <iostream>
using namespace std;
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#define SIZE 32


ofstream logfile;

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
                           1,1,1,1
                          };
int statArr[16]= {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
/* TRY USING ZEROES FOR SPECIFIC DECLARATIONS IN EVOLVE FUNCTIONS WHEN THEY ARE OUT OF SCOPE*/
void evolve39318(std::bitset<20000> &s,int nbytes)
{
    logfile << "evolve38318: Evolving.." <<endl;

    // VERY REPETITIVE RESULTS?
    // RULE 39318 4N

    int i=0,nbits=0;
    nbits = nbytes*8;

    std::bitset<20000> t;
    t[0] = s[0] ^ s[1] ^ (s[nbits-2] | s[nbits-1]);
    t[1] = s[1] ^ s[2] ^ (s[nbits-1] | s[0]);
    t[nbits-1] = s[nbits-1] ^ s[0] ^ (s[nbits-3] | s[nbits-2]);
    for (i = 2; i < nbits-1; i++)
    {
        t[i] = s[i] ^ s[i+1] ^ (s[i-2] | s[i-1]);
    }

    for (i = 0; i <= nbits-1; i++)s[i] = t[i];
}
void evolve57630z(std::bitset<20000> &s,int nbytes) //ZERO BOUNDARY EVOLUTION
{
    int i=0,nbits=0;
    nbits = nbytes*8;

    std::bitset<20000> t;
    logfile << "evolve57630b: Evolving.. with zero boundary boolean" <<endl;
    // RULE 57630 4N
    t[0] = 0 ^ 0 ^ (s[0] | s[1]);
    t[1] = 0 ^ s[0] ^ (s[1] | s[2]);
    t[nbits-1] = s[nbits-3] ^ s[nbits-2] ^ (s[nbits-1] | 0);
    for (i = 2; i < nbits-1; i++)
    {
        t[i] = s[i-2] ^ s[i-1] ^ (s[i] | s[i+1]);
    }

    for (i = 0; i <= nbits-1; i++)s[i] = t[i];
}
void evolve57630b(std::bitset<20000> &s,int nbytes) //ZERO BOUNDARY EVOLUTION
{
    int i=0,nbits=0;
    nbits = nbytes*8;

    std::bitset<20000> t;
    logfile << "evolve57630b: Evolving.. with boolean" <<endl;
    // RULE 57630 4N
    t[0] = s[nbits-2] ^ s[nbits-1] ^ (s[0] | s[1]);
    t[1] = s[nbits-1] ^ s[0] ^ (s[1] | s[2]);
    t[nbits-1] = s[nbits-3] ^ s[nbits-2] ^ (s[nbits-1] | s[0]);
    for (i = 2; i < nbits-1; i++)
    {
        t[i] = s[i-2] ^ s[i-1] ^ (s[i] | s[i+1]);
    }

    for (i = 0; i <= nbits-1; i++)s[i] = t[i];

}

int nonlinearity(std::bitset<8> &s)
{
    logfile << "nonlinearity: Nonlinearity count on 8 bits starting.." <<endl;
    int oncount=0;
    for(int i=0; i < 8 ; i++)
    {
        (s[i] == 1)?oncount++:oncount=oncount;
    }
    return oncount;
}
int nonlinearityhalfone(std::bitset<8> &s)
{
    logfile << "nonlinearityhalfone: Nonlinearity count on first half starting.." <<endl;
    int oncount=0;
    for(int i=0; i < 4 ; i++)
    {
        (s[i] == 1)?oncount++:oncount=oncount;
    }
    return oncount;
}
int nonlinearityhalftwo(std::bitset<8> &s)
{
    logfile << "nonlinearityhalftwo: Nonlinearity count on second half starting.." <<endl;
    int oncount=0;
    for(int i=4; i < 8 ; i++)
    {
        (s[i] == 1)?oncount++:oncount=oncount;
    }
    return oncount;
}
void pokertest(std::bitset<8> &s)
{
    logfile << "pokertest: Starting pokertest for given bits.." <<endl;
    for(int i=0; i < 5 ; i+=4)
    {
        for(int t=0; t<61; t+=4)
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
                            {
                                statArr[t/4] = statArr[t/4] +1;
                            }
                            else
                            {
                                statArr[t]=statArr[t]+1;
                            }
                        }
                    }
                }

            }
        }

    }
}
int main()
{
    logfile.open("log.txt");
    int gens;
    int ic;
    string M;
    string encM;
    string key;
    string choice;
    system ("color 0A");
    int gen=0;
    logfile << "Main: Init variables complete.." <<endl;
#ifdef USER_Input
    logfile << "Main: User Input defined.." <<endl;
    cout << "Input generation number: ";
    cin >> gens;
    cout <<"Input pass phrase: ";
    cin >> key;
    cout <<"Input message: ";
    cin >> M;
    logfile << "Main: User Input entered.." <<endl;
#else
    // SUBDIVIDE NON LINEARITY TOCREATE HISTOGRAM

    gens = GENERATIONS;
    key = KEY;
//    M = MESSAGE;
    //gens = 78;
    //key = "Hgaj2q!zhquJ>Ak?qdk8wck;Subvol%18-0v_dnk49cvQjkzNUp&`aZqjv~-jsmdr}k£,@ajeI9MevK_jwQUH)yw<j4JNwqK$%ldshjbdKnQW^2u(hmls?ma}yLS=¬M"; //1024bit key
    //key = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
    //M   = "This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER "; //Long message
    //M   = "This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER This is a secret message, Tell Everyone to change Baris Tanyeri's grades to 100, his student id is 4183078, Regards Your MASTER "; //Long message 2048B
//2017B//
    //M = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Scis enim me quodam tempore Metapontum venisse tecum neque ad hospitem ante devertisse, quam Pythagorae ipsum illum locum, ubi vitam ediderat, sedemque viderim. Aufidio, praetorio, erudito homine, oculis capto, saepe audiebam, cum se lucis magis quam utilitatis desiderio moveri diceret. Nihil est enim, de quo minus dubitari possit, quam et honesta expetenda per se et eodem modo turpia per se esse fugienda. Duo Reges: constructio interrete. Ita fit illa conclusio non solum vera, sed ita perspicua, ut dialectici ne rationem quidem reddi putent oportere: si illud, hoc; Hic Speusippus, hic Xenocrates, hic eius auditor Polemo, cuius illa ipsa sessio fuit, quam videmus. Nec vero dico eorum metum mortis, qui, quia privari se vitae bonis arbitrentur, aut quia quasdam post mortem formidines extimescant, aut si metuant, ne cum dolore moriantur, idcirco mortem fugiant; Quibus rebus vita consentiens virtutibusque respondens recta et honesta et constans et naturae congruens existimari potest. Quibus autem in rebus tanta obscuratio non fit, fieri tamen potest, ut id ipsum, quod interest, non sit magnum. Ratio enim nostra consentit, pugnat oratio. Haec mirabilia videri intellego, sed cum certe superiora firma ac vera sint, his autem ea consentanea et consequentia, ne de horum quidem est veritate dubitandum. Itaque non discedit ab eorum curatione, quibus praeposita vitam omnem debet gubernare, ut mirari satis istorum inconstantiam non possim. Persecutus est Aristoteles animantium omnium ortus, victus, figuras, Theophrastus autem stirpium naturas omniumque fere rerum, quae e terra gignerentur, causas atque rationes; Eam tum adesse, cum dolor omnis absit; Quaeque de virtutibus dicta sunt, quem ad modum eae semper voluptatibus inhaererent, eadem de amicitia dicenda sunt. De maximma autem re eodem modo, divina mente atque natura mundum universum et eius maxima partis administrari. In homine autem summa omnis animi est et in animo rationis, ex qua virtus est, quae rationis absolutio definitur, quam etiam atque etiam explicandam putant.";
    //key="nottingham";
    M = "I need help at location NG7 2RD arrive ASAP";
    choice = "n";

#endif // Static_Input
    bitset<8> bitM[M.size()];
    bitset<8> bitK[M.size()];
    //if(M.size()<128)bitset<8> bitKn[128];
    bitset<8> bitKn[M.size()];
    bitset<20000> K;
    bitset<20000> Kd;
    bitset<8> bitMs[M.size()];
    bitset<8> bitMd[M.size()];
    float nonlineardata [M.size()];
    logfile << "Main: bitsets defined..." <<endl;
    int b=0;
    int nbits = M.size()*8;
    int by=0;
    // BITSET CONVERSIONS
    cout <<"Plain:";
    for (std::size_t i = 0; i < M.size(); ++i)
    {
        bitM[i] =  bitset<8>(M[i]);
        cout << char(bitM[i].to_ulong());

    }

    logfile << "Main:  Message ASCII to boolean conversions complete" <<endl;
//    if(key.size() < M.size())
//    {
//        int t=0;
//        for(int i=key.size(); i<M.size(); i++)
//        {
//            bitKn[i] =  bitset<8>(key[t]);
//            bitK[i] = bitset<8>(key[t]);
//            if(t==key.size())t=0;
//            t+=1;
//        }
//    }
    cout <<endl<<endl<<"Key:";
    // TODO : USE SHA256 FOR KEY
    if(key.size() < 128)
    {
        logfile << "Main: input Key less than 128.. regenerating key.." <<endl;
        for(int i=0; i<M.size(); i++)
        {
            int cur=(i%key.size());

            bitKn[i] = bitset<8>(key[cur]);
            bitK[i] = bitset<8>(key[cur]);
            //for(int ic=0;i<128; i++)evolve39318(bitKn[ic]);
            cout << char(bitKn[i].to_ulong());
        }
    }
    else
    {
        logfile << "Main: Key size bigger than 128.. scaling key..." <<endl;
        for(int i=0; i<128; ++i)
        {
            bitKn[i] =  bitset<8>(key[i]);
            bitK[i]=  bitset<8>(key[i]);
            cout << char(bitKn[i].to_ulong());
        }
    }

    //TRANSFER PASSWORD TO A BIGGER WORLD
    for (std::size_t i = 0; i < M.size()*8; ++i)
    {
        K[i] = bitKn[b].test(i%8);
        Kd[i] = K[i];
        if(i%8 == 0)b+=1;
    }
    logfile << "Main: IV transferred to bigger world.." <<endl;
#ifdef DEBUG_MODE
    cout <<endl<< "Message"<<"                    "<<"KEY"<<endl;
#endif // DEBUG_MODE
    // TODO: RESHAPE USER KEY HERE TO OBTAIN 1024 bit key
    // EVOLUTION
    logfile << "Main: Starting evolution.." <<endl;
    for(gen=0; gen<gens; gen++)
    {
        evolve57630b(K,M.size()); // This is done over the entire world doesnt need another loop
        for(ic=0; ic<M.size(); ic++)
        {
            //evolve39318(bitM[ic]);
            //original// evolve57630z(bitKn[ic]);

            //evolve39318(bitK[ic]);
            //devolve57630(bitK[ic]);
#ifdef DEBUG_MODE
            cout << bitM[ic].to_string() <<"                    "<<bitK[ic].to_string()<<endl;
#endif // DEBUG_MODE
        }
#ifdef DEBUG_MODE
        for(ic=0; ic<M.size(); ic++)cout << char(bitM[ic].to_ulong()); // OUTPUT STRING EQUIVALENT
        cout<<"                    ";
        for(ic=0; ic<key.size(); ic++)cout << char(bitKn[ic].to_ulong());
        cout <<endl;
        // system ("CLS"); // COOL
#endif // DEBUG_MODE
    }

    // SPLIT THE WORLD IN SMALLER WORLDS
    for (int i = 0; i <= nbits-1; i++)
    {
        bitKn[by].set(i%8,K.test(i));

        if(i%8==0)by+=1;
    }

    logfile << "Main: Evolution complete .." <<endl;
    cout <<endl<< "EVOLVED"<<endl<<endl;
    cout << "Encrypted message:";
    //XOR OPERATION ENCRYPTION
    int oncount=0;
    int oncountout=0,oncountone=0,oncounttwo=0;
#ifdef SHOW_Properties
    logfile << "Main: Show cryptanalysis defined.." <<endl;
    ofstream linearityfile;
    ofstream linearityfiletwo;
    ofstream pokerfile;
    ofstream encfile;
    ofstream encbitfile;
    //ofstream pokerfiletwo;
    linearityfile.open("nonlinearitydata.txt");
    linearityfiletwo.open("nonlinearitydata8.txt");
    pokerfile.open("pokerfile.txt");
    encfile.open("encfile.txt");
    encbitfile.open("encbitfile.txt");
    //pokerfiletwo.open("pokerfile2.txt");
    logfile << "Main: Opening files complete.." <<endl;
#endif // SHOW_Properties
    logfile << "Main: Encryption started.." <<endl;
    for(ic=0; ic<M.size(); ic++)
    {
        for (int i = 0; i <= 7; i++)
            bitMs[ic][i] = bitM[ic][i] ^ bitKn[ic][i]; // XOR KEY WITH THE MESSAGE
        oncount += nonlinearity(bitKn[ic]);
        oncountone += nonlinearityhalfone(bitKn[ic]);
        oncounttwo += nonlinearityhalftwo(bitKn[ic]);
#ifdef SHOW_Properties
        //TEST LINEARITY
        linearityfile << (nonlinearityhalfone(bitKn[ic])*100)/(4) <<endl;
        linearityfile << (nonlinearityhalftwo(bitKn[ic])*100)/(4) <<endl;
        linearityfiletwo << (nonlinearity(bitKn[ic])*100)/(8) <<endl;
        pokertest(bitKn[ic]);
#endif // SHOW_Properties
        cout << char(bitMs[ic].to_ulong()) ;    // ENCRYPTED OUTPUT
        encfile << char(bitMs[ic].to_ulong());
        encbitfile << bitMs[ic].to_string();
    }
    logfile << "Main: Encryption finished running.." <<endl;
    double monoout= erfc(double(double(double(oncount-((M.size()*8)-oncount))/double(M.size()*8))/sqrt(2)));
    if(monoout<0.01)
    {
        cout <<endl<<"Failed to pass monobits test"<<endl;
        logfile << "Main: Failed to pass monobits test.." <<endl;
    }
#ifdef SHOW_Properties
    logfile << "Main: Outputting properties.." <<endl;
    cout <<endl<< "Poker Test results:" << endl;
    for(int iw=0; iw<16; iw++)
    {
        pokerfile << statArr[iw] << endl;
        cout << iw <<" : " << statArr[iw] <<endl;
    }

    cout <<endl <<"Monobits:"<<monoout<<endl;
    //printf("%.10f",monoout);
    cout <<endl <<"Monobits2:" << ((oncountone+oncounttwo)*100)/(8*M.size()) << endl;
    linearityfile.close();
    linearityfiletwo.close();
    pokerfile.close();
    encfile.close();
    encbitfile.close();
#endif // SHOW_Properties

    //pokerfiletwo.close();
    //DECRYPTION
    logfile << "Main: Files are closed" <<endl;
#ifdef FAST_Decrypt
    logfile << "Main: Fast decryption defined using the already generated key on memory.." <<endl;
    cout <<endl<<endl<< "Decrypted message:";
    for(ic=0; ic<M.size(); ic++)
    {
        for (int i = 0; i <= 7; i++)
            bitMd[ic][i] = bitMs[ic][i] ^ bitKn[ic][i]; // XOR EVOLVED KEY WITH THE ENCRYPTED MESSAGE

        cout << char(bitMd[ic].to_ulong()) ;    // DECRYPTED OUTPUT
    }
    logfile << "Main: Decryption finished running.." <<endl;
    ////////////////////////////////////////////////
#else
    logfile << "Main: Manual decryption defined starting decryption using the previously input key.." <<endl;
    ofstream decfile;
    decfile.open("decfile.txt");
    for(int gen=0; gen<gens; gen++)
    {
        evolve57630b(Kd,M.size()); // this needs to be here explained in encryption
        for(ic=0; ic<M.size(); ic++)
        {
            //evolve39318(bitM[ic]);
            //original//evolve57630z(bitK[ic]);

            //evolve39318(bitK[ic]);
            //devolve57630(bitK[ic]);
#ifdef DEBUG_MODE
            cout << bitM[ic].to_string() <<"                    "<<bitK[ic].to_string()<<endl;
#endif // DEBUG_MODE
        }
#ifdef DEBUG_MODE
        for(ic=0; ic<M.size(); ic++)cout << char(bitM[ic].to_ulong()); // OUTPUT STRING EQUIVALENT
        cout<<"                    ";
        for(ic=0; ic<key.size(); ic++)cout << char(bitK[ic].to_ulong());
        cout <<endl;
        // system ("CLS"); // COOL
#endif // DEBUG_MODE
    }

    by=0;
    // SPLIT THE WORLD IN SMALLER WORLDS
    for (int i = 0; i <= nbits-1; i++)
    {
        bitK[by].set(i%8,Kd.test(i));

        if(i%8==0)by+=1;
    }
    logfile << "Main: Decrypting message and outputting to the screen.." <<endl;
    cout <<endl<<endl<< "Decrypted message:";
    for(ic=0; ic<M.size(); ic++)
    {
        for (int i = 0; i <= 7; i++)
            bitMd[ic][i] = bitMs[ic][i] ^ bitK[ic][i]; // XOR EVOLVED KEY WITH THE ENCRYPTED MESSAGE

        cout << char(bitMd[ic].to_ulong()) ;    // DECRYPTED OUTPUT
        decfile << char(bitMd[ic].to_ulong());
    }
#endif
    logfile << "Main:finished running.." <<endl;
    logfile.close();
    return 0;
}
/* DEPRECATED FUNCTIONS: DO NOT USE UNLESS YOU KNOW WHAT YOU ARE DOING
void evolve57630(std::bitset<8> &s)
{
    int i;
    std::bitset<8> t;
    logfile << "evolve57630: Evolving..." <<endl;
    // RULE 57630 4N
    t[0] = s[6] ^ s[7] ^ (s[0] | s[1]);
    t[1] = s[7] ^ s[0] ^ (s[1] | s[2]);
    t[7] = s[5] ^ s[6] ^ (s[7] | s[0]);
    for (i = 2; i < 7; i++)
    {
        t[i] = s[i-2] ^ s[i-1] ^ (s[i] | s[i+1]);


    }

    // REWRITE TO ARRAY
    for (i = 0; i <= 7; i++)s[i] = t[i];
}
////////////////////TODO DO NOT USE
void devolve57630(std::bitset<8> &s)
{
    int i;
    std::bitset<8> t;
    logfile << "devolve57630: 'd'Evolving.." <<endl;
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
*/
