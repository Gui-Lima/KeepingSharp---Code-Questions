using namespace std;

std::string encUtil(std::string text){
    //This is a test!", 1 -> "hsi  etTi sats!"
    string result ="";
    string copia = text;
    for(int i = 0, j = 1;i<copia.length();i++){
        if(i%2!=0){
            result += copia[i];
            text.erase(j, 1);
            j++;
        }
    }

    result += text;

    return result;
}

std::string encrypt(std::string text, int n) {
    //abcde (2) -> bdace -> baedc

    for(int i =0;i<n;i++){
        text = encUtil(text);
    }
    return text;
}

string decUtil(string encryptedText){
    string firstHalf = "";
    string secondHalf = "";

    int i = 0;
    for(;i<encryptedText.length() / 2;i++){
        firstHalf += encryptedText[i];
    }
    for(;i<encryptedText.length();i++){
        secondHalf += encryptedText[i];
    }

    string result = "";

    int count = 0;
  while(result.length() < encryptedText.length()){
        if(count < secondHalf.length()){
            result += secondHalf[count];

        }
        if(count < firstHalf.length()){
            result += firstHalf[count];
        }
        count++;
    }
    return result;
}

std::string decrypt(std::string encryptedText, int n) {
    cout << "Text : " << encryptedText << " times : " << n << endl;
    
    for(int i =0;i<n;i++){
        encryptedText = decUtil(encryptedText);
    }
    return encryptedText;
}
