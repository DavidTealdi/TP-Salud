#include <iostream>
#include <stdlib.h>
#include <string>
#include <cctype>

using namespace std;


/* DIMENSION FISICA*/

const int MAX=100;

/*STRUCTs*/

struct Paciente{
    string apellido, nombre;
    long long dni, telefono;
};

struct Especialidad{
    int codigo;
    string nombre, descripcion;
};

struct Tiempo{
    int dia, mes, anio;
};
struct Hora{
    int hora, minuto;
};
struct Turno{
    int codigo;
    Tiempo fecha;
    Hora horario;
    int dni, codigoEspecialidad, estado;
};

/*  FUNCIONES  */

/*  Funciones secundarias  */

/*FUNCIONES PARA IMPRIMIR STRUCTS*/

/* imprimirTurno

  PROPOSITO:  imprimir un elemento de un arreglo de tipo struct turno
  PARAMETROS: se necesita del arreglo y el numero del elemento en el arreglo
  RETORNO:    no se retornara nada

*/

void imprimirTurno(Turno agenda[], int codigo){
    cout<<"Codigo del Turno: "<<agenda[codigo].codigo<<endl;
    cout<<"DNI del Paciente: "<<agenda[codigo].dni<<endl;
    cout<<"Codigo de la Especialidad Medica: "<<agenda[codigo].codigoEspecialidad<<endl;
    cout<<"Fecha: "<<agenda[codigo].fecha.dia<<"/"<<agenda[codigo].fecha.mes<<"/"<<agenda[codigo].fecha.anio<<endl;
    cout<<"Hora: "<<agenda[codigo].horario.hora<<":"<<agenda[codigo].horario.minuto<<" hs"<<endl;
    if(agenda[codigo].estado==1){
        cout<<"Estado: Activo"<<endl;
    }
    else{
        cout<<"Estado: Cancelado"<<endl;
    }
}

/* imprimirTurnosdePacientes

  PROPOSITO:  imprimir los turnos activos de un paciente
  PARAMETROS: se necesita del arreglo tipo turno, la dimension logica del arreglo y el dni del paciente
  RETORNO:    no se retornara nada

*/

void imprimirTurnosdePacientes(int dlAgenda, Turno agenda[], int dniPaciente){
    for(int i=0; i<dlAgenda;i++){                               //itera por el arreglo
        if(agenda[i].estado==1 and agenda[i].dni==dniPaciente){ //si el turno esta activo y pertenece al paciente lo imprime
            cout<<endl;
            imprimirTurno(agenda, i);
        }
    }
};

/* imprimirPaciente

  PROPOSITO:  imprimir un elemento de un arreglo de tipo struct paciente
  PARAMETROS: se necesita del arreglo y el numero del elemento en el arreglo
  RETORNO:    no se retornara nada

*/

void imprimirPaciente(Paciente fichaPaciente[], int num){
       cout<<"Apellido: "<<fichaPaciente[num].apellido<<endl;
       cout<<"Nombre: "<<fichaPaciente[num].nombre<<endl;
       cout<<"DNI: "<<fichaPaciente[num].dni<<endl;
       cout<<"Telefono: "<<fichaPaciente[num].telefono<<endl;

};

/* imprimirEspecialidad

  PROPOSITO:  imprimir un elemento de un arreglo de tipo struct especialidad
  PARAMETROS: se necesita del arreglo y el numero del elemento en el arreglo
  RETORNO:    no se retornara nada

*/

void imprimirEspecialidad(Especialidad especialidades[], int num){
       cout<<"Codigo: "<<especialidades[num].codigo<<endl;
       cout<<"Nombre: "<<especialidades[num].nombre<<endl;
       cout<<"Descripcion: "<<especialidades[num].descripcion<<endl;
};

/*FUNCIONES PARA ACOMODAR LOS FORMATOS DE TEXTOS*/

/* capitalize

  PROPOSITO:  tranforma un texto al formato capitalize, donde la primer letra del texto esta en
              mayuscula, y el resto en minuscula
  PARAMETROS: un string
  RETORNO:    no se retornara nada, ya que el parametro es pasado por referencia

*/
void capitalize(string & texto){
    int largo;
    largo=texto.length();           //guarda la cantidad de caracteres del texto
    texto[0]=toupper(texto[0]);     //cambia el primer caracter a mayuscula
    for(int i=1; i<=largo;i++){     //itera por la cadena cambiando los caracteres a minuscula
        texto[i]=tolower(texto[i]);
    }
};

/* title

  PROPOSITO:  poner un texto con cada palabra en mayuscula
  PARAMETROS: el texto a transformar
  RETORNO:    retornara el texto ya transformado

*/
string title(string frase){
    string nuevaFrase, palabra;
    int largo, espacio;
    frase=frase+' ';                            //va a agregar un espacio a la frase para poder iterar las palabras separandolas con los espacios
    do{
        espacio=frase.find(' ');                //busca el espacio
        palabra=frase.substr(0,espacio);        //almacena la primer palabra en otra variable
        palabra[0]=toupper(palabra[0]);         //pone en mayuscula el primer espacio de la frase
        largo=palabra.length();                 //mide el largo de la palabra para poder iterar por ella
        for(int i=1; i!=largo; i++){            //itera por la palabra
            palabra[i]=tolower(palabra[i]);     //cambia a minuscula el resto de los elemento de la palabra
        }
        nuevaFrase=nuevaFrase+palabra+' ';      //almacena la palabra ya modificada+' '
        frase=frase.erase(0,espacio+1);         //borra la palabra ya modificada
    }while(frase.find(' ')!=string::npos);      //este proceso lo repite hasta que la frase no tenga mas espacios
    nuevaFrase.erase(nuevaFrase.length()-1,nuevaFrase.length());    //borra el espacio que queda de la ultima palabra
    return nuevaFrase;                          //retorna el nuevo texto
};

/*FUNCIONES PARA EL FUNCIONAMIENTO DE LAS FUNCIONES MAYORES*/

/* busquedaPaciente

  PROPOSITO:  iterar sobre un arreglo de tipo paciente, buscando si existe el paciente
              con el dni indicado en los parametros
  PARAMETROS: se necesita del arreglo de tipo paciente, el dni del paciente que se busca y la
              dimension lógica del arreglo.
  RETORNO:    se retornará el lugar que ocupa en el arreglo el dni indicado o un -1 si no existe
              un paciente con ese dni.

*/

int busquedaPaciente(Paciente fichasPacientes[], int dni, int & dl){
    for(int i=0; i<dl; i++){               //itera por el arreglo de pacientes
        if(fichasPacientes[i].dni==dni){    //si el dni del arreglo es igual al que se pasa por
            return i;                       //parametro retorna el lugar que ocupa en el arreglo
        }
    }
    return -1;      //sino existe en el arreglo retorna un -1
};

/* caracterEspeciales

  PROPOSITO:  revisar si un caracter es una letra o espacio o apostrofe, que son aceptados en nombres y apellidos
  PARAMETROS: el caracter a retornar
  RETORNO:    retornara un valor booleano

*/

bool caracterEspeciales(char caracter){
    string caracteresAceptados="abcdefghijklmnñopqrstuvwxyzáéíóúABCDEFGHIJKLMNÑOPQRSTUVWXYZÁÉÍÓÚ' ";
    if(caracteresAceptados.find(caracter)!=string::npos){
        return true;    //verificando que el caracter es una letra o espacio o '
    }
    else{
        return false;   //avisando que puede ser un número o caracter invalido
    }
};

/* validarTexto

  PROPOSITO:  revisar si un texto tiene algún simbolo que no sea una letra o que msd
  PARAMETROS: el texto a analizar
  RETORNO:    se retornará: true si el texto no contine caracteres invalidos
                            false si el texto contine caracteres invalidos

*/

bool validarTexto(string texto){
    int largo;
    largo=texto.length();           //mide la cadena para iterar por ella
    for(int i=0; i!=largo; i++){    //itera por la cadena
        if(caracterEspeciales(texto[i])==false){  //llama a la funcion que le avisa si es un caracter no valido
            return false;                       //si es un caracter invalido retorna el valor false
        }
    }
    return true;    //sino al final de la iteracion devuelve el valor true
};

