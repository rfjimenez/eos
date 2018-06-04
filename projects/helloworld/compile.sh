eosiocpp -o helloworld.wast helloworld.cpp
eosiocpp -g helloworld.abi helloworld.hpp
cleos set contract helloworld ../helloworld
