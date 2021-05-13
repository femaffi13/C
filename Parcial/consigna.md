**Datos:**
Una empresa de ventas de artículos electrónicos y electrodomésticos, necesita una aplicación específica para la facturación generada por puntos de ventas minoristas a sus clientes y para saber qué categoría es la más vendida. La empresa, tiene como criterio, categorizar los productos como:
categoría ‘G’: Grandes electrodomésticos
categoría ‘P’: Pequeños electrodomésticos
categoría ‘E’: Equipos de informática y telecomunicaciones
Para resolver el problema de la facturación informatizando el sistema, lo seleccionan a Ud., y se reúnen para el análisis funcional. El escenario global es que tienen 8 puntos de venta, cada uno tiene muchos clientes –desconocen la cantidad- y, que estos clientes compran algún producto de los mencionados en las categorías, cuyos costos varían. Por lo tanto en la reunión definen lo siguiente:

Requerimientos:
1. Construir una función que permita procesar cada punto de venta, que se identifican con un número entero positivo. Por cada uno, se ingresan una serie de clientes, que también se identifican con un número entero positivo. Y por cada cliente se ingresa:
Clase (G, P ó E) -caracter-
Importe, -número real-
Esta función debe emitir, durante el proceso de obtención de los resultados parciales y por cada punto de venta la facturación total por categoría con su cantidad de clientes.
Ejemplo de la primera iteración de grupo: -
Punto de venta 1 – Facturación: -
G: 72566,89, 5 clientes -
P: 81214,69, 2 clientes -
E: 101987,50, 3 clientes -
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