/* hayUnTexto

  PROPOSITO:  revisar si un texto no esta vacío
  PARAMETROS: el texto a analizar
  RETORNO:    se retornará: true si el texto contiene uno o mas caracteres
                            false si el texto no contiene caracteres

*/

bool hayUnTexto(string & texto){
    int largo;
    largo=texto.length();   //almacena un
    if(largo<1){
        return false; //en el caso que el texto este vacio
    }
    else{
        return true;  //en el caso de que si haya texto en la variable
    }
};

/* validarFecha

  PROPOSITO:  verificar que las fechas sean correctas segun el calendario y que estas no sobrepasen cierta fecha
  PARAMETROS: el mes y el dia que hay que verificar
  RETORNO:    se retornará: true si son fechas validas
                            false si no son fechas validas

*/
bool validarFecha(int & dia, int & mes, int & anio, Tiempo & fechaAConsiderar){
    int diaConsiderar, mesConsiderar, anioConsiderar;

    diaConsiderar=fechaAConsiderar.dia;     //se va a almacenar en diferentes variables
    mesConsiderar=fechaAConsiderar.mes;     //el valor de la fecha con el que se debe comparar
    anioConsiderar=fechaAConsiderar.anio;

    //primero va a compara que la fecha no sea menor a la considerada
    if((dia<diaConsiderar) and (mes<=mesConsiderar) and (anio<=anioConsiderar)){
        return false;
    }

    //revisa que en caso que sea febrero no tenga mas de 28 dias
    if(mes==2 and dia>28){
        return false;
    }

    //revisa que los meses que tienen solo 30 días, no se almacenen con 31
    if((mes==4 or mes==6 or mes==9 or mes==11) and dia>30){
        return false;
    }
    return true;//si todo esta correcto retorna true
}

/* solicitarFecha

  PROPOSITO:  solicitar los datos de las fechas, ingresar año, mes y dia
  PARAMETROS: una fecha a considerar, puede ser el dia de hoy, como un dia con el que se deba comparar
  RETORNO:    retornara una fecha

*/

Tiempo solicitarFecha(Tiempo & fechaConsiderar){
    int anio, mes, dia; Tiempo nueva; bool validacion;
    do{
        cout<<"Anio: ";
        cin>>anio;
        while(anio<2022){
            cout<<"Has ingresado una fecha fuera de nuestro rango: "<<endl;
            cin>>anio;
        }
        cout<<"Mes: ";
        cin>>mes;
        while(mes<1 or mes>12){
            cout<<"Has ingresado una fecha invalida, vuelve a intentarlo: "<<endl;
            cin>>mes;
        }
        cout<<"Dia: ";
        cin>>dia;
        while(dia<1 or dia>31){
            cout<<"Has ingresado una fecha invalida, vuelve a intentarlo: ";
            cin>>dia;
        }
        validacion=validarFecha(dia, mes, anio, fechaConsiderar);
        if(validacion==false){
            cout<<"Has ingresado una fecha invalida, vuelve a intentarlo"<<endl;
        }
    }while(validacion==false);
    nueva.anio=anio;
    nueva.mes=mes;
    nueva.dia=dia;
    return nueva;
}

/* solicitarHora

  PROPOSITO:  solicitar los datos de las horas, en este caso consideramos que la clinica estaria abierta en el horario de las 8 a 20
  PARAMETROS: no requiere de ningun parametro
  RETORNO:    retornara una hora

*/

Hora solicitarHora(){
    int hora, minuto; struct Hora horario;

    cout<<"\nDebes tener en cuenta que el horario de atencion de la clinica es de 8hs a 20hs,\ny que nuestro turnos son de 30 minutos. "<<endl;
    cout<<"Ingrese el horario:"<<endl;
    cout<<"Hora: ";
    cin>>hora;
    while(hora<8 or hora>20){
        cout<<"Ha ingresado una hora invalida, vuelva a intentarlo: "<<endl;
        cin>>hora;
    }
    cout<<"En punto(0) o y media(1): ";
    cin>>minuto;
    while(minuto<0 or minuto>1){
        cout<<"Ha ingresado un valor invalido, vuelva a intentarlo: "<<endl;
        cin>>minuto;
    }
    if(minuto==0){
        cout<<"Se le ha asignado el turno a las "<<hora<<":00 hs"<<endl;
        horario.hora=hora;
        horario.minuto=00;
    }
    else{
        cout<<"Se le ha asignado el turno a las "<<hora<<":30 hs"<<endl;
        horario.hora=hora;
        horario.minuto=30;
    }
    return horario;
};

/* cantTurnosDelPaciente

  PROPOSITO:  cuenta la cantidad de turnos activos que tiene un paciente
  PARAMETROS: dni del paciente, arreglo con los turnos de los pacientes, dimension logica de los turnos
  RETORNO:    retornara la cantidad de turnos que posee el paciente

*/

int cantTurnosDelPaciente(int & dniPaciente, Turno agenda[], int & dlAgenda){
    int contador=0;
    for(int i=0; i<=dlAgenda;i++){
        if(agenda[i].dni==dniPaciente){
            contador++;
        }
    }
    return contador;
};

/* turnoDeEspecialidadActivo

  PROPOSITO:  revisa si un paciente ya tiene un turno activo para cierta especialidad
  PARAMETROS: dni del paciente, arreglo con los turnos de los pacientes, dimension logica de los turnos
              y codigo especifico de la especialidad
  RETORNO:    se retornará: true si tiene turnos activos
                            false si no tiene turnos activos
*/

bool turnoDeEspecialidadActivo(int & dniBuscado, int & dlAgenda, Turno agenda[], int & codEspecialidad){
    for(int i=0; i<=dlAgenda; i++){
        if(agenda[i].dni==dniBuscado and agenda[i].codigoEspecialidad==codEspecialidad and agenda[i].estado==1){
            return true;
        }
    }
    return false;
};

/* turnoDeEspecialidad

  PROPOSITO:  revisa si una especialidad tiene algun turno activo
  PARAMETROS: arreglo con los turnos, dimension logica de los turnos y el codigo de la especialidad
              y codigo especifico de la especialidad
  RETORNO:    se retornará: true si hay turnos activos
                            false si no hay turnos activos
*/

bool tieneTurnosEspecialidad(int & codigoBuscado, int & dlAgenda, Turno agenda[]){
    for(int i=0; i<=dlAgenda; i++){
        if(agenda[i].codigoEspecialidad==codigoBuscado and agenda[i].estado==1){
            return true;
        }
    }
    return false;
}


/*  Funciones para el submenu de ADMINISTRAR ESPECIALIDADES MEDICAS  */

/* Alta_de_Especialidades_Medicas

  PROPOSITO:  agregar una especialidad medica al sistema
  PARAMETROS: se necesitata de un arreglo de tipo especialidad y la dimension logica de tal arreglo
  RETORNO:    no se retornara nada

*/

