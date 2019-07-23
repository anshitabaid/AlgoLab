#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int value;
	struct node *next;

} Node;

typedef struct head {
	Node *head;
} Head;

typedef struct graph {

	int vertices;
	Head* array;

} Graph;

Node* newNode(int value) {
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	return newNode;
}

Graph* createGraph(int vertices) {

	Graph *graph = (Graph*)malloc(sizeof(Graph));
	graph->vertices = vertices;

	graph->array = (Head*)malloc(vertices * sizeof(struct head));

	for (int i = 0; i<vertices; i++) {
		((graph->array)+i)->head = NULL;
	}

	return graph;

}

void printMatrix(Graph *graph) {
	int i, j;
	int a[graph->vertices][graph->vertices];
	Node *temp = (Node*)malloc(sizeof(Node));
	for (i=0; i<graph->vertices; i++) {
		temp = ((graph->array)+i)->head;
		while(temp->next != NULL) {
			a[i][temp->value] = 1;
			temp = temp->next;
		}
		for (j = 0; j<graph->vertices; j++) {
			if (a[i][j] != 1) {
				a[i][j] = 0;
			}
		}
	}

	for (i=0; i<graph->vertices; i++) {

		printf("[");

		for(j=0; j<graph->vertices; j++) {

			printf("%d ", a[i][j]);

		}

		printf("]\n");

	}

}

void printGraph(Graph *graph) {

	int v;
	for (v = 0; v < graph->vertices; v++) {

		printf("\nAdjacency list of vertex %d\n", v);
		Node *temp = ((graph->array)+v)->head;
		while(temp!=NULL) {
			printf("-> %d", temp->value);
			temp = temp->next;
		}
		printf("\n");

	}

	printMatrix(graph);

}

void addEdge(Graph *graph, int src, int dest) {

	Node *temp = newNode(dest);

	if(((graph->array)+src)->head == NULL) {
		((graph->array)+src)->head = temp;
	}
	else {
		Node *lastNode = ((graph->array)+src)->head;
		while(lastNode->next != NULL) {
			lastNode = lastNode->next;
		}
		lastNode->next = temp;
	}

	temp = newNode(src);

	if(((graph->array)+dest)->head == NULL) {
		((graph->array)+dest)->head = temp;
	}
	else {
		Node *lastNode = ((graph->array)+dest)->head;
		while(lastNode->next != NULL) {
			lastNode = lastNode->next;
		}
		lastNode->next = temp;
	}

}

int main() {

	int V = 5; 
    Graph* graph = createGraph(V); 
    addEdge(graph, 0, 1); 
    addEdge(graph, 0, 4); 
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3); 
    addEdge(graph, 1, 4); 
    addEdge(graph, 2, 3); 
    addEdge(graph, 3, 4); 
    printGraph(graph); 
    return 0; 

}