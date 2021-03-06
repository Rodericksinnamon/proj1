/*--------- Encryption and Decryption Program 
INSTRUCTIONS: Program takes input from file relative to encryption type. It stores
that encryption in the corresponding file named EncryptedR for rotation and EncryptedS for 
substitution. Then peforms decryption of that enrcypted text stored in that file when the decryption
option is selected.--------*/

# include <stdio.h>

/*------ Function prototype list. These functions will be used throughout the program
they are listed here so that the system knows what their arguments are, much in the same
way one declares an int or char value inside main. A function is declared outside of main.
See the detailed descrption of each function below main where they are written.
--------*/

char encryption_rotation(char [], int); 

char decryption_rotation(char [],int); 

char encryption_substitution(char [], char[]);

char decryption_substitution(char [], char[]);

void upper_string(char []);


int main() 
{
    
        char message[10000]; //Declares a string to store the file input in for operation.
        char choice; // A char variable to store the users input choice. Could be type int, however letters were chosen so key does not get mixed with choices in menu.
        int key;    // Value between 0 and 26 that the alphabet used for the text is to be shifted by.
 /* Declaring pointers and pointer type for various files to be used in the program */    
      FILE *RotationText;
      FILE *SubstitutionText;
      FILE *ER;
      FILE *ES;
 //Friendly user interface
 
    printf("welcome\n \n");
    
    printf("Select an option for Cipher and Cipher type:\n \nRotation Encyrption > (a)\n \n");
    printf("Substitution Encryption > (b)\n \n");
    printf("Rotation Decryption > (c)\n \n");
    printf("Substition Decryption > (d) \n \n");
    printf("Rotation Decryption attack > (e) \n \n");
    printf("Substitution Decryption attack > (f) \n \n");
    scanf("%c", &choice); //scans for user input a,b,c,d. and stores in choice.

    
    
/*----- Switch case to respond to the input from user. Within each respective case is the appropriate function
that the user has called for the various encryption or decryption type. Each case is a complete operation in of itself. 
Upon complettion of the case the entire program will cease.
------*/    
    switch(choice)
    {
                case 'a':
                      printf("You selected Rotation Encryption\n \n Enter a key(between 0 and 26):> \n"); //Tells the user what encryption/decryption type they selected and prompts for key.
                      scanf("%d", &key); //scans for user input between 0 and 26 and stores in key
                      printf("key entered: ---> %d\n \n", key); //Tells the user what key was entered.
               
                      RotationText = fopen("RotationText.txt", "r"); //opens file for reading and stores it in RotationText.
                      ER = fopen("EncryptedR.txt", "w"); //opens file for writing

                      fread(message, 1000, 1, RotationText);//Reads the entire file and stores it in the string message. limited to 10000 characters.
                      message[(sizeof message)-1] = 0;//sets string index 9999 to 0. 
                      upper_string(message); //Changes value of any lower case letter to upper case.
                      
                      encryption_rotation(message, key); //Function taking string and key as arguments will return new value of string.

                      printf("Encrypted Message is: \n \n%s\n", message); //prints string/encrypted message.
                        
                      fputs(message, ER); //Sends string to file
                      
                      fclose(RotationText); //closes file
                      fclose(ER);
                    break;
                    
                case 'b':
                      printf("You selected Substitution Encryption\n"); //Tells the user what they have selected.
                      printf("Enter a subsitution string of 26 letters");

                      char sub[27];
                      scanf("%s", sub);
                      upper_string(sub); //converts to upper case the string sub.  
                      
                      SubstitutionText = fopen("SubstitutionText.txt", "r+"); //opens file for reading and stores it in substitutionText.
                      ES = fopen("EncryptedS.txt", "w"); //Opens file for writing
                      
                      fread(message, 1000, 1, SubstitutionText);
                      message[(sizeof message)-1] = 0;
                      upper_string(message); //Changes value of any lower case letter to upper case.
                      
                      encryption_substitution(message, sub); //Function taking string and substitution as arguments will return new value of string.

                      printf("Encrypted Message is: \n \n%s\n", message); //prints string/encrypted message.
                      
                      fputs(message, ES); //Sends string 'message' to file
                      
                      fclose(SubstitutionText); //closes file.
                      fclose(ES);
                    break; 
                
                case 'c':
                      printf("You selected Rotation Decryption\n \n Enter a key: \n");
                      scanf("%d", &key); //scans for user input between 0 and 26 and stores in key
                      printf("key entered: ---> %d\n \n", key); //Tells the user what key was entered. 
                      
                      ER = fopen("EncryptedR.txt", "r"); // Opens file for reading
                      RotationText = fopen("RotationText.txt", "w"); //opens file for writing and stores it in RotationDecryption.
                      
                      fread(message, 10000, 1, ER);
                      message[(sizeof message)-1] = 0;
                      
                      upper_string(message); //Changes value of any lower case letter to upper case.
                      
                      decryption_rotation(message, key); //Function taking string and key as arguments will return new value of string.
                      
                      printf("Decrypted Message is: \n \n%s\n", message); //prints string/encrypted message.
                     
                      fputs(message, RotationText); //Sends message to Rotation Text
                     
                      fclose(ER);
                      fclose(RotationText);//Closes file.
                      
                     break;
                     
                case 'd':
                      printf("You selected Substitution Decryption\n \n");
                       printf("Enter a subsitution string of 26 letters");

                      char subd[27];
                      scanf("%s", subd);
                      
                      //char subd[] = "qwertyuiopasdfghjklzxcvbnm";
                       
                      upper_string(subd);
                    
                      ES = fopen("EncryptedS.txt", "r");  
                      SubstitutionText = fopen("SubstitutionText.txt", "w"); //opens file for writing.
                      
                      fread(message, 10000, 1, ES);
                      message[(sizeof message)-1] = 0;
                      
                      upper_string(message); //Changes value of any lower case letter to upper case.
                      
                      decryption_substitution(message, subd); //Function taking string and substitution alphabet as arguments will return new value of string.
                     
                      printf("Decrypted Message is: \n \n%s\n", message); //prints string/encrypted message.
                      
                      fputs(message, SubstitutionText);
                      
                      fclose(ES);
                      fclose(SubstitutionText); //Closes file
                      
                     break;
                case 'e':
                    printf("You selected to do a Rotation Decryption attack.");
                     break;
                case 'f':
                    printf("You selected to do a Substitution Decryption attack.");
                     break;
                default:
                
                    printf("Invalid choice please restart program\n");
        }
                    
        return 0;
        
}
/*------------------------------------
Function of type char. Takes two arguments, a char string and an integer. 
Encrypts a text with a caesar cipher.
It then returns a string index. Repeating until the end of the string.
-------------------------------------*/
char encryption_rotation(char s[], int a)
{
        char cipher; //Declaring char variable to be used for encryption
         int i;     //Declaring integer to take index value to shuffle through string.
      
    
    for(i = 0; s[i] != '\0'; ++i)//Counts through each string index until the end.
    {
            cipher = s[i]; //assigns index value to an individual variable to be operated on
            
        if(cipher >= 'A' && cipher <= 'Z')//checks to see if value is within normal alphabet.
        {
            cipher = cipher + a;  //adds the value of the key to the letter changing its ASCII value                

            if(cipher > 'Z') //checks again to make sure value is not outside range of letters
             {
                cipher = cipher - 'Z' + 'A' - 1;//If ASCII value greater than Z moves it to make it a letter again.
                                                //Eg, if Z shifts by 2 it becomes B, instead of a bracket
             }
                else if(cipher == '\0') //If cipher is at the end of the string read with fread it doesn't change the value of the null, otherwise it changes value and prints an unwanted character.
                    cipher = cipher + 0;
                }
                    else // if the character is anything other than a letter (Space, . , ! ? etc) value is unchanged.
                {
                    {
                        cipher = cipher + 0;
                    }
        }

            s[i] = cipher; //Assigns new value to the old index.
            
    }        
            
        return s[i]; //Returns index value to string in main.

}
/*-----------------------------------
 Function of type char. Takes two arguments, a char string and an integer. 
Decrypts an Encrypted text with a caesar cipher and known key.
It then returns a string index. Repeating until the end of the string.
-------------------------------------*/
char decryption_rotation(char s[],int a)
{
          char cipher; //Declaring char variable to be used for decryption
         int i; //Declaring variable to count through string
      
      
    
    for(i = 0; s[i] != '\0'; ++i) //Shuffles through string from beggining to end.
    {
            cipher = s[i]; //Assigns value of index of string to cipher for operating
  /*--------
  Special characters listed to ensure their value does not change
  --------*/          
      switch(cipher)
      {
        
        case ':':
                s[i] = cipher;
        
        case ' ':
                s[i] = cipher;
               
        case '.':
                s[i] = cipher;
               
        case '?':
                s[i] = cipher;
               
        case ',':
                s[i] = cipher;
        
              
        default:
                cipher = cipher;
        }    

        if(cipher >= 'A' && cipher <= 'Z') //Checks to see if ASCII value of cipher is within alphabet.
             {
                 cipher = cipher - a; //Changes value of cipher relative to key                 

           if(cipher < 'A') //checks to see if key moved value outside of alphabet. 
            {
                cipher = cipher + 'Z' - 'A' + 1; //If value outside, this places it back in. Eg, key 2 makes A = Y.
            }

            else //string index takes value of new cipher value.
            {
                s[i] = cipher;
            }
       } 
            else //If cipher is within value string index is assigned new cipher value.
            {
                s[i] = cipher;
            }
            
            s[i] = cipher; //If no if statement applies string index takes on the value of cipher from switch case.

}        
            
        return s[i]; //Returns new string index value to string main.
}
/*----------------------------------
 Function of type char. Takes two char strings as arguments.
Encrypts a text with a substitution cipher.
It then returns a string index. Repeating until the end of the string.
-------------------------------------*/
char encryption_substitution(char s[], char sub[])
{
    char cipher; //Declares cipher for operating.
    int i; //Declares i to count through string's index
    
       for(i = 0; s[i] != '\0'; ++i) //Shuffles through string, beggining to end.
    {
            cipher = s[i]; //cipher assigned value of string index.
 /*-------------------------------------------
 Main body of function. Simply checks what alphabet letter cipher is and then
 assigns the corresponding substitution letter and if cipher is not a letter
 the value remains unchanged.
 ---------------------------------------------*/            
        switch(cipher)
        {
            case 'A':
                     cipher = sub[0];
                     break;
            case 'B':
                     cipher = sub[1];
                     break;
            case 'C':
                     cipher = sub[2];
                     break;
            case 'D':
                     cipher = sub[3];
                     break;
            case 'E':
                     cipher = sub[4];
                     break;
            case 'F':
                     cipher = sub[5];
                     break;
            case 'G':
                     cipher = sub[6];
                     break;
            case 'H':
                     cipher = sub[7];
                     break;
            case 'I':
                     cipher = sub[8];
                     break;
            case 'J':
                     cipher = sub[9];
                     break;
            case 'K':
                     cipher = sub[10];
                     break;
            case 'L':
                     cipher = sub[11];
                     break;
            case 'M':
                     cipher = sub[12];
                     break;
            case 'N':
                     cipher = sub[13];
                     break;
            case 'O':
                     cipher = sub[14];
                     break;
            case 'P':
                     cipher = sub[15];
                     break;
            case 'Q':
                     cipher = sub[16];
                     break;
            case 'R':
                     cipher = sub[17];
                     break;
            case 'S':
                     cipher = sub[18];
                     break;
            case 'T':
                     cipher = sub[19];
                     break;
            case 'U':
                     cipher = sub[20];
                     break;
            case 'V':
                     cipher = sub[22];
                     break;
            case 'W':
                     cipher = sub[22];
                     break;
            case 'X':
                     cipher = sub[23];
                     break;
            case 'Y':
                     cipher = sub[24];
                     break;
            case 'Z':
                     cipher = sub[25];
                     break;         
            default:
                     cipher = cipher;
        }     
    s[i] = cipher;  //Assigns new value of cipher to string index
    }
    return s[i]; //returns new string index to string in main.
}
/*----------------------------------
Function of type char. Takes two char strings as arguments.
Decrypts an encrypted text with a substitution cipher.
It then returns a string index. Repeating until the end of the string.
-------------------------------------*/
char decryption_substitution(char s[], char sub[])
{
    char cipher; //cipher declared for operating
    int i; //i declared for counting through string index's
    
       for(i = 0; s[i] != '\0'; ++i)// Counts through string from beggining to end.
     {
            cipher = s[i]; //Assigns value of string index to cipher for operating
/*------------------------
long if else statement to check if character in string is equal to a respective element
in substitution alphabet, if it is the corresponding normal alphabet letter is assigned
to cipher. Assuming subsitution alphabet is entered in chronological order of the letters
in the alphabet it wishes to replace.
-------------------------*/    
        if(sub[0] == cipher) 
        {
            cipher = 'A';
        }
         else if(sub[1] == cipher)
         {
             cipher = 'B';
         }
         else if(sub[2] == cipher)
         {
             cipher = 'C';
         }
            else if(sub[3] == cipher)
         {
             cipher = 'D';
         }
         else if(sub[4] == cipher)
         {
             cipher = 'E';
         }
         else if(sub[5] == cipher)
         {
             cipher = 'F';
         }
         else if(sub[6] == cipher)
         {
             cipher = 'G';
         }
         else if(sub[7] == cipher)
         {
             cipher = 'H';
         }
         else if(sub[8] == cipher)
         {
             cipher = 'I';
         }
         else if(sub[9] == cipher)
         {
             cipher = 'J';
         }
         else if(sub[10] == cipher)
         {
             cipher = 'K';
         }
         else if(sub[11] == cipher)
         {
             cipher = 'L';
         }
         else if(sub[12] == cipher)
         {
             cipher = 'M';
         }
         else if(sub[13] == cipher)
         {
             cipher = 'N';
         }
         else if(sub[14] == cipher)
         {
             cipher = 'O';
         }
         else if(sub[15] == cipher)
         {
             cipher = 'P';
         }
         else if(sub[16] == cipher)
         {
             cipher = 'Q';
         }
         else if(sub[17] == cipher)
         {
             cipher = 'R';
         }
         else if(sub[18] == cipher)
         {
             cipher = 'S';
         }
         else if(sub[19] == cipher)
         {
             cipher = 'T';
         }
         else if(sub[20] == cipher)
         {
             cipher = 'U';
         }
         else if(sub[21] == cipher)
         {
            cipher = 'V';
         }
         else if(sub[22] == cipher)
         {
             cipher = 'W';
         }
         else if(sub[23] == cipher)
         {
             cipher = 'X';
         }
         else if(sub[24] == cipher)
         {
             cipher = 'Y';
         }
         else if(sub[25] == cipher)
         {
             cipher = 'Z';
         }
            else
            {
                cipher = cipher;    
            }
              s[i] = cipher; //Assigns new value of cipher to string index
          }

                            return s[i]; //Returns new string index to string in main 
}
/*--------------------
Function modifies the value of any lower case letter to make it upper case.
ASCII 'a' becomes 'A'. Etc.
--------------------- */
void upper_string(char s[]) //Takes char string as an argurment.
{
   int i = 0; //declares i to count through string
   
   while (s[i] != '\0') //Exit condition is end of string. 
   {
      if (s[i] >= 'a' && s[i] <= 'z') //Checks to see if string index is lower case.
      {
         s[i] = s[i] - 32; //If lower case is will move it to its upper case value.
      }
      i++; //count through string.
   }
}