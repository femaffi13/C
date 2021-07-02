**Datos:**
Una cadena de supermercados tiene N sucursales, todas ubicadas en capitales de provincia y necesita determinado datos respecto de sus ventas. Para ello, se define un vector de N struct con los siguientes datos: 

Id_ Sucursal – tipo int  
Ciudad - array de tipo char[30]  
ventas_del_mes – array de tipo float[30]  
Total_de_ventas_del mes - tipo float (inicialmente campo vacío)  
Importe_Mayor_venta - de tipo float (inicialmente campo vacío)  

1. Además se define un vector con N datos de CEO’s responsables:  
Id_CEO - de tipo int  
Id_Sucursal - tipo int  
Apellido – array de tipo char[30]  

2. Se define un tercer vector de enteros de dimensión N que se inicializara con -1:  

3. Por otra parte, se almacenan en una array bidimensional de N filas por M columnas, las ventas realizadas durante 6 meses anteriores a los cargados en el array de sucursales  

Requerimientos:
1. Construir una función que permita procesar cada punto de venta, que se identifican con un número entero positivo. Por cada uno, se ingresan una serie de clientes, que también se identifican con un número entero positivo. Y por cada cliente se ingresa:  
Clase (G, P ó E) -caracter-  
Importe, -número real-  
Esta función debe emitir, durante el proceso de obtención de los resultados parciales y por cada punto de venta la facturación total por categoría con su cantidad de clientes.
Ejemplo de la primera iteración de grupo:  
Punto de venta 1 – Facturación:  
G: 72566,89, 5 clientes  
P: 81214,69, 2 clientes  
E: 101987,50, 3 clientes  
Ejemplo de la segunda iteración de grupo:  
Punto de venta 2 – Facturación:  
G: 102245,21, 3 clientes  
P: 48432,91, 5 clientes  
E: 20870,30, 2 clientes  
…siguientes iteraciones….  

2. Construir una función auxiliar que reciba -al menos- categoría e importe y devuelva a la función del punto 1, el total acumulado por cada categoría con su cantidad de clientes.

3. Mensaje final en main(), que emita los resultados finales:
    - total general de clientes.
    - qué categoría facturó más y cuál fue el importe.
    - el total general de facturación.