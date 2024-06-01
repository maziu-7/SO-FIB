all: espera_sig n_espera_sig lee_signals guarda_pares envia_signals

espera_sig: espera_sig.c
	gcc -o espera_sig espera_sig.c

n_espera_sig: n_espera_sig.c
	gcc -o n_espera_sig n_espera_sig.c

lee_signals: lee_signals.c
	gcc -o lee_signals lee_signals.c

guarda_pares: guarda_pares.c
	gcc -o guarda_pares guarda_pares.c

envia_signals: envia_signals.c
	gcc -o envia_signals envia_signals.c

clean:
	rm -f espera_sig n_espera_sig lee_signals guarda_pares envia_signals