// ===== SAMURAI v1.0 =====
// A game by Matt Kaczmarek

#include <iostream> // console display
#include <string> // for names
#include <math.h> // pow(a, b) function
#include <cstdlib> // random numbers
#include <ctime> // using clock time for seeded random numbers
using namespace std;

void instructions()
{
    cout << endl;
    cout << "================ SAMURAI ================" << endl;
    cout << endl;
    cout << "> The goal of the game is to defeat as many Ronin as possible." << endl;
    cout << "> You can attack, counter, or wait." << endl;
    cout << "> Attack beats wait, wait beats counter, counter beats wait." << endl;
    cout << "> Waiting makes your opponent mad, and countering makes them wary." << endl;
    cout << "> Enter 'q' at any point to quit the game." << endl;
    cout << "> Press 'Enter' to continue: ";
    cin.ignore(); // wait for user
}

int main()
{
    // Variables
    int wins;
    int hp;
    int maxHP = 3; // never changes
    string eName;
    int eAggro;
    int eHP;
    int eMove;
    int will;
    char userAction;
    
    // 173 given names
    string names[173] = { "AKI", "AKIHIKO", "AKIHIRO", "AKIO", "AKIRA", "AOI", "ARATA", "ATSUSHI", "DAI", "DAICHI", "DAIKI", "DAISUKE", "EIJI", "FUMIO", "GOROU", "HACHIRO", "HAJIME", "HARU", "HARUO", "HIDEAKI", "HIDEKI", "HIDEO", "HIKARU", "HIRO", "HIROAKI", "HIROKI", "HIROSHI", "HIROYUKI", "HISAO", "HISASHI", "HISOKA", "HITOSHI", "HOTAKA", "ICHIROU", "ISAMU", "ISAO", "IWAO", "IZANAGI", "JIROU", "JUN", "JUNICHI", "JUROU", "KAEDE", "KATASHI", "KATSU", "KATSUMI", "KATSUO", "KATSURO", "KAZUHIKO", "KAZUHIRO", "KAZUKI", "KAZUO", "KEI", "KEIICHI", "KEIJI", "KEN", "KENICHI", "KENJI", "KENSHIN", "KENTA", "KICHIROU", "KIN", "KIYOSHI", "KOHAK", "KOICHI", "KOJI", "KOU", "KUNIO", "KUROU", "KYOU", "MADOKA", "MAKOTO", "MAMORU", "MANABU", "MASA", "MASAAKI", "MASAHIKO", "MASAHIRO", "MASAKI", "MASANORI", "MASAO", "MASARU", "MASASHI", "MASATO", "MASAYOSHI", "MASAYUKI", "MASUMI", "MICHI", "MICHIO", "MIKIO", "MINORI", "MINORU", "MITSUO", "MITSURU", "NAO", "NAOKI", "NOBORU", "NOBU", "NOBUO", "NOBUYUKI", "NORI", "NORIO", "OROCHI", "OSAMU", "RAIDEN", "ROKURO", "RYO", "RYOTA", "RYUU", "SABURO", "SADAO", "SATORU", "SATOSHI", "SEIICHI", "SEIJI", "SHICHIRO", "SHIGEO", "SHIGERU", "SHIN", "SHINICHI", "SHINJI", "SHIRO", "SHOICHI", "SHOJI", "SHOU", "SHUICHI", "SHUJI", "SORA", "SUSUMU", "TADAO", "TADASHI", "TAKAHIRO", "TAKAO", "TAKASHI", "TAKAYUKI", "TAKEHIKO", "TAKEO", "TAKESHI", "TAKUMI", "TAMOTSU", "TARO", "TATSUO", "TATSUYA", "TERUO", "TETSUO", "TETSUYA", "TOMIO", "TORU", "TOSHI", "TOSHIAKI", "TOSHIO", "TOSHIYUKI", "TSUNEO", "TSUTOMU", "TSUYOSHI", "YASUHIRO", "YASUO", "YASUSHI", "YOICHI", "YOSHIAKI", "YOSHIHIRO", "YOSHIKAZU", "YOSHINORI", "YOSHIO", "YOSHIRO", "YOSHITO", "YOSHIYUKI", "YUICHI", "YUJI", "YUKIO", "YUTAKA", "YUU", "YUUDAI" };

    // Game loop
    while (userAction != 'q')
    {
        // Show instructions
        instructions();

        // Reset player stats
        wins = 0;
        hp = 3;
        wins = 0;

        // Generate new random seed
        srand(time(0));

        while (hp > 0)
        {
            // Generate enemy
            eName = names[rand() % 173];
            eAggro = 10 + (rand() % 30); // 25 +/- 15
            eHP = 3;

            // Start fight
            cout << "\n=+=+=+ " << "Opponent #" << wins+1 << ": " << eName << " +=+=+=\n";

            while (hp > 0 & eHP > 0)
            {
                // Enemy move
                will = eAggro + (rand() % 100);
                if (will > 125)
                {
                    eMove = 1; // attack
                } else if (will < 75)
                {
                    eMove = 2; // counter
                } else
                {
                    eMove = 3; // wait
                }

                // Player move
                cout << "\n> HP = " << hp << endl;
                cout << "> Enemy HP = " << eHP << endl;
                cout << "> 1) Attack, 2) Counter, 3) Wait: ";
                do
                {
                    try
                    {
                        cin >> userAction;
                    } catch (int e)
                    {
                        cout << "> Invalid move" << endl;
                    }
                } while (userAction != 'q' & userAction != '1' & userAction != '2' & userAction != '3' );

                // if input is q, end the program
                if (userAction == 'q') {
                    return 0;
                }

                // Result
                cout << endl;
                if (eMove == 1 & userAction == '1')
                {
                    cout << "> You and your opponent cross swords." << endl;
                } else if (eMove == 2 & userAction == '1')
                {
                    cout << "> Your opponent counters your attack." << endl;
                    hp -= 1;
                } else if (eMove == 3 & userAction == '1')
                {
                    cout << "> You catch your opponent off guard." << endl;
                    eHP -= 1;
                } else if (eMove == 1 & userAction == '2')
                {
                    cout << "> You counter your opponent's attack." << endl;
                    eHP -= 1;
                } else if (eMove == 2 & userAction == '2')
                {
                    cout << "> You both stand ready, but nothing happens." << endl;
                } else if (eMove == 3 & userAction == '2')
                {
                    cout << "> You stand ready, but your opponent hesitates." << endl;
                } else if (eMove == 1 & userAction == '3')
                {
                    cout << "> Your opponent catches you off guard." << endl;
                    hp -= 1;
                } else if (eMove == 2 & userAction == '3')
                {
                    cout << "> Your opponent stands ready, but you wait." << endl;
                } else if (eMove == 3 & userAction == '3')
                {
                    cout << "> You and your opponent stare at each other menacingly." << endl;
                }

                // Update aggro
                if (userAction == '2')
                {
                    eAggro -= 25;
                } else if (userAction == '3')
                {
                    eAggro += 25;
                }

                // Keep aggro within bounds
                if (eAggro > 75)
                {
                    eAggro = 75;
                } else if (eAggro < -75)
                {
                    eAggro = -75;
                }
            }
            if (hp > 0) // Victory
            {
                cout << endl << "> You won!" << endl;
                wins += 1;
                cout << "> You now have " << wins << " win(s)." << endl;
            } else // Defeat
            {
               cout << endl << "Rest in peace!" << endl;
               cout << "> You beat " << wins << " Ronin.";
            }
        }

    }

    return 0;
}