
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
    for(i=0; i<binaryText.length(); i=i+4)
    {
         string hexaChar="";

        hexaChar+= binaryText[i];
        hexaChar+= binaryText[i+1];
        hexaChar+= binaryText[i+2];
        hexaChar+= binaryText[i+3];
        hexaDecimalText += bitsMapping[hexaChar];
      //  cout<<hexaDecimalText<<endl;
    }
    return hexaDecimalText;
}

string permutationFunction(string inputText, int * permutaedTable, int permutationNumber)
{
    int iterator;
    string permutedString="";
    for(iterator=0; iterator<permutationNumber; iterator++)
    {
        permutedString = permutedString+inputText[permutaedTable[iterator]-1];
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
           cout<<"Before initial permutation : "<<plainText<<endl;

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

            int expansionD_BoxTable[48]= { 32, 1, 2, 3, 4, 5, 4, 5,
                      6, 7, 8, 9, 8, 9, 10, 11,
                      12, 13, 12, 13, 14, 15, 16, 17,
                      16, 17, 18, 19, 20, 21, 20, 21,
                      22, 23, 24, 25, 24, 25, 26, 27,
                      28, 29, 28, 29, 30, 31, 32, 1 };
             int s_BoxTable[8][4][16]=  { { 14, 4, 13, 1, 2, 15, 11, 8, 3, 10, 6, 12, 5, 9, 0, 7,
                          0, 15, 7, 4, 14, 2, 13, 1, 10, 6, 12, 11, 9, 5, 3, 8,
                          4, 1, 14, 8, 13, 6, 2, 11, 15, 12, 9, 7, 3, 10, 5, 0,
                          15, 12, 8, 2, 4, 9, 1, 7, 5, 11, 3, 14, 10, 0, 6, 13 },
                        { 15, 1, 8, 14, 6, 11, 3, 4, 9, 7, 2, 13, 12, 0, 5, 10,
                          3, 13, 4, 7, 15, 2, 8, 14, 12, 0, 1, 10, 6, 9, 11, 5,
                          0, 14, 7, 11, 10, 4, 13, 1, 5, 8, 12, 6, 9, 3, 2, 15,
                          13, 8, 10, 1, 3, 15, 4, 2, 11, 6, 7, 12, 0, 5, 14, 9 },

                        { 10, 0, 9, 14, 6, 3, 15, 5, 1, 13, 12, 7, 11, 4, 2, 8,
                          13, 7, 0, 9, 3, 4, 6, 10, 2, 8, 5, 14, 12, 11, 15, 1,
                          13, 6, 4, 9, 8, 15, 3, 0, 11, 1, 2, 12, 5, 10, 14, 7,
                          1, 10, 13, 0, 6, 9, 8, 7, 4, 15, 14, 3, 11, 5, 2, 12 },
                        { 7, 13, 14, 3, 0, 6, 9, 10, 1, 2, 8, 5, 11, 12, 4, 15,
                          13, 8, 11, 5, 6, 15, 0, 3, 4, 7, 2, 12, 1, 10, 14, 9,
                          10, 6, 9, 0, 12, 11, 7, 13, 15, 1, 3, 14, 5, 2, 8, 4,
                          3, 15, 0, 6, 10, 1, 13, 8, 9, 4, 5, 11, 12, 7, 2, 14 },
                        { 2, 12, 4, 1, 7, 10, 11, 6, 8, 5, 3, 15, 13, 0, 14, 9,
                          14, 11, 2, 12, 4, 7, 13, 1, 5, 0, 15, 10, 3, 9, 8, 6,
                          4, 2, 1, 11, 10, 13, 7, 8, 15, 9, 12, 5, 6, 3, 0, 14,
                          11, 8, 12, 7, 1, 14, 2, 13, 6, 15, 0, 9, 10, 4, 5, 3 },
                        { 12, 1, 10, 15, 9, 2, 6, 8, 0, 13, 3, 4, 14, 7, 5, 11,
                          10, 15, 4, 2, 7, 12, 9, 5, 6, 1, 13, 14, 0, 11, 3, 8,
                          9, 14, 15, 5, 2, 8, 12, 3, 7, 0, 4, 10, 1, 13, 11, 6,
                          4, 3, 2, 12, 9, 5, 15, 10, 11, 14, 1, 7, 6, 0, 8, 13 },
                        { 4, 11, 2, 14, 15, 0, 8, 13, 3, 12, 9, 7, 5, 10, 6, 1,
                          13, 0, 11, 7, 4, 9, 1, 10, 14, 3, 5, 12, 2, 15, 8, 6,
                          1, 4, 11, 13, 12, 3, 7, 14, 10, 15, 6, 8, 0, 5, 9, 2,
                          6, 11, 13, 8, 1, 4, 10, 7, 9, 5, 0, 15, 14, 2, 3, 12 },
                        { 13, 2, 8, 4, 6, 15, 11, 1, 10, 9, 3, 14, 5, 0, 12, 7,
                          1, 15, 13, 8, 10, 3, 7, 4, 12, 5, 6, 11, 0, 14, 9, 2,
                          7, 11, 4, 1, 9, 12, 14, 2, 0, 6, 10, 13, 15, 3, 5, 8,
                          2, 1, 14, 7, 4, 10, 8, 13, 15, 12, 9, 0, 3, 5, 6, 11 } };
         int permutationTable[32] =  { 16, 7, 20, 21,
                    29, 12, 28, 17,
                    1, 15, 23, 26,
                    5, 18, 31, 10,
                    2, 8, 24, 14,
                    32, 27, 3, 9,
                    19, 13, 30, 6,
                    22, 11, 4, 25 };

                  cout<<endl;

                  for(int iterator=0;iterator<16;iterator++){

                    string rightExpandedString = permutationFunction(rightSplit,expansionD_BoxTable,48);

                    string x_OrString = x_orFunctionality(roundKeyBinary[iterator],rightExpandedString);

                    string compressionBytes = "";
// convert 6 bits to 4 bits
              for(int iterator=0;iterator<8;iterator++){
                int s_Box_Row = 2*int(x_OrString[iterator*6]-'0')+int(x_OrString[iterator*6+5]-'0');
                int s_Box_Column = 8*int(x_OrString[iterator*6+1]-'0')+4*int(x_OrString[iterator*6+2]-'0')+2*int(x_OrString[iterator*6+3]-'0')+int(x_OrString[iterator*6+4]-'0');

                int s_BoxValue = s_BoxTable[iterator][s_Box_Row][s_Box_Column];

                compressionBytes = compressionBytes+char(s_BoxValue/8+'0');
                s_BoxValue =s_BoxValue%8;
                compressionBytes = compressionBytes+char(s_BoxValue/4+'0');
                s_BoxValue =s_BoxValue%4;
                compressionBytes = compressionBytes+char(s_BoxValue/2+'0');
                s_BoxValue =s_BoxValue%2;
                compressionBytes = compressionBytes+char(s_BoxValue+'0');


              }

              compressionBytes = permutationFunction(compressionBytes,permutationTable,32);

                x_OrString = x_orFunctionality(compressionBytes,leftSplit);

                leftSplit = compressionBytes;

                //Swapping left-right partition
                if(iterator!=15){
                    swap(leftSplit,rightSplit);

                }
                cout<<"Round : "<<(iterator+1)<<" "<<binaryToHexaDecimal(leftSplit)<<" "<<binaryToHexaDecimal(rightSplit)<<" "<<roundKeyHexaDecimal[iterator]<<endl;
                  }
                 string combinedString = leftSplit+rightSplit;

                 int finalPermutation[64]= { 40, 8, 48, 16, 56, 24, 64, 32,
                           39, 7, 47, 15, 55, 23, 63, 31,
                           38, 6, 46, 14, 54, 22, 62, 30,
                           37, 5, 45, 13, 53, 21, 61, 29,
                           36, 4, 44, 12, 52, 20, 60, 28,
                           35, 3, 43, 11, 51, 19, 59, 27,
                           34, 2, 42, 10, 50, 18, 58, 26,
                           33, 1, 41, 9, 49, 17, 57, 25 };

                           string cipherText = binaryToHexaDecimal(permutationFunction(combinedString,finalPermutation,64));
                return cipherText;

                  }


int main()
{

    string plainText ="123456ABCD132536";
//     plainText ="0146C0963E2B1E2E";
     plainText ="AAAAAAAAAAAAAAAA";
cout<<"Plain Text :"<<plainText<<endl;
    string desKey = "AABB09182736CCDD";
//     desKey = "C83FA926AEDBA7E4";
     desKey = "AAAAAAAAAAAAAAAA";

//    cout<<hexaDecimalToBinary(plainText)<<endl;
//    cout<<hexaDecimalToBinary(desKey)<<endl;
//    cout<<x_orFunctionality(hexaDecimalToBinary(plainText),hexaDecimalToBinary(desKey))<<endl;

desKey = hexaDecimalToBinary(desKey);

int keyParityBit[56] = { 57, 49, 41, 33, 25, 17, 9,
                     1, 58, 50, 42, 34, 26, 18,
                     10, 2, 59, 51, 43, 35, 27,
                     19, 11, 3, 60, 52, 44, 36,
                     63, 55, 47, 39, 31, 23, 15,
                     7, 62, 54, 46, 38, 30, 22,
                     14, 6, 61, 53, 45, 37, 29,
                     21, 13, 5, 28, 20, 12, 4 };
  desKey = permutationFunction(desKey,keyParityBit,56);

  int shiftingTable[16] = { 1, 1, 2, 2,
                            2, 2, 2, 2,
                            1, 2, 2, 2,
                            2, 2, 2, 1 };

    int keyCompressionTable[48] = { 14, 17, 11, 24, 1, 5,
                         3, 28, 15, 6, 21, 10,
                         23, 19, 12, 4, 26, 8,
                         16, 7, 27, 20, 13, 2,
                         41, 52, 31, 37, 47, 55,
                         30, 40, 51, 45, 33, 48,
                         44, 49, 39, 56, 34, 53,
                         46, 42, 50, 36, 29, 32 };


string left = desKey.substr(0, 28);
    string right = desKey.substr(28, 28);

    vector<string> roundKeyBinary; // roundKeyBinary for RoundKeys in binary
    vector<string> roundKeyHexaDecimal; // roundKeyHexaDecimal for RoundKeys in hexadecimal
    for (int iterator = 0; iterator < 16;iterator++) {
        left = shiftBitsInLeft(left, shiftingTable[iterator]);
        right = shiftBitsInLeft(right, shiftingTable[iterator]);


        string combine = left + right;

        string RoundKey = permutationFunction(combine, keyCompressionTable, 48);

        roundKeyBinary.push_back(RoundKey);
        roundKeyHexaDecimal.push_back(binaryToHexaDecimal(RoundKey));
    }

    cout <<endl <<"Encryption:"<<endl<<endl;
    string cipherText = encryptionInDataEncryptionStandard(plainText, roundKeyBinary, roundKeyHexaDecimal);
    cout << "\ncipher Text: " << cipherText << endl;

    cout <<endl <<"Decryption"<<endl<<endl;;
    reverse(roundKeyBinary.begin(), roundKeyBinary.end());
    reverse(roundKeyHexaDecimal.begin(), roundKeyHexaDecimal.end());
    string text = encryptionInDataEncryptionStandard(cipherText, roundKeyBinary, roundKeyHexaDecimal);
    cout << "\nPlain Text: " << text << endl;

    return 0;
}


