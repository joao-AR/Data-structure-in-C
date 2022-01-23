t1:
	gcc -c parametros.c -o parametros
	gcc -c abrir_input.c -o abrir_input
	gcc -c pilha.c -o pilha
	gcc -c lista.c -o lista
	gcc -c fila.c -o fila
	gcc -c geo.c -o geo
	gcc -c svg.c -o svg
	gcc -c qry.c -o qry
	gcc -c formas.c -o formas
	gcc main.c ./parametros ./abrir_input ./pilha ./lista ./fila ./geo ./svg ./qry ./formas -o t1 -lm -fstack-protector-all -std=c99

clean:
	rm ./parametros ./abrir_input ./pilha ./lista ./fila ./geo ./svg ./qry ./formas ./t1