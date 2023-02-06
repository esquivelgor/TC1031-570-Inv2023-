#ifndef _GRAPH_H
#define _GRAPH_H

#include "Ip.h"
#include "IpData.h"
#include "LinkedList.h"
#include "MaxHeap.h"
#include "QueueLinkedList.h"
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#define INF 0x3f3f3f3f

class Graph {
private:
  MaxHeap<IpData> ipHeap;
  int numNodes;
  int numEdges;
  int indexBM;
  // Lista de adyacencia (vector de listas de pares (vertice, peso))
  std::vector<LinkedList<std::pair<int, int>>> adjList;
  std::map<unsigned int, Ip> mapIp;
  void heap();
  void splitStr(std::string line, std::vector<std::string> &res,
                std::string delim);

public:
  Graph();
  ~Graph();
  void loadDirWeightedGraph(std::istream &input);
  void processData();
  void print();
  void dijkstraAlgorithmBM();
  int findIpIndex(std::string ipString);
};

#endif // _GRAPH_H
