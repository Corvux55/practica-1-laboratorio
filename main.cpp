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
void problema7(){
    char original[50];
    char final[50];
    int indice=0;
    cout << "Ingrese una palabra: ";
    cin >> original;
    for (int i = 0; original[i] != '\0'; i++){
        bool yaExiste=false;
        for (int j =0; j<indice; j++){
            if (final[j] == original[i]){
                yaExiste = true;
                break;
            }
        }
        if (!yaExiste){
            final[indice]=original[i];
            indice++;
        }
    }
    final[indice]= '\0';
    cout << "original:" << original << ". Sin repetidos: " << final <<endl;
}
void problema8(){
    char original[50];
    char texto[50];
    char numero[50];
    int postexto=0;
    int posNum=0;
    cout << "Ingrese una cadena de caracteres: ";
    cin >> original;
    for (int i=0; original[i] != '\0'; i++){
        if (original[i] >= '0' && original[i] <= '9'){
            numero[posNum] = original[i];
            posNum++;
        }
        else{
            texto[postexto] = original[i];
            postexto++;
        }
    }
    texto[postexto] = '\0';
    numero[posNum] = '\0';
    cout << "Original: " << original << endl;
    cout << "Texto: " << texto << ". Numero: " << numero << endl;
}
void problema9(){
    int n;
    char cadena[50];
    cout << "Ingrese el tamano de cada grupo: ";
    cin >> n;
    cout << "Ingrese una cadena de digitos: ";
    cin >> cadena;
    int lon = 0;
    while (cadena[lon] != '\0')
        lon++;

    int faltantes = (n - lon % n) % n;

    char rellena[60];
    int k = 0;
    for (int i = 0; i < faltantes; i++)
        rellena[k++] = '0';
    for (int i = 0; i < lon; i++)
        rellena[k++] = cadena[i];
    rellena[k] = '\0';

    int grupos = k / n;
    int suma = 0;
    for (int g = 0; g < grupos; g++){
        int grp = 0;
        for (int i = 0; i < n; i++)
            grp = grp * 10 + (rellena[g * n + i] - '0');
        suma += grp;
    }
    cout << "Original: " << cadena << "." << endl;
    cout << "Suma: " << suma << "." << endl;
}
void problema10(){
    char romano[50];
    char simbolos[] = {'M','D','C','L','X','V','I'};
    int valores[]   = {1000,500,100,50,10,5,1};
    cout << "Ingrese un numero romano: ";
    cin >> romano;
    int lon = 0;
    while (romano[lon] != '\0')
        lon++;

    bool valido = true;
    for (int i = 0; i < lon; i++){
        int consec = 1;
        while (i + 1 < lon && romano[i + 1] == romano[i]){
            consec++;
            i++;
        }
        if (consec > 3){
            valido = false;
            break;
        }
    }
    if (!valido){
        cout << "El numero ingresado fue: " << romano << endl;
        cout << "Invalido: hay mas de 3 caracteres iguales seguidos." << endl;
        return;
    }

    int vnum[50];
    for (int i = 0; i < lon; i++){
        vnum[i] = 0;
        for (int s = 0; s < 7; s++)
            if (simbolos[s] == romano[i])
                vnum[i] = valores[s];
    }

    int total = 0;
    for (int i = 0; i < lon; i++){
        int siguiente = 0;
        if (i + 1 < lon)
            siguiente = vnum[i + 1];
        if (vnum[i] < siguiente)
            total -= vnum[i];
        else
            total += vnum[i];
    }
    cout << "El numero ingresado fue: " << romano << endl;
    cout << "Que corresponde a: " << total << "." << endl;
}
void problema11(){
    char sala[15][20];
    for (int f = 0; f < 15; f++)
        for (int c = 0; c < 20; c++)
            sala[f][c] = '-';

    int continuar = 1;
    while (continuar == 1){
        cout << " ";
        for (int c = 1; c <= 20; c++)
            if (c < 10)
                cout << "  " << c;
            else
                cout << " " << c;
        cout << endl;

        for (int f = 0; f < 15; f++){
            cout << char('A' + f);
            for (int c = 0; c < 20; c++)
                cout << sala[f][c] << "  ";
            cout << endl;
        }

        char fila;
        int asiento;
        cout << "Ingrese fila (A-O) y asiento (1-20): ";
        cin >> fila >> asiento;
        if (fila < 'A' || fila > 'O' || asiento < 1 || asiento > 20){
            cout << "Fila o asiento invalido." << endl;
        }
        else{
            int f = fila - 'A';
            if (sala[f][asiento - 1] == '-'){
                sala[f][asiento - 1] = '+';
                cout << "Asiento reservado." << endl;
            }
            else{
                sala[f][asiento - 1] = '-';
                cout << "Reserva cancelada." << endl;
            }
        }
        cout << "Ingrese 1 para continuar o 0 para terminar: ";
        cin >> continuar;
    }
}
void problema12(){
    int n;
    cout << "Ingrese el orden de la matriz (n): ";
    cin >> n;
    int m[20][20];
    cout << "Ingrese los numeros de la matriz:" << endl;
    for (int f = 0; f < n; f++)
        for (int c = 0; c < n; c++)
            cin >> m[f][c];

    cout << "Matriz ingresada:" << endl;
    for (int f = 0; f < n; f++){
        for (int c = 0; c < n; c++)
            cout << m[f][c] << " ";
        cout << endl;
    }

    bool repetido = false;
    for (int f = 0; f < n && !repetido; f++)
        for (int c = 0; c < n && !repetido; c++)
            for (int f2 = 0; f2 < n && !repetido; f2++)
                for (int c2 = 0; c2 < n && !repetido; c2++)
                    if ((f != f2 || c != c2) && m[f][c] == m[f2][c2])
                        repetido = true;

    int sumaReferencia = 0;
    for (int c = 0; c < n; c++)
        sumaReferencia += m[0][c];

    bool magica = !repetido;
    for (int f = 0; f < n && magica; f++){
        int sumaFila = 0;
        for (int c = 0; c < n; c++)
            sumaFila += m[f][c];
        if (sumaFila != sumaReferencia)
            magica = false;
    }
    for (int c = 0; c < n && magica; c++){
        int sumaCol = 0;
        for (int f = 0; f < n; f++)
            sumaCol += m[f][c];
        if (sumaCol != sumaReferencia)
            magica = false;
    }
    if (magica){
        int sumaDiag1 = 0;
        int sumaDiag2 = 0;
        for (int i = 0; i < n; i++){
            sumaDiag1 += m[i][i];
            sumaDiag2 += m[i][n - 1 - i];
        }
        if (sumaDiag1 != sumaReferencia || sumaDiag2 != sumaReferencia)
            magica = false;
    }

    if (magica)
        cout << "La matriz es un cuadrado magico." << endl;
    else
        cout << "La matriz NO es un cuadrado magico." << endl;
}
void problema14(){
    int m[5][5];
    int num = 1;
    for (int f = 0; f < 5; f++)
        for (int c = 0; c < 5; c++)
            m[f][c] = num++;

    cout << "Matriz original:" << endl;
    for (int f = 0; f < 5; f++){
        for (int c = 0; c < 5; c++)
            cout << m[f][c] << " ";
        cout << endl;
    }

    int rot90[5][5], rot180[5][5], rot270[5][5];
    for (int f = 0; f < 5; f++)
        for (int c = 0; c < 5; c++){
            rot90[f][c] = m[4 - c][f];
            rot180[f][c] = m[4 - f][4 - c];
            rot270[f][c] = m[c][4 - f];
        }

    cout << "Matriz rotada 90 grados:" << endl;
    for (int f = 0; f < 5; f++){
        for (int c = 0; c < 5; c++)
            cout << rot90[f][c] << " ";
        cout << endl;
    }

    cout << "Matriz rotada 180 grados:" << endl;
    for (int f = 0; f < 5; f++){
        for (int c = 0; c < 5; c++)
            cout << rot180[f][c] << " ";
        cout << endl;
    }

    cout << "Matriz rotada 270 grados:" << endl;
    for (int f = 0; f < 5; f++){
        for (int c = 0; c < 5; c++)
            cout << rot270[f][c] << " ";
        cout << endl;
    }
}
void problema17(){
    int n;
    cout << "Ingrese un numero: ";
    cin >> n;
    int total = 0;
    for (int a = 2; a < n; a++){
        int sumaA = 0;
        for (int d = 1; d < a; d++)
            if (a % d == 0)
                sumaA += d;
        int b = sumaA;
        int sumaB = 0;
        for (int d = 1; d < b; d++)
            if (b % d == 0)
                sumaB += d;
        if (b > a && b < n && sumaB == a)
            total += a + b;
    }
    cout << "El resultado de la suma es: " << total << "." << endl;
}
void problema18() {
    int N;
    cout << "Ingrese el numero de permutacion (N): ";
    cin >> N;
    if (N < 1 || N > 3628800) {
        cout << "Error: N debe estar entre 1 y 3,628,800" << endl;
        return;
    }
    long long factoriales[10] = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    char digitos[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    string resultado = "";
    int n = N - 1;
    for (int i = 9; i >= 0; i--) {
        int indice = n / factoriales[i];
        n = n % factoriales[i];
        resultado += digitos[indice];
        for (int j = indice; j < 9; j++)
            digitos[j] = digitos[j + 1];
    }
    cout << "La permutacion numero " << N << " es: " << resultado << endl;
}
int main()
{
    problema18();
    return 0;
}
