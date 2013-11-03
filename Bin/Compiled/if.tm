* if.tm
* Standard prelude:
  0:     LD  6,0(0)     load maxaddress from location 0
  1:     ST  0,0(0)     clear location 0
* End of standard prelude.
  2:     ST  0,1(5)     Declaration
  3:    LDC  0,4(0)     Load INT
  4:     ST  0,1(5)     Assignment
  5:     LD  0,1(5)     Load ID
  6:     ST  0,0(6)     Save Temp
  7:    LDC  0,10(0)     Load INT
  8:     LD  1,0(6)     Load Temp
  9:    SUB  0,1,0      Execute Binary <
 10:    JLT  0,2(7)     |
 11:    LDC  0,0(0)     |
 12:    LDA  7,1(7)     |
 13:    LDC  0,1(0)     |
 15:    LDC  0,1(0)     Load INT
 16:    OUT  0,0,0      Write
 14:    JEQ  0,3(7) 	Execute ELSE
 18:    LDC  0,0(0)     Load INT
 19:    OUT  0,0,0      Write
 17:    LDA  7,2(7) 	Jump to ENDIF after THEN
 20:     LD  0,1(5)     Load ID
 21:     ST  0,0(6)     Save Temp
 22:    LDC  0,10(0)     Load INT
 23:     LD  1,0(6)     Load Temp
 24:    SUB  0,1,0      Execute Binary >
 25:    JGT  0,2(7)     |
 26:    LDC  0,0(0)     |
 27:    LDA  7,1(7)     |
 28:    LDC  0,1(0)     |
 30:    LDC  0,0(0)     Load INT
 31:    OUT  0,0,0      Write
 29:    JEQ  0,3(7) 	Execute ELSE
 33:    LDC  0,1(0)     Load INT
 34:    OUT  0,0,0      Write
 32:    LDA  7,2(7) 	Jump to ENDIF after THEN
 35:     LD  0,1(5)     Load ID
 36:     ST  0,0(6)     Save Temp
 37:    LDC  0,4(0)     Load INT
 38:     LD  1,0(6)     Load Temp
 39:    SUB  0,1,0      Execute Binary <=
 40:    JLE  0,2(7)     |
 41:    LDC  0,0(0)     |
 42:    LDA  7,1(7)     |
 43:    LDC  0,1(0)     |
 45:    LDC  0,1(0)     Load INT
 46:    OUT  0,0,0      Write
 44:    JEQ  0,3(7) 	Execute ELSE
 48:    LDC  0,0(0)     Load INT
 49:    OUT  0,0,0      Write
 47:    LDA  7,2(7) 	Jump to ENDIF after THEN
 50:     LD  0,1(5)     Load ID
 51:     ST  0,0(6)     Save Temp
 52:    LDC  0,4(0)     Load INT
 53:     LD  1,0(6)     Load Temp
 54:    SUB  0,1,0      Execute Binary >=
 55:    JGE  0,2(7)     |
 56:    LDC  0,0(0)     |
 57:    LDA  7,1(7)     |
 58:    LDC  0,1(0)     |
 60:    LDC  0,1(0)     Load INT
 61:    OUT  0,0,0      Write
 59:    JEQ  0,3(7) 	Execute ELSE
 63:    LDC  0,0(0)     Load INT
 64:    OUT  0,0,0      Write
 62:    LDA  7,2(7) 	Jump to ENDIF after THEN
 65:     LD  0,1(5)     Load ID
 66:     ST  0,0(6)     Save Temp
 67:    LDC  0,4(0)     Load INT
 68:     LD  1,0(6)     Load Temp
 69:    SUB  0,1,0      Execute Binary =
 70:    JEQ  0,2(7)     |
 71:    LDC  0,0(0)     |
 72:    LDA  7,1(7)     |
 73:    LDC  0,1(0)     |
 75:    LDC  0,1(0)     Load INT
 76:    OUT  0,0,0      Write
 74:    JEQ  0,3(7) 	Execute ELSE
 78:    LDC  0,0(0)     Load INT
 79:    OUT  0,0,0      Write
 77:    LDA  7,2(7) 	Jump to ENDIF after THEN
 80:     LD  0,1(5)     Load ID
 81:     ST  0,0(6)     Save Temp
 82:    LDC  0,4(0)     Load INT
 83:     LD  1,0(6)     Load Temp
 84:    SUB  0,1,0      Execute Binary !=
 85:    JNE  0,2(7)     |
 86:    LDC  0,0(0)     |
 87:    LDA  7,1(7)     |
 88:    LDC  0,1(0)     |
 90:    LDC  0,0(0)     Load INT
 91:    OUT  0,0,0      Write
 89:    JEQ  0,3(7) 	Execute ELSE
 93:    LDC  0,1(0)     Load INT
 94:    OUT  0,0,0      Write
 92:    LDA  7,2(7) 	Jump to ENDIF after THEN
 95:     LD  0,1(5)     Load ID
 96:     ST  0,0(6)     Save Temp
 97:    LDC  0,4(0)     Load INT
 98:     LD  1,0(6)     Load Temp
 99:    SUB  0,1,0      Execute Binary =
100:    JEQ  0,2(7)     |
101:    LDC  0,0(0)     |
102:    LDA  7,1(7)     |
103:    LDC  0,1(0)     |
105:    LDC  0,1337(0)     Load INT
106:    OUT  0,0,0      Write
104:    JEQ  0,3(7) 	Execute ELSE
107:    LDA  7,0(7) 	Jump to ENDIF after THEN
* End of execution.
108:   HALT  0,0,0      
