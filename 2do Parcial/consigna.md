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
1. Función que reciba el vector de sucursales y cargue en el campo ‘Total_de_ventas_del_mes’, el total del array ‘ventas_del_mes’.  

2. Función que reciba el vector de sucursales, la matriz de ventas y cargue en el campo ‘Importe_Mayor_venta’ la mayor de las ventas obtenida de la matriz.  

3. Función que reciba el vector de sucursales, el vector de enteros y cargue en este vector, las posiciones de los registros del vector de sucursales cuyo ‘Total_de_ventas_del_mes’ no supere al ‘Importe_Mayor_venta’. Los datos de las posiciones deben almacenarse en forma contigua. Esta función debe retornar la cantidad de sucursales detectadas que cumplan con esa directiva.  

4. Función que reciba el vector de sucursales, vector de CEO’s, vector de posiciones y la cantidad retornada en la función anterior y emita el campo ‘Ciudad’ de las sucursales que hayan cumplido la directiva y el campo ‘Apellido’ del CEO que corresponde a esa ciudad.  

5. Función que reciba el vector de sucursales y lo ordene por ciudad en forma descendente. No utilizar qsort. Para su resolución se debe elegir uno de los cuatro algoritmos dados en clase (función obligatoria para aprobar).