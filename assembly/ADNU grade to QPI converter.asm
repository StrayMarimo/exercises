section .data
    numMsg db 'Numerical Grade: ', 0
    letterMsg db 0xa, 'Letter Grade: ', 0
    qpiMsg db 0xa, 'QPI: ', 0
    wrongMsg db 'Wrong input. Try again.', 0
    qpiGrade db '0', 0
    numGrade db '0', 0
    letterGrade db 'F', 0
    
section .bss
    buffer resb 4
section .text
    global _main
_main:

    ; read input as a string
    mov eax, 3           ; system call for read
    mov ebx, 0           ; file descriptor for stdin
    mov ecx, buffer      ; buffer to store input
    mov edx, 4           ; maximum number of bytes to read
    int 80h              ; call kernel

    ; convert string to integer
    xor ebx, ebx         ; clear ebx
    mov bl, byte [buffer] ; load first character of buffer to ebx
    sub ebx, '0'         ; convert character to integer
    cmp ebx, 0           ; check if it's a valid digit
    jl invalid_input     ; if not, jump to error message
    mov eax, ebx         ; initialize result with first digit
    mov ecx, 10          ; initialize divisor with 10
    mov esi, buffer      ; initialize index to second character
    
next_digit:
    inc esi              ; move to next character
    cmp byte [esi], 0    ; check if end of string
    je comp1        ; if yes, jump to input completed
    mov bl, byte [esi]   ; load next character to ebx
    sub bl, '0'          ; convert character to integer
    cmp bl, 0            ; check if it's a valid digit
    jl invalid_input     ; if not, jump to error message
    mul ecx              ; multiply result by 10
    add eax, ebx         ; add new digit to result
    jmp next_digit       ; continue with next digit

comp1:
    ; compare input to 100
    cmp eax, 100
    je num100     
    jmp comp2

comp2:
    cmp eax, 98
    jge num99
    jmp comp3

comp3:
    cmp eax, 96
    jge num98
    jmp comp4

comp4:
    cmp eax, 95
    jge num97
    jmp comp5
    
comp5:
    cmp eax, 93
    jge num96
    jmp comp6
    
comp6:
    cmp eax, 92
    jge num95
    jmp comp7

comp7:
    cmp eax, 90
    jge num94
    jmp comp8

comp8:
    cmp eax, 88
    jge num93
    jmp comp9

comp9:
    cmp eax, 87
    jge num92
    jmp comp10

comp10:
    cmp eax, 85
    jge num91
    jmp comp11

comp11:
    cmp eax, 84
    jge num90
    jmp comp12

comp12:
    cmp eax, 82
    jge num89
    jmp comp13

comp13:
    cmp eax, 80
    jge num88
    jmp comp14

comp14:
    cmp eax, 79
    jge num87
    jmp comp15

comp15:
    cmp eax, 78
    jge num86
    jmp comp16

comp16:
    cmp eax, 76
    jge num85
    jmp comp17

comp17:
    cmp eax, 74
    jge num84
    jmp comp18

comp18:
    cmp eax, 72
    jge num83
    jmp comp19

comp19:
    cmp eax, 71
    jge num82
    jmp comp20

comp20:
    cmp eax, 69
    jge num81
    jmp comp21

comp21:
    cmp eax, 68
    jge num80
    jmp comp22

comp22:
    cmp eax, 66
    jge num79
    jmp comp23

comp23:
    cmp eax, 65
    jge num78
    jmp comp24

comp24:
    cmp eax, 63
    jge num77
    jmp comp25

comp25:
    cmp eax, 61
    jge num76
    jmp comp26

comp26:
    cmp eax, 60
    jge num75
    jmp comp27

comp27:
    cmp eax, 50
    jge num74
    jmp comp28

comp28:
    cmp eax, 40
    jge num73
    jmp comp29

comp29:
    cmp eax, 30
    jge num72
    jmp comp30

comp30:
    cmp eax, 20
    jge num71
    jmp comp31

comp31:
    cmp eax, 0
    jge num70

invalid_input:
    ; display error message and exit
    mov eax, 4           ; system call for write
    mov ebx, 1           ; file descriptor for stdout
    mov ecx, wrongMsg    ; message to display
    mov edx, 23          ; message length
    int 80h              ; call kernel
    jmp exit

num100:
    mov dword [numGrade], "100"
    call dispNumGrade
    jmp setLetterGradeA
    
num99:
    mov dword [numGrade], "99"
    call dispNumGrade
    jmp setLetterGradeA
    
num98:
    mov dword [numGrade], "98"
    call dispNumGrade
    jmp setLetterGradeA

num97:
    mov dword [numGrade], "97"
    call dispNumGrade
    jmp setLetterGradeBP
    
num96:
    mov dword [numGrade], "96"
    call dispNumGrade
    jmp setLetterGradeBP

num95:
    mov dword [numGrade], "95"
    call dispNumGrade
    jmp setLetterGradeBP

num94:
    mov dword [numGrade], "94"
    call dispNumGrade
    jmp setLetterGradeBP

num93:
    mov dword [numGrade], "93"
    call dispNumGrade
    jmp setLetterGradeB

num92:
    mov dword [numGrade], "92"
    call dispNumGrade
    jmp setLetterGradeB

num91:
    mov dword [numGrade], "91"
    call dispNumGrade
    jmp setLetterGradeB

