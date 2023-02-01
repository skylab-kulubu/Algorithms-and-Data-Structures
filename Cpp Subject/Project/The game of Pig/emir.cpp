#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int diceRoll();
int humanTurn(int humanTotalScore);
int computerTurn(int computerTotalScore);
int main(){
	srand(time(0));
    int humanTotalScore = 0, computerTotalScore = 0;
    		cout << "Sira oyuncuda. Zar atmak icin e'ye basiniz"<<endl;
    		if (humanTotalScore<100 && computerTotalScore>=100)
    			{
    	 			cout<<"Bilgisayar kazandi"<<endl;
    			}
    		else if(humanTotalScore>=100 && computerTotalScore<100)
    			{
        			cout<<"Oyuncu kazandi"<<endl;
    			}
    
    return 0;
}
int humanTurn(int humanTotalScore){	
		int temp_score=0;
		int lastRoll;
		char rollorhold;
		cout<<"Oyuncunun toplam puani "<<humanTotalScore<<endl;
		cout<<"Tekrar zar atmak icin e'ye, mevcutu korumak icin h'ye basiniz "<<endl;
		cin>>rollorhold;
		while(rollorhold=='e'){
			srand(time(NULL));
			lastRoll=diceRoll();
				if(lastRoll==1){
					cout<<"Oyuncu icin zar 1 geldi ve sira bilgisayara gecti"<<endl;
					break;}
				else{
					temp_score+=lastRoll;
					cout<<"Oyuncu icin zar "<<lastRoll<<"geldi.\n"<<"Bu elde oyuncunun puani "<<temp_score<<endl;
				}
		}
		while(rollorhold=='h'){
			humanTotalScore+=temp_score;
		}
			return humanTotalScore;				
		}
int computerTurn(int computerTotalScore){ 
		int temp_score = 0;
 		int lastRoll;
    cout << "Bilgisayarin puani " << computerTotalScore<<endl;
    while ((temp_score <20) && (temp_score != 1))
    {
        lastRoll = diceRoll();
        if (lastRoll == 1)
        {
            cout << "Bilgisayar icin zar 1 geldi ve sira oyuncuya gecti" << endl;
            break;
        }
        else
        {
            temp_score += lastRoll;
            cout << "Bilgisayar icin zar "<<lastRoll<<"geldi.\n"<<" Bu elde bilgisayarın puani "<<temp_score<<endl;
        }
    }
    if(temp_score >= 20)
    	{	
        computerTotalScore += temp_score;
        cout << "Bilgisayarin birikmis puani " << lastRoll<<endl;
    	}
   
    	return computerTotalScore;
	}			
	int diceRoll(){
		int roll;
		roll=(int)(rand()%6)+1;
		return roll;
	}
