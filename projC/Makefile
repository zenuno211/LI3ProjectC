cc = gcc
CFLAGS = -Wall -ansi -g -o
PKG = -I/usr/include/glib-2.0 -I/usr/lib/x86_64-linux-gnu/glib-2.0/include -lglib-2.0
INC_P = include/
SRC_P = src/


program: main.o cliente.o produto.o produtos.o venda.o clientes.o faturacaoP.o faturacaoGlobal.o SGV.o viewQueries.o controllerQueries.o controller.o view.o filial.o filiais.o queryStructs.o
			$(cc) $(CFLAGS) program main.o cliente.o produto.o produtos.o venda.o clientes.o faturacaoP.o faturacaoGlobal.o SGV.o viewQueries.o controllerQueries.o controller.o view.o filial.o filiais.o queryStructs.o $(PKG)

main.o: $(SRC_P)main.c $(INC_P)produtos.h $(INC_P)venda.h $(INC_P)clientes.h $(INC_P)faturacaoP.h $(INC_P)faturacaoGlobal.h $(INC_P)filial.h $(INC_P)filiais.h
			@echo "Compiling main"
			$(cc) $(PKG) -c $(SRC_P)main.c 

SGV.o: $(SRC_P)SGV.c $(INC_P)SGV.h $(INC_P)produtos.h $(INC_P)clientes.h $(INC_P)faturacaoGlobal.h $(INC_P)venda.h $(INC_P)filial.h $(INC_P)filiais.h $(INC_P)queryStructs.h
			@echo "A compilar SGV"
			$(cc) $(PKG) -c $(SRC_P)SGV.c

queryStructs.o: $(SRC_P)queryStructs.c $(INC_P)queryStructs.h
			@echo "A compilar queryStructs"
			$(cc) $(PKG) -c $(SRC_P)queryStructs.c

view.o: $(SRC_P)view.c $(INC_P)view.h
			@echo "A compilar view"
			$(cc) $(PKG) -c $(SRC_P)view.c

filial.o: $(SRC_P)filial.c $(INC_P)filial.h $(INC_P)venda.h
			@echo "A compilar filial"
			$(cc) $(PKG) -c $(SRC_P)filial.c

viewQueries.o: $(SRC_P)viewQueries.c $(INC_P)viewQueries.h
			@echo "A compilar viewQueries"
			$(cc) $(PKG) -c $(SRC_P)viewQueries.c

controller.o: $(SRC_P)controller.c $(INC_P)controller.h $(INC_P)controllerQueries.h
			@echo "A compilar controller"
			$(cc) $(PKG) -c $(SRC_P)controller.c

controllerQueries.o: $(SRC_P)controllerQueries.c $(INC_P)controllerQueries.h $(INC_P)SGV.h $(INC_P)view.h
			@echo "A compilar controllerQueries"
			$(cc) $(PKG) -c $(SRC_P)controllerQueries.c

cliente.o: $(SRC_P)cliente.c $(INC_P)cliente.h
			@echo "A compilar cliente"
			$(cc) $(PKG) -c $(SRC_P)cliente.c

produto.o: $(SRC_P)produto.c $(INC_P)produto.h
			@echo "A compilar produto"
			$(cc) $(PKG) -c $(SRC_P)produto.c

produtos.o: $(SRC_P)produtos.c $(INC_P)produtos.h $(INC_P)produto.h
			@echo "A compilar produtos"
			$(cc) $(PKG) -c $(SRC_P)produtos.c

venda.o: $(SRC_P)venda.c $(INC_P)venda.h
			@echo "A compilar venda"
			$(cc) $(PKG) -c $(SRC_P)venda.c

clientes.o: $(SRC_P)clientes.c $(INC_P)clientes.h $(INC_P)cliente.h
			@echo "A compilar clientes"
			$(cc) $(PKG) -c $(SRC_P)clientes.c

faturacaoP.o: $(SRC_P)faturacaoP.c $(INC_P)faturacaoP.h
			@echo "A compilar faturacaoP"
			$(cc) $(PKG) -c $(SRC_P)faturacaoP.c

faturacaoGlobal.o: $(SRC_P)faturacaoGlobal.c $(INC_P)faturacaoGlobal.h $(INC_P)faturacaoP.h
			@echo "A compilar faturacaoGlobal"
			$(cc) $(PKG) -c $(SRC_P)faturacaoGlobal.c

filiais.o: $(SRC_P)filiais.c $(INC_P)filiais.h $(INC_P)filial.h
			@echo "A compilar filiais"
			$(cc) $(PKG) -c $(SRC_P)filiais.c

clean: 
		rm -f *.o program

memcheck:
		valgrind --leak-check=full --show-leak-kinds=all ./program
