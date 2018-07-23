using namespace std;

struct card{
    int number;
    /* 0 - hearts
     * 1 - spades
     * 2 - diamonds
     * 3 - clubs
     */
    int suits;
};

int getSuitFromString(char suit){
    switch(suit){
        case 'S':return 1;

        case 'H':return 0;

        case 'D':return 2;

        case 'C':return 3;
    }
}

int getNumberFromString(char number){
    //2, 3, 4, 5, 6, 7, 8, 9, T(en), J(ack), Q(ueen), K(ing), A(ce)
    switch(number){
        case '2': return 2;
        case '3': return 3;
        case '4': return 4;
        case '5': return 5;
        case '6': return 6;
        case '7': return 7;
        case '8': return 8;
        case '9': return 9;
        case 'T': return 10;
        case 'J': return 11;
        case 'Q': return 12;
        case 'K': return 13;
        case 'A': return 14;
    }
}

struct PokerHand {
    vector<card> hand;
    PokerHand (const char* pokerhand) {
        string temp = "";
        for(int i =0;i<14;i++){
            if(pokerhand[i] == ' '){
                card tempo;
                tempo.suits = getSuitFromString(pokerhand[1]);
                tempo.number = getNumberFromString(pokerhand[0]);
                hand.push_back(tempo);
                temp = "";
            }
            else
                temp += pokerhand[i];
        }
        card tempo;
        tempo.suits = getSuitFromString(pokerhand[1]);
        tempo.number = getNumberFromString(pokerhand[0]);
        hand.push_back(tempo);
    }

    int getHandValue(){
    	    
    }

    bool royalFlush(){
    	if(this->has())
    }

	bool straighFlush(){

	}

	bool fourOfAKind(){

	}

	bool FullHouse(){

	}

	bool flush(){

	}

	bool straight(){

	}

	bool threeOfAKind(){

	}

	bool twoPair(){

	}

	bool Pair(){

	}

    bool has(int value, int suit){
    	for(int i = 0;i<hand.size();i++){
    		if(value == hand[i].nunmber && suit == hand[i].suit){
    			return true;
    		}
    	}
    return false;
    }
};

enum class Result { Win, Loss, Tie };


Result compare (const PokerHand &player, const PokerHand &opponent) {


    return Result::Loss;
}

int main(){
    compare("2H 3H 4H 5H 6H", "KS AS TS QS JS");
    return 0;
}


