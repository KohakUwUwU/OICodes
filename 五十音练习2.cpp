//LizPlum
#include<bits/stdc++.h>
#include "sys/timeb.h"
#define int long long
using namespace std;

string ping[500]={" ","あ","い","う","え","お","か","き","く","け","こ","さ","し","す","せ","そ","た","ち","つ","て","と","な","に","ぬ","ね","の","は","ひ","ふ","へ","ほ","ま","み","む","め","も","や","ゆ","よ","ら","り","る","れ","ろ","わ","を","ん","が","ぎ","ぐ","げ","ご","ざ","じ","ず","ぜ","ぞ","だ","ぢ","づ","で","ど","ば","び","ぶ","べ","ぼ","ぱ","ぴ","ぷ","ぺ","ぽ","きゃ","きゅ","きょ","しゃ","しゅ","しょ","ちゃ","ちゅ","ちょ","にゃ","にゅ","にょ","ひゃ","ひゅ","ひょ","みゃ","みゅ","みょ","りゃ","りゅ","りょ","ぎゃ","ぎゅ","ぎょ","じゃ","じゅ","じょ","びゃ","びゅ","びょ","ぴゃ","ぴゅ","ぴょ","ツァ","ファ","ウィ","ティ","フィ","ディ","トゥ","ドゥ", "デュ","ウェ","シェ","チェ","ツェ","フェ","ジェ","ウォ","ツォ","フォ"};
string pian[500]={" ","ア","イ","ウ","エ","オ","カ","キ","ク","ケ","コ","サ","シ","ス","セ","ソ","タ","チ","ツ","テ","ト","ナ","ニ","ヌ","ネ","ノ","ハ","ヒ","フ","ヘ","ホ","マ","ミ","ム","メ","モ","ヤ","ユ","ヨ","ラ","リ","ル","レ","ロ","ワ","ヲ","ン","ガ","ギ","グ","ゲ","ゴ","ザ","ジ","ズ","ゼ","ゾ","ダ","ヂ","ヅ","デ","ド","バ","ビ","ブ","ベ","ボ","パ","ピ","プ","ペ","ポ","キャ","キュ","キョ","シャ","シュ","ショ","チャ","チュ","チョ","ニャ","ニュ","ニョ","ヒャ","ヒュ","ヒョ","ミャ","ミュ","ミョ","リャ","リュ","リョ","ギャ","ギュ","ギョ","ジャ","ジュ","ジョ","ビャ","ビュ","ビョ","ピャ","ピュ","ピョ","ツァ","ファ","ウィ","ティ","フィ","ディ","トゥ","ドゥ", "デュ","ウェ","シェ","チェ","ツェ","フェ","ジェ","ウォ","ツォ","フォ"};
string engl[500]={"   ","a","i","u","e","o","ka","ki","ku","ke","ko","sa","shi","su","se","so","ta","chi","tsu","te","to","na","ni","nu","ne","no","ha","hi","fu","he","ho","ma","mi","mu","me","mo","ya","yu","yo","ra","ri","ru","re","ro","wa","wo","nn","ga","gi","gu","ge","go","za","ji","zu","ze","zo","da","di","du","de","do","ba","bi","bu","be","bo","pa","pi","pu","pe","po", "kya", "kyu", "kyo", "sha", "shu", "sho", "cha", "chu", "cho", "nya", "nyu", "nyo", "hya", "hyu", "hyo", "mya", "myu", "myo", "rya", "ryu", "ryo", "gya", "gyu", "gyo",  "ja",  "ju",  "jo", "bya", "byu", "byo", "pya", "pyu", "pyo", "tsa",  "fa",  "wi","teli",  "fi","deli","tolu","dolu","delyu",  "we", "she", "che", "tse",  "fe",  "je", "ulo", "tso",  "fo"};
inline void run()
{
	clock_t start,end;
	start = clock();
	srand(time(NULL));
	struct timeb timeSeed;
	ftime(&timeSeed);
	srand(timeSeed.time * 1000 + timeSeed.millitm);  // milli time
    const int MAX = 122;
    const int MIN = 1;
    const int max1 = 2;
    const int min1 = 1;
 	int True=0;
 	cout<<"萩聞喘屎鳩議補秘憧亟恬基!籾楚葎200\n";
	for(int i=1;i<=200;i++)
	{
		srand(time(NULL));
		struct timeb timeSeed;
		ftime(&timeSeed);
		srand(timeSeed.time * 1000 + timeSeed.millitm);
   		int word = rand() % (MAX - MIN + 1) + MIN;
   		int pp = rand() % (max1-min1+1)+min1;
   		string targ;
		if(pp==1)targ=ping[word];
   		else targ=pian[word];
   		cout<<targ<<' ';
   		string str;
   		cin>>str;
   		if(str==engl[word])cout<<"T\n",True++;
   		else cout<<"F "<<engl[word]<<'\n';
 	}
	end = clock();
 	cout<<"score:"<<True<<'\n';
 	cout<<"time:"<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;
 	cout<<"Enter any letter to continue...\n";
}
signed main()
{
 	while(1)
 	{
 		run();	
	}
	return 0;
}

