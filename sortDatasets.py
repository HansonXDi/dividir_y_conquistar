import random 

# crea un arreglo de tamaño 10^6 con números aleatorios
# entre 0 y 10^n
def datasetAleatorio(n):
    lista = []
    for i in range(10**n):
        lista.append(random.randint(0, 10**6))
    with open('datasetSort.txt', 'w') as archivo:
        for elemento in lista:
            archivo.write(str(elemento) + "\n")

# crea un dataset ordenado (de menor a mayor)
def datasetOrdenado(n):
    lista = []
    for i in range(10**n):
        lista.append(i)
    with open('datasetSort.txt', 'w') as archivo:
        for elemento in lista:
            archivo.write(str(elemento) + "\n")

# crea un dataset ordenado al reves (de mayor a menor)
def datasetInverso(n):
    lista = []
    for i in range(10**n):
        lista.append(10**n - i)
    with open('datasetSort.txt', 'w') as archivo:
        for elemento in lista:
            archivo.write(str(elemento) + "\n")

# crea un dataset ordenado hasta la mitad y luego desordenado
def datasetSemiOrdenado(n):
    lista = []
    for i in range(10**n):
        if i < 10**(n-1):
            lista.append(i)
        else:
            lista.append(random.randint(0, 10**6))
    with open('datasetSort.txt', 'w') as archivo:
        for elemento in lista:
            archivo.write(str(elemento) + "\n")

opcion = input("Ingrese el tipo de dataset que desea crear:\n1. Aleatorio\n2. Ordenado\n3. Ordenado al reves\n4. Semi ordenado\n")
n = int(input("Ingrese la potencia de 10 del tamaño del arreglo a generar: 10^"))
if opcion == '1':
    datasetAleatorio(n)
elif opcion == '2':
    datasetOrdenado(n)
elif opcion == '3':
    datasetInverso(n)
elif opcion == '4':
    datasetSemiOrdenado(n)