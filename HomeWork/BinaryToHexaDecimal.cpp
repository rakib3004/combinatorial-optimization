
#include<bits/stdc++.h>
using namespace std;

string hexaDecimalToBinary(string hexaDecimalText)
{
    map<char,string> byteMapping;
    string binaryText="";
    byteMapping['0']="0000";
    byteMapping['1']="0001";
    byteMapping['2']="0010";
    byteMapping['3']="0011";
    byteMapping['4']="0100";
    byteMapping['5']="0101";
    byteMapping['6']="0110";
    byteMapping['7']="0111";
    byteMapping['8']="1000";
    byteMapping['9']="1001";
    byteMapping['A']="1010";
    byteMapping['B']="1011";
    byteMapping['C']="1100";
    byteMapping['D']="1101";
    byteMapping['E']="1110";
    byteMapping['F']="1111";
    int i=0;

    for(i=0; i<hexaDecimalText.size(); i++)
    {
        binaryText +=  byteMapping[hexaDecimalText[i]];
//        cout<<binaryText<<endl;
    }
    return binaryText;

}

string binaryToHexaDecimal(string binaryText)
{
    map<string,string> bitsMapping;
    string hexaDecimalText="";
    bitsMapping["0000"]="0";
    bitsMapping["0001"]="1";
    bitsMapping["0010"]="2";
    bitsMapping["0011"]="3";
    bitsMapping["0100"]="4";
    bitsMapping["0101"]="5";
    bitsMapping["0110"]="6";
    bitsMapping["0111"]="7";
    bitsMapping["1000"]="8";
    bitsMapping["1001"]="9";
    bitsMapping["1010"]="A";
    bitsMapping["1011"]="B";
    bitsMapping["1100"]="C";
    bitsMapping["1101"]="D";
    bitsMapping["1110"]="E";
    bitsMapping["1111"]="F";
    int i=0;
    for(i=0; i<binaryText.length(); i=i+4)
    {
            string hexaChar="";

        hexaChar+= binaryText[i];
        hexaChar+= binaryText[i+1];
        hexaChar+= binaryText[i+2];
        hexaChar+= binaryText[i+3];
        hexaDecimalText += bitsMapping[hexaChar];
//        cout<<hexaDecimalText<<endl;

    }
    return hexaDecimalText;
}


int main()
{

    string plainText = "0000000101000110110000001001011000111110001010110001111000101110";
        string  dESkey = "1100100000111111101010010010011010101110110110111010011111100100";
        cout<<"Plain Text : "<<binaryToHexaDecimal(plainText)<<endl;
        cout<<"DES Key : "<<binaryToHexaDecimal(dESkey)<<endl;

    return 0;
}



