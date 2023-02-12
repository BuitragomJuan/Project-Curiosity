#include <iostream>
#include <string.h>


using namespace std;

bool encontrarC(char comando[200]){
	bool flag=true;
	char *apu;
	int c1,c2,c3,c4,c5,c6,c7,c8,c9,c10,c11;
	apu=strtok(comando," ");
	//se dividio el string en varios con division por espacios
	c1=strcmp("cargar_comandos",(apu));
	c2=strcmp("cargar_elementos",(apu));
	c3=strcmp("agregar_movimiento",(apu));
	c12=strcmp("agregar_analisis",(apu));
	c4=strcmp("agregar_elemento",(apu));
	c5=strcmp("guardar",(apu));
	c6=strcmp("simular_comandos",(apu));
	c7=strcmp("salir",(apu));
	c8=strcmp("ubicar_elementos",(apu));
	c9=strcmp("en_cuadrante",(apu));
	c10=strcmp("crear_mapa",(apu));
	c11=strcmp("ruta_mas_larga",(apu));
	//se comparo con cada comando y se guardo en las variables enteras
	
	
	if(c1==0){
		apu=strtok(NULL," ");
		cout<<endl<<"nombre archivo : "<<apu;
	}
	else if(c2==0){
		apu=strtok(NULL," ");
		cout<<endl<<"nombre archivo : "<<apu;
	}	
	else if(c3==0){
		apu=strtok(NULL," ");
		cout<<endl<<"tipo movimiento : "<<apu;
		apu=strtok(NULL," ");
		cout<<endl<<"magnitud : "<<apu;
		apu=strtok(NULL," ");
		cout<<endl<<"unidad medida : "<<apu;
	}
	else if(c4==0){
		apu=strtok(NULL," ");
		cout<<endl<<"tipo comp : "<<apu;
		apu=strtok(NULL," ");
		cout<<endl<<"tamaño : "<<apu;
		apu=strtok(NULL," ");
		cout<<endl<<"unidad med: "<<apu;
		apu=strtok(NULL," ");
		cout<<endl<<"coordx : "<<apu;
		apu=strtok(NULL," ");
		cout<<endl<<"corrdy : "<<apu;
	}
	else if(c5==0){
		apu=strtok(NULL," ");
		cout<<endl<<"tipo archivo : "<<apu;
		apu=strtok(NULL," ");
		cout<<endl<<"nombre archivo : "<<apu;
	
	}
	else if(c6==0){
		apu=strtok(NULL," ");
		cout<<endl<<"coord x : "<<apu;
		apu=strtok(NULL," ");
		cout<<endl<<"coordy : "<<apu;
	}
	else if(c7==0){
		//poner un return 0 o algo asi porque es salir
	}
	else if(c8==0){
		//ubicar elementos
	}
	else if(c9==0){
		apu=strtok(NULL," ");
		cout<<endl<<"coord x1 : "<<apu;
		apu=strtok(NULL," ");
		cout<<endl<<"coord x2 : "<<apu;
		apu=strtok(NULL," ");
		cout<<endl<<"coord y1 : "<<apu;
		apu=strtok(NULL," ");
		cout<<endl<<"coord y2: "<<apu;
	}
	else if(c10==0){
		apu=strtok(NULL," ");
		cout<<endl<<"coeficiente conectividad: "<<apu;
	}
	else if(c11==0){
		//ruta mas larga
	}
	else if(c12==0){
		apu=strtok(NULL," ");
		cout<<endl<<"tipo analisis : "<<apu;
		apu=strtok(NULL," ");
		cout<<endl<<"objeto : "<<apu;
		apu=strtok(NULL," ");
		cout<<endl<<"comentario : "<<apu;
	}
	else{
		flag=false;
	}
	
	return flag;
}

