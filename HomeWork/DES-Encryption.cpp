
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
        binaryText = binaryText+ byteMapping[hexaDecimalText[i]];
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
    string hexaChar="";
    for(i=0; i<binaryText.size(); i=i+4)
    {
        hexaChar = binaryText[i]+binaryText[i+1]+binaryText[i+2]+binaryText[i+3];
        hexaDecimalText = hexaDecimalText+bitsMapping[hexaChar];
    }
    return hexaDecimalText;
}

string permutationFunction(string inputText, int * permutaedTable, int permutationNumber)
{
    int iterator;
    string permutedString="";
    for(iterator=0; iterator<permutationNumber; iterator++)
    {
        permutedString = inputText[permutaedTable[iterator]-1];
    }
    return permutedString;
}
string x_orFunctionality(string aString, string bString)
{

    int iterator=0;
    string outputString="";
    for(iterator=0; iterator<aString.size(); iterator++)
    {

        if(aString[iterator]==bString[iterator])
        {
            outputString= outputString+"0";
        }
        else
        {
            outputString= outputString+"1";
        }
    }
    return outputString;
}

string shiftBitsInLeft(string inputKey, int shiftNumber)
{
    string outputKey="";
    string shiftingKey="";
    int iterator,jterator;
    for(jterator=0; jterator<shiftNumber; jterator++)
    {

        for(iterator=1; iterator<28; iterator++)
        {
            shiftingKey = shiftingKey+ inputKey[iterator];
        }
        shiftingKey=shiftingKey+inputKey[0];
        inputKey = shiftingKey;
        shiftingKey="";
    }
    return inputKey;
}

string encryptionInDataEncryptionStandard(string plainText, vector<string> roundKeyBinary, vector<string>roundKeyHexaDecimal){

plainText = hexaDecimalToBinary(plainText);

int initialPermutation[64]= { 58, 50, 42, 34, 26, 18, 10, 2,
                             60, 52, 44, 36, 28, 20, 12, 4,
                             62, 54, 46, 38, 30, 22, 14, 6,
                             64, 56, 48, 40, 32, 24, 16, 8,
                             57, 49, 41, 33, 25, 17, 9, 1,
                             59, 51, 43, 35, 27, 19, 11, 3,
                             61, 53, 45, 37, 29, 21, 13, 5,
                             63, 55, 47, 39, 31, 23, 15, 7 };
           plainText = permutationFunction(plainText,initialPermutation,64);
           cout<<"After initial permutation : "<<binaryToHexaDecimal(plainText)<<endl;

            string leftSplit = plainText.substr(0,32);
            string rightSplit = plainText.substr(32,32);
            cout<<"After splitting : L0="<<leftSplit<<", R0="<<rightSplit<<endl;

}
int main()
{

    string plainText ="123456ABCD132536";

    string desKey = "AABB09182736CCDD";

    cout<<hexaDecimalToBinary(plainText)<<endl;
    cout<<hexaDecimalToBinary(desKey)<<endl;
    cout<<x_orFunctionality(hexaDecimalToBinary(plainText),hexaDecimalToBinary(desKey))<<endl;

    return 0;
}


