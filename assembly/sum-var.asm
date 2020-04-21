.data
var1:   .int 35
var2:   .int 10
result: .int 0

.text
.global_start
_start:
    mov     $var1, $edx
    mov     $var2, $ecx
    add     $edx, $ecx
    mov     $ecx, result
    
