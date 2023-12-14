#include <bits/stdc++.h>
using namespace std;

string getLongestRegex(string a, string b, string c){
  
  // Build a sorted set of unique characters from a and b
  set<char> chars;
  for(char ch: a) chars.insert(ch);
  for(char ch: b) chars.insert(ch);
  
  // Try all possible lengths of regex
  for(int len = chars.size(); len >= 1; len--){
    
    // Generate all lexographically sorted regexes of length len
    string regex = "";
    for(int i=0; i<len; i++){
      regex += '[';
      for(auto it = chars.begin(); it != chars.end(); it++){
        regex += *it;
        if(regex.length() == len*2 - 1) break; 
      }
      regex += ']';
    }
    
    // Check if regex matches a, b but not c
    if(regexMatches(a, regex) && regexMatches(b, regex) && !regexMatches(c, regex))
      return regex;
  }
  
  return "-1";
}

bool regexMatches(string s, string regex){
  // Check if s matches regex
  return true; 
}

int main() {

  string a = "AERB";
  string b = "ATRC"; 
  string c = "AGCB";
  
  cout << getLongestRegex(a, b, c) << endl;
  
  return 0;
}
