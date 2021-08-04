#include <stdio.h>
#include <stdlib.h>

int main()
{
        //variables declaration
        int cont=0;
        double pi=4.0;
        int factors = 0;
        double x=-3;
        double y;
        //input
        printf("Type the number of numbers you want to see after the comma of PI: ");
        scanf("%i",&factors);
        char output[factors];
	//data process
	//this while needs 1 billion lops to recieve max precision in a reasonable time	
       	while(cont < 1000000000)
        {
                y = 4.0/x;
                pi = pi + y;
                if(x <0)
                {
                        x = x - 2;
                }else
                {
                        x = x + 2;
                }
                x = x * (-1);
                cont++;
        }
	//output
	snprintf(output,factors,"%0.10000f",pi);
	printf("You will print %i numbers after the comma\n",factors);
	printf("Remember this is just an approximation\n");
	printf("%s\n",output);
        return 0;
}
                                                   
