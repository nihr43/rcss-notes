
//nathan hensel;	fall 2017

//this code uses the breadth first search alrgorithm to find the shortest path through a building on an elevator that can only go up 'u' or down 'd' floors




#include <stdio.h>
#include <stdlib.h>

int queue[100], front = -1, rear = -1;

//task 1:  create full adjacency list for input  ;done
//task 2:  find shortest path in that list
//				-> this will be the first path in which BFS finds the target, because all weights are 1	;done
//task 3:  record, traceback, and print the path taken	;done

typedef struct graph
{
	int size;
	struct node* array[100];
} graph;

typedef struct node
{
	int value;
	int flag;
	struct a_list_node* pre;
	struct a_list_node* head;
} node;

typedef struct a_list_node			//adj nodes are not nodes
{
	int value;
	struct a_list_node* next;
} a_list_node;


//creates graph, returns pointer.  a graph is an array of nodes, nodes have adj lists
graph* create_graph(int size)
{
	graph* g = malloc(sizeof(graph));
	g->size = size;

	//create nodes in array
	int i;
	for (i=1; i<size+1; i++)
	{
		g->array[i] = malloc(sizeof(node));
		g->array[i]->value = i;
		g->array[i]->head = NULL;
		g->array[i]->flag = 0;
		g->array[i]->pre = NULL;
	}
	return g;
}


//prints graph for testing
void print_graph(graph* g)
{
	printf("\nAdjacency List:\n");
    int i;
    for (i=1; i<(g->size+1); i++)
    {
		a_list_node* iterator = g->array[i]->head;
		printf("\nnode %d:", g->array[i]->value);

		while (iterator)
		{
			printf(" -> %d", iterator->value);
			iterator = iterator->next;
		}
	}
	printf("\n\n");
}


//creates adjacencies where possible and adds them to nodes at graph array[i].  
void create_lists(graph* g, int u, int d)
{
	int i;

	for (i=1; i<(g->size+1); i++)
    {
		if (g->array[i]->value > d)				//if value of node is high enough, add downward adj
		{
			a_list_node* new_adjacency = malloc(sizeof(a_list_node));		//create record of adjacency
			new_adjacency->value = g->array[i]->value - d;
			new_adjacency->next = g->array[i]->head;						//switch things around, assign new_adj at head of list
			g->array[i]->head = new_adjacency;
		}
		if (g->array[i]->value + u <= g->size)				//if value of node is low enough, add upward adj
		{
			a_list_node* new_adjacency = malloc(sizeof(a_list_node));		//create record of adjacency
			new_adjacency->value = g->array[i]->value + u;
			new_adjacency->next = g->array[i]->head;						//switch things around, assign new_adj at head of list
			g->array[i]->head = new_adjacency;
		}
	}
}


void enqueue(int node)
{
	if (front == -1)
		front = 0;
	rear = rear + 1;
	queue[rear] = node;
}

int dequeue()
{
	int dequeued;
	dequeued = queue[front];
	front = front + 1;
	return dequeued;
}

int queue_empty()
{
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}

void trace_path(graph* g, int i)
{
	if (g->array[i]->pre != NULL)
	{
		printf("%d <- ", i);
		trace_path(g, g->array[i]->pre);
	}
	else
		printf("%d", i);
}

void free_all(graph* g)
{
    int i;

//free the adjacency nodes
    for (i=1; i<(g->size+1); i++)
    {
		a_list_node* iterator = g->array[i]->head;
		a_list_node* temp;

		while (iterator)
		{
			temp = iterator;
			iterator = iterator->next;
			free(temp);
		}
	}


//free the nodes
    for (i=1; i<(g->size+1); i++)
    {
		free(g->array[i]);
	}


//free the graph root
	free(g);

}

//finds shortest path for graph g, start, goal     ;bfs augmented with pre pointer to retrace path
void bfs(graph* g, int start, int goal)
{
	a_list_node* iterator = g->array[start]->head;

	//printf("\nnode: %d", g->array[start]->value);

	enqueue(start);

	int i, j;

	while (queue_empty() != 1)
	{
		i = dequeue();
		//printf("\n%d", i);

		g->array[i]->flag = 1;
		iterator = g->array[i]->head;
			while (iterator)
			{
				if (g->array[iterator->value]->flag == 0)
				{
					g->array[iterator->value]->flag = 1;
					g->array[iterator->value]->pre = i;
					enqueue(iterator->value);

				}
				iterator = iterator->next;

			}
	}



//	printf("\nPredecessors:\n");							//prints all nodes and their predecessors for debugging

//    for (j=1; j<(g->size+1); j++)
//    {
//		printf("\nnode %d from", g->array[j]->value);
//		printf(" %d", g->array[j]->pre);
//	}

	if (g->array[goal]->pre == 0)
		printf("\n\ntake the stairs");
	else
	{
	printf("\n\n");
	trace_path(g, goal);
	}

	printf("\n\n");

}


int main(int argc, int *argv[])
{

	int f, s, g, u, d, i;

	if ( argc != 6 )
	{
		printf( "usage: f, s, g, u, d\n");
		exit(0);
	}

	f = atoi(argv[1]);		//converts characters to ints
	s = atoi(argv[2]);
	g = atoi(argv[3]);
	u = atoi(argv[4]);
	d = atoi(argv[5]);


	graph* graph = create_graph(f);
	create_lists(graph, u, d);
//	print_graph(graph);
	bfs(graph, s, g);

	free_all(graph);

	return 0;
}