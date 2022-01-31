
_main:

;Blue_Ara.c,4 :: 		void main()
;Blue_Ara.c,6 :: 		TRISD=0;
	CLRF        TRISD+0 
;Blue_Ara.c,7 :: 		Uart1_Init(9600);
	BSF         BAUDCON+0, 3, 0
	MOVLW       2
	MOVWF       SPBRGH+0 
	MOVLW       8
	MOVWF       SPBRG+0 
	BSF         TXSTA+0, 2, 0
	CALL        _UART1_Init+0, 0
;Blue_Ara.c,8 :: 		delay_ms(100);
	MOVLW       3
	MOVWF       R11, 0
	MOVLW       138
	MOVWF       R12, 0
	MOVLW       85
	MOVWF       R13, 0
L_main0:
	DECFSZ      R13, 1, 1
	BRA         L_main0
	DECFSZ      R12, 1, 1
	BRA         L_main0
	DECFSZ      R11, 1, 1
	BRA         L_main0
	NOP
	NOP
;Blue_Ara.c,11 :: 		while(1)
L_main1:
;Blue_Ara.c,13 :: 		if(Uart1_Data_Ready())
	CALL        _UART1_Data_Ready+0, 0
	MOVF        R0, 1 
	BTFSC       STATUS+0, 2 
	GOTO        L_main3
;Blue_Ara.c,15 :: 		registro=Uart1_Read();
	CALL        _UART1_Read+0, 0
	MOVF        R0, 0 
	MOVWF       _registro+0 
;Blue_Ara.c,16 :: 		if(registro== 'A')
	MOVF        R0, 0 
	XORLW       65
	BTFSS       STATUS+0, 2 
	GOTO        L_main4
;Blue_Ara.c,18 :: 		while(Uart1_Read()!='X')
L_main5:
	CALL        _UART1_Read+0, 0
	MOVF        R0, 0 
	XORLW       88
	BTFSC       STATUS+0, 2 
	GOTO        L_main6
;Blue_Ara.c,20 :: 		Portd.rd0=1;
	BSF         PORTD+0, 0 
;Blue_Ara.c,21 :: 		delay_ms(1000);
	MOVLW       26
	MOVWF       R11, 0
	MOVLW       94
	MOVWF       R12, 0
	MOVLW       110
	MOVWF       R13, 0
L_main7:
	DECFSZ      R13, 1, 1
	BRA         L_main7
	DECFSZ      R12, 1, 1
	BRA         L_main7
	DECFSZ      R11, 1, 1
	BRA         L_main7
	NOP
;Blue_Ara.c,22 :: 		Portd.rd0=0;
	BCF         PORTD+0, 0 
;Blue_Ara.c,23 :: 		delay_ms(1000);
	MOVLW       26
	MOVWF       R11, 0
	MOVLW       94
	MOVWF       R12, 0
	MOVLW       110
	MOVWF       R13, 0
L_main8:
	DECFSZ      R13, 1, 1
	BRA         L_main8
	DECFSZ      R12, 1, 1
	BRA         L_main8
	DECFSZ      R11, 1, 1
	BRA         L_main8
	NOP
;Blue_Ara.c,24 :: 		}
	GOTO        L_main5
L_main6:
;Blue_Ara.c,25 :: 		}
L_main4:
;Blue_Ara.c,26 :: 		if(registro== 'S')
	MOVF        _registro+0, 0 
	XORLW       83
	BTFSS       STATUS+0, 2 
	GOTO        L_main9
;Blue_Ara.c,28 :: 		while(Uart1_Read()!='X')
L_main10:
	CALL        _UART1_Read+0, 0
	MOVF        R0, 0 
	XORLW       88
	BTFSC       STATUS+0, 2 
	GOTO        L_main11
;Blue_Ara.c,30 :: 		Portd.rd1=1;
	BSF         PORTD+0, 1 
