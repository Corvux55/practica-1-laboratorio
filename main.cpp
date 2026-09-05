#include <iostream>

using namespace std;
/*void fun_a(int *px, int *py);
void fun_b(int a[], int tam);
void prueba_fun_c();
void prueba_punto3();

int main()
{
    int array[10] ={0,1,2,3,4,5,6,7,8,9};
    fun_b(array, 10);
    prueba_fun_c();
    prueba_punto3();
}
void fun_a(int *px, int *py)
{
    int tmp= *px;
    *px = *py;
    *py = tmp;
}
void fun_b(int a[], int tam)
{
    int f, l;
    int *b =a;
    for (f = 0, l = tam -1; f<l; f++, l--)
    {
        fun_a(&b[f], &b[l]);
    }
}
*/
/*
    Con ayuda del debugger, examine la representacion en memoria del arreglo array y responda:

    1) Cual es su direccion en memoria? Cuantos bytes se dedican a almacenar cada elemento de array?
       - Direccion de array: como es una variable en el stack, la direccion cambia cada vez que se ejecuta, en este caso la direccion es 0x7fffffffe5f0
       - Bytes por elemento: a cada elemento del array le pertenecen 4 bytes
       - Los 10 elementos ocupan 10 x 4 = 40 bytes consecutivos en el stack.

    2) Cual es la direccion y el contenido en memoria del elemento array[3]?
       - Direccion de array[3]: 0x7fffffffe5fc, que es la direccion inicial mas 12 bytes
       - Contenido antes de fun_b: 3
       - Contenido despues de fun_b: 6, porque fun_b invierte el arreglo

    3) Describa el efecto que tiene la funcion fun_b sobre el arreglo array.
       - fun_b invierte el orden de los elementos del arreglo.
       - Lo hace tomando el primer y el ultimo elemento y cambiandolos de lugar, luego el segundo con el penultimo, y asi hasta llegar al centro.
       - Usa un puntero b que apunta al inicio del arreglo, y dos indices: uno desde el inicio (f) y otro desde el final (l).
       - En cada pasada cambia los elementos y avanza: f sube de uno en uno y l baja de uno en uno.
       - Iteraciones realizadas:
           f=0, l=9 -> cambia array[0] con array[9]  -> {9,1,2,3,4,5,6,7,8,0}
           f=1, l=8 -> cambia array[1] con array[8]  -> {9,8,2,3,4,5,6,7,1,0}
           f=2, l=7 -> cambia array[2] con array[7]  -> {9,8,7,3,4,5,6,2,1,0}
           f=3, l=6 -> cambia array[3] con array[6]  -> {9,8,7,6,4,5,3,2,1,0}
           f=4, l=5 -> cambia array[4] con array[5]  -> {9,8,7,6,5,4,3,2,1,0}
           f=5, l=4 -> f ya no es menor que l, termina el bucle.
       - Resultado final: {9, 8, 7, 6, 5, 4, 3, 2, 1, 0}
    */

/* 2. La siguiente funcion contiene errores. Corrijalos para que funcione correctamente:
 * void fun_c (double *a, int n; double *promedio, double *suma){
    int i;
    suma =0.0;
    for (i=0; i<n; i++){
        suma += (a + i);
    }
    promedio = suma /n;
}
 * Implemente un caso de prueba para la funcion anterior que permita verificar su correcto funcionamiento.
 */

void fun_c(double *a, int n, double *promedio, double *suma)
{
    int i;
    *suma = 0.0; //falta un asterisco: suma guarda la direccion, *suma guarda el valor
    for (i = 0; i < n; i++)
    {
        *suma += *(a + i); //(a + i) es la direccion del elemento; *(a + i) es su valor
    }
    *promedio = *suma / n; //promedio es puntero, se escribe con *promedio
}

void prueba_fun_c()
{
    /*
    Caso de prueba: dados 4 valores, la suma debe dar 10.0 y el promedio 2.5.
    */
    double datos[] = {1.0, 2.0, 3.0, 4.0};
    double promedio, suma;
    fun_c(datos, 4, &promedio, &suma);
    cout << "suma = " << suma << " promedio = " <<promedio <<endl;
}

/* 3. Se tiene la siguiente declaracion e inicializacion:
 * unsigned short b[4][2] = {{77, 50}, {5, 2}, {28, 39}, {99, 3}};
 * Complete la numeracion de las direcciones de memoria (en notacion hexadecimal) para cada
 * uno de los 8 elementos de b. Puede seleccionar un valor arbitrario para la primera posicion.
 * Determine el valor de las siguientes expresiones:
 * b, b+2, *(b+2), *(b+2)+1, *(*(b+2)+1), b[3][1], *b++
 */

// Cada unsigned short ocupa 2 bytes, asi que cada elemento sigue al anterior 2 direcciones de distancia.
// Elijo la base 0xFF00 para b[0][0]; cada fila tiene 2 elementos (4 bytes en total).

/*
Direcciones de cada elemento:
  b[0][0] = 0xFF00  (77)     b[0][1] = 0xFF02  (50)
  b[1][0] = 0xFF04  (5)      b[1][1] = 0xFF06  (2)
  b[2][0] = 0xFF08  (28)     b[2][1] = 0xFF0A  (39)
  b[3][0] = 0xFF0C  (99)     b[3][1] = 0xFF0E  (3)

Valor de las expresiones:
  b            = 0xFF00 (direccion del primer elemento)
  b+2          = 0xFF08 (direccion de la fila 2)
  *(b+2)       = 0xFF08 (direccion de b[2][0]) = b[2]
  *(b+2)+1     = 0xFF0A (direccion de b[2][1])
  *(*(b+2)+1)  = 39     (valor de b[2][1])
  b[3][1]      = 3      (valor de la fila 3, segunda columna)
  *b++         = ERROR DE COMPILACION (b es un arreglo y no se puede incrementar)
*/

