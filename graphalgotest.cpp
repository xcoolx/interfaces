#include <set>
#include <stdint.h>
#include <string>

class Edge
{
private:
    uint32_t id;
    uint32_t length;
    uint32_t nodeID_1;
    uint32_t nodeID_2;
public:
    explicit Edge ( uint32_t, uint32_t, uint32_t, uint32_t );
    Edge ( ) = delete;
    uint32_t getId ( )const;
    uint32_t getLength ( ) const;
    uint32_t getNodeID_1 ( )const;
    uint32_t getNodeID_2 ( )const;
    inline friend bool operator<(const Edge& _Left, const Edge& _Right);
};

bool operator<( const Edge& _Left, const Edge& _Right )
{
    return (_Left.id < _Right.id);
}

class Node
{
private:
    uint32_t id;
    std::string name;
    uint32_t dimension; //how many arcs use this node
    std::set<uint32_t> NeighboursIds; // store neighbour IDs, saves memory
public:
    explicit Node ( uint32_t, const std::string& );
    Node ( ) = delete;
    uint32_t getId ( ) const;
    const std::string& getName ( ) const;
    uint32_t getDimension ( ) const;
    //logic: find or provide neighbours
    inline friend bool operator<(const Node& _Left, const Node& _Right);
};

bool operator<(const Node& _Left, const Node& _Right)
{
    return (_Left.id < _Right.id);
}

class Graph
{
private:
    uint32_t nodesAmount;
    uint32_t edgesAmount;
    std::set<Node> NodeArr; // Store the nodes directly, not pointers
    std::set<Edge> EdgeArr;
    uint32_t **map;
public:
    Graph ( );
    ~Graph ( );
    void addNode ( Node& );
    void addEdge ( Edge& );
};

void Graph::addNode ( Node& node )
{
    nodesAmount++;
    NodeArr.insert ( node );
}

void Graph::addEdge ( Edge& edge )
{
    nodesAmount++;
    EdgeArr.insert ( edge );
}

Node::Node ( uint32_t _id, const std::string& _name )
{
    id = _id;
    name = _name;
}

uint32_t Node::getId ( ) const
{
    return id;
}

const std::string& Node::getName ( ) const
{
    return name;
}

uint32_t Node::getDimension ( ) const
{
    return dimension;
}

Edge::Edge ( uint32_t _id, uint32_t _length, uint32_t id_1, uint32_t id_2)
{
    id = _id;
    length = _length;
    nodeID_1 = id_1;
    nodeID_2 = id_2;
}

uint32_t Edge::getId ( )const
{
    return id;
}

uint32_t Edge::getLength ( ) const
{
    return length;
}

uint32_t Edge::getNodeID_1 ( )const
{
    return nodeID_1;
}

uint32_t Edge::getNodeID_2 ( )const
{
    return nodeID_2;
}