void Alta_de_Especialidades_Medicas(Especialidad especialidades[], int & dl){
    Especialidad nuevaEspecialidad; char eleccion;

    //ASIGNA EL CODIGO UNICO DE LA ESPECIALIDAD
    nuevaEspecialidad.codigo=dl;

    //INGRESA EL NOMBRE DE LA ESPECIALIDAD
    cout<<"Ingrese el nombre de la Especialidad Medica: "<<endl;
    getline(cin>>ws,nuevaEspecialidad.nombre);
    nuevaEspecialidad.nombre=title(nuevaEspecialidad.nombre);

    //valida el texto
    while(validarTexto(nuevaEspecialidad.nombre)==false && hayUnTexto(nuevaEspecialidad.nombre)==true){
        cout<<"Se ha ingresado un texto invalido o no ha completado el campo, asi que vuelva a intentarlo: ";
        getline(cin>>ws,nuevaEspecialidad.nombre);
    }

    //CONSULTA SI DESEA AÑADIR DESCRIPCIÓN Y SI ES ASÍ LA ALMACENA
    do{
        cout<<"Deseas agregar una descripcion?(S/N)"<<endl;
        cin>>eleccion;
        eleccion=toupper(eleccion); //valida la eleccion

        switch(eleccion){
        case 'S':
            cout<<"Ingrese la descripcion de la Especialidad: ";
            getline(cin>>ws, nuevaEspecialidad.descripcion);
            capitalize(nuevaEspecialidad.descripcion);
            //valida el texto

            while(validarTexto(nuevaEspecialidad.descripcion)==false){
                cout<<"Se ha ingresado un texto invalido, vuelva a intentarlo: ";
                getline(cin>>ws,nuevaEspecialidad.descripcion);
            }
            eleccion='N';//cambia el valor de la variable para acceder al corte del bucle
            break;

        case 'N':
            nuevaEspecialidad.descripcion=""; //no almacena nada en la descripcion
            break;
        default:
            cout<<"Ha ingresado una opcion invalida, vuelva a intentarlo"<<endl;    //le avisa al usuario
            break;
        }
    }while(eleccion!='N');

    //ALMACENA EN EL ARREGLO LOS DATOS SOLICITADOS
    especialidades[dl]=nuevaEspecialidad;

    //MUESTRA AL USUARIO COMO QUEDO LA ESPECIALIDAD
    cout<<"La especialidad quedo así: "<<endl;
    imprimirEspecialidad(especialidades,dl);

    dl++;//incrementa la dimension logica

    system("pause");
    system("cls");
    cout<<endl;
};

/* Modificacion_de_Especialidades_Medicas

  PROPOSITO:  modificar una especialidad medica al sistema
  PARAMETROS: se necesitata de un arreglo de tipo especialidad y la dimension logica de tal arreglo
  RETORNO:    no se retornara nada

*/

void Modificacion_de_Especialidades_Medicas(Especialidad especialidades[], int dl){
    int codigoEspecialidad; Especialidad modificaciones;
    char eleccion;

    cout<<"Ingresar el codigo de la Especialidad a Modificar: "<<endl;
    cin>>codigoEspecialidad;
    while(codigoEspecialidad>=dl){
        cout<<"La especialidad indicada no existe";
        cin>>codigoEspecialidad;
    }
    cout<<"Se va a modificar "<<especialidades[codigoEspecialidad].nombre<<endl;

    modificaciones.codigo=codigoEspecialidad;
    do{
        //MODIFICACION DEL NOMBRE DE LA ESPECIALIDAD MEDICA
        //pregunta si desea modificarlo o no

        cout<<"Desea modificar el nombre de la especialidad medica?(S/N) ";
        cin>>eleccion;
        eleccion=toupper(eleccion); //valida la eleccion

        switch(eleccion){

        case 'S':
            //si el usuario desea modificar el nombre de la especialidad:
            //se le solicita el nuevo nombre
            cout<<"Ingrese el nuevo Nombre de la Especialidad: ";
            getline(cin>>ws, modificaciones.nombre);
            modificaciones.nombre=title(modificaciones.nombre);

            //valida de que sea un texto, sin caracteres extraños
            //si llegará a tenerlos le solicita al usuario reingresar el nuevo nombre de la especialidad
            while(validarTexto(modificaciones.nombre)==false && hayUnTexto(modificaciones.nombre)==true){
                cout<<"Se ha ingresado un texto invalido, vuelva a intentarlo: ";
                getline(cin>>ws,modificaciones.nombre);
            };
            //se guarda el nuevo nombre ya en el formato indicado
            modificaciones.nombre=title(modificaciones.nombre);
            eleccion='N';
            break;

        case 'N':
            //si el usuario no desea modificar el nombre, se guarda el antiguo nombre en la nueva variable
            modificaciones.nombre=especialidades[codigoEspecialidad].nombre;
            break;

        default:
            cout<<"Ha ingresado una opcion invalida, vuelva a intentarlo: ";    //le avisa al usuario
            cin>>eleccion;
            eleccion=toupper(eleccion); //valida la eleccion
            break;
        }
    }while(eleccion!='N');

    do{
        //MODIFICACION DE LA DESCRIPCION DE LA ESPECIALIDAD
        //pregunta si desea modificarlo o no
        cout<<"Desea modificar la descripcion de la especialidad(S/N)?";
        cin>>eleccion;
        eleccion=toupper(eleccion);             //valida la eleccion

        switch(eleccion){

        case 'S':
            //si el usuario desea modificar la descripcion de la especialidad, le pide una nueva descripcion.
            cout<<"Ingrese la nueva Descripcion: ";
            getline(cin>>ws, modificaciones.descripcion);
            capitalize(modificaciones.nombre);

            //valida el texto
            while(validarTexto(modificaciones.descripcion)==false){
                cout<<"Se ha ingresado un texto invalido, vuelva a intentarlo: ";
                getline(cin>>ws,modificaciones.nombre);
                capitalize(modificaciones.nombre);
            }
            eleccion='N';
            break;

        case 'N':
            modificaciones.descripcion=especialidades[codigoEspecialidad].descripcion;
            break;

        default:
            cout<<"Ha ingresado una opcion invalida, vuelva a intentarlo: ";    //le avisa al usuario
            break;
        }
    }while(eleccion!='N');

    //MUESTRA GENERAL DEL RESULTADO
    especialidades[codigoEspecialidad]=modificaciones;
    imprimirEspecialidad(especialidades,codigoEspecialidad);

    system("pause");
    system("cls");
    cout<<endl;
};

/* Baja_de_Especialidades_Medicas

  PROPOSITO:  quitar una especialidad medica del sistema
  PARAMETROS: arreglo de especialidades, dimension logica de las especialidades, arreglo con los turnos
              dimension logica del arreglo con los turnos
  RETORNO:    no se retornara nada

*/

void Baja_de_Especialidades_Medicas(Especialidad especialidades[], int & dlEspecilidades, Turno agenda[], int & dlAgenda){
    int codigoEliminar; char eleccion;

    //SOLICITA AL USUARIO QUE
    cout<<"Ingresar el codigo de la Especialidad Medica: ";
    cin>>codigoEliminar;

    //revisa que exista tal codigo, sino es asi vuelve al menu principal
    if(codigoEliminar>=dlEspecilidades){
        cout<<"La Especialidad Medica indicada no existe dentro del sistema.";
        system("pause");
        system("cls");
        return;
    }

    //muestra cual seria la especialidad y le consulta al usuario si desea eliminarla
    do{
        imprimirEspecialidad(especialidades, codigoEliminar);
        cout<<"¿Esta seguro que desea eliminar a esta Especialidad Medica?(S/N)";
        cin>>eleccion;
        eleccion=toupper(eleccion);

        switch(eleccion){

        default:
            cout<<"Ha ingresado una opcion invalida";    //le avisa al usuario
            system("pause");
            system("cls");
            break;

        case 'N':
            cout<<"No se ha eliminado a la Especialidad Medica "<<codigoEliminar;
            system("pause");
            system("cls");
            break;

        case 'S':

            //revisa que no existan turnos activos para esa especialidad, si llegará a haber
            // turnos activos la funcion avisa y vuelve al menu principal
            if(tieneTurnosEspecialidad(codigoEliminar, dlAgenda, agenda)==true){
                cout<<"No se puede eliminar a la Especialidad Medica, ya que tiene turnos activos."<<endl;
                system("pause");
                system("cls");
                return;
            }

            //si no tiene turnos itera por la cadena buscando donde tiene que empezar a pisar
            //los elementos para asi "eliminar" la especialidad
            int l=0;
            while(l<dlEspecilidades and especialidades[l].codigo!=codigoEliminar){
                l++;
            }
            if(especialidades[l].codigo==codigoEliminar){
                for(int s=l; s<dlEspecilidades-1; s++){
                    especialidades[s]=especialidades[s+1];
                }
                dlEspecilidades--;
                cout<<"Se ha eliminado a la Especialidad Medica"<<endl;
                system("pause");
                system("cls");
                return;
            }

        }
    }while(eleccion!='N');

    system("pause");
    system("cls");
    cout<<endl;
};

/*  Listado_de_Especialidades_Medicas_completo

  PROPOSITO:  mostrar la lista de Especialidades Medicas completo
  PARAMETROS: se requerira de un arreglo de tipo Especialidad y su arreglo correspondiente
  RETORNO:    no se retornara nada

*/