;Blue_Ara.c,31 :: 		delay_ms(1000);
	MOVLW       26
	MOVWF       R11, 0
	MOVLW       94
	MOVWF       R12, 0
	MOVLW       110
	MOVWF       R13, 0
L_main12:
	DECFSZ      R13, 1, 1
	BRA         L_main12
	DECFSZ      R12, 1, 1
	BRA         L_main12
	DECFSZ      R11, 1, 1
	BRA         L_main12
	NOP
;Blue_Ara.c,32 :: 		Portd.rd1=0;
	BCF         PORTD+0, 1 
;Blue_Ara.c,33 :: 		delay_ms(1000);
	MOVLW       26
	MOVWF       R11, 0
	MOVLW       94
	MOVWF       R12, 0
	MOVLW       110
	MOVWF       R13, 0
L_main13:
	DECFSZ      R13, 1, 1
	BRA         L_main13
	DECFSZ      R12, 1, 1
	BRA         L_main13
	DECFSZ      R11, 1, 1
	BRA         L_main13
	NOP
;Blue_Ara.c,34 :: 		}
	GOTO        L_main10
L_main11:
;Blue_Ara.c,35 :: 		}
L_main9:
;Blue_Ara.c,36 :: 		if(registro== 'D')
	MOVF        _registro+0, 0 
	XORLW       68
	BTFSS       STATUS+0, 2 
	GOTO        L_main14
;Blue_Ara.c,38 :: 		while(Uart1_Read()!='X')
L_main15:
	CALL        _UART1_Read+0, 0
	MOVF        R0, 0 
	XORLW       88
	BTFSC       STATUS+0, 2 
	GOTO        L_main16
;Blue_Ara.c,40 :: 		Portd.rd2=1;
	BSF         PORTD+0, 2 
;Blue_Ara.c,41 :: 		delay_ms(1000);
	MOVLW       26
	MOVWF       R11, 0
	MOVLW       94
	MOVWF       R12, 0
	MOVLW       110
	MOVWF       R13, 0
L_main17:
	DECFSZ      R13, 1, 1
	BRA         L_main17
	DECFSZ      R12, 1, 1
	BRA         L_main17
	DECFSZ      R11, 1, 1
	BRA         L_main17
	NOP
;Blue_Ara.c,42 :: 		Portd.rd2=0;
	BCF         PORTD+0, 2 
;Blue_Ara.c,43 :: 		delay_ms(1000);
	MOVLW       26
	MOVWF       R11, 0
	MOVLW       94
	MOVWF       R12, 0
	MOVLW       110
	MOVWF       R13, 0
L_main18:
	DECFSZ      R13, 1, 1
	BRA         L_main18
	DECFSZ      R12, 1, 1
	BRA         L_main18
	DECFSZ      R11, 1, 1
	BRA         L_main18
	NOP
;Blue_Ara.c,44 :: 		}
	GOTO        L_main15
L_main16:
;Blue_Ara.c,45 :: 		}
L_main14:
;Blue_Ara.c,46 :: 		if(registro== 'W')
	MOVF        _registro+0, 0 
	XORLW       87
	BTFSS       STATUS+0, 2 
	GOTO        L_main19
;Blue_Ara.c,48 :: 		while(Uart1_Read()!='X')
L_main20:
	CALL        _UART1_Read+0, 0
	MOVF        R0, 0 
	XORLW       88
	BTFSC       STATUS+0, 2 
	GOTO        L_main21
;Blue_Ara.c,50 :: 		Portd.rd3=1;
	BSF         PORTD+0, 3 
;Blue_Ara.c,51 :: 		delay_ms(1000);
	MOVLW       26
	MOVWF       R11, 0
	MOVLW       94
	MOVWF       R12, 0
	MOVLW       110
	MOVWF       R13, 0
L_main22:
	DECFSZ      R13, 1, 1
	BRA         L_main22
	DECFSZ      R12, 1, 1
	BRA         L_main22
	DECFSZ      R11, 1, 1
	BRA         L_main22
	NOP
