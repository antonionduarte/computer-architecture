# pseudoconstantes
EXIT = 1
LINUX_SYSCALL = 0x80

.data
vetor: .int 1, 2, 5, 7 ,8, 5 # um vetor de inteiros
len = (. - vetor) / 4

# explicando a len, basicamente vetor é a primeira posição do vetor, e len é a última (o ponto corrente)
# fazendo a sua subtração obtemos o tamanho em Bytes dos vetor, para obtermos a length do vetor
# realizamos a sua divisão por quatro (pois cada inteiro ocupada 4 bytes)
