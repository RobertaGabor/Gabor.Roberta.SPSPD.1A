#ifndef UTN_BIBLIOTECA_H_INCLUDED
#define UTN_BIBLIOTECA_H_INCLUDED
/*PRIMERAS FUNCIONES*/
/** \brief Pide un char y o devuelve
 *
 * \param Mensaje de peticion
 * \return char
 *
 */
char utn_getLetra(char mensaje[]);
/** \brief valida que lo ingresado sea un telefono
 *
 * \param vector de numeros
 * \param
 * \return 1 si es un telefono sino 0
 *
 */
int utn_validarTelefono (char vector[]);

/** \brief Busca la posicion donde se encuentre el numero entero buscado
 *
 * \param tanaño del array
 * \param entero que se desea buscar
 * \return devuelve -1 si no lo encontro, sino devuelve el indice donde se encuentra
 *
 */
int utn_buscadorEspacio(int vector[],int tam,int buscado);
/** \brief Inicializa todos los indices del vectoe con un entero
 *
 * \param vector que se va a inicializar
 * \param tamañode vector
 * \entero que sera el valor de inicio
 * \return el vector ya inicializado
 *
 */
void utn_inicializadorString (int vector[],int tam,int inicio);
/** \brief Pide al usuario 2 numeros, valida que sean correctamente numeros y busca el mayor de los dos
 *
 * \param x int primer entero ingresado
 * \param y int segundo entero ingresado
 * \param mayor int* por referencia devuelve el mayor de los dos
 * \return devuelve 0 si son iguales, o 1 si uno de los dos es mayor que el otro
 *
 */
int utn_numeroMayor(int x, int y,int* mayor);
/** \brief Inicializa todo un array de floats con un numero
 *
 * \param vector de tipo float
 * \param tamaño del vector
 * \param numero inicializador
 * \return 0 si se logro inicializar -1 si no.
 *
 */
int utn_inicializadorFloat (float vector[],int tam,float inicio);





//-----------------------------------------------------------------------------------------------------
/*FUNCIONES UTILIZABLES*/


int validatedSexo (char* sexo);
int validarSexo (char vector);
int getSexo(char sexo[],char* mensaje,char* mensajeError,int reintentos);

int validarNumeroInt (char vector[],int tam);
int validatedInt(int* numero);
int getInt(int* numero,char* mensaje,char* mensajeError,int minimo,int maximo,int reintentos);

int floatValidated(float* numero);
int validarNumeroFloat (char vector[],int tam);
int getFloat(float* numero,char* mensaje,char* mensajeError,int max,int min,int reintentos);

int getString(char string[],int tam,char* mensaje,char* mensajeError,int reintentos);
int validarStringLetras (char vector[],int tam);
int stringValidated(char cadena[],int tam);
int scanString (char ingreso[],int tam);

int alfanumericoValidated(char cadena[],int tam);
int getAlfanumerico(char string[],int tam,char* mensaje,char* mensajeError,int reintentos);
#endif // UTN_BIBLIOTECA_H_INCLUDED
