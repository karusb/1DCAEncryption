/*
    BazCrypt 4 Neighbourhood Cellular Automata XOR Encryption
    Copyright (C) 2017  Baris Tanyeri

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.


*/

////////////////////////////////////////
////// SAMPLE MESSAGES AND KEYS ////////
//key = "Hgaj2q!zhquJ>Ak?qdk8wck;Subvol%18-0v_dnk49cvQjkzNUp&`aZqjv~-jsmdr}k£,@ajeI9MevK_jwQUH)yw<j4JNwqK$%ldshjbdKnQW^2u(hmls?ma}yLS=¬M"; //1024bit key
//2017B//
//"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Scis enim me quodam tempore Metapontum venisse tecum neque ad hospitem ante devertisse, quam Pythagorae ipsum illum locum, ubi vitam ediderat, sedemque viderim. Aufidio, praetorio, erudito homine, oculis capto, saepe audiebam, cum se lucis magis quam utilitatis desiderio moveri diceret. Nihil est enim, de quo minus dubitari possit, quam et honesta expetenda per se et eodem modo turpia per se esse fugienda. Duo Reges: constructio interrete. Ita fit illa conclusio non solum vera, sed ita perspicua, ut dialectici ne rationem quidem reddi putent oportere: si illud, hoc; Hic Speusippus, hic Xenocrates, hic eius auditor Polemo, cuius illa ipsa sessio fuit, quam videmus. Nec vero dico eorum metum mortis, qui, quia privari se vitae bonis arbitrentur, aut quia quasdam post mortem formidines extimescant, aut si metuant, ne cum dolore moriantur, idcirco mortem fugiant; Quibus rebus vita consentiens virtutibusque respondens recta et honesta et constans et naturae congruens existimari potest. Quibus autem in rebus tanta obscuratio non fit, fieri tamen potest, ut id ipsum, quod interest, non sit magnum. Ratio enim nostra consentit, pugnat oratio. Haec mirabilia videri intellego, sed cum certe superiora firma ac vera sint, his autem ea consentanea et consequentia, ne de horum quidem est veritate dubitandum. Itaque non discedit ab eorum curatione, quibus praeposita vitam omnem debet gubernare, ut mirari satis istorum inconstantiam non possim. Persecutus est Aristoteles animantium omnium ortus, victus, figuras, Theophrastus autem stirpium naturas omniumque fere rerum, quae e terra gignerentur, causas atque rationes; Eam tum adesse, cum dolor omnis absit; Quaeque de virtutibus dicta sunt, quem ad modum eae semper voluptatibus inhaererent, eadem de amicitia dicenda sunt. De maximma autem re eodem modo, divina mente atque natura mundum universum et eius maxima partis administrari. In homine autem summa omnis animi est et in animo rationis, ex qua virtus est, quae rationis absolutio definitur, quam etiam atque etiam explicandam putant.";
//5000 BITS
//"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Quod non faceret, si in voluptate summum bonum poneret. Eam stabilem appellas. Si stante, hoc natura videlicet vult, salvam esse se, quod concedimus; Duo Reges: constructio interrete. Virtutis, magnitudinis animi, patientiae, fortitudinis fomentis dolor mitigari solet. Et ille ridens: Video, inquit, quid agas; Nonne igitur tibi videntur, inquit, mala? Ex rebus enim timiditas, non ex vocabulis nascitur. Quae hic rei publicae vulnera inponebat, eadem ille sanabat. Quid enim de amicitia statueris utilitatis causa expetenda vides. Ubi ut eam caperet aut quando? Stup";
//20000BITS
//"Lorem ipsum dolor sit amet, consectetur adipiscing elit. Mihi, inquam, qui te id ipsum rogavi? Illud vero minime consectarium, sed in primis hebes, illorum scilicet, non tuum, gloriatione dignam esse beatam vitam, quod non possit sine honestate contingere, ut iure quisquam glorietur. Nec tamen exprimi verbum e verbo necesse erit, ut interpretes indiserti solent, cum sit verbum, quod idem declaret, magis usitatum. Hic homo severus luxuriam ipsam per se reprehendendam non putat, et hercule, Torquate, ut verum loquamur, si summum bonum voluptas est, rectissime non putat. Ut, inquit, in fidibus pluribus, nisi nulla earum non ita contenta nervis sit, ut concentum servare possit, omnes aeque incontentae sint, sic peccata, quia discrepant, aeque discrepant; Quanta autem ab illis varietas argumentorum ratione concludentium eorumque cum captiosis interrogationibus dissimilitudo! Quid, quod plurimis locis quasi denuntiant, ut neque sensuum fidem sine ratione nec rationis sensibus exquiramus? Et si in ipsa gubernatione neglegentia est navis eversa, maius est peccatum in auro quam in palea. Duo Reges: constructio interrete. Habes, inquam, Cato, formam eorum, de quibus loquor, philosophorum. Illud enim rectum est quod katortwma dicebas contingitque sapienti soli, hoc autem inchoati cuiusdam officii est, non perfecti, quod cadere in non nullos insipientes potest. Ut optime, secundum naturam affectum esse possit. In sapientem solum cadit, isque finis bonorum, ut ab ipsis Stoicis scriptum videmus, a Xenocrate atque ab Aristotele constitutus est. Sed si duo honesta proposita sint, alterum cum valitudine, alterum cum morbo, non esse dubium, ad utrum eorum natura nos ipsa deductura sit. Tenere autem virtutes eas ipsas, quarum modo feci mentionem, nemo poterit, nisi statuerit nihil esse, quod intersit aut differat aliud ab alio, praeter honesta et turpia. Quarum cum una sit, qua mores conformari putantur, differo eam partem, quae quasi stirps ets huius quaestionis. Equidem in omnibus istis conclusionibus hoc putarem philosophia nobisque dignum, et maxime, cum summum bonum quaereremus, vitam nostram, consilia, voluntates, non verba corrigi. Hic si Peripateticus fuisset, permansisset, credo, in sententia, qui dolorem malum dicunt esse, de asperitate autem eius fortiter ferenda praecipiunt eadem, quae Stoici. Vides igitur, si amicitiam sua caritate metiare, nihil esse praestantius, sin emolumento, summas familiaritates praediorum fructuosorum mercede superari. Praeclare enim Epi";
//Different 20000 BITS
//"Hic quoque suus est de summoque bono dissentiens dici vere Peripateticus non potest. Obscura, inquit, quaedam esse confiteor, nec tamen ab illis ita dicuntur de industria, sed inest in rebus ipsis obscuritas. Beatus sibi videtur esse moriens. Utrum enim sit voluptas in iis rebus, quas primas secundum naturam esse diximus, necne sit ad id, quod agimus, nihil interest. Nam et a te perfici istam disputationem volo, nec tua mihi oratio longa videri potest. Quae possunt eadem contra Carneadeum illud summum bonum dici, quod is non tam, ut probaret, protulit, quam ut Stoicis, quibuscum bellum gerebat, opponeret. Voluptatis causa, etiam si eam non consequare, aut non dolendi, etiam si id assequi nequeas, aut eorum, quae secundum naturam sunt, adipiscendi, etiam si nihil consequare. Ea, quae dialectici nunc tradunt et docent, nonne ab illis instituta sunt aut inventa sunt? Nos autem non solum beatae vitae istam esse oblectationem videmus, sed etiam levamentum miseriarum. An quae de prudentia, de cognitione rerum, de coniunctione generis humani, quaeque ab eisdem de temperantia, de modestia, de magnitudine animi, de omni honestate dicuntur? Vitae autem degendae ratio maxime quidem illis placuit quieta. Nam ceteris in rebus síve praetermissum sive ignoratum est quippiam, non plus incommodi est, quam quanti quaeque earum rerum est, in quibus neglectum est aliquíd. Eam si varietatem diceres, intellegerem, ut etiam non dicente te intellego; Ut enim, inquit, gubernator aeque peccat, si palearum navem evertit et si auri, item aeque peccat, qui parentem et qui servum iniuria verberat. Nonne videmus quanta perturbatio rerum omnium consequatur, quanta confusio? Nam si dicent ab illis has res esse tractatas, ne ipsos quidem Graecos est cur tam multos legant, quam legendi sunt. Quid enim mihi potest esse optatius quam cum Catone, omnium virtutum auctore, de virtutibus disputare? Quae hic rei publicae vulnera inponebat, eadem ille sanabat. Familiares nostros, credo, Sironem dicis et Philodemum, cum optimos viros, tum homines doctissimos. Quae iam oratio non a philosopho aliquo, sed a censore opprimenda est. Sic igitur in homine perfectio ista in eo potissimum, quod est optimum, id est in virtute, laudatur. Nunc idem, nisi molestum est, quoniam tibi non omnino displicet definire et id facis, cum vis, velim definias quid sit voluptas, de quo omnis haec quaestio est. Sed isti ipsi, qui voluptate et dolore omnia metiuntur, nonne clamant sapienti plus semper adesse quod velit quam q";

