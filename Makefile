main:
	g++ main.cpp -o main -L/usr/include/mysql/mysql -lmysqlclient
main1:
	g++ main1.cpp -o main1 -L/usr/include/mysql/mysql -lmysqlclient
	
install:
	sudo apt-get install libmysqlclient-dev
clean:
	rm main		
run:
	./main
run1:
	./main1		
