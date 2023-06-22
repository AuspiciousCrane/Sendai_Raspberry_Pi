build:
	mkdir -p target
	gcc -o ./target/main main.c -lpigpio -lrt -pthread
run:
	mkdir -p target
	gcc -o ./target/main main.c -lpigpio -lrt -pthread
	sudo ./target/main
clean:
	rm -rf ./target

