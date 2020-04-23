# pseudoconstantes
EXIT = 1
LINUX_SYSCALL = 0x80

# notas:
# - a utilização de "$" é para aceder diretamente ao elemento que colocamos a seguir
#   quando colocamos uma constante ou um número diretamente, estamos a aceder obviamente a essa constante ou número
#   pode ficar confuso quando colocamos uma variável, para isso relembrar que as variáveis guardam realmente um
#   ENDEREÇO de MEMÓRIA, portanto quando colocamos o "$" antes estamos na verdade a aceder diretamente ao endereço de memória
#
# - a utilização de "()" é para aceder ao CONTEÚDO que está num determinado ENDEREÇO de MEMÓRIA
#   é tal como se desreferenciássemos um pointer em C

.data
vetor: .int 1, 2, 5, 7 ,8, 5 # um vetor de inteiros
LEN = (. - vetor) / 4 # comprimento do vetor (notar que está a maíscula pois é uma constante)

resultado: .int 0 # variável onde é guardado o comprimento do vetor

# explicando a constante LEN, basicamente "vetor" é a primeira posição do vetor, e "." é a última (o ponto corrente)
# fazendo a sua subtração ". - vetor" obtemos o tamanho em Bytes do vetor, logo, para obtermos o comprimento do vetor
# realizamos a sua divisão por quatro (pois cada inteiro ocupada 4 Bytes)

.text # secção de código
.global _start
_start:
    mov $vetor, %eax # movemos o vetor em si (endereço de memória) e não o conteúdo do vetor
    mov (%eax), %ebx # agora movemos o conteúdo de %eax usando "()" para ebx
                     # esse conteúdo será o valor do primeiro elemento do vetor (%ebx é onde guardamos a soma)
    mov $LEN, %ecx # guardar o LEN (comprimento do vetor) no registo %ecx 
ciclo:
    dec %ecx
    jz fim
    add $4, %eax # aumentar em 4 bytes ebx, indo portanto para o próximo inteiro
    add (%eax), %ebx # somar o conteúdo do próximo elemento do vetor a %ebx
    jmp ciclo # saltar de novo para o inicio do ciclo
fim:
    mov  %ebx, soma # guardar o resultado na variável "soma"

    mov $0, %ebx
    mov $EXIT, %eax
    int $LINUX_SYSCALL, %eax
