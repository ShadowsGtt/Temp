object = *.c
client:$(object)
	gcc -I/usr/include/mysql $(object) -L/usr/libmysql -lmysqlclient -lpthread -lcurses -o client 
clean:
	rm client
