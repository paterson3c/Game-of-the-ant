#!/bin/bash

# Verificar si se recibieron los argumentos requeridos
if [ $# -lt 1 ] || [ $# -gt 2 ]; then
    exit 1
fi

# Verificar que el primer argumento sea 0 o 1
if [ "$1" != "0" ] && [ "$1" != "1" ]; then
    exit 1
fi

# Establecer el nombre del fichero de pruebas
if [ $# -eq 2 ]; 
then
    test_file=$2
else
    test_file="test"
fi

# Compilar el fichero de código fuente
make $test_file

# Ejecutar el programa con o sin valgrind según el valor del primer argumento
if [ "$1" == "0" ]; then
     ./$(basename $test_file)
else
    valgrind --leak-check=full --track-origins=yes ./$(basename $test_file)
fi

# Ejecutar todas las pruebas si no se especificó un nombre de fichero de pruebas
if [ $# -eq 1 ]; then
    for test_file in *"$test_file"; do
        ./$(basename $test_file)
    done
fi
