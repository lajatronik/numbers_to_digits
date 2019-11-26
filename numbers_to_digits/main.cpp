#define SW_VERSION "1.00"

#include <iostream>
#include <string>
#include <vector>
#include <sstream> 
#include <algorithm>

using namespace std; 

vector<string> ones {"","one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
vector<string> teens {"ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen","sixteen", "seventeen", "eighteen","nineteen"};
vector<string> tens {"", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
vector<string> scale {"hundred", "thousand", "million", "billion"};

string nameForNumber (long number) // Extract name for number
{
    if (number < 10) {
        return ones[number];
    } else if (number < 20) {
        return teens [number - 10];
    } else if (number < 100) {
        return tens[number / 10] + ((number % 10 != 0) ? " " + nameForNumber(number % 10) : "");
    } else if (number < 1000) {
        return nameForNumber(number / 100) + " hundred" + ((number % 100 != 0) ? " " + nameForNumber(number % 100) : "");
    } else if (number < 1000000) {
        return nameForNumber(number / 1000) + " thousand" + ((number % 1000 != 0) ? " " + nameForNumber(number % 1000) : "");
    } else if (number < 1000000000) {
        return nameForNumber(number / 1000000) + " million" + ((number % 1000000 != 0) ? " " + nameForNumber(number % 1000000) : "");
    } else if (number < 1000000000000) {
        return nameForNumber(number / 1000000000) + " billion" + ((number % 1000000000 != 0) ? " " + nameForNumber(number % 1000000000) : "");
    }
    return "error";
}

int tokens_to_int( const std::vector<std::string> &s )
{
  int scale = 1;
  int rv=0;
  
  for( std::vector<std::string>::const_reverse_iterator it = s.rbegin(); it != s.rend() ; ++it )
  {
    std::string cw = *it;
    //Things that add to the current value
    if( cw == "one" )   { rv += 1 * scale; }
    if( cw == "two" )   { rv += 2 * scale; }
    if( cw == "three" ) { rv += 3 * scale; }
    if( cw == "four" )  { rv += 4 * scale; }
    if( cw == "five" )  { rv += 5 * scale; }
    if( cw == "six" )   { rv += 6 * scale; }
    if( cw == "seven" )  { rv += 7 * scale; }
    if( cw == "eight" )  { rv += 8 * scale; }
    if( cw == "nine" )   { rv += 9 * scale; }
    if( cw == "ten" )    { rv += 10 * scale; }

    // Teens
    if( cw == "eleven" )    { rv += 11 * scale; }
    if( cw == "twelve" )    { rv += 12 * scale; }
    if( cw == "thirteen" )  { rv += 13 * scale; }
    if( cw == "fourteen" )  { rv += 14 * scale; }
    if( cw == "fiveteen" )  { rv += 15 * scale; }
    if( cw == "sixteen" )   { rv += 16 * scale; }
    if( cw == "seventeen" ) { rv += 17 * scale; }
    if( cw == "eighteen" )  { rv += 18 * scale; }
    if( cw == "nineteen" )  { rv += 19 * scale; }

    // Multiples of 10
    if( cw == "twenty" )    { rv += 20 * scale; }
    if( cw == "thirty" )    { rv += 30 * scale; }
    if( cw == "fourty" )    { rv += 40 * scale; }
    if( cw == "fivety" )    { rv += 50 * scale; }
    if( cw == "sixty" )     { rv += 60 * scale; }
    if( cw == "seventy" )   { rv += 70 * scale; }
    if( cw == "eighty" )    { rv += 80 * scale; }
    if( cw == "ninety" )    { rv += 90 * scale; }

    //Things that effect scale for following entries
    if( cw == "hundred" )   { scale *= 100; }
    if( cw == "thousand" )  { if( scale==100) { scale=1000; } else { scale*=1000; } }
    if( cw == "million" )   { if( scale==1000) { scale=1000000; } else { scale*=1000000; } }
    if( cw == "billion" )   { if( scale==1000000) { scale=1000000000; } else { scale*=1000000000; } }
    
  }

  return rv;
}
  
void getNumberFromString(string s) // Extract all integers from string
{
   stringstream str_strm;
   str_strm << s; //convert the string s into stringstream
   string temp_str;
   int temp_int = 0;
   vector<string> myvector ;
   
   while(!str_strm.eof()) 
   {
      str_strm >> temp_str; //take words into temp_str one by one
      if(stringstream(temp_str) >> temp_int) //try to convert string to int if is an int then extract text from number
      { 
         cout << nameForNumber(temp_int) << " ";
      }
      else //if it is not an int then leave text
      { //
        if (std::find(ones.begin(), ones.end(), temp_str) != ones.end())// Element in vector.
        {
            myvector.push_back (temp_str);
        }
        else if (std::find(teens.begin(), teens.end(), temp_str) != teens.end())
        {
            myvector.push_back (temp_str);
        }
        else if (std::find(tens.begin(), teens.end(), temp_str) != teens.end())
        {
            myvector.push_back (temp_str);
        }
        else if (std::find(scale.begin(), scale.end(), temp_str) != scale.end())
        {
            myvector.push_back (temp_str);
        }
        else // Check strign and vector
        {
            
            if((temp_str.compare("and")) != 0 && myvector.size() != 0) 
            {
                cout << tokens_to_int(myvector) << " ";
                myvector.clear();
                cout << temp_str << " ";
            }
            else
            {
                cout << temp_str << " ";
            }
        }
    
      }
   }
   
    if (myvector.size() != 0) cout << tokens_to_int(myvector);
    temp_str = ""; //clear temp string
}

int main() 
{
    long input = 0;
    string str;
    
    do
    {
        cout << "Please enter a text: ";   
        getline(cin, str); 
        getNumberFromString(str);
        cout << "\n" << endl;
    }while (input > 0);
    return 0;
    
}