///////////////////////////////////////
#define GNULICENSE "    BazCrypt  Copyright (C) 2017  Baris Tanyeri \n  This program comes with ABSOLUTELY NO WARRANTY.\n    This is free software, and you are welcome to redistribute it \n    under certain conditions; refer to GNU V3 Public License."


#include <iostream>
using namespace std;
#include <bitset>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <math.h>
#include <cmath>
#include <string>
#include <iostream>


ofstream logfile;
void evolve39318(std::bitset<20000> &s,int nbytes);
void evolve57630z(std::bitset<20000> &s,int nbytes);
void evolve57630b(std::bitset<20000> &s,int nbytes);
int nonlinearity(std::bitset<8> &s);
int nonlinearityhalfone(std::bitset<8> &s);
int nonlinearityhalftwo(std::bitset<8> &s);
void pokertest(std::bitset<8> &s);
// Bit Values to search are defined here
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

int main(int argc,char *argv[])
{
    // GNU License Output //
    cout << GNULICENSE <<endl<<endl<<endl;
    // All Processes are logged in log.txt //

    int gens;
    unsigned int ic;
    int algo =0;
    string M;   // Message
    string encM; // Encrypted Message
    string key; // Key
    string q; // quit parameter
    string fname; //filename parametere
    string newfname;
    string tempt; //temp data
    ifstream inputdata; //input data
    ofstream keyout;
    ofstream linearityfile;
    ofstream linearityfiletwo;
    ofstream pokerfile;
    ofstream encfile;

    ofstream encbitfile;
    bool pass = true;
    bool filechoice = false;
    bool interactive = false;
    bool keyoutc = false;
    bool logtrail = false;
    bool statM = false;
    bool readback = false;
    bool encdebug =false;
    bool keyares = false;
    bool encbitout =false;
    bool newout = false;
    int tick = 0;
    system ("color 0A"); // Console colour green
    int gen=0;

    int argno = 1;
    if (argc <2)
    {
        cout << "No or few input arguments, interactive mode starting..."<<endl;
        interactive = true;
    }
    else
    {


        while (argv[argno]!= NULL)
        {

            //cout << argv[argno] << endl;
            if(argv[argno][0]==char('-'))
            {


                if (argv[argno]== string("-f"))
                {

                    //set file input
                    filechoice = true;
                    fname = argv[argno+1];
                    tick += 1;
                }
                if (argv[argno]== string("-n"))
                {

                    //set file input
                    newout = true;
                    newfname = argv[argno+1];
                    tick += 1;
                }
                if (argv[argno]==string("-g"))
                {
                    gens = atoi(argv[argno+1]);
                    if(gens > 0 )tick +=1;

                }
                if (argv[argno]==string("-m"))
                {
                    statM = true;
                    M =  argv[argno+1];
                    tick += 1;
                }
                if (argv[argno]==string("-p"))
                {
                    key = argv[argno+1];
                    tick +=1;
                }
                if (argv[argno]==string("-a") && int(argv[argno+1] >=0))
                {
                    algo = atoi(argv[argno+1]);
                }
                if (argv[argno] == string("-Ko"))
                {

                    keyoutc = true;
                }
                if (argv[argno] == string("-b"))
                {

                    encbitout = true;
                }
                if (argv[argno] == string("-Kr"))
                {

                    keyares = true;
                }
                if (argv[argno] == string("-R"))
                {
                    readback = true;
                }
                if (argv[argno] == string("-De"))
                {
                    encdebug = true;
                }
                if (argv[argno] == string("-L"))
                {

                    if(argv[argno+1] == string("0"))logtrail = false;
                    if(argv[argno+1] == string("1"))logtrail = true;
                }
            }
            else cout<< "Unexpected character as a parameter, ex: BazCrypt.exe -f myfile.txt -g 1500 -p 123abc -Ko -L 1"<<endl;
            argno += 1;
        }
        if (tick < 3)
        {
            cout << "Not enough combination of inputs, starting in interactive mode with defaults..."<<endl;
            interactive = true;
        }
    }
    if(logtrail)logfile.open("log.txt");
    if (interactive)
    {

        if(logtrail)logfile << "Main: User Input defined.." <<endl;
        cout << "Input generation number: ";
        cin >> gens;
        cout <<"Input pass phrase: ";
        cin >> key;
        cout <<"Choose : File (1) , Plain Text (0): ";
        cin >> filechoice;
    }
    if (filechoice)
    {
        if (interactive)cout << "Please enter the filename that is within the executable directory"<<endl;
        if (interactive)cin >> fname;
        inputdata.open(fname.c_str());
        inputdata.seekg(0, std::ios::end);
        M.reserve(inputdata.tellg());
        inputdata.seekg(0, std::ios::beg);

        M.assign((std::istreambuf_iterator<char>(inputdata)),
                 std::istreambuf_iterator<char>());
        inputdata.close();
    }
    else
    {

        if(!statM)
        {
            cout <<"Input message: ";
            cin.ignore();
            std::getline(std::cin,M,'\n');
        }
    }
    //cin>> M;
    if(logtrail)logfile << "Main: User Input entered.. using option" <<filechoice<<endl;
    if(logtrail)logfile << "Main: Evolving for " << gens << "  generations "<<endl;


    // Define Bitsets to hold message and CA world

    bitset<8> bitM[M.size()];
    bitset<8> bitK[M.size()];
    bitset<8> bitKn[M.size()];
    bitset<20000> K;
    K.reset();
    bitset<20000> Kd;
    bitset<8> bitMs[M.size()];

    if(logtrail)logfile << "Main: bitsets defined..." <<endl;
    int b=0;
    int nbits = M.size()*8; //bits in the string
    int by=0;

    // String to BITSET CONVERSIONS
    if(readback)cout <<"Plain:";
    for (std::size_t i = 0; i < M.size(); ++i)
    {
        bitM[i] =  bitset<8>(M[i]);
        if(readback)cout << char(bitM[i].to_ulong());

    }

    if(logtrail)logfile << "Main:  Message ASCII to boolean conversions complete" <<endl;

    cout <<endl<<endl<<"Key:";

    if(readback)if(key.size() < M.size())
        {
            if(logtrail)logfile << "Main: input Key less than Message size.. regenerating key.." <<endl;
            for(unsigned int i=0; i<M.size(); i++)
            {
                int cur=(i%key.size());

                bitKn[i] = bitset<8>(key[cur]);
                bitK[i] = bitset<8>(key[cur]);
                //for(int ic=0;i<128; i++)evolve39318(bitKn[ic]);
                if(readback)cout << char(bitKn[i].to_ulong());
            }
        }
        else
        {
            // This case is very unlikely considering a large message
            if(logtrail)logfile << "Main: Key size text size equal or key bigger.." <<endl;
            for(unsigned int i=0; i<M.size(); ++i)
            {
                bitKn[i] =  bitset<8>(key[i]);
                bitK[i]=  bitset<8>(key[i]);
                if(readback)cout << char(bitKn[i].to_ulong());
            }
        }

    //TRANSFER PASSWORD TO A BIGGER WORLD
    for (std::size_t i = 0; i < M.size()*8; ++i)
    {
        K[i] = bitKn[b].test(i%8); // check the values in bitKn
        if(i%8 == 0)b+=1; // Increase b at every 8 iterations
    }
    if(logtrail)logfile << "Main: IV transferred to bigger world.." <<endl;

    if(encdebug)cout <<endl<< "Message"<<"                    "<<"KEY"<<endl;

    do
    {
        by=0;
        // EVOLUTION
        if(logtrail)logfile << "Main: Starting evolution.." <<endl;
        if (pass)
        {
            for(gen=0; gen<gens; gen++)
            {
                switch (algo)
                {
                case 0:
                    evolve57630b(K,M.size()); // This is done over the entire world doesnt need another loop
                    if(logtrail)logfile << "evolve57630b: Evolving.. with boolean" <<endl;
                    break;
                case 1:
                    evolve57630z(K,M.size());
                    if(logtrail)logfile << "evolve57630z: Evolving.. with zero boundary boolean" <<endl;
                    break;
                case 2:
                    evolve39318(K,M.size());
                    if(logtrail)logfile << "evolve38318: Evolving.." <<endl;
                    break;
                default:
                    evolve57630b(K,M.size());
                    break;
                }
                if(encdebug)
                {

                    for(ic=0; ic<M.size(); ic++)
                    {
                        // Use Deprecated Functions here

                        cout << bitM[ic].to_string() <<"                    "<<bitK[ic].to_string()<<endl;

                    }
                    for(ic=0; ic<M.size(); ic++)cout << char(bitM[ic].to_ulong()); // OUTPUT STRING EQUIVALENT
                    cout<<"                    ";
                    for(ic=0; ic<key.size(); ic++)cout << char(bitKn[ic].to_ulong());
                    cout <<endl;
                    // system ("CLS"); // COOL
                }
            }
        }
        else
        {
            switch (algo)
            {
            case 0:
                evolve57630b(K,M.size()); // This is done over the entire world doesnt need another loop
                if(logtrail)logfile << "evolve57630b: Evolving.. with boolean (pass)" <<endl;
                break;
            case 1:
                evolve57630z(K,M.size());
                if(logtrail)logfile << "evolve57630z: Evolving.. with zero boundary boolean (pass)" <<endl;
                break;
            case 2:
                evolve39318(K,M.size());
                if(logtrail)logfile << "evolve38318: Evolving.. (pass)" <<endl;
                break;
            default:
                evolve57630b(K,M.size());
                break;
            }
            gens = gens +1;
            cout << endl << "Your new generation number: " <<gens <<endl;
            cout << endl << "NOTE YOUR NEW GENERATION NUMBER !" << endl;
        }

        if(keyoutc)keyout.open("keyout.txt");

        // SPLIT THE WORLD IN SMALLER WORLDS
        for (int i = 0; i <= nbits-1; i++)
        {
            bitKn[by].set(i%8,K.test(i));

            if(keyoutc)keyout << K.test(i);

            if(i%8==0)by+=1;
        }

        if(keyoutc)keyout.close();

        if(logtrail)logfile << "Main: Evolution complete .." <<endl;
        cout <<endl<< "EVOLVED"<<endl<<endl;
        cout << "Encrypted message:";
        //XOR OPERATION ENCRYPTION
        int oncount=0;
        //int oncountone=0,oncounttwo=0;

        if(logtrail)logfile << "Main: Show cryptanalysis defined.." <<endl;


        //linearityfile.open("nonlinearitydata.txt");
        if(keyares)linearityfiletwo.open("nonlinearitydata8.txt");
        if(keyares)pokerfile.open("pokerfile.txt");
        if (newout)encfile.open(newfname.c_str());
        else encfile.open(fname.c_str());
        if(encbitout)encbitfile.open("encbitfile.txt");

        if(logtrail)logfile << "Main: Opening files complete.." <<endl;

        if(logtrail)logfile << "Main: Encryption started.." <<endl;

        for(ic=0; ic<M.size(); ic++)
        {
            for (int i = 0; i <= 7; i++)
                bitMs[ic][i] = bitM[ic][i] ^ bitKn[ic][i]; // XOR KEY WITH THE MESSAGE
            // Bit count functions
            oncount += nonlinearity(bitKn[ic]);
            //oncountone += nonlinearityhalfone(bitKn[ic]);
            //oncounttwo += nonlinearityhalftwo(bitKn[ic]);

            //TEST LINEARITY
            //linearityfile << (nonlinearityhalfone(bitKn[ic])*100)/(4) <<endl;
            //linearityfile << (nonlinearityhalftwo(bitKn[ic])*100)/(4) <<endl;
            if(keyares)linearityfiletwo << (nonlinearity(bitKn[ic])*100)/(8) <<endl;
            if(keyares)pokertest(bitKn[ic]);
            encfile << char(bitMs[ic].to_ulong());
            if(encbitout)encbitfile << bitMs[ic].to_string();

            cout << char(bitMs[ic].to_ulong()) ;    // ENCRYPTED OUTPUT

        }
        if(logtrail)logfile << "Main: Encryption finished running.." <<endl;
        double monoout= erfc(double(double(double(std::abs(double(oncount-((M.size()*8)-oncount))))/double((sqrt(M.size()*8))))/sqrt(2))); // This is the monobit magic equation of NIST SP800
        if(monoout<0.01) // Needs to be >0.01
        {
            cout <<endl<<"Failed to pass monobits test"<<endl;
            if(logtrail)logfile << "Main: Failed to pass monobits test.." <<endl;
            pass =  false;
        }
        else
        {
            pass = true;
            cout << endl <<"Pass..."<<endl;
        }


        if(keyares)
        {
            if(logtrail)logfile << "Main: Outputting properties.." <<endl;
            cout <<endl<< "Poker Test results:" << endl;

            for(int iw=0; iw<16; iw++)
            {
                pokerfile << statArr[iw] << endl;
                cout << iw <<" : " << statArr[iw] <<endl;
            }

            cout <<endl <<"Monobits2:" << ((oncount)*100)/(8*M.size()) << endl;
            //linearityfile.close();
            linearityfiletwo.close();
            pokerfile.close();
        }
        encfile.close();
        if(encbitout)encbitfile.close();


        if(pass==false)system("CLS");
    }
    while(pass==false);
    if(logtrail)logfile << "Main: Files are closed" <<endl;

    if(logtrail)logfile << "Main:finished running.." <<endl;
    if(logtrail)logfile.close();
    cout << endl << endl<< "Encrypt & Decrypt Complete Press Any Key then Enter to Continue..."<<endl;
    cin >> q ;
    return 0;
}
// EVOLVE FUNCTIONS
// Inputs MUST be a bitset of 20000 bits
// Nbytes is the message size in bytes which determines the boundaries of evolution within the world
void evolve39318(std::bitset<20000> &s,int nbytes)
{

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
void evolve57630b(std::bitset<20000> &s,int nbytes) //CYCLIC BOUNDARY EVOLUTION
{
    int i=0,nbits=0;
    nbits = nbytes*8;

    std::bitset<20000> t;

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
// Bit counting functions that takes a bitset of 8 bits as input
// Half functions counts the half of the set hence 2 functions "halfone" "halftwo"
int nonlinearity(std::bitset<8> &s)
{

    int oncount=0;
    for(int i=0; i < 8 ; i++)
    {
        (s[i] == 1)?oncount++:oncount=oncount;
    }
    return oncount;
}
int nonlinearityhalfone(std::bitset<8> &s)
{

    int oncount=0;
    for(int i=0; i < 4 ; i++)
    {
        (s[i] == 1)?oncount++:oncount=oncount;
    }
    return oncount;
}
int nonlinearityhalftwo(std::bitset<8> &s)
{

    int oncount=0;
    for(int i=4; i < 8 ; i++)
    {
        (s[i] == 1)?oncount++:oncount=oncount;
    }
    return oncount;
}

// Poker test functions takes bitsets of 8 which counts the occurences of the bit values given in array bitval
void pokertest(std::bitset<8> &s)
{
    for(int i=0; i <= 5 ; i+=4) // iterates twice for 8 bits
    {
        for(int t=0; t<61; t+=4) //go through bitvals
        {
            if(s[i] == bitval[t] && s[i+1] == bitval[t+1] && s[i+2] == bitval[t+2] && s[i+3] == bitval[t+3]) // CHECK THE OCCURRENCES SPECIFIED IN BITVAL
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
