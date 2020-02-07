connectn.out: connectn.o board.o game_over.o get_valid_move.o play.o
	gcc -g -Wall -Werror -o connectn.out connectn.o board.o game_over.o get_valid_move.o play.o
connectn.o: connectn.c connectn.h board.h game_over.h get_valid_move.h play.h
	gcc -g -Wall -Werror -c connectn.c
board.o: board.c board.h
	gcc -g -Wall -Werror -c board.c
game_over.o: game_over.c game_over.h
	gcc -g -Wall -Werror -c game_over.c
get_valid_move.o: get_valid_move.c get_valid_move.h
	gcc -g -Wall -Werror -c get_valid_move.c
play.o: play.c play.h
	gcc -g -Wall -Werror -c play.c
clean:
	rm -rf *.o *.outg