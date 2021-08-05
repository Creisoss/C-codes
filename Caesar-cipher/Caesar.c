#include <stdio.h>
#include <stdlib.h>
int main()
{

	char CurrentWord(int DirSpeed,char current);
	void WriteOnFile(char text[300]);
	int pointer;
	char message[300];
	char encryptedMessage[300];
	
	while(1>0){
		printf("Write a message: ");
		scanf(" %[^\n]s",message);
		printf("Choose how to encrypt the message by typing the direction and how fast the pointer will move\n");
		printf("You can choose to type between 26 an -26 but type 0 to end the program: ");
		scanf("%i",&pointer);
	
		if(pointer == 0){	
			return 0;
		}else{
		for(int i =0;i <300;i++){
			encryptedMessage[i] = CurrentWord(pointer,message[i]); 
		}
	
		}
		printf("%s\n",message);
		printf("%s\n",encryptedMessage);
		WriteOnFile(encryptedMessage);
	}
}

//this function encrypt the current letter and return the ecrypted letter
char CurrentWord(int DirSpeed,char current)
{
	char lower[]="abcdefghijklmnopqrstuvwxyz";
	char upper[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int pointer = 0;
	if(current >= 'A' && current <= 'Z'){
		for(int i =0;i <26;i++){
			for(int j=0;j<26;j++){
				if(current == upper[j]){
					pointer = j;
					break;
				}
			}
			pointer = pointer + DirSpeed;
			if(pointer < 0){
				pointer = pointer + 26;
			}
			if(pointer >= 26){
				pointer = pointer - 26;
			}
			return upper[pointer];
		}
        }else if(current >= 'a' && current <= 'z'){
		    for(int i =0;i <26;i++){
			   for(int j=0;j<26;j++){
                                if(current == lower[j]){
                                        pointer = j;
                                        break;
                                }
                        }
                        pointer = pointer + DirSpeed;
                        if(pointer < 0){
                                pointer = pointer + 26;
                        }
                        if(pointer >= 26){
                                pointer = pointer - 26;
                        }
			return lower[pointer];
                }
        }else if(current == ' '){
		return ' ';
	}else{
		return '\0';
        }

}
//Write the encrypted message on atxt file
void WriteOnFile(char text[300])
{
	FILE *f = fopen("Crypto.txt", "a");
	if (f == NULL)
	{
    		printf("Error opening file!\n");
    		exit(1);
	}	

	/* print some text */
	fprintf(f,"%s\n", text);

}
