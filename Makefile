main:
	g++ main.cpp -o main -L/usr/include/mysql/mysql -lmysqlclient
install:
	sudo apt-get install libmysqlclient-dev
clean:
	rm main		
run:
	./main	