void Listado_de_Especialidades_Medicas_completo(Especialidad especialidades[], int & dl){

    cout<<"\nEsta es la lista de especialidades de la clinica: "<<endl;

    for(int i=0; i<dl;i++){
        cout<<endl;
        imprimirEspecialidad(especialidades, i);
    }

    cout<<endl;
    system("pause");
    system("cls");;
};

/*  Listado_de_Especialidades_Medicas_por_busqueda

  PROPOSITO:  pedir al usuario un codigo de especialidad medica, para
              luego mostrar la especialidad asociada a ese codigo
  PARAMETROS: requerira de un arreglo de tipo Especialidad y su respectiva dimension logica
  RETORNO:    no se retornara nada

*/

void Listado_de_Especialidades_Medicas_por_busqueda(Especialidad especialidades[], int & dl){

    int codigoBusqueda;

    cout<<"Ingresar el codigo de la Especialidad Medica: ";
    cin>>codigoBusqueda;

    //revisa que exista tal codigo, sino es asi vuelve al menu principal
    if(codigoBusqueda>=dl){
        cout<<"La Especialidad Medica indicada no existe dentro del sistema.";
        system("pause");
        system("cls");
        return;
    }

    cout<<"\nLa especialidad es la siguiente: "<<endl;
    imprimirEspecialidad(especialidades, codigoBusqueda);

    system("pause");
    system("cls");
    cout<<endl;

};


/*  Funciones para el submenu de ADMINISTRAR PACIENTES  */

/*  Alta_de_Pacientes

  PROPOSITO:  agregar a un paciente
  PARAMETROS: se requerira de un arreglo del tipo paciente, declarado con anterioridad, y la dimension
              logica de tal arreglo.
  RETORNO:    no se retornara nada

*/

void Alta_de_Pacientes(Paciente fichasPacientes[], int & dl){
    Paciente nuevoPaciente;

    //los datos primero se almacenarán en una variable de tipo paciente, para luego colocarla en el
    //lugar que corresponda del arreglo

    //se le pide al usuario los datos para ingresar al nuevo paciente
    //INGRESO DEL APELLIDO:
    cout<<"Ingrese el Apellido: ";
    getline(cin>>ws, nuevoPaciente.apellido);

    //se almacena y luego se verifica que sea un texto, y no contenga ningun tipo de número o caracter dentro de el
    while(validarTexto(nuevoPaciente.apellido)==false && hayUnTexto(nuevoPaciente.apellido)==true){
        cout<<"Se ha ingresado un texto invalido, vuelva a intentarlo: ";
        getline(cin>>ws,nuevoPaciente.apellido);
    };

    //se transforma el apellido y se coloca en el formato indicado
    nuevoPaciente.apellido=title(nuevoPaciente.apellido);

    //INGRESO DEL NOMBRE:
    cout<<"Ingrese el Nombre: ";
    getline(cin>>ws, nuevoPaciente.nombre);

    //se almacena y luego se verifica que sea un texto, y no contenga ningun tipo de número o caracter dentro de el
    while(validarTexto(nuevoPaciente.nombre)==false && hayUnTexto(nuevoPaciente.nombre)==true){
        cout<<"Se ha ingresado un texto invalido, vuelva a intentarlo: ";
        getline(cin>>ws,nuevoPaciente.nombre);
    }
    //se transforma el nombre y se coloca en el formato indicado
    nuevoPaciente.nombre=title(nuevoPaciente.nombre);

    //INGRESO DEL DNI:
    cout<<"Ingrese el DNI: ";
    cin>>nuevoPaciente.dni;
    while(nuevoPaciente.dni<0){
        cout<<"Ha ingresado un valor invalido, vuelva a intentarlo: ";
        cin>>nuevoPaciente.dni;
    }

    //INGRESO DEL TELEFONO:
    cout<<"Ingrese el Telefono: ";
    cin>>nuevoPaciente.telefono;
    while(nuevoPaciente.dni<0){
        cout<<"Ha ingresado un valor invalido, vuelva a intentarlo: ";
        cin>>nuevoPaciente.dni;
    }

    //se almacena el nuevo paciente dentro del arreglo
    fichasPacientes[dl]=nuevoPaciente;
    cout <<"Se ha agregado a "<<fichasPacientes[dl].apellido<<+", "+fichasPacientes[dl].nombre<<endl;

    //se incrementa la dimension logica
    dl++;

    system("pause");
    system("cls");
};

/*  Modificacion_de_Pacientes

  PROPOSITO:  modificar a un paciente
  PARAMETROS: se requerira de un arreglo del tipo paciente, declarado con anterioridad, y la dimension
              logica de tal arreglo.
  RETORNO:    no se retornara nada

*/

void Modificacion_de_Pacientes(Paciente fichaPaciente[], int & dl){
    int dniModificar, espacioFicha; char eleccion; Paciente modificaciones;

    //primero se le pedira al usuario que ingrese un dni, para que lo busque en el arreglo

    cout<<"Ingresar el DNI del Paciente: ";
    cin>>dniModificar;

    //por medio de una funcion verifica que el paciente este ingresado en el sistema
    espacioFicha=busquedaPaciente(fichaPaciente,dniModificar,dl);

    //si el paciente no esta en el sistema, se le indica a el usuario que ingrese otro dni.
    while(espacioFicha==-1){
        cout<<"El dni ingresado no esta ingresado en el sistema."<<endl;
        cout<<"Ingresar el DNI de un paciente existente: ";
        cin>>dniModificar;
        espacioFicha=busquedaPaciente(fichaPaciente,dniModificar,dl);
    };
    //se le muestra al usuario cual es el paciente que se va a modificar
    cout<<"Se va a modificar al paciente "+fichaPaciente[espacioFicha].apellido+", "+fichaPaciente[espacioFicha].nombre<<endl;

    //almacenará todos los datos en una variable del tipo struct paciente para luego reemplazarla en el arreglo
    //por lo que al no poder modificar el dni, desde el comienzo almacena el dni indicado por el usuario
    modificaciones.dni=fichaPaciente[espacioFicha].dni;

    //en caso de que el usuario este en desacuerdo al final del proceso y quiere comenzar denuevo la
    //modificacion de los datos del DNI indicado, el programa volverá a pedir posibles apellidos, nombres o telefono nuevos

    //MODIFICACION DEL APELLIDO DEL PACIENTE
    //pregunta si desea modificarlo o no

    do{
        cout<<"Desea modificar el apellido del paciente?(S/N) ";
        cin>>eleccion;
        eleccion=toupper(eleccion); //valida la eleccion
        switch(eleccion){

        case'S':
            //si el usuario desea modificar el apellido:
            //se le solicita el nuevo apellido
            cout<<"Ingrese el nuevo Apellido: ";
            getline(cin>>ws, modificaciones.apellido);

            //valida de que sea un texto, sin caracteres extraños
            //si llegará a tenerlos le solicita al usuario reingresar el nuevo apellido
            while(validarTexto(modificaciones.apellido)==false && hayUnTexto(modificaciones.apellido)==true){
                cout<<"Se ha ingresado un texto invalido, vuelva a intentarlo: ";
                getline(cin>>ws,modificaciones.apellido);
            };
            //se guarda el nuevo apellido ya en el formato indicado
            modificaciones.apellido=title(modificaciones.apellido);
            eleccion='N';
            break;

        case 'N':
            //si el usuario no desea modificar el apellido:
            modificaciones.apellido=fichaPaciente[espacioFicha].apellido;
            break;

        default:
            cout<<"Ha ingresado una opcion invalida, vuelva a intentarlo: ";    //le avisa al usuario
            break;
        }

    }while(eleccion!='N');
    //MODIFICACION DEL NOMBRE DEL PACIENTE
    do{
        //pregunta si desea modificarlo o no
        cout<<"Desea modificar el nombre del paciente?(S/N)?";
        cin>>eleccion;
        eleccion=toupper(eleccion);             //valida la eleccion

      switch(eleccion){

      case 'S':
        //si el usuario desea modificar el nombre del paciente, le pide un nuevo nombre y lo valida.
        cout<<"Ingrese el nuevo Nombre: ";
        getline(cin>>ws, modificaciones.nombre);
        while(validarTexto(modificaciones.nombre)==false && hayUnTexto(modificaciones.nombre)==true){
            cout<<"Se ha ingresado un texto invalido, vuelva a intentarlo: ";
            getline(cin>>ws,modificaciones.nombre);
            modificaciones.nombre=title(modificaciones.nombre);
        }
        eleccion='N';
        break;

      case 'N':
        modificaciones.nombre=fichaPaciente[espacioFicha].nombre;
        break;

      default:
        cout<<"Ha ingresado una opcion invalida, vuelva a intentarlo: ";    //le avisa al usuario
        break;
      }
    }while(eleccion!='N');

    //MODIFICACION DEL TELEFONO DEL PACIENTE
    do{
        //pregunta si desea modificarlo o no
        cout<<"Desea modificar el telefono del paciente?(S/N)";
        cin>>eleccion;
        eleccion=toupper(eleccion); //valida la eleccion
        switch(eleccion){

        case 'S':
            cout<<"Ingrese el nuevo Telefono: ";
            cin>>modificaciones.telefono;
            while(modificaciones.telefono<0){
                cout<<"Se ha ingresado un numero invalido, vuelva a intentarlo: ";
                cin>>modificaciones.telefono;
            };
            eleccion='N';
            break;

        case 'N':
            modificaciones.telefono=fichaPaciente[espacioFicha].telefono;
            break;

        default:
            //si ingresa una opcion invalida, vuelve a pedir que ingrese lo que desea hacer
            cout<<"Ha ingresado una opcion invalida, vuelva a intentarlo: ";    //le avisa al usuario
            break;
        }
    }while(eleccion!='N');

    //MUESTRA GENERAL DEL RESULTADO
    fichaPaciente[espacioFicha]=modificaciones;
    imprimirPaciente(fichaPaciente,espacioFicha);

    system("pause");
    system("cls");
    cout<<endl;
};

