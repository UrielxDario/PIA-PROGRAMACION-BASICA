#include <iostream>
#include <conio.h>
#include <string.h>
#include <string>
#include <fstream>
#include<stdlib.h>
#include <ctype.h>

using namespace std; 

void Agendar();
void Ver();
void Modificar();
void Eliminar();
void Archivos();
int Validar(string nombre[]);

int reg;
int cantPacientes, *cantidad;
string *nombre, *hora, *trat, *desc;
float *precio, *total, *subtotal;
int n;


int main()
{
    int opcion;
    
    do
    {

        system("cls");
        cout << "********MENU********" << endl;
        cout << "1. Agendar cita" << endl;
        cout << "2. Citas vigentes" << endl;
        cout << "3. Modificar cita" << endl;
        cout << "4. Eliminar cita" << endl;
        cout << "5. Limpiar pantalla" << endl;
        cout << "6. Salir" << endl;
        cout << "********************" << endl;
        cout << "Opcion:";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            Agendar();
            return main();
            break;

        case 2:
        	Ver();
        	return main();
            break;
            
        case 3:
        	Modificar();
			return main();	
            break;
            
        case 4:
        	Eliminar();
        	return main();
            break;
            
        case 5:
        	system ("cls");
        	system("pause");
            break;
            
        case 6:
        	system("cls");
        	Archivos();
        	return 0;
            break;
            
        default:
        	system ("cls");
            cout << "!!! OPCION NO VALIDA !!!" << endl;
            system ("pause");
            break;
        }

        
    } while (opcion != 6);

    

    
    return 0;
}

int Validar(string s)
{
	
	for (int i = 0; i < s.length(); i++)
    {
        char x = s.at(i);
        if ( !(x >= 65 && x<=90 || x >= 97 && x<=122 || x==32 ) )
		{
			cout << "INGRESE SOLO LETRAS \n";
		   return 1;
		}
		 
    }
    return 2;
}

void Agendar()
{
	int val;
	
	system ("cls");
	cout << "Numero de citas para agendar : ";
	cin >> cantPacientes;
	
	
	nombre = new string [cantPacientes];
	hora = new string [cantPacientes];
	trat = new string [cantPacientes];
	desc = new string [cantPacientes];
	precio = new float [cantPacientes];
	cantidad = new int [cantPacientes];
	subtotal = new float [cantPacientes];
	total = new float [cantPacientes];
	
	for (int i=0; i<cantPacientes;i++)
    {
    	
    
        system("cls");
        cout << "-----------------CITA " << i+1 << "-----------------"<<endl;
        
        
        while (getchar() != '\n');
        
        do
		{
		cout << "*Ingrese nombre del paciente:" << endl;
        getline(cin, nombre[i]);
        
        val = Validar(nombre[i]);
        } while (val == 1);
        
        
        cout << "*Hora del tratamiento (formato 12hrs):" << endl;
        getline(cin, hora[i]);
        
        do
		{
        cout << "*Nombre del tratamiento:" << endl;
        getline(cin, trat[i]);
        
        val = Validar(trat[i]);
        } while (val == 1);
        
        do
        {
		
        cout << "*Descripcion del tratamiento:" << endl;
        getline(cin, desc[i]);
        val = Validar(desc[i]);
        } while (val == 1);

        cout << "*Precio unitario : " << endl <<"$";
        cin >> precio[i];

        cout << "*Cantidad de tratamientos: " << endl;
        cin >> cantidad[i];

        subtotal [i] = precio[i] * cantidad [i];
        total [i]= (subtotal [i] * 0.16) + subtotal[i];
        
        cout << "-----------------------\n";
        cout << "Subtotal: $" << subtotal[i]<<endl;
        cout << "-----------------------\n";
        cout << "TOTAL: $"<< total [i];
		cout << "\n-----------------------"<<endl;
        
		system("pause");
		
	}
}

