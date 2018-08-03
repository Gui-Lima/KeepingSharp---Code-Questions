
#include <iostream>
#include "vector"
#include "string"

using namespace std;
enum class Result { Win, Loss, Tie };

struct card{
    int number;
    /* 0 - hearts
     * 1 - spades
     * 2 - diamonds
     * 3 - clubs
     */
    int suits;

    bool equals(card toCompare){
        if(toCompare.number == number && toCompare.suits == suits){
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
    static vector<card> hand;

    static card first;
    static card second;
    static card third;
    static card fourth;
    static card fifth;
    static int tieBreak;
    static int tieBreak2;

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
        sort();
        first = hand[0];
        second =  hand[1];
        third = hand[2];
        fourth = hand[3];
        fifth = hand[4];
    }


    static int getHandValue() {
        if(FullHouse()){
            return 6;
        }
        else if(threeOfAKind()) {
            return 3;
        }
        else if(fourOfAKind()){
            return 7;
        }
        else if(royalFlush()){
            return 9;
        }
        else if(straighFlush()){
            return 8;
        }
        else if(flush()){
            return 5;
        }
        else if(straight()){
            return 4;
        }
        else if(twoPair()){
            return 2;
        }
        else if(Pair()){
            return 1;
        }
    }

    static bool royalFlush(){

        if(has(10, 0) && has(11, 0) && has(12, 0) && has(13, 0) && has(14, 0) ){
             tieBreak = 100;
             tieBreak2 = 100;
            return true;
        }
        if(has(10, 1) && has(11, 1) && has(12, 1) && has(13, 1) && has(14, 1) ){
             tieBreak = 100;
             tieBreak2 = 100;
            return true;
        }
        if(has(10, 2) && has(11, 2) && has(12, 2) && has(13, 2) && has(14, 2) ){
             tieBreak = 100;
             tieBreak2 = 100;
            return true;
        }
        if(has(10, 3) && has(11, 3) && has(12, 3) && has(13, 3) && has(14, 3) ){
             tieBreak = 100;
             tieBreak2 = 100;
            return true;
        }
        return false;
    }

    static bool straighFlush(){
        if(straight() && flush()){
            return true;
        }
    }


    static bool fourOfAKind(){
        if(first.number == second.number && first.number == third.number && first.number == fourth.number && first.number != fifth.number){
            tieBreak = first.number;
            tieBreak2 = fifth.number;
            return true;
        }
        if(second.number == third.number && second.number == fourth.number && second.number == fifth.number && second.number != first.number){
            tieBreak = second.number;
            tieBreak2 =  first.number;
            return true;
        }
        return false;
    }

    static bool FullHouse(){
        if(first.number == second.number && second.number != third.number && third.number == fourth.number && fourth.number == fifth.number){
            tieBreak = third.number;
            tieBreak2 = first.number;
            return true;
        }
        if(first.number == second.number && second.number == third.number && third.number != fourth.number && fourth.number == fifth.number){
            tieBreak = first.number;
            tieBreak2 = fifth.number;
            return true;
        }
        return false;
    }

    static bool flush(){
        //5 cards same suit

        if(first.suits == second.suits && second.suits == third.suits && third.suits == fourth.suits && fourth.suits == fifth.suits){
            tieBreak = fifth.number;
            tieBreak2 = fourth.number;
            return true;
        }
        return false;
    }

    static bool straight(){
        if(first.number +1 == second.number && second.number +1 == third.number && third.number+1 == fourth.number && fourth.number +1 == fifth.number){
            tieBreak = fifth.number;
            tieBreak2 = fifth.number;
            return true;
        }
        if(first.number == 2 && second.number == 3 && third.number == 4 && fourth.number == 5 && fifth.number == 14){
            tieBreak2 = fifth.number;
            tieBreak = fifth.number;
            return true;
        }
        return false;
    }

    static int max(int i, int j){
        if(i>j){
            return i;
        }
        if(j>i){
            return j;
        }
        return 0;
    }

    static bool threeOfAKind(){
        card temp = hand[0];
        card temp2 = hand[1];
        card temp3 = hand[2];
        if(temp.number == hand[1].number && temp.number == hand[2].number && temp.number != hand[3].number && temp.number != hand[4].number){
            tieBreak = first.number;
            tieBreak2 = max(fourth.number, fifth.number);
            return true;
        }

        if(temp2.number == hand[2].number && temp2.number == hand[3].number && temp2.number != hand[4].number && temp2.number != hand[0].number){
            tieBreak = second.number;
            tieBreak2 = max(fifth.number, first.number);
            return true;
        }
        if(temp3.number == hand[3].number && temp3.number == hand[4].number && temp3.number != hand[0].number && temp3.number != hand[1].number){
            return true;
        }
        return false;
    }

    static bool twoPair(){

        if(threeOfAKind()){
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

    static bool Pair(){
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

    static bool has(int value, int suit){
        for(int i = 0;i<hand.size();i++){
            if(value == hand[i].number && suit == hand[i].suits){
                return true;
            }
        }
        return false;
    }

    bool print(){
        for(int i =0;i<hand.size();i++){
            cout << "Card : " << hand[i].number << endl;
            cout << "Suit : " << hand[i].suits << endl;
            cout << "------------------" << endl;
        }
    }



    void evaluateHand(){
        if(FullHouse()){
            cout << "This hand is a FullHouse!" << endl;
        }
        else if(threeOfAKind()){
            cout << "This hand is a Three of a kind" << endl;
        }
        else if(fourOfAKind()){
            cout << "This hand is a Four of a kind!" << endl;
        }
        else if(royalFlush()){
            cout << "This hand is a Royal Flush! YOU WIN!" << endl;
        }
        else if(straighFlush()){
            cout << "This hand is a straight flush! OWO" << endl;
        }
        else if(flush()){
            cout << "This hand is a flush " << endl;
        }
        else if(straight()){
            cout << "This hand is a straight" << endl;
        }
        else if(twoPair()){
            cout << "This hand is a two pair" << endl;
        }
        else if(Pair()){
            cout << "This hand is a Pair" << endl;
        }
    }

};




Result compare (const PokerHand &player, const PokerHand &opponent) {
    int playerScore = player.getHandValue();
    int opponentScore = opponent.getHandValue();
    if(playerScore > opponentScore){
        return Result::Win;
    }
    else if(opponentScore > playerScore){
        return Result::Loss;
    }
    else{
        switch(playerScore){
            case 1:     return player.pairTie(opponent);
                break;
            case 2:     return twoPairTie();
                break;
            case 3:     return threeKindTie();
                break;
            case 4:     return straightTie();
                break;
            case 5:     return flushTie();
                break;
            case 6:     return fullHouseTie();
                break;
            case 7:     return fourKindTie();
                break;
            case 8:     return straigthFlush();
                break;
            case 9:     return Result::Tie;
                break;
        }
    }
}


int main(){
    PokerHand a("AS 2S 3S 4S 5S");
    a.print();
    a.evaluateHand();
    return 0;
}