num90:
    mov dword [numGrade], "90"
    call dispNumGrade
    jmp setLetterGradeB

num89:
    mov dword [numGrade], "89"
    call dispNumGrade
    jmp setLetterGradeCP

num88:
    mov dword [numGrade], "88"
    call dispNumGrade
    jmp setLetterGradeCP

num87:
    mov dword [numGrade], "87"
    call dispNumGrade
    jmp setLetterGradeCP

num86:
    mov dword [numGrade], "86"
    call dispNumGrade
    jmp setLetterGradeCP

num85:
    mov dword [numGrade], "85"
    call dispNumGrade
    jmp setLetterGradeC

num84:
    mov dword [numGrade], "84"
    call dispNumGrade
    jmp setLetterGradeC

num83:
    mov dword [numGrade], "83"
    call dispNumGrade
    jmp setLetterGradeC

num82:
    mov dword [numGrade], "82"
    call dispNumGrade
    jmp setLetterGradeC

num81:
    mov dword [numGrade], "81"
    call dispNumGrade
    jmp setLetterGradeDP

num80:
    mov dword [numGrade], "80"
    call dispNumGrade
    jmp setLetterGradeDP

num79:
    mov dword [numGrade], "79"
    call dispNumGrade
    jmp setLetterGradeDP

num78:
    mov dword [numGrade], "78"
    call dispNumGrade
    jmp setLetterGradeDP

num77:
    mov dword [numGrade], "77"
    call dispNumGrade
    jmp setLetterGradeD

num76:
    mov dword [numGrade], "76"
    call dispNumGrade
    jmp setLetterGradeD

num75:
    mov dword [numGrade], "75"
    call dispNumGrade
    jmp setLetterGradeD

num74:
    mov dword [numGrade], "74"
    call dispNumGrade
    jmp setLetterGradeF

num73:
    mov dword [numGrade], "73"
    call dispNumGrade
    jmp setLetterGradeF

num72:
    mov dword [numGrade], "72"
    call dispNumGrade
    jmp setLetterGradeF

num71:
    mov dword [numGrade], "71"
    call dispNumGrade
    jmp setLetterGradeF

num70:
    mov dword [numGrade], "70"
    call dispNumGrade
    jmp setLetterGradeF

setLetterGradeA:
  mov dword [letterGrade], "A"
  call dispLetterGrade
  mov dword[qpiGrade], "4.00"
  jmp dispQPIGrade

setLetterGradeBP:
  mov dword [letterGrade], "B+"
  call dispLetterGrade
  mov dword[qpiGrade], "3.50"
  jmp dispQPIGrade

setLetterGradeB:
  mov dword [letterGrade], "B"
  call dispLetterGrade
  mov dword[qpiGrade], "3.00"
  jmp dispQPIGrade

setLetterGradeCP:
  mov dword [letterGrade], "C+"
  call dispLetterGrade
  mov dword[qpiGrade], "2.50"
  jmp dispQPIGrade

setLetterGradeC:
  mov dword [letterGrade], "C"
  call dispLetterGrade
  mov dword[qpiGrade], "2.00"
  jmp dispQPIGrade

setLetterGradeDP:
  mov dword [letterGrade], "D+"
  call dispLetterGrade
  mov dword[qpiGrade], "1.50"
  jmp dispQPIGrade

setLetterGradeD:
  mov dword [letterGrade], "D"
  call dispLetterGrade
  mov dword[qpiGrade], "1.00"
  jmp dispQPIGrade

setLetterGradeF:
  mov dword [letterGrade], "F"
  call dispLetterGrade
  mov dword[qpiGrade], "0.00"
  jmp dispQPIGrade

dispNumGrade:
    ; display numerical grade message 
    mov eax, 4           ; system call for write
    mov ebx, 1           ; file descriptor for stdout
    mov ecx, numMsg  ; message to display
    mov edx, 17         ; message length
    int 80h              ; call kernel
   
    ; display numerical grade
    mov eax, 4           ; system call for write
    mov ebx, 1           ; file descriptor for stdout
    mov ecx, numGrade  ; message to display
    mov edx, 5          ; message length
    int 80h              ; call kernel
    
    ret
    
dispLetterGrade:
   
     ; display letter grade message
    mov eax, 4           ; system call for write
    mov ebx, 1           ; file descriptor for stdout
    mov ecx, letterMsg  ; message to display
    mov edx, 15         ; message length
    int 80h              ; call kernel
   
    ; display letter grade
    mov eax, 4           ; system call for write
    mov ebx, 1           ; file descriptor for stdout
    mov ecx, letterGrade  ; message to display
    mov edx, 3          ; message length
    int 80h              ; call kernel

    ret
    
    
dispQPIGrade:
   
     ; display success message and exit
    mov eax, 4           ; system call for write
    mov ebx, 1           ; file descriptor for stdout
    mov ecx, qpiMsg  ; message to display
    mov edx, 6         ; message length
    int 80h              ; call kernel
   
    ; display success message and exit
    mov eax, 4           ; system call for write
    mov ebx, 1           ; file descriptor for stdout
    mov ecx, qpiGrade  ; message to display
    mov edx, 4          ; message length
    int 80h              ; call kernel
    
    jmp exit
        
exit:
    mov eax, 1           ; system call for exit
    xor ebx, ebx         ; return 0
    int 80h              ; call kernel
