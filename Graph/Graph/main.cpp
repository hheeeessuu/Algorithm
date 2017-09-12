//
//  main.cpp
//  Graph
//
//  Created by kim on 2017. 8. 25..
//  Copyright © 2017년 kim. All rights reserved.
//

// 코딩 인터뷰 퀘스천
/*
#include <iostream>
namespace Adjacency_Metrix {
    struct Graph {
        int V;
        int E;
        int **Adj;  // 2차원 메트릭스가 필요하기 때문에 이중 포인터를 사용
    };
    
    // 이것은 adj 매트릭스를 이용해서 그래프를 생성하는 코드입니다.
    struct Graph *adjMatrixOfGraph() {
        int i, u, v;
        struct Graph *G = (struct Graph*) malloc(sizeof(struct Graph));
        if(!G) {
            printf("Memory Error");
            return nullptr;
        }
        scanf("Number of Vertices : %d, Number of Edge : %d", &G->V, &G->E);
        G->Adj = (int **)malloc(sizeof(G->V * G->V));
        
        for(u = 0; u < G->V; u++)
            for(v = 0; v < G->V; v++)
                G->Adj[u][v] = 0;
        
        for(i = 0; i < G->E; i++) {
            // 간선을 읽습니다.
            scanf("Reading Edgh : %d %d", &u, &v);
            // 무향 그래프이므로 두 경우 모두 1로 결정
            G->Adj[u][v] = 1;
            G->Adj[v][u] = 1;
        }
        
        return G;
    }
}

namespace Adjacency_List {
    // 연결 리스트의 노드
    struct ListNode {
        int vertexNumber;
        struct ListNode *next;
    };

    
    struct Graph {
        int V;
        int E;
        ListNode **Adj;   //연결 리스트의 head
    };
    
    
    // 이 코드는 확장된 리스트를 사용하여 그래프를 생성합니다.
    struct Graph *adjListOfGraph() {
        int i, x, y;
        struct ListNode *temp;
        struct Graph *G = (struct Graph *)malloc(sizeof(struct Graph));
        if(!G) {
            printf("Memory Error");
            return nullptr;
        }
        scanf("Number of Vertices : %d, Number of Edges : %d", &G->V, &G->E);
        G->Adj = (ListNode **)malloc(G->V * sizeof(struct ListNode));
        for(i = 0; i < G->V; i++) {
            // 아 슈벌탱아 코드좀 확인하고 책만들어 시발
            // 맞는지 정확하지 않음 책이랑 틀림.
            G->Adj[i] = (struct ListNode*)malloc(sizeof(struct ListNode));
            G->Adj[i]->vertexNumber = i;
            G->Adj[i]->next = G->Adj[i];
        }
        
        for(i = 0; i < G->E; i++) {
            // 간선을 읽음
            scanf("Reading Edge : %d %d", &x, &y);
            temp = (struct ListNode *) malloc(sizeof(struct ListNode));
            temp->vertexNumber = y;
            temp->next = G->Adj[x];
            G-> Adj[x]->next = temp;
            temp = (struct ListNode *) malloc(sizeof(struct ListNode));
            temp->vertexNumber = y;
            temp->next = G->Adj[y];
            G->Adj[y]->next = temp;
        }
        
        return G;
    }
}

// 깊이 우선 탐색(Depth First Search)[DFS]
//const int tempGraphV = 100;
#define tempGraphV 100
int Visited[tempGraphV];

void DFS(struct Graph *G, int u) {
    Visited[u] = 1;
    for (int v = 0; v< tempGraphV; v++) {
        /* 예를 들어 그래프를 인접 매트릭스로 표현한다면,
         u에서 방문하지 않은 인접 정점을 찾는데 사용되는 조건은
         if(!Visited[v] && G->Adj[u][v] 입니다.
         
         for each 정점 u에서 방문하지 않은 인접 정점 v{
            DFS(v);
         }
    }
}

void DFSTraversal() {
    Graph *G = nullptr;
    for(int i = 0; i < tempGraphV; i++)
        Visited[i] = 0;
    // 그래프가 하나 이상의 컴포넌트를 가진다면 아래 루프가 필요합니다.
    for(int i = 0; i < tempGraphV; i++)
        if(!Visited[i])
            DFS(G, i);
}

#include <queue>

//void BFS (struct Graph *G, int u) {
//    int v;
//    std::queue<int> Q;
//    Q.push(u);
//    while (!Q.empty()) {
//        u = Q.front();
//        Q.pop();
//    
//    }
//    
//}

int main() {
     return 0;
}
*/
