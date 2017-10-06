#include <iostream>
#include <fstream>
#include <string>
#include <vector>


void convert(std:: vector <char>key);
 std:: vector <char> alphabet 
    {'a','b','c','d','e','f','g','h','i','j','k','l','m','n',
    'o','p','q','r','s','t','u','v','w','x','y','z'};
    
int main() {
    std:: string k;
  std:: cout << "Please input word: ";
  std:: cin >> k;
  std:: vector<char> key(k.c_str(), k.c_str() + k.size() + 1);
  convert(key);
  return 0;
}


void convert(std::vector <char> key){
    int count=0;
    int letter;
    int input;
    char c;
    bool exists;
    std:: vector <char> cipher(1);
    
    for (count = 0; count < key.size()-1; count++){
        for (letter = 0; letter <cipher.size(); letter++){
            if (key[count] == cipher[letter]){
              exists = true;
              break;
              }
                else {
                    exists = false;
                }
            }
            
        
    if (exists != true)
                  cipher.push_back(key [count]);
    }
    
    for (count = 0; cipher.size() < 27; count++) {
        for (letter = 0; letter <cipher.size(); letter++){
            if (alphabet[count] == cipher[letter]){
              exists = true;
              break;
              }
                else {
                    exists = false;
                }
            }
            
        
    if (exists != true)
        cipher.push_back(alphabet [count]);
    else
        exists = false;
    }
  
  std:: ifstream secret;
  std:: ofstream coded;
  
  std:: cout << "\nEnter 1 to encode or 2 to decode.\n";
  std:: cin >> input;
  
  if (input == 1){
  secret.open("message.txt");
  coded.open("codedMessage.txt");
  while(secret >> std:: noskipws >>c){
     if (c == ' ')
       coded << " ";
     else {
      for (count = 0; c != alphabet[count]; count++){
          
      } 
      coded << cipher[count+1];
  }}
  secret.close();
  coded.close();
  }
  else if (input == 2){
   secret.open("message.txt");
  coded.open("codedMessage.txt");
  while(secret >> std:: noskipws >>c){
     if (c == ' ')
       coded << " ";
     else {
      for (count = 0; c != cipher[count]; count++){
          
      } 
      coded << alphabet[count-1];
  }}
  secret.close();
  coded.close();
  }
  else
  std:: cout << "Invalid input.";
}
