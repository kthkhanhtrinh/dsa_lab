template <class T>
class DGraph {
public:
     class VertexNode; // Forward declaration
     class Edge; // Forward declaration
protected:
     VertexNode* nodeList; //list of vertexNode of DGraph
     int countVertex;
     int countEdge;
public:
     DGraph() {
          this->nodeList = nullptr;
          this->countEdge = 0;
          this->countVertex = 0;
     }
     ~DGraph() {};
     VertexNode* getVertexNode(T vertex);
     void add(T vertex);
 
     void connect(T from, T to, float weight=0);
 
     void removeVertex(T removeVertex);
     bool removeEdge(T from, T to);
     string shape();
     bool empty();
     void clear();
     void printGraph();

public:
     class VertexNode {
     private:
          T vertex;
          Edge* adList; //list of adjacent edge of this vertex
          VertexNode* next;

          friend class Edge;
          friend class DGraph;
     public:

          VertexNode(T vertex, Edge* adList = nullptr, VertexNode* next = nullptr) {
               this->vertex = vertex;
               this->adList = adList;
               this->next = next;
     }
          string toString();
          void addAdjacentEdge(Edge* newEdge);
          bool connectTo(VertexNode* toNode, float weight = 0);
          bool removeTo(VertexNode* toNode);
          Edge* getEdge(VertexNode* toNode);
     };
 
     class Edge {
     private:
          VertexNode* fromNode;
          VertexNode* toNode;
          float weight;
          Edge* next;
          
          friend class VertexNode;
          friend class DGraph;
     public:
          Edge(VertexNode* fromNode, VertexNode* toNode, float weight = 0.0, Edge* next = nullptr) {
               this->fromNode = fromNode;
               this->toNode = toNode;
               this->weight = weight;
               this->next = next;
          }
          string toString();

     };
};

template<class T>
typename DGraph<T>::Edge* DGraph<T>::VertexNode::getEdge(VertexNode* toNode) {
    //TODO: Iterate through the adjacency list of this vertex
    //      checking if there exists an edge with this vertex as the starting vertex 
    //      and "toNode" as the ending vertex. 
    //      If not return nullptr, else return that edge.
    Edge* tmp = adList;
    while(tmp != nullptr)
    {
        if(tmp->toNode == toNode)
        {
            return tmp;
        }
        tmp = tmp->next;
    }
    return nullptr;
}

template<class T>
void DGraph<T>::VertexNode::addAdjacentEdge(Edge* newEdge) {
    //TODO: add newEdge to adjacency list of this vertex.
    if(adList == nullptr)
        adList = newEdge;
    else
    {
        Edge* tmp = adList;
        while(tmp->next != nullptr)
            tmp = tmp->next;
        
        tmp->next = newEdge;
    }


}

template<class T>
bool DGraph<T>::VertexNode::connectTo(VertexNode* toNode, float weight) {
    //TODO: get edge from this node to "toNode".
    
    //TODO: If the edge is not existed, create a new Edge and add it to the adjacency list. 
    //      If the edge is existed, update its weight.
    
    //TODO: Return true if a new Edge is created; otherwise, return false.
    
    Edge* curr = getEdge(toNode);
    if(curr == nullptr)
    {
        Edge* newEdge = new Edge(this, toNode, weight);
        addAdjacentEdge(newEdge);
        return true;
    }
    curr->weight = weight;
    return false;

}

