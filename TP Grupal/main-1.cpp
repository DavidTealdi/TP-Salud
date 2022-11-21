#include <iostream>
#include <stdlib.h>

using namespace std;

/*  FUNCIONES  */


/*  Funciones para el submenu de ADMINISTRAR ESPECIALIDADES MEDICAS  */

/* Alta_de_Especialidades_Medicas

  PROPOSITO:  agregar una especialidad medica al sistema
  PARAMETROS: no se requerira de ningun parametro
  RETORNO:    no se retornara nada

*/

void Alta_de_Especialidades_Medicas(){

    cout<<endl;
    cout<<"Se ha agregado una Especialidad Medica" <<endl;
    system("pause");
    cout<<endl;
};

/* Modificacion_de_Especialidades_Medicas

  PROPOSITO:  modificar una especialidad medica al sistema
  PARAMETROS: no se requerira de ningun parametro
  RETORNO:    no se retornara nada

*/

void Modificacion_de_Especialidades_Medicas(){

    cout<<endl;
    cout<<"Se ha modificado una Especialidad Medica"<<endl;
    system("pause");
    cout<<endl;
};

/* Baja_de_Especialidades_Medicas

  PROPOSITO:  quitar una especialidad medica al sistema
  PARAMETROS: no se requerira de ningun parametro
  RETORNO:    no se retornara nada

*/

void Baja_de_Especialidades_Medicas(){

    cout<<endl; // Espacios entre linea
    cout<<"Se ha eliminado una Especialidad Medica" <<endl;
    system("pause");
    cout<<endl;
};

/*  Listado_de_Especialidades_Medicas_completo

  PROPOSITO:  mostrar la lista de Especialidades Medicas pre-existente
  PARAMETROS: no se requerira de ningun parametro
  RETORNO:    no se retornara nada

*/

void Listado_de_Especialidades_Medicas_completo(){

    cout<<endl;
    cout<<"Se mostraron las Especialidades Medicas pre-existentes"<<endl;
    system("pause");
    cout<<endl;
};

/*  Listado_de_Especialidades_Medicas_por_busqueda

  PROPOSITO:  pedir al usuario un codigo de especialidad medica, para
              luego mostrar la especialidad asociada a ese codigo
  PARAMETROS: no se requerira de ningun parametro
  RETORNO:    no se retornara nada

*/

void Listado_de_Especialidades_Medicas_por_busqueda(){

    cout<<endl;
    cout<<"Mostrara� la especialidad medica que se ha solicitado por medio de un codigo unico"<<endl;
    system("pause");
    cout<<endl;
};


/*  Funciones para el submenu de ADMINISTRAR PACIENTES  */

/*  Alta_de_Pacientes

  PROPOSITO:  agregar a un paciente
  PARAMETROS: no se requerira de ningun parametro
  RETORNO:    no se retornara nada

*/

void Alta_de_Pacientes(){

    cout<<endl;
    cout <<"Se ha agregado un paciente"<<endl;
    system("pause");
    cout<<endl;
};

/*  Modificacion_de_Pacientes

  PROPOSITO:  modificar a un paciente
  PARAMETROS: no se requerira de ningun parametro
  RETORNO:    no se retornara nada

*/

void Modificacion_de_Pacientes(){

    cout<<endl;
    cout<<"Se ha modificado un paciente" <<endl;
    system("pause");
    cout<<endl;
};

/*  Baja_de_Pacientes

  PROPOSITO:  se va a eliminar a un paciente
  PARAMETROS: no se requerira de ningun parametro
  RETORNO:    no se retornara nada

*/

void Baja_de_Pacientes(){

    cout<<endl;
    cout<<"Se ha eliminado un paciente"<<endl;
    system("pause");
    cout<<endl;
};

/*  Listado_de_Pacientes_completo

  PROPOSITO:  se va a mostrar la lista de pacientes pre-existentes
  PARAMETROS: no se requerira de ningun parametro
  RETORNO:    no se retornara nada

*/

