// Kullanýcýnýn girdiði sýnav notu hem vize hem final notundan büyükse yaz."Ogrenci.txt"var
#include <stdio.h>
#include <stdlib.h>

main()
{
	FILE *OgrenciDosyasi;
	FILE *Dosya;
	
	int OgrenciNo,Vize,Final;
	char Ad[10];
	int sinavNotu;

	printf("Lutfen bir sinav notu giriniz:");
	scanf("%d",&sinavNotu);
		
	OgrenciDosyasi=fopen("Ogrenci.txt","r");
	Dosya=fopen("notlar2.txt","w");
	
	while(!feof(OgrenciDosyasi))
	{	
		fscanf(OgrenciDosyasi,"%d	%s	%d	%d\n",&OgrenciNo,&Ad,&Vize,&Final);  //satir	
		//printf("%d	%s	%d	%d\n",OgrenciNo,Ad,Vize,Final);
		
		if(Vize>=sinavNotu && Final>=sinavNotu)
		{
			fprintf(Dosya,"%d	%s	%d	%d\n",OgrenciNo,Ad,Vize,Final);
		}
	}		
}

