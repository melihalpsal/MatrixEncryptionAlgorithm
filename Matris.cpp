#include <stdio.h>
#include <conio.h>
#include <locale.h>
#include <string.h>

fonk(char *metin,char *alfabe,char melih[][5],char naci[][5],char alpsal[][5])
{
     
     int i,j,k=0,satirvesutunlar[100],satirvesutunlar2[100],z; 
     
     while(metin[k]!='\0')
	 {
	 	
		for(j=0;j<30;j++)
        {
     	   if(metin[k]==alfabe[j])
     	   {
     		break;
		   }
		}
		
	   if(k%2)
	   {
	   	i=j%5;
	   	satirvesutunlar[k]=i;
	   	i=j/5;
	   	satirvesutunlar2[k]=i;
	   }
	   
	   else
	   {
	   	i=j/5;
	    satirvesutunlar[k]=i;
	    i=j%5;
	    satirvesutunlar2[k]=i;
	   }
	   
       k++;   
	                     
     }
	 
	 for(z=0;z<strlen(metin);z++)
	  {
	  	metin[z]=alpsal[satirvesutunlar[z]][satirvesutunlar[z+1]]; 
	  	metin[z+1]=naci[satirvesutunlar2[z+1]][satirvesutunlar2[z]]; z++;
	  }
	   
}

cozme(char *metin,char *alfabe,char melih[][5],char *naci,char *alpsal)
{
     
     int i,j,k=0,satirvesutunlar[100],satirvesutunlar2[100],z; 
     
     
     while(metin[k]!='\0')
	 {
	 	if((k%2)==0)
	 	{
	 		for(j=0;j<30;j++)
            {
     	      if(metin[k]==alpsal[j])
     	       {
     		      break;
		       }
		    }
		    
		    satirvesutunlar[k]=j/5;
		    satirvesutunlar2[k]=j%5;
		}
		
		else
		{
			for(j=0;j<30;j++)
            {
     	      if(metin[k]==naci[j])
     	       {
     		      break;
		       }
		    }
		    
		    satirvesutunlar[k]=j%5;
		    satirvesutunlar2[k]=j/5;
		}
	   
        k++;                      
     }
	 
	 for(z=0;z<strlen(metin);z++)
	  {
	  	metin[z]=melih[satirvesutunlar[z]][satirvesutunlar[z+1]]; 
	  	metin[z+1]=melih[satirvesutunlar2[z+1]][satirvesutunlar2[z]]; z++;
	  }
	   
}

main()
{
	setlocale(LC_ALL,"Turkish"); 
	 char alfabe[30] = { 'a', 'b', 'c', 'ç', 'd', 'e', 'f', 'g', 'ð', 'h', 'ý', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'ö', 'p', 'r', 's', 'þ', 't', 'u', 'ü', 'v', 'y', 'z', 'x' };
     char matris1[6][5] = { { 'a', 'b', 'c', 'ç', 'd' }, { 'e', 'f', 'g', 'ð', 'h' }, { 'ý', 'i', 'j', 'k', 'l' }, { 'm', 'n', 'o', 'ö', 'p' }, { 'r', 's', 'þ', 't', 'u' }, { 'ü', 'v', 'y', 'z', 'x' } };	 
	 char ucuncu[6][5] = { { 'c', 'p', 'k', 'ð', 'i' }, { 'v', 't', 'o', 'x', 'd' }, { 'z', 'f', 'u', 'b', 'm' }, { 'a', 'ü', 'e', 'h', 'j' }, { 'ý', 'y', 'ö', 's', 'g' }, { 'n', 'þ', 'l', 'ç', 'r' } };	 
	 char birinci[6][5] = { { 'k', 'g', 'c', 'o', 'x' }, { 's', 'v', 'u', 'p', 'd' }, { 'h', 'm', 'z', 'ý', 't' }, { 'y', 'ç', 'r', 'b', 'l' }, { 'ö', 'f', 'i', 'e', 'ð' }, { 'j', 'þ', 'a', 'n', 'ü' } };	 
     char metin[100],z,*tmp1,*tmp2; tmp1=(&birinci[0][0]); tmp2=(&ucuncu[0][0]); int sayac; 
     printf("Metin giriniz: "); gets(metin); int i=0,j,k;  char c = metin[0];
     
     while(c!='\0')
     {
     	for(j=0;j<30;j++)
        {
     	   if(c==alfabe[j])
     	   {
     		break;
		   }
		   
		   if(j==29)
		   {
		   	printf("Yanlýþ metin girdiniz! Lütfen geçerli bir metin giriniz: "); gets(metin); c = metin[0]; j=-1; i=0;
		   }
	    }
	    
	    i++;
	    c=metin[i];
	 }
	 
	 if(strlen(metin)%2)
	 {
	 	metin[strlen(metin)]='x';
	 }
    
     
     fonk(metin,alfabe,matris1,ucuncu,birinci);
     printf("\nsifreli :%s",metin);
     cozme(metin,alfabe,matris1,tmp2,tmp1);
     printf("\n\nacilmis :%s",metin); getch();
}