void prueba_punto3()
{
    unsigned short b[4][2] = {{77, 50}, {5, 2}, {28, 39}, {99, 3}};

    cout << "Direcciones: " << endl;
    cout << "  b           = " << b << endl;          // direccion de la 1a fila (b[0][0])
    cout << "  b+2         = " << b+2 << endl;        // direccion de la fila 2
    cout << "  *(b+2)      = " << *(b+2) << endl;     // direccion de b[2][0]
    cout << "  *(b+2)+1    = " << *(b+2)+1 << endl;   // direccion de b[2][1]
    cout << "  *b++ no compila en C++ (b es un arreglo)" << endl;

    cout << "Valores: " << endl;
    cout << "  *(*(b+2)+1) = " << *(*(b+2)+1) << endl; // valor de b[2][1] = 39
    cout << "  b[3][1]     = " << b[3][1] << endl;      // valor 3
    cout << "  **b         = " << **b << endl;          // valor de b[0][0] = 77

    unsigned short (*p)[2] = b;   // puntero a filas, equivalente a b
    cout << "  *p++        = " << *( *p++ ) << endl;  // con puntero: devuelve 77

}

void problema1()
{
    int monto;
    cout << "Ingrese un monto: ";
    cin >> monto;
    if (monto < 0){
        cout << "Valor no valido, ingrese un valor positivo: ";
        cin >> monto;
    }
    int valores[]={50000,20000,10000,5000,2000,1000,500,200,100,50};
    int cantidades[10]={10};
    int total_valores=10;
    for (int i=0; i<total_valores; i++){
        cantidades[i]= monto/valores[i];
        monto = monto%valores[i];
    }
    cout << "Billetes 50000: " << cantidades[0] << endl;
    cout << "Billetes 20000: " << cantidades[1] << endl;
    cout << "Billetes 10000: " << cantidades[2] << endl;
    cout << "Billetes 5000: " << cantidades[3] << endl;
    cout << "Billetes 2000: " << cantidades[4] << endl;
    cout << "Billetes 1000: " << cantidades[5] << endl;
    cout << "Monedas 500: " << cantidades[6] << endl;
    cout << "Monedas 200: " << cantidades[7] << endl;
    cout << "Monedas 100: " << cantidades[8] << endl;
    cout << "Monedas 50: " << cantidades[9] << endl;
    cout << "Faltante: : " << monto << endl;
}
void problema2()
{
    const int N = 200;
    char letras[N];
    int conteo[26] = {0};

    int semilla;
    semilla = (int)(long)&semilla;   // direccion del stack, cambia en cada ejecucion
    for (int i = 0; i < N; i++)
    {
        semilla = semilla * 1103515245 + 12345;   // generador propio
        letras[i] = 'A' + semilla % 26;
        cout << letras[i];
    }
    cout << endl;

    for (int i = 0; i < N; i++)
        conteo[letras[i] - 'A']++;

    for (int i = 0; i < 26; i++)
        if (conteo[i] > 0)
            cout << char('A' + i) << ": " << conteo[i] << endl;
}
void problema3(){
    char cadena1[50],cadena2[50];
    cout << "Ingrese la primera cadena: \n";
    cin >> cadena1;
    cout << "Ingrese la segunda cadena: \n";
    cin >> cadena2;
    int lon1=0,lon2=0;
    while (cadena1[lon1]!='\0'){
        lon1++;
    }
    while (cadena2[lon2]!='\0'){
        lon2++;
    }
    bool iguales=true;
    if (lon1 != lon2){
        iguales = false;
    }
    else{
        for(int i=0; i<lon1; i++){
            if (cadena1[i] != cadena2[i]){
                iguales = false;
                break;
            }
        }
    }
    if (iguales){
        cout << "Las cadenas son iguales";
    }
    else{
        cout << "Las cadenas son diferentes";
    }
}
void problema4(){
    char cadena[50];
    cout << "Ingresa la cadena de numeros: ";
    cin >>cadena;
    int numero=0;
    int i=0;
    while (cadena[i] != '\0'){
        int digito = cadena[i]-'0';
        numero = numero * 10 + digito;
        i++;
    }
    cout << "El numero entero obtenido es: "<<numero<<endl;
}
void int_a_cadena(int numero, char cadena[])
{
    int i = 0;
    long n = numero;
    if (n < 0){
        cadena[i++] = '-';
        n = -n;
    }
    int inicio = i;
    do {
        cadena[i++] = char('0' + n % 10);
        n = n / 10;
    } while (n > 0);
    cadena[i] = '\0';
    for (int f = inicio, l = i - 1; f < l; f++, l--){
        char tmp = cadena[f];
        cadena[f] = cadena[l];
        cadena[l] = tmp;
    }
}
void problema5(){
    int numero;
    char cadena[50];
    cout << "Ingrese un numero entero: ";
    cin >> numero;
    int_a_cadena(numero, cadena);
    cout << "La cadena obtenida es: " << cadena << endl;
}
void problema6(){
    char cadena[50];
    char original[50];
    cout << "Ingrese una cadena: ";
    cin >> cadena;
    int i;
    for (i = 0; cadena[i] != '\0'; i++)
        original[i] = cadena[i];
    original[i] = '\0';
    for (i = 0; cadena[i] != '\0'; i++)
        if (cadena[i] >= 'a' && cadena[i] <= 'z')
            cadena[i] = cadena[i] - 'a' + 'A';
    cout << "Original: " << original << ". En mayusculas: " << cadena << endl;
}
int main()
{
    problema6();
    return 0;
}
