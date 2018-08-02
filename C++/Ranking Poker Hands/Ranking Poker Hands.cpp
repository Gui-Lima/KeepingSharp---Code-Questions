
#include <iostream>
#include "vector"
#include "string"

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

    card first;
    card second;
    card third;
    card fourth;
    card fifth;
    void sort(){
        for(int i = 0;i<hand.size();i++){
            for(int j = i+1;j<hand.size();j++){
                if(hand[i].number > hand[j].number){
                    card temp = hand[i];
                    hand[i] = hand[j];
                    hand[j] = temp;
                }
            }
        }
    }


    PokerHand (const char* pokerhand) {
        string temp = "";
        for(int i =0;i<14;i++){
            if(pokerhand[i] == ' '){
                card tempo;
                tempo.suits = getSuitFromString(pokerhand[i-1]);
                tempo.number = getNumberFromString(pokerhand[i-2]);
                hand.push_back(tempo);
                temp = "";
            }
            else
                temp += pokerhand[i];
        }
        card tempo;
        //last pos are 13 and 12
        tempo.suits = getSuitFromString(pokerhand[13]);
        tempo.number = getNumberFromString(pokerhand[12]);
        hand.push_back(tempo);
        this->sort();
        first = hand[0];
        second =  hand[1];
        third = hand[2];
        fourth = hand[3];
        fifth = hand[4];
    }


    int getHandValue(){
        if(this->FullHouse()){
            return 6;
        }
        else if(this->threeOfAKind()){
            return 3;
        }
        else if(this->fourOfAKind()){
            return 7;
        }
        else if(this->royalFlush()){
            return 9;
        }
        else if(this->straighFlush()){
            return 8;
        }
        else if(this->flush()){
            return 5;
        }
        else if(this->straight()){
            return 4;
        }
        else if(this->twoPair()){
            return 2;
        }
        else if(this->Pair()){
            return 1;
        }
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
        if(this->straight() && this->flush()){
            return true;
        }
    }


    bool fourOfAKind(){
        if(first.number == second.number && first.number == third.number && first.number == fourth.number && first.number != fifth.number){
            return true;
        }
        if(second.number == third.number && second.number == fourth.number && second.number == fifth.number && second.number != hand[0].number){
            return true;
        }
        return false;
    }

    bool FullHouse(){
        if(first.number == second.number && second.number != third.number && third.number == fourth.number && fourth.number == fifth.number){
            return true;
        }
        if(first.number == second.number && second.number == third.number && third.number != fourth.number && fourth.number == fifth.number){
            return true;
        }
        return false;
    }

    bool flush(){
        //5 cards same suit

        if(first.suits == second.suits && second.suits == third.suits && third.suits == fourth.suits && fourth.suits == fifth.suits){
            return true;
        }
        return false;
    }

    bool straight(){
        if(first.number +1 == second.number && second.number +1 == third.number && third.number+1 == fourth.number && fourth.number +1 == fifth.number){
            return true;
        }
        if(first.number == 2 && second.number == 3 && third.number == 4 && fourth.number == 5 && fifth.number == 14){
            return true;
        }
        return false;
    }

    bool threeOfAKind(){
        card temp = hand[0];
        card temp2 = hand[1];
        card temp3 = hand[2];
       if(temp.number == hand[1].number && temp.number == hand[2].number && temp.number != hand[3].number && temp.number != hand[4].number){
            return true;
        }

        if(temp2.number == hand[2].number && temp2.number == hand[3].number && temp2.number != hand[4].number && temp2.number != hand[0].number){
            return true;
        }
        if(temp3.number == hand[3].number && temp3.number == hand[4].number && temp3.number != hand[0].number && temp3.number != hand[1].number){
            return true;
        }
        return false;
    }

    bool twoPair(){

        if(this->threeOfAKind()){
            return false;
        }

        int nPairs = 0;
        for(int i =0;i<hand.size();i++){
            card temp = hand[i];
            card temp2 = hand[i+1];

            if(temp.number == temp2.number && i + 2 >= hand.size()) {
                nPairs++;
            }
            else if(temp.number == temp2.number && i+2< hand.size() && !(temp2.number == hand[i+2].number)){
                nPairs++;
            }

        }
        return nPairs==2;
    }

    bool Pair(){
       int pairs = 0;
        for(int i =0;i<hand.size() - 1;i++){
            card temp = hand[i];
            card temp2 = hand[i+1];
            if(temp.number == temp2.number){
                pairs++;
            }
        }
        return pairs==1;
    }

    bool has(int value, int suit){
        for(int i = 0;i<hand.size();i++){
            if(value == hand[i].number && suit == hand[i].suits){
                return true;
            }
        }
        return false;
    }

    bool print(){
        for(int i =0;i<this->hand.size();i++){
            cout << "Card : " << hand[i].number << endl;
            cout << "Suit : " << hand[i].suits << endl;
            cout << "------------------" << endl;
        }
    }

    void evaluateHand(){
        if(this->FullHouse()){
            cout << "This hand is a FullHouse!" << endl;
        }
        else if(this->threeOfAKind()){
            cout << "This hand is a Three of a kind" << endl;
        }
        else if(this->fourOfAKind()){
            cout << "This hand is a Four of a kind!" << endl;
        }
        else if(this->royalFlush()){
            cout << "This hand is a Royal Flush! YOU WIN!" << endl;
        }
        else if(this->straighFlush()){
            cout << "This hand is a straight flush! OWO" << endl;
        }
        else if(this->flush()){
            cout << "This hand is a flush " << endl;
        }
        else if(this->straight()){
            cout << "This hand is a straight" << endl;
        }
        else if(this->twoPair()){
            cout << "This hand is a two pair" << endl;
        }
        else if(this->Pair()){
            cout << "This hand is a Pair" << endl;
        }
    }

};

enum class Result { Win, Loss, Tie };


Result compare (const PokerHand &player, const PokerHand &opponent) {
    

    return Result::Loss;
}


int main(){
    PokerHand a("AS 2S 3S 4S 5S");
    a.print();
    a.evaluateHand();
    return 0;
}