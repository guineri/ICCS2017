#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>
#include <mpi.h>
#include <unistd.h>
#include <string.h> 
#include "comm.h"


void sendMessage(char *origem,char *destino, Type tipo, void *buffer, int size){
	
	
	int i,dest,N,ori,tag;
	FILE *file_map_rank;
	char **matrix;

	file_map_rank = fopen("/home/labpi/Dropbox/Experimentos_artigo/comm/rank_map","r");
	fscanf(file_map_rank,"%d",&N);
	
	matrix =  (char**) malloc(N*sizeof(char*));

	for (i=0;i<N;i++){
		matrix[i] = (char*) malloc(32*sizeof(char));
	}

	for(i=0;i<N;i++){
		fscanf(file_map_rank,"%s",matrix[i]);
	}

	for(i=0;i<N;i++){
		if(strcmp(destino,matrix[i])==0){
			dest = i;
			break;
		}
	}
	for(i=0;i<N;i++){
		if(strcmp(origem,matrix[i])==0){
			ori = i;
			break;
		}
	}


	int rank;
	switch(tipo){


		case SHORT:
			printf("TODO SHORT\n");
			break;
		case INT:
			//printf("Entrei no INT SEN
			int *data_int;
			data_int = (int*)buffer;
			MPI_Comm_rank (MPI_COMM_WORLD, &rank);
			//printf("Rank Send : %d rank atual: %d destino: %s\n",dest,rank,destino);
			tag = ori*13 + dest*17;
			MPI_Send(data_int, size, MPI_INT,dest, tag, MPI_COMM_WORLD);
			break;
		case LONG:
			printf("TODO LONG\n");
			break;
		case LONG_LONG: 
			printf("TODO LONG_LONG\n");
			break;
		case UNSIGNED_CHAR:
			printf("TODO_UNSIGNED_CHAR\n");
			break;
		case UNSIGNED_SHORT:
			printf("TODO UNSIGNED_SHORT\n");
			break;
		case UNSIGNED:
			printf("TODO_UNSIGNED\n");
			break;
		case UNSIGNED_LONG:
			printf("TODO UNSIGNED LONG\n");
			break;
		case UNSIGNED_LONG_LONG:
			printf("TODO UNSIGNED LONG LONG\n");
			break;
		case FLOAT:
			//printf("Entrei no FLOAT SEND\n");
			float *data_float;
			data_float = (float*)buffer;
			MPI_Comm_rank (MPI_COMM_WORLD, &rank);
			//printf("Rank Send : %d rank atual: %d destino: %s\n",dest,rank,destino);
			tag = ori*13 + dest*17;
			MPI_Send(data_float, size, MPI_FLOAT,dest, tag, MPI_COMM_WORLD);
			break;
		case DOUBLE:
			printf("TODO DOUBLE\n");
			break;
		case LONG_DOUBLE:
			printf("TODO LONG DOUBLE\n");
			break;
		case BYTE:
			printf("TODO BYTE\n");
			break;


	}
	



}


void receiveMessage(char *destino,char *origem, Type tipo, void *buffer, int size){


	int i,ori,N,dest,tag;
	FILE *file_map_rank;
	char **matrix;

	file_map_rank = fopen("/home/labpi/Dropbox/Experimentos_artigo/comm/rank_map","r");
	fscanf(file_map_rank,"%d",&N);
	
	matrix =  (char**) malloc(N*sizeof(char*));

	for (i=0;i<N;i++){
		matrix[i] = (char*) malloc(32*sizeof(char));
	}

	for(i=0;i<N;i++){
		fscanf(file_map_rank,"%s",matrix[i]);
	}

	for(i=0;i<N;i++){
		if(strcmp(origem,matrix[i])==0){
			ori = i;
			break;
		}
	}

	for(i=0;i<N;i++){
		if(strcmp(destino,matrix[i])==0){
			dest = i;
			break;
		}
	}

	int rank;
	switch(tipo){


		case SHORT:
			printf("TODO SHORT\n");
			break;
		case INT:
			//printf("Entrei no INT RECV\n");
			int *data_int;
			data_int = (int*) buffer;
			MPI_Comm_rank (MPI_COMM_WORLD, &rank);
			//printf("Rank Recv : %d rank atual: %d origem: %s\n",ori,rank,origem);
			tag = ori*13 + dest*17;
			MPI_Recv(data_int, size, MPI_INT, ori, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			break;
		case LONG:
			printf("TODO LONG\n");
			break;
		case LONG_LONG: 
			printf("TODO LONG LONG\n");
			break;
		case UNSIGNED_CHAR:
			printf("TODO UNSIGNED CHAR\n");
			break;
		case UNSIGNED_SHORT:
			printf("TODO UNSIGNED SHORT\n");
			break;
		case UNSIGNED:
			printf("TODO UNSIGNED\n");
			break;
		case UNSIGNED_LONG:
			printf("TODO UNSIGNED LONG\n");
			break;
		case UNSIGNED_LONG_LONG:
			printf("TODO UNSIGNED LONG LONG\n");
			break;
		case FLOAT:
			//printf("Entrei no FLOAT RECV\n");
			float *data_float;
			data_float = (float*) buffer;
			MPI_Comm_rank (MPI_COMM_WORLD, &rank);
			//printf("Rank Recv : %d rank atual: %d origem: %s\n",ori,rank,origem);
			tag = ori*13 + dest*17;
			MPI_Recv(data_float, size, MPI_FLOAT, ori, tag, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
			break;
		case DOUBLE:
			printf("TODO DOUBLE\n");
			break;
		case LONG_DOUBLE:
			printf("TODO LONG DOUBLE\n");
			break;
		case BYTE:
			printf("TODO BYTE\n");
			break;


	}



}


 

