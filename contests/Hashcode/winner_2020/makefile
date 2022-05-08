main: main.cpp mutationRegion.o crossover.o getDistance.o intensify.o print.o receive.o utils.o evaluate.o initialize_random.o MA.o mutation.o Problem.o send.o Individual.o mutationPercentageUsed.o  
	mpic++.openmpi main.cpp mutationRegion.o crossover.o getDistance.o intensify.o print.o receive.o utils.o evaluate.o initialize_random.o MA.o mutation.o Problem.o send.o Individual.o mutationPercentageUsed.o  -O2 -o  main

mutationRegion.o: Individual.h Problem.h mutationRegion.cpp
	mpic++.openmpi -O2 -c -o $@ mutationRegion.cpp 

Individual.o: Individual.h Individual.cpp
	mpic++.openmpi -O2 -c -o $@ Individual.cpp 

crossover.o: crossover.cpp Individual.h 
	mpic++.openmpi -O2 -c -o $@ crossover.cpp

getDistance.o: getDistance.cpp Individual.h 
	mpic++.openmpi -O2 -c -o $@ getDistance.cpp

intensify.o: intensify.cpp Individual.h 
	mpic++.openmpi -O2 -c -o $@ intensify.cpp

print.o: print.cpp Individual.h 
	mpic++.openmpi -O2 -c -o $@ print.cpp

receive.o: receive.cpp Individual.h 
	mpic++.openmpi -O2 -c -o $@ receive.cpp

evaluate.o: evaluate.cpp Individual.h 
	mpic++.openmpi -O2 -c -o $@ evaluate.cpp

initialize_random.o: initialize_random.cpp Individual.h 
	mpic++.openmpi -O2 -c -o $@ initialize_random.cpp

mutation.o: mutation.cpp Individual.h 
	mpic++.openmpi -O2 -c -o $@ mutation.cpp

mutationPercentageUsed.o: mutationPercentageUsed.cpp Individual.h 
	mpic++.openmpi -O2 -c -o $@ mutationPercentageUsed.cpp

send.o: send.cpp Individual.h 
	mpic++.openmpi -O2 -c -o $@ send.cpp

Problem.o: Problem.h
	mpic++.openmpi -O2 -c -o $@ Problem.cpp

MA.o: MA.h Individual.h Problem.h MA.cpp
	mpic++.openmpi -O2 -c -o $@ MA.cpp

utils.o: utils.cpp utils.h
	mpic++.openmpi -O2 -c -o $@ utils.cpp

clean:
	rm -f main *.o
