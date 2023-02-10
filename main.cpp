#include<iostream>

using namespace std;

int main(){

    cout << "commit de prueba" <<endl;

}


/*
comando: cargar_comandos nombre_archivo
salida en pantalla:
(Archivo vacío) nombre_archivo no contiene comandos.
(Archivo erróneo) nombre_archivo no se encuentra o no puede leerse.
(Resultado exitoso) n comandos cargados correctamente desde nombre_archivo .
descripción: Carga en memoria los comandos de desplazamiento contenidos en el archivo identificado
por nombre_archivo , es decir, utiliza adecuadamente las estructuras lineales para cargar la información
de los comandos en memoria. Si dentro de la misma sesión de trabajo ya se han cargado otros archivos
de comandos (usando el comando cargar_comandos), la información debe sobreescribirse en memoria,
es decir, no se deben combinar informaciones de comandos de diferentes archivos.
• comando: cargar_elementos nombre_archivo
salida en pantalla:
(Archivo vacío) nombre_archivo no contiene elementos.
(Archivo erróneo) nombre_archivo no se encuentra o no puede leerse.
(Resultado exitoso) n elementos cargados correctamente desde nombre_archivo .
descripción: Carga en memoria los datos de puntos de interés o elementos contenidos en el archivo
identificado por nombre_archivo , es decir, utiliza adecuadamente las estructuras lineales para cargar
la información de los elementos en memoria. Si dentro de la misma sesión de trabajo ya se han cargado
otros archivos de puntos de interés (usando el comando cargar_elementos), la información debe
sobreescribirse en memoria, es decir, no se deben combinar informaciones de elementos de diferentes
archivos.
• comando: agregar_movimiento tipo_mov magnitud unidad_med
salida en pantalla:
(Formato erróneo) La información del movimiento no corresponde a los datos esperados
(tipo, magnitud, unidad).
(Resultado exitoso) El comando de movimiento ha sido agregado exitosamente.
descripción: Agrega el comando de movimiento descrito a la lista de comandos del robot “Curios-
ity”. El movimiento puede ser de dos tipos: avanzar o girar. La magnitud corresponde al valor del
movimiento; si es avanzar, el número de unidades que se espera avanzar, si es girar la cantidad de grados
que debe girar. La unidad de medida corresponde a la convención con la que se mide la magnitud del
2
movimiento (centimetros, metros, grados, ...). Si no se envía la información completa y adecuada
del comando de movimiento, éste no puede agregarse a la lista de los comandos que se enviarán al robot
desde la tierra.
• comando: agregar_analisis tipo_analisis objeto comentario
salida en pantalla:
(Formato erróneo) La información del análisis no corresponde a los datos esperados (tipo,
objeto, comentario).
(Resultado exitoso) El comando de análisis ha sido agregado exitosamente.
descripción: Agrega el comando de análisis descrito a la lista de comandos del robot “Curiosity”. El
análisis puede ser de tres tipos: fotografiar, composicion o perforar. El objeto es el nombre del
elemento que se quiere analizar (roca, arena, monticulo, ...). El comentario es opcional y permite agregar
más información sobre el elemento o el análisis, este comentario estará encerrado entre comillas simples
(ejemplo: ’roca_cuadrante_32’). Si no se envía la información completa y adecuada del comando de
análisis, éste no puede agregarse a la lista de los comandos que se enviarán al robot desde la tierra.
• comando: agregar_elemento tipo_comp tamaño unidad_med coordX coordY
salida en pantalla:
(Formato erróneo) La información del elemento no corresponde a los datos esperados (tipo,
tamaño, unidad, x, y).
(Resultado exitoso) El elemento ha sido agregado exitosamente.
descripción: Agrega el componente o elemento descrito a la lista de puntos de interés del robot “Cu-
riosity”. El tipo de componente puede ser uno entre roca, crater, monticulo o duna. El tamaño
es un valor real que da cuenta de qué tan grande es el elemento; y la unidad de medida complementa
este valor con la convención que se usó para su medición (centimetros, metros, ...). Finalmente, las
coordenadas x y y corresponden a números reales que permiten conocer la ubicación del elemento en
el sistema de coordenadas del suelo marciano utilizado por el vehículo. Si no se envía la información
completa y adecuada del elemento, éste no puede agregarse a la lista de puntos de interés que se enviarán
al robot desde la tierra.
• comando: guardar tipo_archivo nombre_archivo
salida en pantalla:
(No hay información) La información requerida no está almacenada en memoria.
(Escritura exitosa) La información ha sido guardada en nombre_archivo .
(Problemas en archivo) Error guardando en nombre_archivo .
descripción: Guarda en el archivo nombre_archivo la información solicitada de acuerdo al tipo de
archivo: comandos almacena en el archivo la información de comandos de movimiento y de análisis que
debe ejecutar el robot, elementos almacena en el archivo la información de los componentes o puntos
de interés conocidos en el suelo marciano.
• comando: simular_comandos coordX coordY
salida en pantalla:
(No hay información) La información requerida no está almacenada en memoria.
(Resultado exitoso) La simulación de los comandos, a partir de la posición (coordX,coordY ),
deja al robot en la nueva posición (nuevoX ,nuevoY ).
descripción: Permite simular el resultado de los comandos de movimiento que se enviarán al robot
“Curiosity” desde la Tierra, facilitando asi la validación de la nueva posición en la que podría ubicarse.
Para ejecutarse adecuadamente, requiere conocer la posición actual (coordenadas x y y) del vehículo.
Hay que tener en cuenta que sólo los comandos de movimiento son necesarios, no los de análisis.
• comando: salir
salida en pantalla:
(No tiene salida por pantalla)
descripción: Termina la ejecución de la aplicación.
2.2.2 Componente 2: Planeación de desplazamientos
Objetivo: Utilizar una estructura de datos jerárquica que permita almacenar datos geométricos para analizar
los puntos de interés sobre el cielo marciano y así facilitar en el futuro la planificación automática de desplaza-
mientos. Los comandos que se deben implementar como parte de este componente son:
3
• comando: ubicar_elementos
salida en pantalla:
(No hay información) La información requerida no está almacenada en memoria.
(Problemas con elementos) Los siguientes elementos no pudieron procesarse adecuadamente:
...
(Resultado exitoso) Los elementos han sido procesados exitosamente.
descripción: El comando debe utilizar la información de puntos de interés almacenada en memoria
para ubicarlos en una estructura de datos jerárquica adecuada, que permita luego realizar consultas
geográficas sobre estos elementos. Si alguno de los elementos no puede agregarse adecuadamente, debe
generarse un mensaje de error, pero deben terminarse de procesar todos los elementos almacenados en
memoria.
• comando: en_cuadrante coordX1 coordX2 coordY1 coordY2
salida en pantalla:
(Formato erróneo) La información del cuadrante no corresponde a los datos esperados (x_min,
x_max, y_min, y_max).
(No hay información) Los elementos no han sido ubicados todavía (con el comando ubicar_elementos).
(Resultado exitoso) Los elementos ubicados en el cuadrante solicitado son: ...
descripción: Permite utilizar la estructura creada con el comando anterior para retornar una lista de
los componentes o elementos que están dentro del cuadrante geográfico descrito por los límites de co-
ordenadas en x y y. Es necesario haber ejecutado el comando ubicar_elementos para poder realizar
la búsqueda por cuadrantes. Los límites de coordenadas deben garantizar que coordX1 <coordX2 y
coordY1 <coordY2 .
2.2.3 Componente 3: Recorridos entre puntos de interés
Objetivo: A partir de la información de puntos de interés, utilizar representaciones en grafos para crear
representaciones geográficas (mapas) que permitan posteriormente identificar regiones de interés sobre el
suelo marciano para aterrizajes y exploración. Los comandos que se deben desarrollar como parte de este
componente son:
• comando: crear_mapa coeficiente_conectividad
salida en pantalla:
(No hay información) La información requerida no está almacenada en memoria.
(Resultado exitoso) El mapa se ha generado exitosamente. Cada elemento tiene n vecinos.
descripción: El comando debe utilizar la información de puntos de interés almacenada en memoria para
ubicarlos en una estructura no lineal y conectarlos entre sí teniendo en cuenta el coeficiente de conec-
tividad dado. El objetivo es que cada elemento esté conectado a los demás elementos más cercanos a
él, midiendo la cercanía a través de la distancia euclidiana entre los elementos. Esta distancia euclidiana
también se utiliza como el peso o etiqueta de la conexión entre los elementos. Con el coeficiente de
conectividad se identifica la cantidad de vecinos que puede tener cada elemento tomando como base el
total de elementos que se ubicarán en el mapa (ejemplo: si se van a ubicar 35 elementos, y el coeficiente
de conectividad es 0.4, la cantidad de vecinos que cada elemento debe tener es 35 * 0.4 = 14).
• comando: ruta_mas_larga
salida en pantalla:
(No hay información) El mapa no ha sido generado todavía (con el comando crear_mapa).
(Resultado exitoso) Los puntos de interés más alejados entre sí son ... y ... La ruta
que los conecta tiene una longitud total de ... y pasa por los siguentes elementos:
...
descripción: Con el mapa ya creado, el comando permite identificar los dos componentes más alejados
entre sí de acuerdo a las conexiones generadas. Es importante aclarar que el comando retorna los ele-
mentos más alejados de acuerdo a las conexiones que se encuentran en el mapa, no los elementos que
estén a mayor distancia euclidiana entre sí. Al encontrar esa ruta más larga dentro del mapa, el comando
imprime en pantalla los elementos de origen y destino, la longitud total de la ruta, y la secuencia de
elementos que hay que seguir para ir del elemento origen al elemento destino
*/
