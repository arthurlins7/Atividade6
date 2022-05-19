#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

sem_t mutex,vazio,compor;

int *buffer;
int P,C,N,B;

pthread_t *produtores;
pthread_t *consumidores;

int produto(pthread_t self){
	int i = 0;
	int p = 1 + rand()%40;
	while(!pthread_equal(*(produtores+i),self) && i < P){
		i++;
	}
	printf("\nProdutor %d produzindo %d na posição %d", i+1, p, B);
	return p;
}

void consumo(int p,pthread_t self){
	int i = 0;
	while(!pthread_equal(*(consumidores+i),self) && i < C){
		i++;
	}
	for(i=0;i<=N;++i)
	printf("\nConsumidor %d consumindo %d na posição %d", i+1, p, B);
	
}

void* consumidor(void *s){
	int c;
	while(1){
		sem_wait(&compor);
		sem_wait(&mutex);
		c = *(buffer+B);
		consumo(c,pthread_self());
		--B;
		sem_post(&mutex);
		sem_post(&vazio);
		sleep(1+rand()%5);
	}

}

void* produtor(void *s){

	while(1){
		int p = produto(pthread_self());
		sem_wait(&vazio);
		sem_wait(&mutex);
		++B;
		*(buffer + B) = p; 
		sem_post(&mutex);
		sem_post(&compor);
		sleep(1 + rand()%3);
	}

}

int main(void){
	printf("Insira o numero de produtores, consumidores, o limite e o tamanho do buffer:");
	scanf("%d",&P);
	scanf("%d",&C);
  scanf("%d",&N);
  scanf("%d",&B);
  produtores = (pthread_t*) malloc(P*sizeof(pthread_t));
	consumidores = (pthread_t*) malloc(C*sizeof(pthread_t));
	buffer = (int*) malloc(B*sizeof(int));

  sem_init(&mutex,0,1);
	sem_init(&compor,0,0);
	sem_init(&vazio,0,B);

	for(int i=0;i<N;i++){
		pthread_create(produtores+i,NULL,&produtor,NULL);
  }
  
	for(int i=0;i<N;i++){
		pthread_create(consumidores+i,NULL,&consumidor,NULL);
  }
  
	for(int i=0;i<N;i++){
		pthread_join(*(produtores+i),NULL);
	}
	for(int i=0;i<N;i++){
		pthread_join(*(consumidores+i),NULL);
	}

	return 0;
}
