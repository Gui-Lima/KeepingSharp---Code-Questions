
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
    vector<card> hand;

    card first;
    card second;
    card third;
    card fourth;
    card fifth;
    int tieBreak;
    int tieBreak2;
    int tieBreak3;
    int tieBreak4;
    int tieBreak5;

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


    int getHandValue() {
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
        else{
            tieBreak = fifth.number;
            tieBreak2 = fourth.number;
            tieBreak3 = third.number;
            tieBreak4 = second.number;
            tieBreak5 = first.number;
            return 0;
        }
    }

    bool royalFlush(){

        if(has(10, 0) && has(11, 0) && has(12, 0) && has(13, 0) && has(14, 0) ){
            tieBreak = 100;
            tieBreak2 = 100;
            tieBreak3 = 100;
            tieBreak4 = 100;
            tieBreak5 = 100;
            return true;
        }
        if(has(10, 1) && has(11, 1) && has(12, 1) && has(13, 1) && has(14, 1) ){
            tieBreak = 100;
            tieBreak2 = 100;
            tieBreak3 = 100;
            tieBreak4 = 100;
            tieBreak5 = 100;
            return true;
        }
        if(has(10, 2) && has(11, 2) && has(12, 2) && has(13, 2) && has(14, 2) ){
            tieBreak = 100;
            tieBreak2 = 100;
            tieBreak3 = 100;
            tieBreak4 = 100;
            tieBreak5 = 100;
            return true;
        }
        if(has(10, 3) && has(11, 3) && has(12, 3) && has(13, 3) && has(14, 3) ){
            tieBreak = 100;
            tieBreak2 = 100;
            tieBreak3 = 100;
            tieBreak4 = 100;
            tieBreak5 = 100;
            return true;
        }
        return false;
    }

    bool straighFlush(){
        if(straight() && flush()){
            tieBreak = fifth.number;
            tieBreak2 = fourth.number;
            tieBreak3 = third.number;
            tieBreak4 = fourth.number;
            tieBreak5 = fifth.number;
            return true;
        }
    }


    bool fourOfAKind(){
        if(first.number == second.number && first.number == third.number && first.number == fourth.number && first.number != fifth.number){
            tieBreak = first.number;
            tieBreak2 = fifth.number;
            tieBreak3 = 100;
            tieBreak4 = 100;
            tieBreak5 = 100;
            return true;
        }
        if(second.number == third.number && second.number == fourth.number && second.number == fifth.number && second.number != first.number){
            tieBreak = second.number;
            tieBreak2 =  first.number;
            tieBreak3 = 100;
            tieBreak4 = 100;
            tieBreak5 = 100;
            return true;
        }
        return false;
    }

    bool FullHouse(){
        if(first.number == second.number && second.number != third.number && third.number == fourth.number && fourth.number == fifth.number){
            tieBreak = third.number;
            tieBreak2 = first.number;
            tieBreak3 = 100;
            tieBreak4 = 100;
            tieBreak5 = 100;
            return true;
        }
        if(first.number == second.number && second.number == third.number && third.number != fourth.number && fourth.number == fifth.number){
            tieBreak = first.number;
            tieBreak2 = fifth.number;
            tieBreak3 = 100;
            tieBreak4 = 100;
            tieBreak5 = 100;
            return true;
        }
        return false;
    }

    bool flush(){
        //5 cards same suit

        if(first.suits == second.suits && second.suits == third.suits && third.suits == fourth.suits && fourth.suits == fifth.suits){
            tieBreak = fifth.number;
            tieBreak2 = fourth.number;
            tieBreak3 = third.number;
            tieBreak2 = second.number;
            tieBreak5 = first.number;
            return true;
        }
        return false;
    }

    bool straight(){
        if(first.number +1 == second.number && second.number +1 == third.number && third.number+1 == fourth.number && fourth.number +1 == fifth.number){
            tieBreak = fifth.number;
            tieBreak2 = fifth.number;
            tieBreak3 = fifth.number;
            tieBreak4 = fifth.number;
            tieBreak5 = fifth.number;
            return true;
        }
        if(first.number == 2 && second.number == 3 && third.number == 4 && fourth.number == 5 && fifth.number == 14){
            tieBreak2 = fifth.number;
            tieBreak = fifth.number;
            tieBreak3 = fifth.number;
            tieBreak4 = fifth.number;
            tieBreak5 = fifth.number;
            return true;
        }
        return false;
    }

    bool threeOfAKind(){
        card temp = hand[0];
        card temp2 = hand[1];
        card temp3 = hand[2];
        if(temp.number == hand[1].number && temp.number == hand[2].number && temp.number != hand[3].number && temp.number != hand[4].number){
            tieBreak = first.number;
            tieBreak2 = max(fourth.number, fifth.number);
            tieBreak3 = min(fourth.number, fifth.number);
            tieBreak4 = 100;
            tieBreak5 = 100;
            return true;
        }

        if(temp2.number == hand[2].number && temp2.number == hand[3].number && temp2.number != hand[4].number && temp2.number != hand[0].number){
            tieBreak = second.number;
            tieBreak2 = max(fifth.number, first.number);
            tieBreak3 = min(fourth.number, fifth.number);
            tieBreak4 = 100;
            tieBreak5 = 100;
            return true;
        }
        if(temp3.number == hand[3].number && temp3.number == hand[4].number && temp3.number != hand[0].number && temp3.number != hand[1].number){
            tieBreak = third.number;
            tieBreak2 = max(first.number, second.number);
            tieBreak3 = min(first.number, second.number);
            tieBreak4 = 100;
            tieBreak5 = 100;
            return true;
        }
        return false;
    }

    bool twoPair(){
        // 22 11 0  --  11 0 22 -- 0 11 22
        if(first.number == second.number && second.number != third.number && third.number != fourth.number && fourth.number == fifth.number && fifth.number != first.number){
            tieBreak = max(first.number, fourth.number);
            tieBreak2 = min(first.number, fourth.number);
            tieBreak3 = third.number;
            tieBreak4 = 100;
            tieBreak5 = 100;
            return true;
        }

        if(first.number != second.number && second.number == third.number && third.number != fourth.number && fourth.number == fifth.number && fifth.number != first.number){
            tieBreak = max(second.number, fifth.number);
            tieBreak2 = min(second.number, fifth.number);
            tieBreak3 = first.number;
            tieBreak4 = 100;
            tieBreak5 = 100;
            return true;
        }

        if(first.number == second.number && second.number != third.number && third.number == fourth.number && fourth.number != fifth.number && fifth.number!=first.number){
            tieBreak = max(first.number, third.number);
            tieBreak2 = min(first.number, third.number);
            tieBreak3 = fifth.number;
            tieBreak4 = 100;
            tieBreak5 = 100;
            return true;
        }
        return false;
    }

    bool Pair(){
        //00 1 2 3
        //1 00 2 3
        //1 2 00 3
        //1 2 3 00

        if(first.number == second.number && second.number != third.number && third.number != fourth.number && fourth.number != fifth.number){
            tieBreak = first.number;
            tieBreak2 = fifth.number;
            tieBreak3 = fourth.number;
            tieBreak4 = third.number;
            tieBreak5 = 100;
            return true;

        }
        if(first.number != second.number && second.number == third.number && third.number != fourth.number && fourth.number != fifth.number){

            tieBreak = second.number;
            tieBreak2 = fifth.number;
            tieBreak3 = fourth.number;
            tieBreak4 = first.number;
            tieBreak5 = 100;
            return true;
        }
        if(first.number != second.number && second.number != third.number && third.number == fourth.number && fourth.number != fifth.number){
            tieBreak = third.number;
            tieBreak2 = fifth.number;
            tieBreak3 = second.number;
            tieBreak4 = first.number;
            tieBreak5 = 100;
            return true;

        }
        if(first.number != second.number && second.number != third.number && third.number != fourth.number && fourth.number == fifth.number){
            tieBreak = fourth.number;
            tieBreak2 = third.number;
            tieBreak3 = second.number;
            tieBreak4 = first.number;
            tieBreak5 = 100;
            return true;

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
    PokerHand player1 = player;
    PokerHand player2 = opponent;
    int player1Score = player1.getHandValue();
    int player2Score = player2.getHandValue();
    if(player1Score > player2Score){
        return Result::Win;
    }
    else if(player2Score > player1Score){
        return Result::Loss;
    }
    else{
        if(player1.tieBreak > player2.tieBreak){
            return Result::Win;
        }
        else if(player1.tieBreak < player2.tieBreak){
            return Result::Loss;
        }
        else{
            if(player1.tieBreak2 > player2.tieBreak2){
                return Result::Win;
            }
            else if(player1.tieBreak2 < player2.tieBreak2){
                return Result::Loss;
            }
            else{
                if(player1.tieBreak3 > player2.tieBreak3){
                    return Result::Win;
                }
                else if(player1.tieBreak3 < player2.tieBreak3){
                    return Result::Loss;
                }
                else{
                    if(player1.tieBreak4 > player2.tieBreak4){
                        return Result::Win;
                    }
                    else if(player1.tieBreak4 < player2.tieBreak4){
                        return Result::Loss;
                    }
                    else{
                        if(player1.tieBreak5 > player2.tieBreak5){
                            return Result::Win;
                        }
                        else if(player1.tieBreak5 < player2.tieBreak5){
                            return Result::Loss;
                        }
                        else{
                            return Result::Tie;
                        }

                    }

                }

            }
        }
    }
}
