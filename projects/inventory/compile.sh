eosiocpp -o inventory.wast inventory.cpp
eosiocpp -g inventory.abi inventory.hpp
cleos set contract inventory ../inventory
