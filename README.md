# TC1030.301-Proyecto_Alejandro_C

proyecto 1 - semestre 2

Este proyecto está diseñado para la organización, presentación, archivación y control de uso de distintos vehículos (tanto motorizados, no motorizados y eléctricos) dentro de un mismo garaje. Entre sus funcionalidades puede llevar registro de kilometraje, capacidad de combustible, combustible actual, rendimiento, características y componentes (motor) en un mismo garaje definido que lleva registro de cuántos y cuáles vehículos contiene, así como la capacidad de agregar o eliminar vehículos de este.

## Funcionamiento
El programa inicialmente define el garaje y su capacidad, posteriormente maneja las opciones de definir y agregar un vehículo, recargar el tanque de un vehículo, incrementar kilometraje, desplegar vehículos en el garaje y finalmente eliminar un vehículo; llevando asi un control de cada vehículo.

## Clases
Vehículo: Clase Abstracta con atributos en común para los 3 tipos de vehículos y solamente métodos virtuales para la presentación y modificación de sus atributos.

Electric: Clase representante de vehículos eléctricos (hija de Vehículos)

Gas: Clase representante de vehículos a base de combustibles fósiles (hija de Vehículos)

Eco: Clase representante de vehículos no motorizados y ecológicos (como bicicletas, patines del diablo, etc) (hija de Vehículos)

Motor: Clase representante de motores tanto eléctricos como a base de combustibles fósiles (Compuesta en Electric y Gas)

Cochera: Clase que representa la cochera única en la que se contendrán, organizarán y editarán los vehículos creados (Agrega con Vehículos)

## Casos de fallo
En caso de introducir valores de un tipo no correspondiente al esperado el programa marcará error.

Aunque sea poco probable el uso del programa de forma masiva (exceso de vehículos), esto puede marcar error a falta de espacio o manejo de este.

## Versiones y correcciones
May 15, 2025 : UML inicial, .hpp inicial (clase Vehiculo)

May 22, 2025 : Clases hijas (Electric, Eco, Gas)

May 29, 2025 : Clase compuesta (Motor), .cpp (main) inicial

Jun 1, 2025 : arreglo de error en include de .hpp

Jun 5, 2025 : Clase agregada (Cochera), UML final, .cpp (main) final, README

## Documentación

Motores Eléctricos:
https://www.gob.mx/cms/uploads/attachment/file/970078/Ficha__Motores_Electricos_200124.pdf
https://www.daze.eu/es-es/blog/tipos-motores-electricos

Motores a base de combustibles fósiles:
https://rentingfinders.com/blog/tecnologia/todos-tipos-motores-coche-existen/
https://autoland.com.pe/conoce-tipos-motores-auto-existen/

### Estructuras relevantes:

Clase abstracta:
https://stackoverflow.com/questions/9029548/abstract-base-struct-in-c

Arreglos y apuntadores
https://www.cimat.mx/~alram/cpa/pointersC.pdf