/*  Baja_de_Pacientes

  PROPOSITO:  se va a eliminar a un paciente
  PARAMETROS: se requerira de un arreglo del tipo paciente, la dimension logica de tal arreglo, un arreglo
              de tipo turno, y la dimension logica de tal
  RETORNO:    no se retornara nada

*/

void Baja_de_Pacientes(Paciente fichasPacientes[], int & dlFichas, int & dlTurnos, Turno agenda[]){
    int dniEliminar, espacioFicha; char eleccion;

    //primero se le pedira al usuario que ingrese un dni, para que lo busque en el arreglo

    cout<<"Ingresar el DNI del Paciente: ";
    cin>>dniEliminar;

    //por medio de una funcion verifica que el paciente este ingresado en el sistema
    espacioFicha=busquedaPaciente(fichasPacientes,dniEliminar,dlFichas);

    //si el paciente no esta en el sistema, se le indica a el usuario que ingrese otro dni.
    if(espacioFicha==-1){
        cout<<"El dni ingresado no esta ingresado en el sistema."<<endl;
        system("pause");
        system("cls");
        return;
    };

    do{
        imprimirPaciente(fichasPacientes, espacioFicha);
        cout<<"¿Esta seguro que desea eliminar a este paciente?(S/N)";
        cin>>eleccion;
        eleccion=toupper(eleccion);

        switch(eleccion){

        default:
            cout<<"Ha ingresado una opcion invalida";    //le avisa al usuario
            system("pause");
            system("cls");
            break;

        case 'N':
            cout<<"No se ha eliminado al paciente del DNI "<<dniEliminar;
            system("pause");
            system("cls");
            break;

        case 'S':
            //revisa que el paciente no tenga turnos y si tiene avisa y retorna a la funcion
            if(cantTurnosDelPaciente(dniEliminar,agenda,dlTurnos)==0){
                cout<<"No se puede eliminar al paciente, ya que tiene turnos activos."<<endl;
                system("pause");
                system("cls");
                return;
            }

            //si el paciente no tiene turnos comienza el proceso para eliminarlo
            int l=0;
            while(l<dlFichas and fichasPacientes[l].dni!=dniEliminar){
                l++;
            }
            if(fichasPacientes[l].dni==dniEliminar){
                for(int s=l; s<dlFichas-1; s++){
                    fichasPacientes[s]=fichasPacientes[s+1];
                }
                dlFichas--;
                cout<<"Se ha eliminado al Paciente"<<endl;
                system("pause");
                system("cls");
                return;
            }

        }
    }while(eleccion!='N');

};

/*  Listado_de_Pacientes_completo

  PROPOSITO:  se va a mostrar la lista de pacientes completo
  PARAMETROS: no se requerira de ningun parametro
  RETORNO:    no se retornara nada

*/

void Listado_de_Pacientes_completo(Paciente fichaPaciente[], int & dl){

    cout<<"\nEsta es la lista de pacientes de la clinica: "<<endl;

    for(int i=0; i<dl;i++){
        cout<<endl;
        imprimirPaciente(fichaPaciente, i);
    }

    cout<<endl;
    system("pause");
    system("cls");
};

/*  Listado_de_Pacientes_por_busqueda

  PROPOSITO:  pedir al usuario un DNI, para luego mostrar el paciente con ese DNI
  PARAMETROS: no se requerira de ningun parametro
  RETORNO:    no se retornara nada

*/

void Listado_de_Pacientes_por_busqueda(Paciente fichaPaciente[], int & dl){

    int dniBusqueda, espacioFicha;
    cout<<"Ingresar el DNI del Paciente: ";
    cin>>dniBusqueda;

    //por medio de una funcion verifica que el paciente este ingresado en el sistema
    espacioFicha=busquedaPaciente(fichaPaciente,dniBusqueda,dl);

    //si el paciente no esta en el sistema, se le indica a el usuario que ingrese otro dni.
    if(espacioFicha==-1){
        cout<<"El dni ingresado no esta ingresado en el sistema."<<endl;
        system("pause");
        system("cls");
        return;
    };

    cout<<"\nLa ficha del Paciente es la siguiente: "<<endl;
    imprimirPaciente(fichaPaciente, espacioFicha);
    cout<<endl;
    system("pause");
    system("cls");
};

/*  Funciones para el submenu de AÑADIR UN TURNO  */

/*  Alta_de_Turnos

  PROPOSITO:  se va a otorgar un turno al paciente que se indique y para la especialidad indicada
  PARAMETROS: un arreglo tipo turno y su dimension logica, un arreglo de tipo paciente y su dimension
              logica y la dimension logica de las especialidades medicas, y tambien la fecha actual
  RETORNO:    no se retornara nada

*/

void Alta_de_Turnos(Turno agenda[], Paciente fichas[], int & dlPacientes, int & dlEspecialidades, int & dlTurno, Tiempo fechaActual){

    int dniPaciente, codEspecialidad;
    Turno nuevo;

    nuevo.codigo=dlTurno;

    //SOLICITA EL DNI DEL PACIENTE Y VERIFICA QUE EXISTA
    cout<<"Ingrese el DNI del paciente: ";
    cin>>dniPaciente;
    if(busquedaPaciente(fichas,dniPaciente,dlPacientes)==-1){
        cout<<"El DNI ingresado no corresponde a un paciente de la clinica"<<endl;
        system("pause");
        system("cls");
        return;
    }
    nuevo.dni=dniPaciente;

    //SOLICITA EL CODIGO DE LA ESPECIALIDAD Y VERIFICA LA EXISTENCIA DE TAL
    cout<<"Ingrese el codigo de la especilidad medica: ";
    cin>>codEspecialidad;
    if(codEspecialidad>=dlEspecialidades){
        cout<<"La especialidad ingresada no esta registrada en el sistema"<<endl;
        system("pause");
        system("cls");
        return;
    }
    nuevo.codigoEspecialidad=codEspecialidad;

    //SE VA A VERIFICAR QUE EL PACIENTE INDICADO NO TIENE UN TURNO ACTIVO DE ESA ESPECIALIDAD MEDICA
    if(turnoDeEspecialidadActivo(dniPaciente, dlTurno, agenda, codEspecialidad)==true){
        cout<<"El paciente ya posee un turno para esa especialidad"<<endl;
        system("pause");
        system("cls");
        return;
    }

    //PARA INGRESAR EL DIA DEL TURNO

    cout<<"Ingresar los datos del dia que se asignará el turno al paciente(valores numericos): "<<endl;
    nuevo.fecha=solicitarFecha(fechaActual);
    cout<<"El turno ha sido reservado para el dia "<<nuevo.fecha.dia<<"/"<<nuevo.fecha.mes<<"/"<<nuevo.fecha.anio<<endl;

    //PARA INGRESAR LA HORA DEL TURNO

    nuevo.horario=solicitarHora();

    nuevo.estado=1;
    cout<<"Ha sido agendado el turno solicitado, ha quedado de la siguente manera\n"<<endl;
    agenda[dlTurno]=nuevo;
    imprimirTurno(agenda,dlTurno);
    dlTurno++;

    cout<<endl;
    system("pause");
    system("cls");
    cout<<endl;
};

