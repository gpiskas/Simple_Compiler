* binops.tm
* Standard prelude:
  0:     LD  6,0(0)     load maxaddress from location 0
  1:     ST  0,0(0)     clear location 0
* End of standard prelude.
  2:     ST  0,1(5)     Declaration
  3:     ST  0,2(5)     Declaration
  4:     ST  0,3(5)     Declaration
  5:     ST  0,4(5)     Declaration
  6:     ST  0,5(5)     Declaration
  7:     ST  0,6(5)     Declaration
  8:     ST  0,7(5)     Declaration
  9:     ST  0,8(5)     Declaration
 10:     ST  0,9(5)     Declaration
 11:     ST  0,10(5)     Declaration
 12:     ST  0,11(5)     Declaration
 13:     ST  0,12(5)     Declaration
 14:     ST  0,13(5)     Declaration
 15:     ST  0,14(5)     Declaration
 16:     ST  0,15(5)     Declaration
 17:     ST  0,16(5)     Declaration
 18:     ST  0,17(5)     Declaration
 19:    LDC  0,2(0)     Load INT
 20:     ST  0,9(5)     Assignment
 21:    LDC  0,5(0)     Load INT
 22:     ST  0,10(5)     Assignment
 23:    LDC  0,10(0)     Load INT
 24:     ST  0,11(5)     Assignment
 25:    LDC  0,10(0)     Load INT
 26:     ST  0,12(5)     Assignment
 27:    LDC  0,5(0)     Load INT
 28:     ST  0,13(5)     Assignment
 29:     LD  0,9(5)     Load ID
 30:     ST  0,0(6)     Save Temp
 31:     LD  0,10(5)     Load ID
 32:     LD  1,0(6)     Load Temp
 33:    ADD  0,1,0      Execute Binary +
 34:     ST  0,17(5)     Assignment
 35:     LD  0,17(5)     Load ID
 36:    OUT  0,0,0      Write
 37:     LD  0,9(5)     Load ID
 38:     ST  0,0(6)     Save Temp
 39:     LD  0,10(5)     Load ID
 40:     LD  1,0(6)     Load Temp
 41:    SUB  0,1,0      Execute Binary -
 42:     ST  0,17(5)     Assignment
 43:     LD  0,17(5)     Load ID
 44:    OUT  0,0,0      Write
 45:     LD  0,9(5)     Load ID
 46:    LDC  1,-1(0)     Apply Unary -
 47:    MUL  0,1,0      |
 48:     ST  0,0(6)     Save Temp
 49:     LD  0,10(5)     Load ID
 50:     LD  1,0(6)     Load Temp
 51:    SUB  0,1,0      Execute Binary -
 52:     ST  0,17(5)     Assignment
 53:     LD  0,17(5)     Load ID
 54:    OUT  0,0,0      Write
 55:     LD  0,11(5)     Load ID
 56:     ST  0,0(6)     Save Temp
 57:     LD  0,10(5)     Load ID
 58:     LD  1,0(6)     Load Temp
 59:    DIV  0,1,0      Execute Binary /
 60:     ST  0,17(5)     Assignment
 61:     LD  0,17(5)     Load ID
 62:    OUT  0,0,0      Write
 63:     LD  0,11(5)     Load ID
 64:     ST  0,0(6)     Save Temp
 65:     LD  0,10(5)     Load ID
 66:     LD  1,0(6)     Load Temp
 67:    MUL  0,1,0      Execute Binary *
 68:     ST  0,17(5)     Assignment
 69:     LD  0,17(5)     Load ID
 70:    OUT  0,0,0      Write
 71:     LD  0,9(5)     Load ID
 72:     ST  0,0(6)     Save Temp
 73:    LDC  0,10(0)     Load INT
 74:     LD  1,0(6)     Load Temp
 75:    SUB  0,1,0      Execute Binary <
 76:    JLT  0,2(7)     |
 77:    LDC  0,0(0)     |
 78:    LDA  7,1(7)     |
 79:    LDC  0,1(0)     |
 80:    OUT  0,0,0      Write
 81:     LD  0,9(5)     Load ID
 82:     ST  0,0(6)     Save Temp
 83:     LD  0,9(5)     Load ID
 84:     LD  1,0(6)     Load Temp
 85:    SUB  0,1,0      Execute Binary <=
 86:    JLE  0,2(7)     |
 87:    LDC  0,0(0)     |
 88:    LDA  7,1(7)     |
 89:    LDC  0,1(0)     |
 90:    OUT  0,0,0      Write
 91:     LD  0,11(5)     Load ID
 92:     ST  0,0(6)     Save Temp
 93:     LD  0,9(5)     Load ID
 94:     LD  1,0(6)     Load Temp
 95:    SUB  0,1,0      Execute Binary >
 96:    JGT  0,2(7)     |
 97:    LDC  0,0(0)     |
 98:    LDA  7,1(7)     |
 99:    LDC  0,1(0)     |
100:    OUT  0,0,0      Write
101:     LD  0,11(5)     Load ID
102:     ST  0,0(6)     Save Temp
103:     LD  0,12(5)     Load ID
104:     LD  1,0(6)     Load Temp
105:    SUB  0,1,0      Execute Binary <=
106:    JLE  0,2(7)     |
107:    LDC  0,0(0)     |
108:    LDA  7,1(7)     |
109:    LDC  0,1(0)     |
110:    OUT  0,0,0      Write
111:    LDC  0,123(0)     Load INT
112:     ST  0,0(6)     Save Temp
113:    LDC  0,123(0)     Load INT
114:     LD  1,0(6)     Load Temp
115:    SUB  0,1,0      Execute Binary =
116:    JEQ  0,2(7)     |
117:    LDC  0,0(0)     |
118:    LDA  7,1(7)     |
119:    LDC  0,1(0)     |
120:    OUT  0,0,0      Write
121:     LD  0,11(5)     Load ID
122:     ST  0,0(6)     Save Temp
123:     LD  0,10(5)     Load ID
124:     LD  1,0(6)     Load Temp
125:    SUB  0,1,0      Execute Binary !=
126:    JNE  0,2(7)     |
127:    LDC  0,0(0)     |
128:    LDA  7,1(7)     |
129:    LDC  0,1(0)     |
130:    OUT  0,0,0      Write
* End of execution.
131:   HALT  0,0,0      
