mov instruction
mov ax, 0x05
- move to register ax #5 (0x05)

(0x01 OR ax)
0000 0001 - mov instruction, if rightmost bit is 1
- 0000 0011 - ax register
- 0000 0101 - bx register
- 0000 0111 - cx register
- 0000 1001 - dx register
- 0000 1011 - stack pointer

mov ax,0x05 - (0x01 OR 0x02) - for ax register since ax register will be 0x02 (0000 0010)