/*  Modificacion_de_Turnos

  PROPOSITO:  se va a modificar el turno al paciente que se indique y para la especialidad indicada
  PARAMETROS: un arreglo tipo turno y su dimension logica, un arreglo de tipo paciente y su dimension
              logica y la dimension logica de las especialidades medicas, y tambien la fecha actual
  RETORNO:    no se retornara nada

*/

void Modificacion_de_Turnos(Paciente fichas[], int & dlPacientes, Turno agenda[], int & dlAgenda, Tiempo hoy){
    int dniPaciente, codigoModificar; char eleccion;
    Turno modificaciones;

    //SOLICITA EL DNI DEL PACIENTE Y VERIFICA QUE EXISTA
    cout<<"Ingrese el DNI del paciente: ";
    cin>>dniPaciente;
    //verfica que exista y si no es así vuelve a pedir que ingrese un dni valido
    while(busquedaPaciente(fichas,dniPaciente,dlPacientes)==-1){
        cout<<"El DNI ingresado no corresponde a un paciente de la clinica, vuelva a intentarlo: "<<endl;
        cin>>dniPaciente;
    }

    modificaciones.dni=dniPaciente;

    //llama a una funcion que contabiliza la cantidad de turnos que posee el paciente

    //si no tiene turnos retorna al menu principal
    if(cantTurnosDelPaciente(dniPaciente,agenda, dlAgenda)==0){
        cout<<"El paciente con el DNI "<<dniPaciente<<" no tiene ningun tipo de turno asignado."<<endl;
        system("pause");
        system("cls");
        return;
    }

    //si tiene turnos los imprime y le pregunta al usuario cual quiere modificar

    cout<<"El paciente tiene el/los siguientes turnos asignados y es: "<<endl;
    imprimirTurnosdePacientes(dlAgenda, agenda, dniPaciente);

    //hace que ingrese el codigo del turno que desea modificar
    cout<<endl<<"Ingresar el codigo del turno que desea modificar: ";
    cin>>codigoModificar;
    // verifica que sea correcto
    while(codigoModificar<0 or codigoModificar>=dlAgenda){
        cout<<"El codigo ingresado no pertence a ningun turno otorga, vuelva a intentarlo: ";
        cin>>codigoModificar;
    }

    //guarda los datos que no son modificables para re-escribirlos y que esten iguales
    modificaciones.codigo=codigoModificar;
    modificaciones.codigoEspecialidad=agenda[codigoModificar].codigoEspecialidad;

    //solicita los nuevos datos que seran la fecha y la hora del turno

    cout<<"Ingresar los datos del dia por el que se modificara el turno al paciente(valores numericos): "<<endl;
    modificaciones.fecha=solicitarFecha(hoy);
    cout<<"El turno ha sido reservado para el dia "<<modificaciones.fecha.dia<<"/"<<modificaciones.fecha.mes<<"/"<<modificaciones.fecha.anio<<endl;

    modificaciones.horario=solicitarHora();

    //consulta si desea efectuar los cambios
    do{
        cout<<"Usted esta seguro que desea efectuar los cambios?(S/N)";
        cin>>eleccion;
        eleccion=toupper(eleccion);

        switch(eleccion){

        case 'N':
            cout<<"El turno no ha sido modificado"<<endl;
            system("pause");
            system("cls");
            break;

        default:
            cout<<"Ha ingresado una opcion invalida. Vuelva a intentarlo.";
            system("pause");
            system("cls");
            break;

        case 'S':
            agenda[codigoModificar]=modificaciones;
            cout<<"Se ha modificado el turno"<<endl;
            imprimirTurno(agenda, codigoModificar);
            system("pause");
            system("cls");
            return;

        }
    }while(eleccion!='N');

};

/*  Baja_de_Turnos

  PROPOSITO:  se va a eliminar el turno al paciente que se indique
  PARAMETROS: un arreglo tipo turno y su dimension logica, un arreglo de tipo paciente y su dimension
              logica, y tambien la fecha actual
  RETORNO:    no se retornara nada

*/

void Baja_de_Turnos(Paciente fichas[], int & dlPacientes, Turno agenda[], int & dlAgenda, Tiempo hoy){
    int dniPaciente, cantTurnos, codigoEliminar; bool validacion; char eleccion;
    hoy.dia=hoy.dia+2;//para calcular las 48 hs antes del turno

    //SOLICITA EL DNI DEL PACIENTE Y VERIFICA QUE EXISTA
    cout<<"Ingrese el DNI del paciente: ";
    cin>>dniPaciente;
    if(busquedaPaciente(fichas,dniPaciente,dlPacientes)==-1){
        cout<<"El DNI ingresado no corresponde a un paciente de la clinica"<<endl;
        system("pause");
        system("cls");
        return;
    }

    cantTurnos=cantTurnosDelPaciente(dniPaciente,agenda,dlAgenda);

    if(cantTurnos==0){
        cout<<"El paciente con el DNI "<<dniPaciente<<" no tiene ningun tipo de turno asignado."<<endl;
        system("pause");
        system("cls");
        return;
    }

    if(cantTurnos==1){
        cout<<"El paciente solo tiene un turno asignado y es: "<<endl;
        for(int i=0; i<dlAgenda;i++){
            if(agenda[i].dni==dniPaciente and agenda[i].estado==1){
                validacion=validarFecha(agenda[i].fecha.dia, agenda[i].fecha.mes, agenda[i].fecha.anio, hoy);
                if(validacion==true){

                    cout<<"Usted esta seguro que desea eliminar el turno?(S/N)";
                    cin>>eleccion;
                    eleccion=toupper(eleccion);

                    switch(eleccion){

                    case 'N':
                        cout<<"El turno no ha sido Cancelado."<<endl;
                        system("pause");
                        system("cls");
                        break;

                    default:
                        cout<<"Ha ingresado una opcion invalida. Vuelva a intentarlo.";
                        system("pause");
                        system("cls");
                        break;

                    case 'S':
                        agenda[0].estado=2;
                        cout<<"Se ha cancelado el turno"<<endl;
                        system("pause");
                        system("cls");
                        return;
                    }
                    }
                }
            else{
                cout<<"Por razones de agenda el turno no puede ser cancelado"<<endl;
                return;
            }
        }
    };

    if(cantTurnos>1){
        cout<<"Los turnos del paciente son: ";
        imprimirTurnosdePacientes(dlAgenda, agenda, dniPaciente);
        cout<<endl<<"Ingresar el codigo del turno que desea eliminar: ";
        cin>>codigoEliminar;
        while(codigoEliminar<0 or codigoEliminar>=dlAgenda){
            cout<<"El codigo ingresado no pertence a ningun turno otorga, vuelva a intentarlo: ";
            cin>>codigoEliminar;
        }
        validacion=validarFecha(agenda[codigoEliminar].fecha.dia, agenda[codigoEliminar].fecha.mes, agenda[codigoEliminar].fecha.anio, hoy);
        if(validacion==true){
           do{
                cout<<"Usted esta seguro que desea cancelar el turno?(S/N)";
                cin>>eleccion;
                eleccion=toupper(eleccion);

                switch(eleccion){

                case 'N':
                    cout<<"El turno no ha sido Cancelado."<<endl;
                    system("pause");
                    system("cls");
                    break;

                default:
                    cout<<"Ha ingresado una opcion invalida. Vuelva a intentarlo.";
                    system("pause");
                    system("cls");
                    break;

                case 'S':
                    agenda[codigoEliminar].estado=2;
                    cout<<"Se ha cancelado el turno"<<endl;
                    system("pause");
                    system("cls");
                    return;

                }
            }while(eleccion!='N');
        }
        else{
            cout<<"Por razones de agenda el turno no puede ser cancelado"<<endl;
            return;
        }


    };
};

