import random 

# genera dos matrices cuadradas de tamaño 2^n
# rellenas de números aleatorios entre 0 y 1000
def datasetStrassen(n):
    filas = 2**n
    filas_columnas = filas
    columnas = filas

    matriz1 = []
    for i in range(filas):
        fila = []
        for j in range(filas_columnas):
            fila.append(random.randint(0, 10**3))
        matriz1.append(fila)

    matriz2 = []
    for i in range(filas_columnas):
        fila = []
        for j in range(columnas):
            fila.append(random.randint(0, 10**3))
        matriz2.append(fila)
    # escribe las matrices en un archivo
    # con sus tamaños al inicio del archivo
    with open('datasetMatrix.txt', 'w') as archivo:
        archivo.write(str(filas) + " " + str(filas_columnas) + "\n")
        for fila in matriz1:
            for elemento in fila:
                archivo.write(str(elemento) + " ")
            archivo.write("\n")
        archivo.write(str(filas_columnas) + " " + str(columnas) + "\n")
        for fila in matriz2:
            for elemento in fila:
                archivo.write(str(elemento) + " ")
            archivo.write("\n")

# hace lo mismo que la funcion anterior pero con la posibilidad de
# hacer matrices rectangulares y cuadradas de cualquier orden, no 
# solo de orden 2^n
def datasetNormal(m, n, p, tipo):
    if tipo == '2':
        filas = n
        filas_columnas = n
        columnas = n
    elif tipo == '3':
        filas = m
        filas_columnas = n
        columnas = p
    
    matriz1 = []
    for i in range(filas):
        fila = []
        for j in range(filas_columnas):
            fila.append(random.randint(0, 10**3))
        matriz1.append(fila)

    matriz2 = []
    for i in range(filas_columnas):
        fila = []
        for j in range(columnas):
            fila.append(random.randint(0, 10**3))
        matriz2.append(fila)
    with open('datasetMatrix.txt', 'w') as archivo:
        archivo.write(str(filas) + " " + str(filas_columnas) + "\n")
        for fila in matriz1:
            for elemento in fila:
                archivo.write(str(elemento) + " ")
            archivo.write("\n")
        archivo.write(str(filas_columnas) + " " + str(columnas) + "\n")
        for fila in matriz2:
            for elemento in fila:
                archivo.write(str(elemento) + " ")
            archivo.write("\n")

opcion = input("¿Que dataset quiere generar? \n 1. Strassen (matrices cuadradas de orden 2^n) \n 2. Matrices cuadradas de orden n \n 3. Matrices rectangulares de orden mxn y nxp \n")
if opcion == '1':
    n = int(input("Ingrese el valor de n: "))
    datasetStrassen(n)
elif opcion == '2':
    n = int(input("Ingrese el valor de n: "))
    datasetNormal(1, n, 1, opcion)
elif opcion == '3':
    m = int(input("Ingrese el valor de m: "))
    n = int(input("Ingrese el valor de n: "))
    p = int(input("Ingrese el valor de p: "))
    datasetNormal(m, n, p, opcion)