void Listado_de_Pacientes_completo(){

    cout<<endl;
    cout<<"Se ha mostrado la lista de pacientes pre-existentes"<<endl;
    system("pause");
    cout<<endl;
};

/*  Listado_de_Pacientes_por_busqueda

  PROPOSITO:  pedir al usuario un DNI, para luego mostrar el paciente con ese DNI
  PARAMETROS: no se requerira de ningun parametro
  RETORNO:    no se retornara nada

*/

void Listado_de_Pacientes_por_busqueda(){

    cout<<endl;
    cout<<"Se ha mostrado a el paciente con el DNI indicado con anterioridad"<<endl;
    system("pause");
    cout<<endl;
};

/*  Funciones para el submenu de A�ADIR UN TURNO  */

/*  Alta_de_Pacientes

  PROPOSITO:  se va a otorgar un turno al paciente que se indique y para la especialidad indicada
  PARAMETROS: no se requerira de ningun parametro
  RETORNO:    no se retornara nada

*/

void Alta_de_Turnos(){

    cout<<endl;
    cout<<"Se ha aprobado el turno para el paciente indicado y para la especialidad solicitada"<<endl;
    system("pause");
    cout<<endl;
};

/*  Modificacion_de_Turnos

  PROPOSITO:  se va a modificar el turno al paciente que se indique y para la especialidad indicada
  PARAMETROS: no se requerira de ningun parametro
  RETORNO:    no se retornara nada

*/

void Modificacion_de_Turnos(){

    cout<<endl;
    cout<<"Se ha modificado el turno para el paciente que se ha solicitado"<<endl;
    system("pause");
    cout<<endl;
};

/*  Baja_de_Turnos

  PROPOSITO:  se va a eliminar el turno al paciente que se indique
  PARAMETROS: no se requerira de ningun parametro
  RETORNO:    no se retornara nada

*/

void Baja_de_Turnos(){

    cout<<endl;
    cout<<""<<endl;
    system("pause"); // Muestra un mensaje, y espera a que se presione una tecla

    cout << "" <<endl; 
};

/*  Listado_de_Turnos_completo

  PROPOSITO:  se va a mostrar el listado de turnos completo
  PARAMETROS: no se requerira de ningun parametro
  RETORNO:    no se retornara nada

*/

void Listado_de_Turnos_completo(){

    cout << "" <<endl; 

    cout << "se ingreso a la Funcion Listado_de_Turnos_completo()" <<endl;
    system("pause"); // Muestra un mensaje, y espera a que se presione una tecla

    cout << "" <<endl; 
};

/*  Listado_de_Turnos_por_busqueda

  PROPOSITO:  se va a mostrar un buscador por el cual buscar en el listado de turnos
  PARAMETROS: no se requerira de ningun parametro
  RETORNO:    no se retornara nada

*/

void Listado_de_Turnos_por_busqueda(){

    cout << "" <<endl; // Espacios entre linea

    cout << "se ingreso a la Funcion Listado_de_Turnos_por_busqueda()" <<endl;
    system("pause"); // Muestra un mensaje, y espera a que se presione una tecla

    cout << "" <<endl; // Espacios entre linea
};