/*  Listado_de_Turnos_completo

  PROPOSITO:  se va a mostrar el listado de turnos pre-existentes
  PARAMETROS: se requerira de un arreglo de tipo Turno, y la dimension logica de tal
  RETORNO:    no se retornara nada

*/

void Listado_de_Turnos_completo(Turno agenda[], int & dl){

    cout<<"\nEsta es la lista de turnos de la clinica: "<<endl;

    for(int i=0; i<dl;i++){
        cout<<endl;
        imprimirTurno(agenda, i);
    }

    cout<<endl;
    system("pause");
    system("cls");

};

/*  Listado_de_Turnos_por_busqueda

  PROPOSITO:  se va a mostrar un buscador por el cual buscar en el listado de turnos
  PARAMETROS: no se requerira de una arreglo de tipo Turno, su dimension logica, la lista de pacientes y su dimension logica, y la dimension logica de la
  RETORNO:    no se retornara nada

*/

void Listado_de_Turnos_por_busqueda(Turno agenda[], int & dlTurno, Paciente fichaPaciente[], int & dlPaciente, int & dlEspecialidad){
    Tiempo fecha, fechaBuscar;
    fecha.dia=1;fecha.mes=1;fecha.anio=2022;
    int eleccion;

    do{
        cout<<"Elija cual es el filtro que desea aplicar: "<<endl;
        cout<<"0. Fecha"<<endl;
        cout<<"1. Paciente"<<endl;
        cout<<"2. Especialidad Medica"<<endl;
        cout<<"3. Estado del Turno"<<endl;
        cout<<"Cual es su eleccion? ";
        cin>>eleccion;
        switch(eleccion){

        case 0: //caso de que busque filtrar por medio de una fecha

            cout<<"Ingresar la fecha de los turnos que desea ver"<<endl;
            fechaBuscar=solicitarFecha(fecha);

            cout<<"\nLos turnos registrados con la fecha indicada son: "<<endl<<endl;
            for(int i=0; i<dlTurno; i++){
                if(fechaBuscar.dia==agenda[i].fecha.dia and fechaBuscar.mes==agenda[i].fecha.mes and fechaBuscar.anio==agenda[i].fecha.anio){
                    imprimirTurno(agenda, i);
                    cout<<endl;
                }
            }
            cout<<endl;
            system("pause");
            system("cls");
            return;

        case 1: //caso de que busque filtrar por medio de un dni

            int dni, espacioFicha;
            cout<<"Ingresar el DNI del Paciente: ";
            cin>>dni;
            //por medio de una funcion verifica que el paciente este ingresado en el sistema
            espacioFicha=busquedaPaciente(fichaPaciente, dni, dlPaciente);

            //si el paciente no esta en el sistema, se le indica a el usuario que ingrese otro dni.
            if(espacioFicha==-1){
                cout<<"El dni ingresado no esta ingresado en el sistema."<<endl;
                system("pause");
                system("cls");
                return;
            };
            cout<<"Estos son los turnos que tiene asignado el paciente"<<endl;
            imprimirTurnosdePacientes(dlTurno,agenda,dni);

            cout<<endl;
            system("pause");
            system("cls");

            return;

        case 2: //caso de que busque filtrar por medio de la especialidad medica
            int codigoEspecialidad;
            cout<<"Ingresar el codigo de la Especialidad Medica: ";
            cin>>codigoEspecialidad;

            //revisa que exista tal codigo, sino es asi vuelve al menu principal
            if(codigoEspecialidad>=dlEspecialidad or codigoEspecialidad<0){
                cout<<"La Especialidad Medica indicada no existe dentro del sistema.";
                system("pause");
                system("cls");
                return;
            }

            cout<<"Los turnos asignados a la especialidad indicada son: "<<endl;
            for(int i=0; i<dlTurno; i++){
                if(agenda[i].codigoEspecialidad==codigoEspecialidad){
                    cout<<endl;
                    imprimirTurno(agenda,i);
                }
            }
            return;

        case 3: //caso de que busque filtrar por medio del estado
            int eleccion2;
            cout<<"Desea ver los turnos activos(1), o los turnos cancelados(2)): ";
            do{
                cin>>eleccion2;
                switch (eleccion2) {
                case 1:
                    for(int i=0; i<dlTurno; i++){
                        if(agenda[i].estado==1){
                            cout<<endl;
                            imprimirTurno(agenda,i);
                        }
                    }
                    system("pause");
                    system("cls");
                    return;

                case 2:
                    for(int i=0; i<dlTurno; i++){
                        if(agenda[i].estado==2){
                            cout<<endl;
                            imprimirTurno(agenda,i);
                        }
                    }
                    system("pause");
                    system("cls");
                    return;

                default:
                    cout<<"Ha ingresado una opcion invalida, reingresela: "<<endl;

                }
            }while(eleccion2<1 or eleccion2>2);


        default:
            cout<<"Ha ingresado una opcion invalida"<<endl;
            system("pause");
            system("cls");
        }
    }while(eleccion<0 or eleccion>3);

};

/*  submenuAdministrarEspecialidadesMedicas

    PROPOSITO:  Ingresará dentro del primer submenú que es en especifico la de
                administrar especialidades medicas y llamará a la función necesaria
                para cumplir lo que desea el usuario
    PARAMETROS: se utilizará la elección que haya otorgado el usuario
    RETORNO:    no se retornara nada

*/

void submenuAdministrarEspecialidadesMedicas(Especialidad especialidades[], int & dl, Turno agenda[], int & dlAgenda){

    char eleccion, subEleccion; // Variable para el switch del case 4

    do{
        // Primero mustra por pantalla la opciones que tiene el usuario
        cout << "Administrar Especialidades Medicas." <<endl;

        cout << "1. Alta de Especialidades Medicas." <<endl;
        cout << "2. Modificacion de Especialidades Medicas." <<endl;
        cout << "3. Baja de Especialidades Medicas." <<endl;
        cout << "4. Listado de Especialidades Medicas." <<endl;
        cout << "\t A. Listado de Especialidades Medicas completo." <<endl;
        cout << "\t B. Listado de Especialidades Medicas Por Busqueda." <<endl;
        cout << "5. Menu principal" <<endl;

        cout<<"Elija una opcion: ";
        cin >> eleccion;


        // Switch para llamar a las funcion segun que opcion se ingreso
        switch(eleccion){

            case '1':
                Alta_de_Especialidades_Medicas(especialidades, dl);
            break;

            case '2':
                Modificacion_de_Especialidades_Medicas(especialidades, dl);
            break;

            case '3':
                Baja_de_Especialidades_Medicas(especialidades, dl, agenda, dlAgenda);
            break;

            case '4':
                do{
                    cout << "Eliga una opcion (A o B)(o C si desea salir): ";
                    cin >> subEleccion;
                    subEleccion=tolower(subEleccion);

                    switch(subEleccion){

                    case 'a':
                        Listado_de_Especialidades_Medicas_completo(especialidades,dl);
                        return;

                    case 'b':
                        Listado_de_Especialidades_Medicas_por_busqueda(especialidades, dl);
                        return;

                    case 'c':
                        system("cls");
                        return;

                    default:
                        cout<<"***Opción Invalida***"<<endl;
                        break;
                    };
                }while(subEleccion!='c');
            break;

            case '5': // Vuelve al menu principal (sale de la funcion y vuelve al main())
                break;

            default: // Se muestra por pantalla un error, y se pregunta nuevamente el submenu 1
                cout<<endl<<"***Opcion invalida***"<<endl;
                system("pause");
                system("cls");
                break;
        };

    }while(eleccion!='5');
    system("cls");
}

