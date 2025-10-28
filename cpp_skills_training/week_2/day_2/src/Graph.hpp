// #include <iostream>
// #include <fstream>
// #include <string>
// #include <memory>
// #include <optional>
// #include <vector>
// #include <algorithm>

// #pragma once

// class Node{
//     public:
//     static inline int numberOfInstances = 0;

//     Node(int id) : id(id) { numberOfInstances++; };

//     void printNeighbors(){
//         for(auto & neighbor : neighbors){
//             std::cout<<neighbor->id<<std::endl;
//         }
//     }

//     void addNeighbor(std::weak_ptr<Node> neighbor)
//     {
//         neighbors.emplace_back(neighbor);
//     }

//     ~Node()
//     {
//         numberOfInstances--; //????????
//     }

// private:
//     int id;
//     std::vector<std::weak_ptr<Node>> neighbors;
// };
