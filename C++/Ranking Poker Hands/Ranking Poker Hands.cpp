using namespace std;

struct card{
    int number;
    /* 0 - hearts
     * 1 - spades
     * 2 - diamonds
     * 3 - clubs
     */
    int suits;

    bool equals(card toCompare){
        if(toCompare.number == this->number && toCompare.suits == this->suits){
            return true;
        }
        return false;
    }
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
        if(this->has(10, 0) && this->has(11, 0) && this->has(12, 0) && this->has(13, 0) && this->has(14, 0) ){
            return true;
        }
        if(this->has(10, 1) && this->has(11, 1) && this->has(12, 1) && this->has(13, 1) && this->has(14, 1) ){
            return true;
        }
        if(this->has(10, 2) && this->has(11, 2) && this->has(12, 2) && this->has(13, 2) && this->has(14, 2) ){
            return true;
        }
        if(this->has(10, 3) && this->has(11, 3) && this->has(12, 3) && this->has(13, 3) && this->has(14, 3) ){
            return true;
        }
        return false;
    }

    bool straighFlush(){

    }

    bool fourOfAKind(){
        int count1 =0 ;
        int count2 = 0;
        card temp1 = hand[0];
        card temp2 = hand[1];
        for (auto &i : hand) {
            if(i.equals(temp1)){
                count1++;
            }
            if(i.equals(temp2)){
                count2++;
            }
        }
        if(count1 == 4 || count2 == 4){
            return true;
        }
        return false;
    }

    bool FullHouse(){
        if(this->threeOfAKind() && this->Pair()){
            return true;
        }
        return false;
    }

    bool flush(){
        
    }

    bool straight(){

    }

    bool threeOfAKind(){
        int count1 =0 ;
        int count2 = 0;
        int count3 = 0;
        card temp1 = hand[0];
        card temp2 = hand[1];
        card temp3 = hand[2];
        for (auto &i : hand) {
            if(i.equals(temp1)){
                count1++;
            }
            if(i.equals(temp2)){
                count2++;
            }
            if(i.equals(temp3)){
                count3++;
            }
        }
        if(count1 == 3 || count2 == 3 || count3 == 3){
            return true;
        }
        return false;
    }

    bool twoPair(){

    }

    bool Pair(){
        for(int i =0;i<hand.size();i++){
            for(int j = i+1;j<hand.size();j++){
                if(hand[i].equals(hand[j])){
                    return true;
                }
            }
        }
        return false;
    }


    bool hasAnySuit(int value){
        for(int i = 0;i<hand.size();i++){
            if(value == hand[i].number){
                return true;
            }
        }
        return false;
    }

    bool has(int value, int suit){
        for(int i = 0;i<hand.size();i++){
            if(value == hand[i].number && suit == hand[i].suits){
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




