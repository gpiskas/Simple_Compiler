* binopscomplex.tm
* Standard prelude:
  0:     LD  6,0(0)     load maxaddress from location 0
  1:     ST  0,0(0)     clear location 0
* End of standard prelude.
  2:     ST  0,1(5)     Declaration
  3:     ST  0,2(5)     Declaration
  4:     ST  0,3(5)     Declaration
  5:     ST  0,4(5)     Declaration
  6:     ST  0,5(5)     Declaration
  7:    LDC  0,2(0)     Load INT
  8:     ST  0,1(5)     Assignment
  9:    LDC  0,5(0)     Load INT
 10:     ST  0,2(5)     Assignment
 11:    LDC  0,10(0)     Load INT
 12:     ST  0,3(5)     Assignment
 13:    LDC  0,10(0)     Load INT
 14:    LDC  1,-1(0)     Apply Unary -
 15:    MUL  0,1,0      |
 16:     ST  0,4(5)     Assignment
 17:    LDC  0,1(0)     Load INT
 18:    LDC  1,-1(0)     Apply Unary -
 19:    MUL  0,1,0      |
 20:     ST  0,5(5)     Assignment
 21:     LD  0,3(5)     Load ID
 22:     ST  0,0(6)     Save Temp
 23:    LDC  0,10(0)     Load INT
 24:     LD  1,0(6)     Load Temp
 25:    DIV  0,1,0      Execute Binary /
 26:     ST  0,0(6)     Save Temp
 27:     LD  0,2(5)     Load ID
 28:     LD  1,0(6)     Load Temp
 29:    ADD  0,1,0      Execute Binary +
 30:     ST  0,0(6)     Save Temp
 31:     LD  0,4(5)     Load ID
 32:     ST  0,-1(6)     Save Temp
 33:     LD  0,5(5)     Load ID
 34:     LD  1,-1(6)     Load Temp
 35:    MUL  0,1,0      Execute Binary *
 36:     ST  0,-1(6)     Save Temp
 37:     LD  0,3(5)     Load ID
 38:     ST  0,-2(6)     Save Temp
 39:    LDC  0,12(0)     Load INT
 40:     LD  1,-2(6)     Load Temp
 41:    ADD  0,1,0      Execute Binary +
 42:     LD  1,-1(6)     Load Temp
 43:    MUL  0,1,0      Execute Binary *
 44:     LD  1,0(6)     Load Temp
 45:    SUB  0,1,0      Execute Binary -
 46:    OUT  0,0,0      Write
 47:     LD  0,1(5)     Load ID
 48:     ST  0,0(6)     Save Temp
 49:     LD  0,3(5)     Load ID
 50:     ST  0,-1(6)     Save Temp
 51:     LD  0,2(5)     Load ID
 52:     LD  1,-1(6)     Load Temp
 53:    ADD  0,1,0      Execute Binary +
 54:     ST  0,-1(6)     Save Temp
 55:     LD  0,1(5)     Load ID
 56:     ST  0,-2(6)     Save Temp
 57:     LD  0,1(5)     Load ID
 58:     LD  1,-2(6)     Load Temp
 59:    MUL  0,1,0      Execute Binary *
 60:     LD  1,-1(6)     Load Temp
 61:    SUB  0,1,0      Execute Binary -
 62:     LD  1,0(6)     Load Temp
 63:    MUL  0,1,0      Execute Binary *
 64:     ST  0,0(6)     Save Temp
 65:    LDC  0,1(0)     Load INT
 66:    LDC  1,-1(0)     Apply Unary -
 67:    MUL  0,1,0      |
 68:     LD  1,0(6)     Load Temp
 69:    MUL  0,1,0      Execute Binary *
 70:    OUT  0,0,0      Write
 71:     LD  0,4(5)     Load ID
 72:    LDC  1,-1(0)     Apply Unary -
 73:    MUL  0,1,0      |
 74:     ST  0,0(6)     Save Temp
 75:     LD  0,5(5)     Load ID
 76:    LDC  1,-1(0)     Apply Unary -
 77:    MUL  0,1,0      |
 78:     LD  1,0(6)     Load Temp
 79:    MUL  0,1,0      Execute Binary *
 80:     ST  0,0(6)     Save Temp
 81:     LD  0,3(5)     Load ID
 82:     LD  1,0(6)     Load Temp
 83:    MUL  0,1,0      Execute Binary *
 84:     ST  0,0(6)     Save Temp
 85:     LD  0,2(5)     Load ID
 86:     LD  1,0(6)     Load Temp
 87:    MUL  0,1,0      Execute Binary *
 88:     ST  0,0(6)     Save Temp
 89:     LD  0,1(5)     Load ID
 90:     LD  1,0(6)     Load Temp
 91:    MUL  0,1,0      Execute Binary *
 92:    OUT  0,0,0      Write
 93:     LD  0,1(5)     Load ID
 94:     ST  0,0(6)     Save Temp
 95:     LD  0,2(5)     Load ID
 96:     LD  1,0(6)     Load Temp
 97:    ADD  0,1,0      Execute Binary +
 98:     ST  0,0(6)     Save Temp
 99:     LD  0,3(5)     Load ID
100:     LD  1,0(6)     Load Temp
101:    ADD  0,1,0      Execute Binary +
102:     ST  0,0(6)     Save Temp
103:     LD  0,4(5)     Load ID
104:     LD  1,0(6)     Load Temp
105:    ADD  0,1,0      Execute Binary +
106:     ST  0,0(6)     Save Temp
107:     LD  0,5(5)     Load ID
108:     LD  1,0(6)     Load Temp
109:    ADD  0,1,0      Execute Binary +
110:    OUT  0,0,0      Write
111:     LD  0,1(5)     Load ID
112:     ST  0,0(6)     Save Temp
113:     LD  0,2(5)     Load ID
114:     LD  1,0(6)     Load Temp
115:    MUL  0,1,0      Execute Binary *
116:     ST  0,0(6)     Save Temp
117:     LD  0,3(5)     Load ID
118:    LDC  1,-1(0)     Apply Unary -
119:    MUL  0,1,0      |
120:     ST  0,-1(6)     Save Temp
121:     LD  0,4(5)     Load ID
122:     LD  1,-1(6)     Load Temp
123:    ADD  0,1,0      Execute Binary +
124:     LD  1,0(6)     Load Temp
125:    DIV  0,1,0      Execute Binary /
126:     ST  0,0(6)     Save Temp
127:     LD  0,5(5)     Load ID
128:     LD  1,0(6)     Load Temp
129:    ADD  0,1,0      Execute Binary +
130:    OUT  0,0,0      Write
* End of execution.
131:   HALT  0,0,0      
