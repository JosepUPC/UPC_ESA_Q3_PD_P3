# PRACTICA COMPLEMENTARIA 3 #

Durante la sesion de la practica 2 manejamos  interrupciones  y en particular la interrupcion del timer.  En la Practica 3( titulada como practica 4) hemos revisado  la operacion de sistemas operativos de tiempo real FreeRtos.
Vamos a realizar un pequeño proyecto que permita la generacion de efectos visuales en un conjunto de leds  .


## Funcionalidad del projecto ##

Realizar  un programa que  genere efectos visuales por lo menos con 3 leds  , aunque lo deseable es que el alumno utilice 4 .

* La velocidad de los efectos se tienen que controlar con 2 pulsadores  , uno para subir la velocidad  y otro para bajarlo. 

* Los efectos luminosos se tendran programados en el programa  y se dispondra de  otro pulsador para cambiar de efecto.


## Requisitos Operativos ##

El programa debera de realizarse por parte del alumno  y debera cumplir los siguientes requisitos.

* el programa se separara en 2 zonas  una de lectura de pulsadores y de gestion de efectos de leds , esta se realizara en  un core  y Otra donde se realizara el procesado de las ordenes que se realizara en un segundo core .

* El programa de gestion lectura y efectos se basara en una interrupcion del timer  

* la gestion de pulsadores  debera de disponer de un filtrado en tiempo real de rebotes   y lanzara las ordenes de ejecucion  en los flancos de bajada. Estas ordenes se ejecutaran  por el programa de procesado de ordenes 

* Los efectos luminosos de los leds  se deben guardar en una estructura  donde se pueda  indicar las diferentes activaciones relativas entre cada led  y  por tanto las modificaciones entre animaciones se realizaran  recorriendo una tabla de punteros a estructuras.


## Realizacion de la practica ##

Esta practica , que  puede realizarse en mas de una sesion requerira  una  consulta  o supervision continua  con el profesor . Pero ,  no debe  retrasar  las practicas  oficiales de las sesiones .