template<class T>
bool DGraph<T>::VertexNode::removeTo(VertexNode *toNode) {
    //TODO: remove the edge with "toNode" as the ending vertex from this node's adjacency list.
    //TODO: return true if success; otherwise, return false.
    if(adList == nullptr)
        return false;
    
    if(adList->toNode == toNode)
    {
        Edge* delEdge = adList;
        adList = adList->next;
        delete delEdge;
        return true;
    }
    
    Edge* prev = adList;
    Edge* curr = adList->next;
    while(curr != nullptr)
    {
        if(curr->toNode == toNode)
        {
            prev->next = curr->next;
            delete curr;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}


template<class T>
typename DGraph<T>::VertexNode* DGraph<T>::getVertexNode(T vertex) {
    //TODO: Iterate through the Node list of the graph 
    //      check if any vertexNode contains vertex. 
    //      If such a vertexNode exists, return it; otherwise, return nullptr.
    if(nodeList == nullptr)
        return nullptr;

    VertexNode* curr = nodeList;
    while(curr != nullptr)
    {
        if(curr->vertex == vertex)
        {
            return curr;
        }
        curr = curr->next;
    }
    return nullptr;
}

template<class T>
void DGraph<T>::add(T vertex) {
    //TODO: create a new vertexNode with vertex.
    //TODO: add new vertexNode to the end of Node list of the graph.
    //TODO: increase the countVertex.

    VertexNode* newVertex = new VertexNode(vertex);
    VertexNode* tmp = nodeList;
    
    if(nodeList == nullptr)
    {
        nodeList = newVertex;
        countVertex = 1;
        return;
    }
    
    while (tmp->next != nullptr)
    {
        /* code */
        tmp = tmp->next;
    }
    tmp->next = newVertex;
    countVertex++;

}

template <class T>
void DGraph<T>::connect(T from, T to, float weight) {
    //TODO: get vertexNode with "from" and vertexNode with "to".

    //TODO: If either of the two vertexNode objects does not exist, 
    //      throw an exception: VertexNotFoundException("Vertex doesn't exist!").
    
    //TODO: connect "from" vertexNode to "to" vertexNode. 
    //      If a new edge is created, increase the countEdge.
    VertexNode* from_node = getVertexNode(from);
    VertexNode* to_node = getVertexNode(to);
    if(from_node == nullptr || to_node == nullptr)
        throw VertexNotFoundException("Vertex doesn't exist!");
    
    bool newEdgeCreated = from_node->connectTo(to_node, weight);

    if(newEdgeCreated)
        countEdge++;

}

template <class T>
bool DGraph<T>::removeEdge(T from, T to) {
    //TODO: get vertexNode with "from" and vertexNode with "to".
        
    //TODO: If either of the two vertexNode objects does not exist, 
    //      throw an exception: VertexNotFoundException("Vertex doesn't exist!").
    
    //TODO: Delete the edge between the "from" vertexNode and the "to" vertexNode. (use removeTo method)
    //      If success return true and decrement the countEdge; otherwise, return false; 

    VertexNode* fromNode = getVertexNode(from);
    VertexNode* toNode = getVertexNode(to);
    if (fromNode == nullptr || toNode == nullptr)
        throw VertexNotFoundException("Vertex doesn't exist!");

    bool isRemoved = fromNode->removeTo(toNode);

    if(isRemoved)
    {
        countEdge--;
        return true;
    }
    return false;
}

template <class T>
void DGraph<T>::removeVertex(T removeVertex) {
    //TODO: get vertexNode with "removeVertex"
        
    //TODO: If this vertexNode isn't existed,
    //      throw an exception: VertexNotFoundException("Vertex doesn't exist!").
    
    //TODO: Iterate through all the vertexNode in the graph's Node list. For each vertexNode:
    //      - Check for an edge from the current vertex to the "removeVertex". 
    //      If such an edge exists, delete it (use removeTo method) and decrement the countEdge. 
    
    //      - Check for an edge from the "removeVertex" to the current vertex. 
    //      If such an edge exists, delete it (use removeTo method) and decrement the countEdge.
    
    //TODO: Delete the vertexNode containing removeVertex from the Node list of the graph
    //      Decrement the countVertex.

    VertexNode* removedNode = getVertexNode(removeVertex);
    if (removedNode == nullptr)
        throw VertexNotFoundException("Vertex doesn't exist!");

    VertexNode* curr = nodeList;
    while (curr != nullptr)
    {
        if(curr->getEdge(removedNode))
        {
            if(curr->removeTo(removedNode))
                countEdge--;
        }

        if(removedNode->getEdge(curr))
        {
            if(removedNode->removeTo(curr))
                countEdge--;
        }
        
        curr = curr->next;
    }

    if(nodeList == removedNode)
        nodeList = nodeList->next;
    else{
        VertexNode* tmp = nodeList;
        while (tmp->next != removedNode) {
            tmp = tmp->next;
        }
        tmp->next = removedNode->next; 
    }

    delete removedNode;
    countVertex--;

}

template<class T>
string DGraph<T>::shape() {
    //TODO: return the string with format: [Vertices: <numOfVertex>, Edges: <numOfEdge>]
    return "[Vertices: " + to_string(countVertex) + ", Edges: " + to_string(countEdge) + "]";

}

template<class T>
bool DGraph<T>::empty() {
    //TODO: return if graph is empty (it doesn't have any vertex and edge)
    return countVertex == 0 && countEdge == 0;
}

template<class T>
void DGraph<T>::clear() {
    //TODO: remove all edges and vertices of graph.
    while (nodeList != nullptr) {
        VertexNode* current = nodeList;

        while (current->adList != nullptr) {
            Edge* tmpEdge = current->adList;
            current->adList = current->adList->next;
            delete tmpEdge; 
        }

        nodeList = nodeList->next;
        delete current;
    }

    countVertex = 0;
    countEdge = 0;
}