/*  submenuAdministrarPacientes

    PROPOSITO:  Ingresará dentro del segundo submenú que es para administrar pacientes y llamará
                a la función necesaria para cumplir lo que desea el usuario
    PARAMETROS: se utilizará la elección que haya otorgado el usuario
    RETORNO:    no se retornara nada

*/

void submenuAdministrarPacientes(Paciente fichaPaciente[], int & dlFichas, int & dlTurnos, Turno agenda[]){

    char eleccion, subEleccion; // Variable para el switch del case 4

    do{ //Se abre un bucle donde el primero se
        // Primero mustra por pantalla la opciones que tiene el usuario
        cout << "Administrar Pacientes." <<endl;

        cout << "1. Alta de Pacientes." <<endl;
        cout << "2. Modificacion de Pacientes." <<endl;
        cout << "3. Baja de Pacientes." <<endl;
        cout << "4. Listado de Pacientes." <<endl;
        cout << "\t A. Listado de Pacientes completo." <<endl;
        cout << "\t B. Listado de Pacientes Por Busqueda." <<endl;
        cout << "5. Menu principal" <<endl;

        cout<<"Elija una opcion: ";
        cin >> eleccion; // Se pide un opcion, luego de mostrar las  opciones en la funcion main()

        // Switch para llamar a las funcione segun que opcion se ingreso
        switch(eleccion){

            case '1':
                Alta_de_Pacientes(fichaPaciente,dlFichas);
                break;

            case '2':
                Modificacion_de_Pacientes(fichaPaciente, dlFichas);
                break;

            case '3':
                Baja_de_Pacientes(fichaPaciente, dlFichas, dlTurnos, agenda);
                break;

            case '4':
                do{
                    cout << "Eliga una opcion (A o B)(o C si desea salir): ";
                    cin >> subEleccion;
                    subEleccion=tolower(subEleccion);
                    switch(subEleccion){

                        case 'a':
                            Listado_de_Pacientes_completo(fichaPaciente, dlFichas);
                            return;

                        case 'b':
                            Listado_de_Pacientes_por_busqueda(fichaPaciente,dlFichas);
                            return;

                        case 'c':
                            system("cls");
                            return;

                        default:
                            cout<<"***Opción Invalida***"<<endl;
                            break;
                        };
                    }while(subEleccion!='c');

            case '5': // Vuelve al menu principal (sale de la funcion y vuelve al main())
                break;

            default: // Se muestra por pantalla un error, y se pregunta nuevamente el submenu 1
                cout<<endl<<"***Opcion invalida***"<<endl;
                system("pause");
                system("cls"); //limpia la consola
                break;

        };

    }while(eleccion!= '5');
    system("cls"); //limpia la consola

}

/*  submenuAdministrarTurnos

    PROPOSITO:  Ingresará dentro del tercer submenú y llamará a la función necesaria
                para cumplir lo que desea el usuario
    PARAMETROS: se utilizará la elección que haya otorgado el usuario
    RETORNO:    no se retornara nada

*/

void submenuAdministrarTurnos(Turno agenda[], Paciente fichas[], int & dlPacientes, int & dlEspecialidades, int & dlTurno, Tiempo diaDeHoy){

    char eleccion, subEleccion; // Variable para el switch del case 4

    do{
        // Primero mustra por pantalla la opciones que tiene el usuario
        cout << "Administrar Turnos." <<endl;

        cout << "1. Alta de Turnos." <<endl;
        cout << "2. Modificacion de Turnos." <<endl;
        cout << "3. Baja de Turnos." <<endl;
        cout << "4. Listado de Turnos." <<endl;
        cout << "\t A. Listado de Turnos completo." <<endl;
        cout << "\t B. Listado de Turnos Por Busqueda." <<endl;
        cout << "5. Menu principal" <<endl;

        cout << "Elija una opcion: ";
        cin >> eleccion; // Se pide un opcion, luego de mostrar las  opciones en la funcion main()

        // Switch para llamar a las funcione segun que opcion se ingreso
        switch(eleccion){

            case '1':
                Alta_de_Turnos(agenda, fichas, dlPacientes, dlEspecialidades, dlTurno, diaDeHoy);
            break;

            case '2':
                Modificacion_de_Turnos(fichas, dlPacientes, agenda, dlTurno, diaDeHoy);
            break;

            case '3':
                Baja_de_Turnos(fichas,dlPacientes, agenda, dlTurno, diaDeHoy);
            break;

            case '4':
                cout << "Eliga una opcion (A o B)(o C si desea salir): ";
                cin >> subEleccion;
                do{
                    switch(subEleccion){

                        case 'a':
                            Listado_de_Turnos_completo(agenda, dlTurno);
                            return;

                        case 'b':
                            Listado_de_Turnos_por_busqueda(agenda, dlTurno, fichas, dlPacientes, dlEspecialidades);
                            return;

                        case 'c':
                            system("cls");
                            return;

                        default:
                            cout<<"***Opción Invalida***"<<endl;
                            break;
                    };
                }while(subEleccion!='c');

            break;

            case '5': // Vuelve al menu principal (sale de la funcion y vuelve al main())
                break;

            default: // Se muestra por pantalla un error, y se pregunta nuevamente el submenu 1

                cout<<"***Opcion invalida***"<<endl;
                system("pause");
                system("cls"); //limpia la consola
                break;

            break;
        };
    }while(eleccion != '5');
    system("cls"); //limpia la consola

    }

/* Función Principal del Programa */

int main(){

    // Variables a usar
    Tiempo comienzoAnio, diaDeHoy;
    comienzoAnio.dia=1;
    comienzoAnio.mes=1;
    comienzoAnio.anio=2022;

    char opcion;
    Especialidad especialidades[MAX];
    Paciente fichas[MAX];
    Turno agenda[MAX];
    int dlFichas, dlEspecialidades, dlAgenda;

    cout<<"BIENVENIDO AL ADMINISTRADOR MEDICO DE LA CLINICA SALUD+"<<endl<<endl;
    cout<<"Lo primero que debes hacer es ingresar que fecha es hoy, \ntenga en cuenta que para que el programa de optimos resultados esta fecha debe sere la correcta"<<endl;
    diaDeHoy=solicitarFecha(comienzoAnio);
    cout<<"Se ha declarado que hoy es "<<diaDeHoy.dia<<"/"<<diaDeHoy.mes<<"/"<<diaDeHoy.anio<<endl;
    system("pause");
    system("cls");

    do{
        // Menu Principal (Primer nivel)
        cout<<"Que desea hacer?"<<endl;

        cout<<"1. Administrar Especialidades Medicas"<<endl;
        cout<<"2. Administrar Pacientes"<<endl;
        cout<<"3. Administrar Turnos"<<endl;
        cout<<"4. Salir"<<endl;

        cout<<"Elija una opcion: ";
        cin >> opcion; // Se ingresa una opcion

        // Submenu (Sugundo Nivel)
        switch(opcion) {

            // Submenu 1
            case '1':
            system("cls"); // Limpia la consola
            submenuAdministrarEspecialidadesMedicas(especialidades, dlEspecialidades, agenda, dlAgenda);   // Luego llama a la funcion
            break;

            // Submenu 2
            case '2':
            system("cls"); // Limpia la consola
            submenuAdministrarPacientes(fichas, dlFichas, dlAgenda, agenda);  // Luego llama a la funcion

            break;

            // Submenu 3
            case '3':
                system("cls"); // Limpia la consol
                submenuAdministrarTurnos(agenda, fichas, dlFichas, dlEspecialidades, dlAgenda, diaDeHoy);  // Luego llama a la funcion

            break;

            case '4': // Opcion 4 de salir (Termina el programa)
                break;

            default:
                cout << "***OPCION INVALIDA***"<<endl; // Mostrar error de opcion
                system("pause");
                system("cls"); // Limpiar la consola
                break;

        };

    }while(opcion!='4');

    system("cls"); // Limpia la consola

    return 0;
};