;Blue_Ara.c,52 :: 		Portd.rd3=0;
	BCF         PORTD+0, 3 
;Blue_Ara.c,53 :: 		delay_ms(1000);
	MOVLW       26
	MOVWF       R11, 0
	MOVLW       94
	MOVWF       R12, 0
	MOVLW       110
	MOVWF       R13, 0
L_main23:
	DECFSZ      R13, 1, 1
	BRA         L_main23
	DECFSZ      R12, 1, 1
	BRA         L_main23
	DECFSZ      R11, 1, 1
	BRA         L_main23
	NOP
;Blue_Ara.c,54 :: 		}
	GOTO        L_main20
L_main21:
;Blue_Ara.c,55 :: 		}
L_main19:
;Blue_Ara.c,56 :: 		if(registro== 'P')
	MOVF        _registro+0, 0 
	XORLW       80
	BTFSS       STATUS+0, 2 
	GOTO        L_main24
;Blue_Ara.c,58 :: 		Portd.rd4=1;
	BSF         PORTD+0, 4 
;Blue_Ara.c,59 :: 		delay_ms(1000);
	MOVLW       26
	MOVWF       R11, 0
	MOVLW       94
	MOVWF       R12, 0
	MOVLW       110
	MOVWF       R13, 0
L_main25:
	DECFSZ      R13, 1, 1
	BRA         L_main25
	DECFSZ      R12, 1, 1
	BRA         L_main25
	DECFSZ      R11, 1, 1
	BRA         L_main25
	NOP
;Blue_Ara.c,60 :: 		Portd.rd4=0;
	BCF         PORTD+0, 4 
;Blue_Ara.c,61 :: 		delay_ms(1000);
	MOVLW       26
	MOVWF       R11, 0
	MOVLW       94
	MOVWF       R12, 0
	MOVLW       110
	MOVWF       R13, 0
L_main26:
	DECFSZ      R13, 1, 1
	BRA         L_main26
	DECFSZ      R12, 1, 1
	BRA         L_main26
	DECFSZ      R11, 1, 1
	BRA         L_main26
	NOP
;Blue_Ara.c,62 :: 		}
L_main24:
;Blue_Ara.c,63 :: 		if(registro== 'R')
	MOVF        _registro+0, 0 
	XORLW       82
	BTFSS       STATUS+0, 2 
	GOTO        L_main27
;Blue_Ara.c,65 :: 		Portd.rd5=1;
	BSF         PORTD+0, 5 
;Blue_Ara.c,66 :: 		delay_ms(1000);
	MOVLW       26
	MOVWF       R11, 0
	MOVLW       94
	MOVWF       R12, 0
	MOVLW       110
	MOVWF       R13, 0
L_main28:
	DECFSZ      R13, 1, 1
	BRA         L_main28
	DECFSZ      R12, 1, 1
	BRA         L_main28
	DECFSZ      R11, 1, 1
	BRA         L_main28
	NOP
;Blue_Ara.c,67 :: 		Portd.rd5=0;
	BCF         PORTD+0, 5 
;Blue_Ara.c,68 :: 		delay_ms(1000);
	MOVLW       26
	MOVWF       R11, 0
	MOVLW       94
	MOVWF       R12, 0
	MOVLW       110
	MOVWF       R13, 0
L_main29:
	DECFSZ      R13, 1, 1
	BRA         L_main29
	DECFSZ      R12, 1, 1
	BRA         L_main29
	DECFSZ      R11, 1, 1
	BRA         L_main29
	NOP
;Blue_Ara.c,69 :: 		}
L_main27:
;Blue_Ara.c,70 :: 		}
L_main3:
;Blue_Ara.c,71 :: 		}
	GOTO        L_main1
;Blue_Ara.c,72 :: 		}
L_end_main:
	GOTO        $+0
; end of _main
