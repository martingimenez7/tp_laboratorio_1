
#define LIBRE 0
#define OCUPADO 1

typedef struct
{
    int idSector;
    char sector[20];
}eSector;

typedef struct
{
   int id;
   char name[51];
   char lastName[51];
   float salary;
   int sector;
   int isEmpty;
   int idSector;
}eEmployee;


/** \brief inicializa a los empleados en libre
 * \param eEmployee[] estructura de empleados
 * \param int tamaño
 * \return void
 */
void initEmployees(eEmployee[], int);

/** \brief busca el primer espacio libre en memoria
 * \param eEmployee[] estructura de empleados
 * \param int tamaño
 * \return int [1] si esta ocupado [0]si esta libre
 */
int buscarLibre(eEmployee[], int);

/** \brief carga datos del empleado
 * \param eEmployee[] estructura de empleados
 * \param int tamaño para el array de empleados
 * \param eSector[] estructura de sector
 * \param int tamañano para el array de sectores
 * \return void
 */
void addEmployees(eEmployee[],int,eSector[],int);

/** \brief busca al empleado por ID
 * \param eEmployee[] estructura de empleados
 * \param int tamaño para el array de empleados
 * \param eSector[] estructura de sector
 * \return int
 */
int findEmployeeById(eEmployee[],int,eSector[]);

/** \brief borra un empleado
 * \param eEmployee[] estructura de empleados
 * \param int tamaño
 * \return int [1]si lo encontro [0]si no lo encontro
 */
int removeEmployee(eEmployee[], int);

/** \brief ordena empleados alfabeticamente
 * \param eEmployee[] estructura de empleados
 * \param int tamaño
 * \return void
 */
void sortEmployees(eEmployee[],int);

/** \brief imprime un empleado
 * \param eEmployee estructura de empleados
 * \param eSector[] estructura de sectores
 * \param int tamaño de array de sectores
 * \return void
 */
void mostrarEmpleado(eEmployee,eSector[], int );

/** \brief imprime lista de empleados
 * \param eEmployee[] estructura de empleados
 * \param int tamaño para el array de empleados
 * \param eSector[] estructura de sector
 * \param int tamañano para el array de sectores
 * \return void
 */
void printEmployees(eEmployee[], int, eSector[], int);

/** \brief imprime lista de empleados ordenados alfabeticamente por sector
 * \param eEmployee[] estructura de empleados
 * \param int tamaño para el array de empleados
 * \param eSector[] estructura de sector
 * \param int tamañano para el array de sectores
 * \return void
 */
void mostrarEmpleadosPorSector(eSector[], int, eEmployee[], int);

/** \brief imprime el total, el promedio y la cantidad de empleados que superan el promedio de sueldos
 * \param eEmployee[] estructura de empleados
 * \param int tamaño
 * \return void
 */
void mostrarPromedioSueldo(eEmployee[],int);

/**
 * \brief Genera un número aleatorio
 * \param desde Número aleatorio mínimo
 * \param hasta Número aleatorio máximo
 * \param iniciar Indica si se trata del primer número solicitado 1 indica que si
 * \return retorna el número aleatorio generado
 */
char numeroAleatorio(int,int,int);

/** \brief lista de empleados para realizar pruebas
 * \param eEmployee[] estructura de empleados
 * \param int tamaño
 * \return void
 */
void hardcodearDatosEmpleados(eEmployee[],int);

char getChar(char[]);
int esSoloLetras(char[]);
void getString(char[],char[]);
int getStringLetras(char[],char[]);
int getStringNumeros(char[],char[]);
int esNumerico(char[]);
int menuDeOpciones(char[]);
float getFloat(char[], char[]);