// Submenu 1
int submenu_1(char opcion){

    char opcion_2; // Variable para el switch del case 4

    cout<<"Elija una opcion: "; cin >> opcion; // Se pide un opcion, luego de mostrar las  opciones en la funcion main()

    while(opcion != '5'){

        // Switch para llamar a las funcione segun que opcion se ingreso
        switch(opcion){

            case '1':
                Alta_de_Especialidades_Medicas();
            break;

            case '2':
                Modificacion_de_Especialidades_Medicas();
            break;

            case '3':
                Baja_de_Especialidades_Medicas();
            break;

            case '4':
                cout << "Eliga una opcion (A o B): "; cin >> opcion_2;

                switch(opcion_2){

                    case 'a':
                        Listado_de_Especialidades_Medicas_completo();
                    break;

                    case 'b':
                        Listado_de_Especialidades_Medicas_por_busqueda();
                    break;
                };
            break;

            case '5': // Vuelve al menu principal (sale de la funcion y vuelve al main())
                break;

            default: // Se muestra por pantalla un error, y se pregunta nuevamente el submenu 1
                system("cls"); //limpia la consola

                cout <<"***Opcion invalida***"<<endl;
            break;
        };

        // Si la opcion no es correcta, se pregunta nuevamente sin salir del While
        cout << "Administrar Especialidades Medicas." <<endl;

        cout << "1. Alta de Especialidades Medicas." <<endl;
        cout << "2. Modificacion de Especialidades Medicas." <<endl;
        cout << "3. Baja de Especialidades Medicas." <<endl;
        cout << "4. Listado de Especialidades Medicas." <<endl;
        cout << "\t A. Listado de Especialidades Medicas completo." <<endl;
        cout << "\t B. Listado de Especialidades Medicas Por Busqueda." <<endl;
        cout << "5. Menu principal" <<endl;

        cout<<"Elija una opcion: "; cin >> opcion;  // Se elige una opcion
    };

    system("cls"); //limpia la consola
    return 0;
}

int submenu_2(char opcion){

    char opcion_2; // Variable para el switch del case 4

    cout<<"Elija una opcion: "; cin >> opcion; // Se pide un opcion, luego de mostrar las  opciones en la funcion main()

    while(opcion != '5'){

        // Switch para llamar a las funcione segun que opcion se ingreso
        switch(opcion){

            case '1':
                Alta_de_Pacientes();
            break;

            case '2':
                Modificacion_de_Pacientes();
            break;

            case '3':
                Baja_de_Pacientes();
            break;

            case '4':
                cout << "Eliga una opcion (A o B): "; cin >> opcion_2;

                switch(opcion_2){

                    case 'a':
                        Listado_de_Pacientes_completo();
                    break;

                    case 'b':
                        Listado_de_Pacientes_por_busqueda();
                    break;
                };
            break;

            case '5': // Vuelve al menu principal (sale de la funcion y vuelve al main())
                break;

            default: // Se muestra por pantalla un error, y se pregunta nuevamente el submenu 1
                system("cls"); //limpia la consola

                cout <<"***Opcion invalida***"<<endl;

            break;

        };

        // Si la opcion no es correcta, se pregunta nuevamente sin salir del While
        cout << "Administrar Pacientes." <<endl;

        cout << "1. Alta de Pacientes." <<endl;
        cout << "2. Modificacion de Pacientes." <<endl;
        cout << "3. Baja de Pacientes." <<endl;
        cout << "4. Listado de Pacientes." <<endl;
        cout << "\t A. Listado de Pacientes completo." <<endl;
        cout << "\t B. Listado de Pacientes Por Busqueda." <<endl;
        cout << "5. Menu principal" <<endl;

        cout<<"Elija una opcion: "; cin >> opcion; // Se elige una opcion
    }

    system("cls"); //limpia la consola
    return 0;

}

int submenu_3(char opcion){

    char opcion_2; // Variable para el switch del case 4

    cout << "Elija una opcion: "; cin >> opcion; // Se pide un opcion, luego de mostrar las  opciones en la funcion main()

    while(opcion != '5'){

        // Switch para llamar a las funcione segun que opcion se ingreso
        switch(opcion){

            case '1':
                Alta_de_Turnos();
            break;

            case '2':
                Modificacion_de_Turnos();
            break;

            case '3':
                Baja_de_Turnos();
            break;

            case '4':
                cout << "Eliga una opcion (A o B): "; cin >> opcion_2;

                switch(opcion_2){

                    case 'a':
                        Listado_de_Turnos_completo();
                    break;

                    case 'b':
                        Listado_de_Turnos_por_busqueda();
                    break;
                };
            break;

            case '5': // Vuelve al menu principal (sale de la funcion y vuelve al main())
                break;

            default: // Se muestra por pantalla un error, y se pregunta nuevamente el submenu 1
                system("cls"); //limpia la consola

                cout<<"***Opcion invalida***"<<endl;

            break;
        };

        // Si la opcion no es correcta, se pregunta nuevamente sin salir del While
        cout << "Administrar Turnos." <<endl;

        cout << "1. Alta de Turnos." <<endl;
        cout << "2. Modificacion de Turnos." <<endl;
        cout << "3. Baja de Turnos." <<endl;
        cout << "4. Listado de Turnos." <<endl;
        cout << "\t A. Listado de Turnos completo." <<endl;
        cout << "\t B. Listado de Turnos Por Busqueda." <<endl;
        cout << "5. Menu principal" <<endl;

        cout<<"Elija una opcion: "; cin >> opcion; // Se elige una opcion
    }

    system("cls"); //limpia la consola

    return 0;
};



