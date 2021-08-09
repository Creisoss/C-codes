#include <stdio.h>


int main(){
	void readFile();
	readFile();
	return 0;
}

//decrypt char by char the string
char decrypt(char msg, int dir)
{
	char lower[]="abcdefghijklmnopqrstuvwxyz";
	char upper[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char letter;
	int pointer = 0;
	int place = 0;
	if(msg >= 'A' && msg <= 'Z'){
		for(int i = 0;i < 26;i++){
			if(msg == upper[i])
			{
				pointer = i;
				break;
			}
			}
			place = pointer + dir;
			if(place < 0)
			{
				place = place + 26;
			}
			if(place >=26)
			{
				place = place - 26;
			}
			
			letter = upper[place];
			return letter;		
		
        }else if(msg >= 'a' && msg <= 'z'){
		   for(int i = 0;i < 26;i++){
			if(msg == lower[i])
			{
				pointer = i;
				break;
			}
		 	}	
		 	place = pointer + dir;
			if(place < 0)
			{
				place = place + 26;
			}
			if(place >=26)
			{
				place = place - 26;
			}
			
			letter = lower[place];
			return letter;	
                
        }else if(msg == ' '){
		return ' ';
	}else{
		return msg;
        }
}

void readFile()
{
	char decrypt(char msg,int dir);
	char dmessage[1000];
	
  	char filename[] = "Crypto.txt";
  	FILE *file = fopen ( "Crypto.txt", "r" );
	//read line a line of the Crypto file then encrypt only the current line
 	 if (file != NULL) {
  	 	char line [1000];
   		while(fgets(line,1000,file)!= NULL) /* read a line from a file */ {
   		//decrypt the encrypted string
			for(int i = 0; i<26;i++)
			{
				for(int j = 0;j<1000;j++)
				{
					dmessage[j] =decrypt(line[j],i);
				}
				if(i==0){
					printf("The possible messages of the encrypted message:  %s\n",dmessage);
				}else{
					printf("%i - %s\n",i,dmessage);
				}
			}
   	 }

   	 	fclose(file);
 	 }	
 	 else {
   	 	perror(filename); //print the error message on stderr.
  	}

}