void Ver()
{
	
	system("cls");
	for (int i=0; i<cantPacientes;i++)
    {
    	
        cout << "*************Cita " << i+1 << "*************"<<endl;
		cout <<"Nombre: "<< nombre[i] <<endl;
		cout <<"Hora: " << hora[i] <<endl;
		cout <<"Tratamiento: " << trat[i] <<endl;
		cout <<"Descripcion: " << desc[i] <<endl;
		cout <<"Precio: "<< precio[i] <<endl;
		cout <<"Cantidad: "<< cantidad[i] <<endl;
		cout<< "........................"<<endl;
		cout <<"Subtotal: $"<< subtotal[i] <<endl;
		cout<< "-----------------------"<<endl;
		cout <<"Total: $" << total[i] <<endl;
		cout<< "-----------------------"<<endl<<endl;	
    }
    system("pause");  
}
void Modificar()
{
	int val;
	int j, op;
	
	system("cls");
	 		cout<< "***Citas actuales: " << cantPacientes << "***\n\n";
	if (cantPacientes != 0)
	{
			
        	cout<< "Numero de cita a modificar: ";
        	cin >> j;
        	j = j-1;
        	
        	cout << "*************Cita " << j+1 << "*************"<<endl;
			cout <<"Nombre: "<< nombre[j] <<endl;
			cout <<"Hora: " << hora[j] <<endl;
			cout <<"Tratamiento: " << trat[j] <<endl;
			cout <<"Descripcion: " << desc[j] <<endl;
			cout <<"Precio: "<< precio[j] <<endl;
			cout <<"Cantidad: "<< cantidad[j] <<endl;
			cout<< "........................"<<endl;
			cout <<"Subtotal: $"<< subtotal[j] <<endl;
			cout<< "-----------------------"<<endl;
			cout <<"Total: $" << total[j] <<endl;
			cout<< "-----------------------"<<endl<<endl;
			
			
			do
			{
        		cout<<"Que desea modificar? (1:Nombre, 2:Hora, 3:NombreTratamiento, 4:Descripcion, 5:Precio, 6:Cantidad)"<<endl;
	     	    cin>>op;
		        switch(op)
		        {
		        case 1:
		        for(int i=j;i==j;i++)
		        {
		            cout<<"..Modificando cita "<<i+1<<"..."<<endl;
		            while (getchar() != '\n'); 
					do
					{
					cout << "*Ingrese nombre del paciente:" << endl;
			        getline(cin, nombre[i]);
			        
			        val = Validar(nombre[i]);
			        } while (val == 1);
		        }
		        break;
		        
		        case 2:
		        for(int i=j;i==j;i++)
		        {
		            cout<<"..Modificando cita "<<i+1<<"..."<<endl;
		            while (getchar() != '\n'); 
					cout << "Hora (FORMATO 12HRS): ";
					getline(cin, hora[i]);
		        }
		        break;
		        
		        case 3:
		        for(int i=j;i==j;i++)
		        {
		            cout<<"..Modificando cita "<<i+1<<"..."<<endl;
		            while (getchar() != '\n'); 
					do
					{
			        cout << "*Nombre del tratamiento:" << endl;
			        getline(cin, trat[i]);
			        
			        val = Validar(trat[i]);
			        } while (val == 1);
		        }
		        break; 
		        
		        case 4:
		        for(int i=j;i==j;i++)
		        {
		            cout<<"..Modificando cita "<<i+1<<"..."<<endl;
		            while (getchar() != '\n'); 
					do
			        {
					
			        cout << "*Descripcion del tratamiento:" << endl;
			        getline(cin, desc[i]);
			        val = Validar(desc[i]);
			        } while (val == 1);
		        }
				break;
				
				case 5:
				for(int i=j;i==j;i++)
		        {
		            cout<<"..Modificando cita "<<i+1<<"..."<<endl;
		             
					cout << "Precio unitario: ";
					cin >> precio[i];
					subtotal [i] = precio[i] * cantidad [i];
        			total [i]= (subtotal [i] * 0.16) + subtotal[i];
		        } 	
		        break;
		        
		        case 6:
				for(int i=j;i==j;i++)
		        {
		            cout<<"..Modificando cita "<<i+1<<"..."<<endl;
		            
					cout << "Cantidad: ";
					cin >> cantidad[i];
					subtotal [i] = precio[i] * cantidad [i];
        			total [i]= (subtotal [i] * 0.16) + subtotal[i];
		        } 	
		        break;
		        
		        default:
		        	system("cls");
		        	cout<<"!!!OPCION NO VALIDA !!!"<<endl;
		        	system("pause");
		        break;
		        	
	        	}
	        	cout<<"\n\nQuiere modificar algo mas? (1:SI, 2:NO): ";
	        	cin >> reg;
	        } while (reg==1);
	        
    } 
    system ("pause");
}

void Eliminar()
{
	int j;
	system("cls");
	cout<< "***Citas actuales: " << cantPacientes << "***\n\n";
	cout << ".........................................\n";
	cout << "Registro a elimiar: ";
	cin >> j;
	j = j - 1;
	for (int i = j;i == j;i++)
	{
		cout << "\n\n";
		cout << "*** Eliminando registro " << j + 1 <<"***" << endl;
		
		nombre[i] = " ";
		trat[i] = " ";
		desc[i] = " ";
		hora[i] = " ";
		precio[i] = 0;
		cantidad[i] = 0;
		subtotal[i] = 0;
		total[i] = 0;
		
	}
	
	cout << "...BORRADO CON EXITO...\n";
	system ("pause");
}

void Archivos ()
{
	ofstream archivo; 
	string nombreArchivo;
	float decimales;
	int enteros;
	string texto;
	
	nombreArchivo = "Citas.txt";
	archivo.open(nombreArchivo.c_str(), ios::out);
	
	if (archivo.fail())
	{
		cout << "!!! ERROR NO SE PUDO CREAR EL ARCHIVO !!!";
		exit(1);
	}
	
	
	for (int i = 0;i < cantPacientes;i++)
	{
		if (nombre[i] == " " )
		{
			archivo << "\n_______________________\n";
			archivo << "CITA ELIMINADA";
			archivo << "\n______________________\n";
		}
		else
		{
			archivo << "__________________________________________________\n";
			archivo << "---------------CITA " << i+1 << "--------------\n";
			texto = nombre[i];
			archivo << "Nombre: " << texto << "\n";
			
			texto = hora[i];
			archivo << "Hora: " << texto << "\n";
			
			texto = trat[i];
			archivo << "Tratamiento: " << texto << "\n";
			
			texto = desc[i];
			archivo << "Descripcion: " << texto << "\n";
			
			enteros = cantidad[i];
			archivo << "Cantidad: " << enteros << "\n";
			
			decimales = precio[i];
			archivo << "Precio Unitario: $" << decimales << "\n";
			
			subtotal [i] = precio[i] * cantidad [i];
			decimales = subtotal [i];
			archivo << "Subtotal: $" << decimales;
			
			
            total [i]= (subtotal [i] * 0.16) + subtotal[i];
            decimales = total [i];
            archivo << "\n.....................\n";
			archivo << "TOTAL: $" << decimales;
			archivo << "\n.....................\n";
			archivo << "_______________________\n\n";
			
		}
	}
	
}
