* while.tm
* Standard prelude:
  0:     LD  6,0(0)     load maxaddress from location 0
  1:     ST  0,0(0)     clear location 0
* End of standard prelude.
  2:     ST  0,1(5)     Declaration
  3:     ST  0,2(5)     Declaration
  4:     ST  0,3(5)     Declaration
  5:    LDC  0,0(0)     Load INT
  6:     ST  0,1(5)     Assignment
  7:     LD  0,1(5)     Load ID
  8:     ST  0,0(6)     Save Temp
  9:    LDC  0,10(0)     Load INT
 10:     LD  1,0(6)     Load Temp
 11:    SUB  0,1,0      Execute Binary <
 12:    JLT  0,2(7)     |
 13:    LDC  0,0(0)     |
 14:    LDA  7,1(7)     |
 15:    LDC  0,1(0)     |
 17:     LD  0,1(5)     Load ID
 18:    OUT  0,0,0      Write
 19:     LD  0,1(5)     Load ID
 20:     ST  0,0(6)     Save Temp
 21:    LDC  0,1(0)     Load INT
 22:     LD  1,0(6)     Load Temp
 23:    ADD  0,1,0      Execute Binary +
 24:     ST  0,1(5)     Assignment
 25:    LDA  7,-19(7) 	Repeat WHILE
 16:    JEQ  0,9(7) 	Jump to ENDDO
 26:    LDC  0,101010101(0)     Load INT
 27:    OUT  0,0,0      Write
 28:     LD  0,1(5)     Load ID
 29:    OUT  0,0,0      Write
 30:    LDC  0,0(0)     Load INT
 31:     ST  0,1(5)     Assignment
 32:    LDC  0,0(0)     Load INT
 33:     ST  0,2(5)     Assignment
 34:     LD  0,1(5)     Load ID
 35:     ST  0,0(6)     Save Temp
 36:    LDC  0,10(0)     Load INT
 37:     LD  1,0(6)     Load Temp
 38:    SUB  0,1,0      Execute Binary <
 39:    JLT  0,2(7)     |
 40:    LDC  0,0(0)     |
 41:    LDA  7,1(7)     |
 42:    LDC  0,1(0)     |
 44:     LD  0,2(5)     Load ID
 45:     ST  0,0(6)     Save Temp
 46:    LDC  0,10(0)     Load INT
 47:     LD  1,0(6)     Load Temp
 48:    SUB  0,1,0      Execute Binary <
 49:    JLT  0,2(7)     |
 50:    LDC  0,0(0)     |
 51:    LDA  7,1(7)     |
 52:    LDC  0,1(0)     |
 54:     LD  0,3(5)     Load ID
 55:     ST  0,0(6)     Save Temp
 56:    LDC  0,1(0)     Load INT
 57:     LD  1,0(6)     Load Temp
 58:    ADD  0,1,0      Execute Binary +
 59:     ST  0,3(5)     Assignment
 60:     LD  0,2(5)     Load ID
 61:     ST  0,0(6)     Save Temp
 62:    LDC  0,1(0)     Load INT
 63:     LD  1,0(6)     Load Temp
 64:    ADD  0,1,0      Execute Binary +
 65:     ST  0,2(5)     Assignment
 66:    LDA  7,-23(7) 	Repeat WHILE
 53:    JEQ  0,13(7) 	Jump to ENDDO
 67:    LDC  0,0(0)     Load INT
 68:     ST  0,2(5)     Assignment
 69:     LD  0,1(5)     Load ID
 70:     ST  0,0(6)     Save Temp
 71:    LDC  0,1(0)     Load INT
 72:     LD  1,0(6)     Load Temp
 73:    ADD  0,1,0      Execute Binary +
 74:     ST  0,1(5)     Assignment
 75:    LDA  7,-42(7) 	Repeat WHILE
 43:    JEQ  0,32(7) 	Jump to ENDDO
 76:    LDC  0,101010101(0)     Load INT
 77:    OUT  0,0,0      Write
 78:     LD  0,3(5)     Load ID
 79:    OUT  0,0,0      Write
* End of execution.
 80:   HALT  0,0,0      