// Funcion Principal
int main(){

    // Variables a usar
    char opcion;

    while(opcion!='4'){

        // Menu Principal (Primer nivel)
        cout<<"Bienvenido al Administrador Medico Salud+."<<endl;

        cout<<"1. Administrar Especialidades Medicas"<<endl;
        cout<<"2. Administrar Pacientes"<<endl;
        cout<<"3. Administrar Turnos"<<endl;
        cout<<"4. Salir"<<endl;

        cout<<"Elija una opcion: "; cin >> opcion; // Se ingresa una opcion

        // Submenu (Sugundo Nivel)
        switch(opcion) {

            // Submenu 1
            case '1':
            system("cls"); // Limpia la consola

                // Primero mustra por pantalla la opciones que tiene el usuario
                cout << "Administrar Especialidades Medicas." <<endl;

                cout << "1. Alta de Especialidades Medicas." <<endl;
                cout << "2. Modificacion de Especialidades Medicas." <<endl;
                cout << "3. Baja de Especialidades Medicas." <<endl;
                cout << "4. Listado de Especialidades Medicas." <<endl;
                cout << "\t A. Listado de Especialidades Medicas completo." <<endl;
                cout << "\t B. Listado de Especialidades Medicas Por Busqueda." <<endl;
                cout << "5. Menu principal" <<endl;

                submenu_1(opcion); // Luego llama a la funcion

            break;

            // Submenu 2
            case '2':
            system("cls"); // Limpia la consola

                // Primero mustra por pantalla la opciones que tiene el usuario
                cout << "Administrar Pacientes." <<endl;

                cout << "1. Alta de Pacientes." <<endl;
                cout << "2. Modificacion de Pacientes." <<endl;
                cout << "3. Baja de Pacientes." <<endl;
                cout << "4. Listado de Pacientes." <<endl;
                cout << "\t A. Listado de Pacientes completo." <<endl;
                cout << "\t B. Listado de Pacientes Por Busqueda." <<endl;
                cout << "5. Menu principal" <<endl;

                submenu_2(opcion);  // Luego llama a la funcion

            break;

            // Submenu 3
            case '3':
            system("cls"); // Limpia la consola

                // Primero mustra por pantalla la opciones que tiene el usuario
                cout << "Administrar Turnos." <<endl;

                cout << "1. Alta de Turnos." <<endl;
                cout << "2. Modificacion de Turnos." <<endl;
                cout << "3. Baja de Turnos." <<endl;
                cout << "4. Listado de Turnos." <<endl;
                cout << "\t A. Listado de Turnos completo." <<endl;
                cout << "\t B. Listado de Turnos Por Busqueda." <<endl;
                cout << "5. Menu principal" <<endl;

                submenu_3(opcion);  // Luego llama a la funcion

            break;

            case '4': // Opcion 4 de salir (Termina el programa)
                break;

            default:
                system("cls"); // Limpiar la consola

                cout << "***OPCION INVALIDA***"<<endl; // Mostrar error de opcion

                return main(); // Retorna al menu principal, (Si se elige una opcion invalida en el menu principal,
                              //  se informa y se pregunta de nuevo)
            break;
        };

    };

    system("cls"); // Limpia la consola

    return 0;
};
