// ödev3 dosya iþlemleri
#include<stdio.h>
#include<stdlib.h>

void Basarili(FILE *BasariliOgrenciDosyasi, int OgrenciNo, char Ad[], int vize, int final, int GenelOrtalama)
{
	int vizeort,finalort,Ort;
	char HarfNotu;
	if(60>=GenelOrtalama)
	{
		HarfNotu='C';
	}
	
	else if(80>=GenelOrtalama)
	{
		HarfNotu='B';
	}
	
	else if(100>=GenelOrtalama)
	{
		HarfNotu='A';
	}
	
	fprintf(BasariliOgrenciDosyasi,"%d\t%s\t%d\t%d\t%d\t%c%c\n",OgrenciNo,Ad,vize,final,GenelOrtalama,HarfNotu,HarfNotu);
}

void Kalan(FILE *KalanOgrenciDosyasi, int OgrenciNo, char Ad[], int vize, int final, int GenelOrtalama)
{
	int vizeort,finalort,Ort;
	char HarfNotu;
	if(40>=GenelOrtalama>=0)
	{
		HarfNotu='D';
	}
	fprintf(KalanOgrenciDosyasi,"%d\t%s\t%d\t%d\t%d\t%c%c\n",OgrenciNo,Ad,vize,final,GenelOrtalama,HarfNotu,HarfNotu);
}

main()
{ 
	FILE *OgrenciDosyasi;
	FILE *BasariliOgrenciDosyasi;
	FILE *KalanOgrenciDosyasi;
	
	int OgrenciNo,vize,final,GenelOrtalama;
	char Ad[10],HarfNotu; 
	int vizeToplam=0,finalToplam=0,sayac=0,Ort=0;
	
	OgrenciDosyasi=fopen("Ogrenci.txt","r");
	BasariliOgrenciDosyasi=fopen("BasariliOgrenciler.txt","w+");
	KalanOgrenciDosyasi=fopen("KalanOgrenciler.txt","w+");
	
	while(!feof(OgrenciDosyasi))
	{	
		fscanf(OgrenciDosyasi,"%d\t%s\t%d\t%d\n",&OgrenciNo,&Ad,&vize,&final);  //satir	
		// printf("%d\t%s\t%d\t%d\n",OgrenciNo,Ad,vize,final); //konsola Ogrenci.txt yazdýrma
		GenelOrtalama=(vize*0.4)+(final*0.6);
		//printf("%d ",GenelOrtalama);
		
		if(GenelOrtalama>40)
		{	
			Basarili(BasariliOgrenciDosyasi,OgrenciNo,Ad,vize,final,GenelOrtalama);		
		}
		else
		{	
			Kalan(KalanOgrenciDosyasi,OgrenciNo,Ad,vize,final,GenelOrtalama);
		}
	}
//Genel tüm öðrencilerin vize ve final ortalamasýný bulup BasariliOgrenciDosyasinýn ve KalanOgrenciDosyasinýn en altýna yazdýrma
/*	rewind(OgrenciDosyasi);  
	
	while(!feof(OgrenciDosyasi)) 
	{
		fscanf(OgrenciDosyasi,"%d\t%s\t%d\t%d", &OgrenciNo, &Ad, &vize, &final);
		vizeToplam += vize;
		finalToplam += final;
		sayac++;
	}
	
	vizeToplam=vizeToplam/sayac;
	finalToplam=finalToplam/sayac;
	
	Ort = (vizeToplam*0.4+finalToplam*0.6);
	
	fprintf(BasariliOgrenciDosyasi,"--\t\t--\t%d\t%d\t%d",vizeToplam,finalToplam,Ort);
	fprintf(KalanOgrenciDosyasi,"--\t\t--\t%d\t%d\t%d",vizeToplam,finalToplam,Ort);
	
*/
	rewind(BasariliOgrenciDosyasi);  // basarali ogrencilerin ortalamasýný bulýup en altýna yazdýrma
	while(!feof(BasariliOgrenciDosyasi)) 
	{
		fscanf(BasariliOgrenciDosyasi,"%d\t%s\t%d\t%d\t%d\t%c%c\n",&OgrenciNo,&Ad,&vize,&final,&GenelOrtalama,&HarfNotu,&HarfNotu);
		vizeToplam += vize;
		finalToplam += final;
		sayac++;
	}
	
	vizeToplam=vizeToplam/sayac;
	finalToplam=finalToplam/sayac;
	
	Ort = (vizeToplam*0.4+finalToplam*0.6);
	
	fprintf(BasariliOgrenciDosyasi,"--\t\t--\t%d\t%d\t%d",vizeToplam,finalToplam,Ort);
	
	vizeToplam=0,finalToplam=0,sayac=0,Ort=0;
	rewind(KalanOgrenciDosyasi);
	while(!feof(KalanOgrenciDosyasi)) 
	{
		fscanf(KalanOgrenciDosyasi,"%d\t%s\t%d\t%d\t%d\t%c%c\n",&OgrenciNo,&Ad,&vize,&final,&GenelOrtalama,&HarfNotu,&HarfNotu);
		vizeToplam += vize;
		finalToplam += final;
		sayac++;
	}

	vizeToplam=vizeToplam/sayac;
	finalToplam=finalToplam/sayac;
	
	Ort = (vizeToplam*0.4+finalToplam*0.6);
	
	fprintf(KalanOgrenciDosyasi,"--\t\t--\t%d\t%d\t%d",vizeToplam,finalToplam,Ort);
}
